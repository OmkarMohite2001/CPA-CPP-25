#ifndef SOLVERWINDOW_H
#define SOLVERWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QAction>
#include <QLabel>

class SolverWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SolverWindow(QWidget *parent = nullptr);

signals:

public slots:
    void launchGravitational();
    void launchColomb();
    void launchQuadratic();
    void launchAboutSolverDialog();
private:
    QMenuBar* pMenuBar;
    QMenu* pFileMenu;
    QMenu* pHelpMenu;

    QAction* pGravityAction;
    QAction* pColombAction;
    QAction* pQuadraticAction;
    QAction* pExitAction;

    QAction* pAboutSolverAction;

    QLabel* pSolverInfo;

    void createActions();
    void createMenus();

};

#endif // SOLVERWINDOW_H
