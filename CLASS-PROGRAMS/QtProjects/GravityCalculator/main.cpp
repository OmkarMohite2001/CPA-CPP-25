#include <QApplication>
#include "gravitycalculatordialog.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    GravityCalculatorDialog* pGravityCalculatorDialog = new GravityCalculatorDialog;
    pGravityCalculatorDialog->show();
    return app.exec();
}
