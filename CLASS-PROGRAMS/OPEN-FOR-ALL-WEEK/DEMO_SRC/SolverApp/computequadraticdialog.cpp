#include "computequadraticdialog.h"


ComputeQuadraticDialog::ComputeQuadraticDialog(QWidget* parent) : QDialog(parent)
{
     pLabel_1 =new QLabel(tr("Enter the CF of x^2:"));
     pLabel_2 = new QLabel(tr("Enter the CF of x:"));
     pLabel_3 = new QLabel(tr("Enter the constant:"));
     pLabel_4 = new QLabel(tr(""));

     pLineEdit_1 = new QLineEdit;
     pLineEdit_2 = new QLineEdit;
     pLineEdit_3 = new QLineEdit;

     pLabel_1->setBuddy(pLineEdit_1);
     pLabel_2->setBuddy(pLineEdit_2);
     pLabel_3->setBuddy(pLineEdit_3);

     pComputeButton = new QPushButton(tr("Compute!"));
     pCloseButton = new QPushButton(tr("Close"));

     connect(pCloseButton,
             SIGNAL(clicked()),
             this,
             SLOT(close()));

     connect(pComputeButton,
             SIGNAL(clicked()),
             this,
             SLOT(doCompute()));

     connect(pLineEdit_1,
             SIGNAL(textChanged(QString)),
             this,
             SLOT(readTextBox_1(QString)));

     connect(pLineEdit_2,
             SIGNAL(textChanged(QString)),
             this,
             SLOT(readTextBox_2(QString))
             );

     connect(pLineEdit_3,
             SIGNAL(textChanged(QString)),
             this,
             SLOT(readTextBox_3(QString))
             );

     entry_1 = new QHBoxLayout;
     entry_1->addWidget(pLabel_1);
     entry_1->addWidget(pLineEdit_1);

     entry_2 = new QHBoxLayout;
     entry_2->addWidget(pLabel_2);
     entry_2->addWidget(pLineEdit_2);

     entry_3 = new QHBoxLayout;
     entry_3->addWidget(pLabel_3);
     entry_3->addWidget(pLineEdit_3);

     leftLayout = new QVBoxLayout;
     leftLayout->addLayout(entry_1);
     leftLayout->addLayout(entry_2);
     leftLayout->addLayout(entry_3);
     leftLayout->addWidget(pLabel_4);

     rightLayout = new QVBoxLayout;
     rightLayout->addWidget(pComputeButton);
     rightLayout->addWidget(pCloseButton);
     rightLayout->addStretch();

     mainLayout = new QHBoxLayout;
     mainLayout->addLayout(leftLayout);
     mainLayout->addLayout(rightLayout);

     setLayout(mainLayout);
     setWindowTitle("Quadratic Equation Solver:");
     setFixedHeight(sizeHint().height());
}

void ComputeQuadraticDialog::readTextBox_1(const QString& str)
{
    A = str.toDouble();
}

void ComputeQuadraticDialog::readTextBox_2(const QString& str)
{
    B = str.toDouble();
}

void ComputeQuadraticDialog::readTextBox_3(const QString& str)
{
    C = str.toDouble();
}

void ComputeQuadraticDialog::doCompute()
{
    double delta = B*B - 4*A*C;
    double R1, R2;
    QString response;
    QString strR1, strR2;

    if(delta < 0)
    {
        response = tr("This equation is no roots in real");
    }
    else
    {
        R1 = (-B + sqrt(delta))/(2*A);
        R2 = (-B - sqrt(delta))/(2*A);
        response = "Root 1 = " + strR1.setNum(R1, 'g', 12) + " Root 2 =" + strR2.setNum(R2, 'g', 12);
    }
    pLabel_4->setText(response);
}
