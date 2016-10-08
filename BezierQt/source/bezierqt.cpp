#include "bezierqt.h"
#include <QShortcut>

bool cornerCutting = true;

// Initialisation de la fenêtre
BezierQt::BezierQt(QWidget *parent)
	: QMainWindow(parent), ui(Ui::BezierQtClass())
{
	ui.setupUi(this);
	// Créer des 3 scènes OpenGL
	glSoul = new GLWidget2D(this);
	glForm = new GLWidget2D(this);
	glSurface = new GLWidget3D(this);
	ui.boxSoulLayout->addWidget(glSoul);
	ui.boxFormLayout->addWidget(glForm);
	ui.boxSurfaceLayout->addWidget(glSurface);
	
	// Créer les raccourcis clavier
	// Ctrl + Q pour quitter
	QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
	QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(quit()));
	// Ctrl + A pour créer de nouvelle l'âme
	shortcut = new QShortcut(QKeySequence("Ctrl+A"), this);
	QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(newSoul()));
	// Ctrl + F pour créer de nouvelle la forme
	shortcut = new QShortcut(QKeySequence("Ctrl+F"), this);
	QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(newForm()));

	// Connect signals
	connect(ui.buttonCreateForm, SIGNAL(clicked()), this, SLOT(newForm()));
	connect(ui.buttonCreateSoul, SIGNAL(clicked()), this, SLOT(newSoul()));
	connect(ui.checkClosedForm, SIGNAL(stateChanged(int)), glForm, SLOT(SetClosedCurve(int)));
	connect(ui.checkClosedSoul, SIGNAL(stateChanged(int)), glSoul, SLOT(SetClosedCurve(int)));
	connect(ui.radioCasteljau, SIGNAL(clicked()), this, SLOT(modeCurve()));
	connect(ui.radioCornerCutting, SIGNAL(clicked()), this, SLOT(modeCurve()));
	connect(ui.radioSimple, SIGNAL(clicked()), this, SLOT(modeExtrusion()));
	connect(ui.radioRevolution, SIGNAL(clicked()), this, SLOT(modeExtrusion()));
	connect(ui.radioGeneral, SIGNAL(clicked()), this, SLOT(modeExtrusion()));
	connect(ui.radioRectangle, SIGNAL(clicked()), this, SLOT(modeFacette()));
	connect(ui.radioTriangle, SIGNAL(clicked()), this, SLOT(modeFacette()));
	connect(glForm, SIGNAL(ReleaseButton()), ui.buttonCreateForm, SLOT(toggle()));
	connect(glSoul, SIGNAL(ReleaseButton()), ui.buttonCreateSoul, SLOT(toggle()));
	connect(glForm, SIGNAL(CourbeUpdated()), this, SLOT(UpdateData3D()));
	connect(glSoul, SIGNAL(CourbeUpdated()), this, SLOT(UpdateData3D()));
	ui.pasEdit->setText(QString("%1").arg(glSurface->pas()));
	ui.coeffEdit->setText(QString("%1").arg(glSurface->coefficient()));
	connect(ui.pasEdit, SIGNAL(textEdited(QString)), this, SLOT(UpdateData3D()));
	connect(ui.coeffEdit, SIGNAL(textEdited(QString)), this, SLOT(UpdateData3D()));
	connect(ui.buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));	
}

// Créer une nouvelle courbe de forme
void BezierQt::newForm()
{
	glForm->NewPoly();
	ui.buttonCreateForm->setChecked(true);
	QApplication::setOverrideCursor(Qt::PointingHandCursor);
}

// Créer une nouvelle courbe de forme
void BezierQt::newSoul()
{
	glSoul->NewPoly();
	ui.buttonCreateSoul->setChecked(true);
	QApplication::setOverrideCursor(Qt::PointingHandCursor);
}

// Changer mode d'extrusion
void BezierQt::modeExtrusion()
{
	if (ui.radioSimple->isChecked() && glSurface->extrusion() != 0)
	{
		glSurface->extrusion(0);
		glSurface->UpdateData(glForm->GetCourbe(), glSoul->GetCourbe());
	}
	if (ui.radioRevolution->isChecked() && glSurface->extrusion() != 1)
	{
		glSurface->extrusion(1);
		glSurface->UpdateData(glForm->GetCourbe(), glSoul->GetCourbe());
	}
	if (ui.radioGeneral->isChecked() && glSurface->extrusion() != 2)
	{
		glSurface->extrusion(2);
		glSurface->UpdateData(glForm->GetCourbe(), glSoul->GetCourbe());
	}
}

// Changer mode de facettisation: rectangulaire ou triangulaire
void BezierQt::modeFacette()
{
	if (ui.radioRectangle->isChecked() && glSurface->facette() != 0)
		glSurface->facette(0);
	if (ui.radioTriangle->isChecked() && glSurface->facette() != 1)
		glSurface->facette(1);
}

// Changer mode de génération de courbe (entre Casteljau et corner cutting)
void BezierQt::modeCurve()
{
	if (ui.radioCasteljau->isChecked() && cornerCutting)
	{
		cornerCutting = false;
		glSoul->NeedUpdate();
		glForm->NeedUpdate();
	}
	if (ui.radioCornerCutting->isChecked() && !cornerCutting)
	{
		cornerCutting = true;
		glSoul->NeedUpdate();
		glForm->NeedUpdate();
	}
}

// Recalculer la surface 3D en fonction de la forme et de l'âme
void BezierQt::UpdateData3D()
{
	glSurface->pas(ui.pasEdit->text().toInt());
	glSurface->coefficient(ui.coeffEdit->text().toFloat());
	glSurface->UpdateData(glForm->GetCourbe(), glSoul->GetCourbe());
}

// Quitter
void BezierQt::quit()
{
	qApp->quit();
}