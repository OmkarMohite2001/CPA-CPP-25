#ifndef QUADRATICSOLVERDIALOG_H
#define QUADRATICSOLVERDIALOG_H

// Qt related Header files
#include <QObject>
#include <QString>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class QuadraticSolverDialog : public QDialog
{
    Q_OBJECT

public:
    // Constructor
    QuadraticSolverDialog(QWidget* parent = 0);


public slots:
    //  User defined slots
    void readTextBox1(const QString&);
    void readTextBox2(const QString&);
    void readTextBox3(const QString&);
    void doCompute();
    void doClear();


private:
    //  Members of object
    double a;                   // Co-efficient of x^2
    double b;                   // Co-efficient of x
    double c;                   // Constant of eqn

    QLabel* pL1;                // For label: "Enter Co-efficient of x^2:
    QLabel* pL2;                // For label: "Enter Co-efficient of x:
    QLabel* pL3;                // For label: "Enter constant of eqn
    QLabel* pOutput;            // For output:
                                //  Root1:Value1, Root2:Value2
                                //  This eqn has one root:value
                                //  This eqn does not have roots in real number set

    QLineEdit* pBox1;           //  Textbox for inputting co-efficient of x^2
    QLineEdit* pBox2;           //  Textbox for inputting co-efficient of x
    QLineEdit* pBox3;           //  Textbox for inputting constant of eqn

    QPushButton* pCompute;      // Compute button to trigger computation
    QPushButton* pClear;        // Clear button to clear existing values in textboxes
    QPushButton* pClose;        // Terminate the application

    QHBoxLayout* pInputEntry1;  //  For pL1 and pBox1
    QHBoxLayout* pInputEntry2;  //  For pL2 and pBox2
    QHBoxLayout* pInputEntry3;  //  For pL3 and pBox3

    QVBoxLayout* leftLayout;    // For pInputEntry1, pInputEntry2, pInputEntry3 and pL4
    QVBoxLayout* rightLayout;   // For pCompute, pClear, pClose

    QHBoxLayout* mainLayout;    //  For leftLayout, rightLayout
};

#endif  // QUADRATICSOLVERDIALOG_H
