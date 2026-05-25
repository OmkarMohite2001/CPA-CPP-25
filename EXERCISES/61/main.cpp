#include <QApplication>
#include "quadraticsolverdialog.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QuadraticSolverDialog* pQuadraticSolverDialog = new QuadraticSolverDialog;
    pQuadraticSolverDialog->show();

    return (app.exec());
}
