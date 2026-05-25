#include <QApplication>
#include "computegravitationaldialog.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ComputeGravitationalDialog* pComputeGravitatioanlDialog = new ComputeGravitationalDialog;
    pComputeGravitatioanlDialog->show();
    return app.exec();
}
