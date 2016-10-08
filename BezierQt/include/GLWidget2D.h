#pragma once

#include <QtOpenGL>
#include "GL/glu.h"
#include "AlgoMath.h"

using namespace std;

#define POINT_SIZE 10

class GLWidget2D : public QOpenGLWidget
{
	Q_OBJECT
public:
	GLWidget2D(QWidget *parent);
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	void UpdateData();
	void NewPoly();
	void ClearPoly();
	void ClearSelected();
	void drawLines(vector<QPoint> points, QColor col);
	void drawPoints(vector<QPoint> points, QColor col);

	int findNearestPoint(QPoint p);
	int pas() { return nbPas; }
	void pas(int p) { nbPas = p; }
	void backgroundColor(QColor col) { bgColor = col; }
	QPoint mouse() { return mousePos; }

	void NeedUpdate() { needUpdate = true; }
	vector<QPoint> GetCourbe();

	~GLWidget2D()
	{
		delete[] t_Timer;
	}

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

public slots:
	void timeOutSlot();
	void SetClosedCurve(int state);

signals:
	void MouseMoved();
	void CourbeUpdated();
	void ReleaseButton();

private:
	QPoint mousePos;
	QTimer *t_Timer;
	QColor bgColor;

	// Définition l'ensemble des points du poly et des courbes
	vector<QPoint> poly;
	vector<QPoint> polyCC;
	vector<QPoint> courbe;
	vector<QPoint> courbeCC;
	vector<int> r;
	QColor colorPoly = QColor(0, 0, 255);
	QColor colorPolyCC = QColor(0, 255, 0);
	QColor colorCourbe = QColor(255, 0, 0);
	QColor colorCourbeCC = QColor(0, 255, 0);
	
	int nbPas = 10;
	bool needUpdate = false;	// nécessaire de recalculer les courbes?
	bool polyCreating = false;	// poly de contrôle en train de créer?
	bool closedCurve = true;	// courbe fermée ?
	int pointSelected = -1;		// sauvegarder le point cliqué par souris
};