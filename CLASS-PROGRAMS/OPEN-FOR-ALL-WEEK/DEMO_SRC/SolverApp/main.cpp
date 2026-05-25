#include <QApplication>
#include "solverwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    SolverWindow* pSolver = new SolverWindow;
    pSolver->show();
    return app.exec();
}
