#include "AlgoExtrusion.h"

//Fonction d'extrusion simple
// form : Figure 2D qui va subire l'extrusion
// nbPas : nombre total des pas
// H : Hauteur total de la figure extruder(longeur de l'extrusion)
// coeff : coeficent d'agrandissement / ou de retrecissement
QVector3D** SurfaceExtrusionSimple(vector<QPoint> form, int nbPas, float coeff, float H)
{
	if (coeff <= 0 || nbPas <= 0)
		return nullptr;

	// Allocate la matrice des points
	QVector3D** surface = nullptr;
	surface = new QVector3D*[form.size()];
	for (int i = 0; i < form.size(); i++)
		surface[i] = new QVector3D[nbPas + 1];

	// Générer h
	float pas = 1.0f / nbPas;
	float *h = new float[nbPas + 1];
	h[0] = 0;
	for (int j = 1; j < nbPas + 1; j++)
		h[j] = h[j - 1] + pas;

	// Générer les points
	for (int i = 0; i < form.size(); i++)
	{
		for (int j = 0; j < nbPas + 1; j++)
		{
			surface[i][j].setX(form[i].x() * (h[j] *(coeff - 1) + 1));
			surface[i][j].setY(form[i].y() * (h[j] *(coeff - 1) + 1));
			surface[i][j].setZ(h[j]*H);
		}
	}
	return surface;
}

//Fonction d'extrusion de révolution
// form : Figure 2D qui va subire l'extrusion
// nbPas : nombre total des pas
QVector3D** SurfaceExtrusionRevolution(vector<QPoint> form, int nbPas)
{
	if (nbPas <= 0)
		return nullptr;

	// Allocate la matrice des points
	QVector3D** surface = nullptr;
	surface = new QVector3D*[form.size()];
	for (int i = 0; i < form.size(); i++)
		surface[i] = new QVector3D[nbPas + 1];

	// Générer les pas des angles
	float pas = 2 * PI / nbPas;
	float *angle = new float[nbPas + 1];
	angle[0] = 0;
	for (int j = 1; j < nbPas + 1; j++)
		angle[j] = angle[j - 1] + pas;

	// Générer les points
	for (int i = 0; i < form.size(); i++)
	{
		for (int j = 0; j < nbPas + 1; j++)
		{
			surface[i][j].setX(form[i].x() * cos(angle[j]));
			surface[i][j].setY(form[i].y());
			surface[i][j].setZ(-form[i].x() * sin(angle[j]));
		}
	}
	return surface;
}

//Fonction d'extrusion généralisée
// form : Figure 2D qui va subire l'extrusion
// soul : la trajectoire d'extrusion
QVector3D** SurfaceExtrusionGeneral(vector<QPoint> form, vector<QPoint> soul)
{
	if (soul.size() <= 0 || form.size() <= 0)
		return nullptr;

	// Allocate la matrice des points
	QVector3D** surface = nullptr;
	surface = new QVector3D*[form.size()];
	for (int i = 0; i < form.size(); i++)
		surface[i] = new QVector3D[soul.size()];

	// Vecteur normal
	QVector3D N(0.0f, 0.0f, 1.0f);

	// Parcourir suivant la courbe trajectoire
	for (int s = 0; s < soul.size(); s++)
	{
		// calcul de la tangente V
		QVector3D V;
		// premier point
		if (s == 0)
		{
			V.setX(soul[s + 1].x() - soul[s].x());
			V.setY(soul[s + 1].y() - soul[s].y());
		}
		// dernier point
		else if (s == soul.size() - 1)
		{
			V.setX(soul[s].x() - soul[s - 1].x());
			V.setY(soul[s].y() - soul[s - 1].y());
		}
		// tous autre cas
		else
		{
			V.setX((soul[s + 1].x() - soul[s - 1].x()) / 2.0f);
			V.setY((soul[s + 1].y() - soul[s - 1].y()) / 2.0f);
		}
		V.setZ(0);
		// calcul du vecteur U
		QVector3D U = QVector3D::crossProduct(V, N).normalized();
		// Générer les points
		for (int i = 0; i < form.size(); i++)
		{
			surface[i][s].setX(soul[s].x() + form[i].x()*U.x() + form[i].y()*N.x());
			surface[i][s].setY(soul[s].y() + form[i].x()*U.y() + form[i].y()*N.y());
			surface[i][s].setZ(0 + form[i].x()*U.z() + form[i].y()*N.z());
		}
	}
	return surface;
}

// Fonction pour déterminer du barycentre d'un ensemble des points
QVector3D Barycentre(vector<QVector3D> poly)
{
	float x = 0, y = 0, z = 0;
	int i = 0;
	for (i = 0; i < poly.size(); i++) 
	{
		x += poly[i].x();
		y += poly[i].y();
		z += poly[i].z();
	}
	x /= i;
	y /= i;
	z /= i;
	return QVector3D(x, y, z);
}