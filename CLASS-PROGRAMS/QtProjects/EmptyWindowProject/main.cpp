#include <QApplication>
#include <QMainWindow>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QMainWindow myWindow;
    myWindow.setWindowTitle("My First Qt Window");
    myWindow.show();
    return app.exec();
}
