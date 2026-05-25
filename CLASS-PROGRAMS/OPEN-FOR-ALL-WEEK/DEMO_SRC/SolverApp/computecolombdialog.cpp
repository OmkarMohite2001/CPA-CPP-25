#include "computecolombdialog.h"

ComputeColombDialog::ComputeColombDialog(QWidget* parent) : QDialog(parent)
{
     pLabel_1 =new QLabel(tr("Enter charge on particle 1:"));
     pLabel_2 = new QLabel(tr("Enter charge on particle 2:"));
     pLabel_3 = new QLabel(tr("Enter the distance between two charges:"));
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
     setWindowTitle("Colomb Force Calculator:");
     setFixedHeight(sizeHint().height());
}

void ComputeColombDialog::readTextBox_1(const QString& str)
{
    q1 = str.toDouble();
}

void ComputeColombDialog::readTextBox_2(const QString& str)
{
    q2 = str.toDouble();
}

void ComputeColombDialog::readTextBox_3(const QString& str)
{
    r = str.toDouble();
}

void ComputeColombDialog::doCompute()
{
    double K = 8.9875517923e9;
    double colombForce = K * q1 * q2 / (r * r);
    QString strColombForce;
    strColombForce.setNum(colombForce, 'g', 12);
    pLabel_4->setText(QString("The Colomb force is:") + strColombForce);
}

