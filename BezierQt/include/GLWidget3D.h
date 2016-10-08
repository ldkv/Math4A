#pragma once

#include <QtOpenGL>
#include <QVector3D>
#include "GL/glu.h"
#include "AlgoMath.h"
#include "AlgoExtrusion.h"
#include "GLWidget2D.h"

using namespace std;

#define POINT_SIZE 10

class GLWidget3D : public QOpenGLWidget
{
	Q_OBJECT
public:
	GLWidget3D(QWidget *parent);
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	
	void ClearSurface();
	void UpdateData(vector<QPoint> form, vector<QPoint> soul);
	void drawFacette();
	int pas() const { return nbPas; }
	void pas(int p) { nbPas = p; }
	float coefficient() const { return coeffExtru; }
	void coefficient(float coeff) { coeffExtru = coeff; }
	void extrusion(int ex) { modeExtrusion = ex; }
	int extrusion() const { return modeExtrusion; }
	void facette(int f) { modeFacette = f; }
	int facette() const { return modeFacette; }
	void backgroundColor(QColor col) { bgColor = col; }
	QPoint mouse() { return mousePos; }

	void keyPressEvent(QKeyEvent *event);

public slots:
	void timeOutSlot();

signals:
	void MouseMoved();

private:
	QPoint mousePos;
	QTimer *t_Timer;
	QColor bgColor;
	QColor colorCourbe = QColor(255, 0, 0);

	// Définition l'ensemble des points du surfce
	QVector3D** surface = nullptr;
	int form_size = 0;
	int soul_size = 0;
	int modeExtrusion = 0;
	int modeFacette = 0;

	// Paramètres d'extrusion
	int nbPas = 10;
	int intervalFacet = 10;
	float coeffExtru = 0.1f;
	float H = 2000.0f;

	// Paramètres pour le caméra
	float eyeX = 0, eyeY = -300, eyeZ = 0;
	float tarX = 0, tarY = 0, tarZ = 0;
	float upX = 1, upY = 0, upZ = 0;
};