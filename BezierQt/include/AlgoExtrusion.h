#pragma once

#include <QGLWidget>
#include <QDebug>
#include <QVector3D>
#include <math.h>
#include "AlgoMath.h"

# define PI	3.14159265358979323846  /* pi */

using namespace std;

QVector3D** SurfaceExtrusionSimple(vector<QPoint> form, int nbPas, float coeff, float H);
QVector3D** SurfaceExtrusionRevolution(vector<QPoint> form, int nbPas);
QVector3D** SurfaceExtrusionGeneral(vector<QPoint> form, vector<QPoint> soul);
QVector3D Barycentre(vector<QVector3D> poly);
