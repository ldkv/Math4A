#include "GLWidget3D.h"

// Initialisation de la scène OpenGL
GLWidget3D::GLWidget3D(QWidget *parent) : QOpenGLWidget(parent)
{
	int seconde = 1000; // 1 seconde = 1000 ms
	int timerInterval = seconde / 60;
	t_Timer = new QTimer(this);
	connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
	t_Timer->start(timerInterval);
	setMouseTracking(true);
	setFocusPolicy(Qt::StrongFocus);
}

// Pour garder les FPS à 60
void GLWidget3D::timeOutSlot()
{
	update();
}

// Supprimer les points du surface
void GLWidget3D::ClearSurface()
{
	if (surface != nullptr)
	{
		for (int i = 0; i < form_size; i++)
			delete[] surface[i];
		delete[] surface;
		surface = nullptr;
	}
}

// Initialisation du module OpenGL
void GLWidget3D::initializeGL()
{
	glClearColor(bgColor.red() / 255.0f, bgColor.green() / 255.0f, bgColor.blue() / 255.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// Redimensionner de la scène pour adapter à la fenêtre principale
void GLWidget3D::resizeGL(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(140, (float)width / height, 1.0f, 10000.0f);
	glEnable(GL_DEPTH_TEST);
}

// Fonction mettre à jour de la scène OpenGL
void GLWidget3D::paintGL()
{
	glClearColor(bgColor.red() / 255.0f, bgColor.green() / 255.0f, bgColor.blue() / 255.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// Fonction pour déplacer le caméra
	gluLookAt(eyeX, eyeY, eyeZ, tarX, tarY, tarZ, upX, upY, upZ);

	// Dessiner la surface
	if (surface != nullptr)
		drawFacette();
}

// Les contrôles clavier pour le caméra
void GLWidget3D::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Z:
		eyeY += eyeY / 10;
		break;
	case Qt::Key_S:
		eyeY -= eyeY / 10;
		break;
	case Qt::Key_X:
		upX = upX == 1 ? 0 : 1;
		break;
	case Qt::Key_W:
		upZ = upZ == 1 ? 0 : 1;
		break;
	case Qt::Key_A:
		eyeZ = -300;
		break;
	case Qt::Key_E:
		eyeZ = 0;
		break;
	default:
		break;
	}
	event->accept();
}

// Fonction facettisation
void GLWidget3D::drawFacette()
{
	glColor3f(colorCourbe.red() / 255.0f, colorCourbe.green() / 255.0f, colorCourbe.blue() / 255.0f);
	int p = nbPas;
	if (modeExtrusion == 2 && soul_size > 0)
		p = soul_size - 1;
	for (int i = 0; i < form_size - 1; i++)
	{
		for (int j = 0; j < p; j++)
		{
			// Facette rectangulaire
			if (modeFacette == 0)
			{
				//Draw the four corners of the rectangle
				//glBegin(GL_QUADS);
				glBegin(GL_LINE_STRIP);
				glVertex3f(surface[i][j].x(), surface[i][j].y(), surface[i][j].z());
				glVertex3f(surface[i + 1][j].x(), surface[i + 1][j].y(), surface[i + 1][j].z());
				glVertex3f(surface[i + 1][j + 1].x(), surface[i + 1][j + 1].y(), surface[i + 1][j + 1].z());
				glVertex3f(surface[i][j + 1].x(), surface[i][j + 1].y(), surface[i][j + 1].z());
				glEnd();
			}
			// Facette triangulaire
			else
			{
				glBegin(GL_LINE_STRIP);
				glVertex3f(surface[i][j].x(), surface[i][j].y(), surface[i][j].z());
				glVertex3f(surface[i + 1][j].x(), surface[i + 1][j].y(), surface[i + 1][j].z());
				glVertex3f(surface[i + 1][j + 1].x(), surface[i + 1][j + 1].y(), surface[i + 1][j + 1].z());
				glVertex3f(surface[i][j].x(), surface[i][j].y(), surface[i][j].z());
				glVertex3f(surface[i + 1][j + 1].x(), surface[i + 1][j + 1].y(), surface[i + 1][j + 1].z());
				glVertex3f(surface[i][j + 1].x(), surface[i][j + 1].y(), surface[i][j + 1].z());
				glEnd();
			}
		}
	}
	/* Facettisation du fond et du bout de la surface */
	vector<QVector3D> extremityHigh, extremityLow;
	QVector3D barycentreHigh, barycentreLow;
	// Récupérer les points des 2 surfaces
	for (int i = 0; i < form_size; i++)
	{
		extremityLow.push_back(surface[i][0]);
		extremityHigh.push_back(surface[i][p - 1]);
	}
	// Calculer les barycentres
	barycentreHigh = Barycentre(extremityHigh);
	barycentreLow = Barycentre(extremityLow);
	// Dessiner les barycentres en vert
	glColor3f(0.0f, 1.0f, 0.0f);
	glPointSize(POINT_SIZE);
	glBegin(GL_POINTS);
	glVertex3f(barycentreHigh.x(), barycentreHigh.y(), barycentreHigh.z());
	glVertex3f(barycentreLow.x(), barycentreLow.y(), barycentreLow.z());
	glEnd();
	// Facettisation
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < form_size - 1; i++) 
	{
		glVertex3f(extremityHigh[i].x(), extremityHigh[i].y(), extremityHigh[i].z());
		glVertex3f(barycentreHigh.x(), barycentreHigh.y(), barycentreHigh.z());
		glVertex3f(extremityHigh[i + 1].x(), extremityHigh[i + 1].y(), extremityHigh[i + 1].z());
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < form_size - 1; i++) 
	{
		glVertex3f(extremityLow[i].x(), extremityLow[i].y(), extremityLow[i].z());
		glVertex3f(barycentreLow.x(), barycentreLow.y(), barycentreLow.z());
		glVertex3f(extremityLow[i + 1].x(), extremityLow[i + 1].y(), extremityLow[i + 1].z());
	}
	glEnd();
}

// Mettre à jour des points du surface (si la forme ou l'âme change)
void GLWidget3D::UpdateData(vector<QPoint> form, vector<QPoint> soul)
{
	ClearSurface();
	if (form.size() > 0)
	{
		form_size = form.size();
		switch (modeExtrusion)
		{
		case 0:	// simple
			surface = SurfaceExtrusionSimple(form, nbPas, coeffExtru, H);
			break;
		case 1:	// révolution
			surface = SurfaceExtrusionRevolution(form, nbPas);
			break;
		case 2:	// générale
			if (soul.size() > 0)
			{
				soul_size = soul.size();
				surface = SurfaceExtrusionGeneral(form, soul);
			}
			break;
		default:
			break;
		}
	}
}