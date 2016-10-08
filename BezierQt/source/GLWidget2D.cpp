#include "GLWidget2D.h"

// m�thode corner cutting activ� ou pas ?
extern bool cornerCutting;

// Initialisation de la sc�ne OpenGL
GLWidget2D::GLWidget2D(QWidget *parent) : QOpenGLWidget(parent)
{
	int seconde = 1000; // 1 seconde = 1000 ms
	int timerInterval = seconde / 60;
	t_Timer = new QTimer(this);
	connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
	t_Timer->start(timerInterval);
	setMouseTracking(true);
}

// Pour garder les FPS � 60
void GLWidget2D::timeOutSlot()
{
	update();
}

// Initialisation du module OpenGL
void GLWidget2D::initializeGL()
{
	glClearColor(bgColor.red() / 255.0f, bgColor.green() / 255.0f, bgColor.blue() / 255.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// Redimensionner de la sc�ne pour adapter � la fen�tre principale
void GLWidget2D::resizeGL(int width, int height)
{
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
}

// Fonction mettre � jour de la sc�ne OpenGL
void GLWidget2D::paintGL()
{
	glClearColor(bgColor.red() / 255.0f, bgColor.green() / 255.0f, bgColor.blue() / 255.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (needUpdate)
		UpdateData();
	drawLines(poly, colorPoly);
	drawPoints(poly, colorPoly);
	drawLines(courbe, colorCourbe);
	drawLines(courbeCC, colorCourbeCC);
}

// Callback pour les click de la souris
void GLWidget2D::mousePressEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		if (polyCreating)
		{
			poly.push_back(event->pos());
			r.push_back(1);
			needUpdate = true;
			qDebug() << event->pos().x() << " " << event->pos().y();
		}
		else
			pointSelected = findNearestPoint(event->pos());
	}
	else if (event->buttons() & Qt::RightButton)
	{
		if (closedCurve && polyCreating)
		{
			if (poly.size() > 0)
				poly.push_back(poly[0]);
			needUpdate = true;
			QApplication::setOverrideCursor(Qt::ArrowCursor);
			emit ReleaseButton();
		}
		polyCreating = false;
	}
}

// Callback pour le mouvement de la souris
void GLWidget2D::mouseMoveEvent(QMouseEvent *event)
{
	mousePos = event->pos();
	emit MouseMoved();
	if (event->buttons() & Qt::LeftButton)
	{
		if (pointSelected >= 0)
		{
			poly[pointSelected] = event->pos();
			needUpdate = true;
		}
	}
}

// Callback pour la rel�che de la souris
void GLWidget2D::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && pointSelected >= 0)
		needUpdate = true;
}

// Recherche du point cliqu� par la souris
int GLWidget2D::findNearestPoint(QPoint p)
{
	int nbPoints = poly.size();
	for (int i = 0; i < nbPoints; i++)
	{
		QPoint d = p - poly[i];
		if (sqrt(pow(d.x(), 2) + pow(d.y(), 2)) <= POINT_SIZE)
			return i;
	}
	return -1;
}

// Supprimer tous les points stocker dans cette sc�ne
void GLWidget2D::ClearPoly()
{
	pointSelected = -1;
	poly.clear();
	polyCC.clear();
	courbe.clear();
	courbeCC.clear();
	r.clear();
}

// Cr�er de nouveau polygone de contr�le
void GLWidget2D::NewPoly()
{
	ClearPoly();
	polyCreating = true;
	needUpdate = true;
}

// Retourner la courbe g�n�r�e
vector<QPoint> GLWidget2D::GetCourbe()
{
	if (cornerCutting)
		return courbeCC;
	else
		return courbe;
}

// Courbe ferm�e ou pas ?
void GLWidget2D::SetClosedCurve(int state)
{
	closedCurve = state == 0 ? false : true;
}

// Mettre � jour des donn�es d'un groupe des points de contr�le et des courbes
void GLWidget2D::UpdateData()
{
	courbe.clear();
	polyCC.clear();
	courbeCC.clear();
	if (cornerCutting)
	{
		polyCC = calculateCornerCutting(-1, poly, r, nbPas);
		courbeCC = generateCourbeCC(-1, polyCC, 0, 1, r, nbPas);
	}
	else
		courbe = calculateCasteljau(poly, 0, 1, nbPas);
	emit CourbeUpdated();
	needUpdate = false;		
}

// Dessiner des c�t�s � partir des points
void GLWidget2D::drawLines(vector<QPoint> points, QColor col)
{
	int nbPoints = points.size();
	if (nbPoints < 2)
		return;
	glColor3f(col.red() / 255.0f, col.green() / 255.0f, col.blue() / 255.0f);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < nbPoints; i++)
		glVertex2i(points[i].x(), points[i].y());
	glEnd();
}

// Dessiner des points
void GLWidget2D::drawPoints(vector<QPoint> points, QColor col)
{
	int nbPoints = points.size();
	if (nbPoints == 0)
		return;
	glColor3f(1, 1, 1);
	glPointSize(POINT_SIZE);
	glBegin(GL_POINTS);
	for (int i = 0; i < nbPoints; i++)
		glVertex2i(points[i].x(), points[i].y());
	glEnd();
}