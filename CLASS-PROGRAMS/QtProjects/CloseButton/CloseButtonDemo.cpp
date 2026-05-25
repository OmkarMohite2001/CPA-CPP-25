#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QPushButton* pButton = new QPushButton("Quit");
    QObject::connect(pButton, SIGNAL(clicked()), &app, SLOT(quit()));
    pButton->show();
    return app.exec();
}

