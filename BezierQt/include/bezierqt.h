#pragma once

#include "ui_bezierqt.h"
#include "GLWidget2D.h"
#include "GLWidget3D.h"

using namespace std;

class BezierQt : public QMainWindow
{
	Q_OBJECT

public:
	BezierQt(QWidget *parent = 0);
	
private slots:
	void newForm();
	void newSoul();
	void modeCurve();
	void modeExtrusion();
	void modeFacette();
	void quit();
	void UpdateData3D();

private:
	Ui::BezierQtClass ui;
	GLWidget2D *glSoul;
	GLWidget2D *glForm;
	GLWidget3D *glSurface;
};