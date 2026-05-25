#include <QStatusBar>
#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include "solverwindow.h"
#include "computegravitationaldialog.h"
#include "computecolombdialog.h"
#include "computequadraticdialog.h"

SolverWindow::SolverWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget* pCentralWidget = new QWidget;
    setCentralWidget(pCentralWidget);

    QWidget* pTopWidget = new QWidget;
    pTopWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    pSolverInfo = new QLabel(tr("Click on <b>File</b> menu to launch a solver"));
    pSolverInfo->setFrameStyle(QFrame::StyledPanel);
    pSolverInfo->setAlignment(Qt::AlignCenter);

    QWidget* pBottomWidget = new QWidget;
    pBottomWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *pCentralWidgetLayout = new QVBoxLayout;
    pCentralWidgetLayout->setContentsMargins(5, 5, 5, 5);
    pCentralWidgetLayout->addWidget(pTopWidget);
    pCentralWidgetLayout->addWidget(pSolverInfo);
    pCentralWidgetLayout->addWidget(pBottomWidget);
    pCentralWidget->setLayout(pCentralWidgetLayout);

    createActions();
    createMenus();

    QString message = tr("This tool-tip will describe the menu");
    statusBar()->showMessage(message);

    setWindowTitle(tr("CPA Solver"));
    setMinimumSize(160, 160);
    resize(600, 600);
}

void SolverWindow::createActions()
{
    pGravityAction = new QAction(tr("Graviltational Solver"), this);
    pGravityAction->setShortcut(tr("Ctrl+G"));
    pGravityAction->setStatusTip(tr("Launch a gravitatinal force solver"));
    connect(pGravityAction, SIGNAL(triggered()), this, SLOT(launchGravitational()));

    pColombAction = new QAction(tr("Colomb Solver"), this);
    pColombAction->setShortcut(tr("Ctrl+E"));
    pColombAction->setStatusTip(tr("Launch a colomb force Solver"));
    connect(pColombAction, SIGNAL(triggered()), this, SLOT(launchColomb()));

    pQuadraticAction = new QAction(tr("Quadratic Solver Solver"), this);
    pQuadraticAction->setShortcut(tr("Ctrl+D"));
    pQuadraticAction->setStatusTip(tr("Launch a Quadratic Equation Solver"));
    connect(pQuadraticAction, SIGNAL(triggered()), this, SLOT(launchQuadratic()));

    pExitAction = new QAction(tr("Exit"), this);
    pExitAction->setShortcuts(QKeySequence::Quit);
    pExitAction->setStatusTip(tr("Exit the application"));
    connect(pExitAction, SIGNAL(triggered()), this, SLOT(close()));

    pAboutSolverAction= new QAction(tr("About Solver"), this);
    pAboutSolverAction->setStatusTip(tr("About solver"));
    connect(pAboutSolverAction, SIGNAL(triggered()), this, SLOT(launchAboutSolverDialog()));
}

void SolverWindow::createMenus()
{
    pFileMenu = menuBar()->addMenu(tr("File"));
    pFileMenu->addAction(pGravityAction);
    pFileMenu->addAction(pColombAction);
    pFileMenu->addAction(pQuadraticAction);
    pFileMenu->addSeparator();
    pFileMenu->addAction(pExitAction);

    pHelpMenu = menuBar()->addMenu(tr("Help"));
    pHelpMenu->addAction(pAboutSolverAction);
}

void SolverWindow::launchGravitational()
{
    ComputeGravitationalDialog* pGravitationalDialog = new ComputeGravitationalDialog(this);
    pGravitationalDialog->show();
}

void SolverWindow::launchColomb()
{
    ComputeColombDialog* pColombDialog = new ComputeColombDialog(this);
    pColombDialog->show();
}

void SolverWindow::launchQuadratic()
{
    ComputeQuadraticDialog* pQuadraticDialog = new ComputeQuadraticDialog(this);
    pQuadraticDialog->show();
}

 void SolverWindow::launchAboutSolverDialog()
 {

 }
