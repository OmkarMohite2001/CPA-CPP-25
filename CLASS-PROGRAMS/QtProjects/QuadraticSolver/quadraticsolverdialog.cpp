#include "quadraticsolverdialog.h"
#include <iostream>
// Constructor
QuadraticSolverDialog::QuadraticSolverDialog(QWidget* parent) : QDialog(parent)
{
    // Allocate labels
    std::cout << "HERE 1" << std::endl;
    this->pL1 = new QLabel(tr("Enter co-efficient of x^2:"));
    this->pL2 = new QLabel(tr("Enter co-efficient of x:"));
    this->pL3 = new QLabel(tr("Enter the constant of eqn:"));
    this->pOutput = new QLabel(tr(""));
    std::cout << "HERE 2" << std::endl;
    // Allocate text-boxes
    this->pBox1 = new QLineEdit;
    this->pBox2 = new QLineEdit;
    this->pBox3 = new QLineEdit;
    std::cout << "HERE 3" << std::endl;
    // Set buddies
    this->pL1->setBuddy(pBox1);
    this->pL2->setBuddy(pBox2);
    this->pL3->setBuddy(pBox3);
    std::cout << "HERE 4" << std::endl;
    // Allocate buttons
    this->pCompute = new QPushButton(tr("Compute"));
    this->pClear = new QPushButton(tr("Clear"));
    this->pClose = new QPushButton(tr("Close"));
    std::cout << "HERE 5" << std::endl;
    // Connect signals with slots
    this->connect(
        this->pBox1,
        SIGNAL(textChanged(QString)),
        this,
        SLOT(readTextBox1(QString))
        );

    this->connect(
        this->pBox2,
        SIGNAL(textChanged(QString)),
        this,
        SLOT(readTextBox2(QString))
        );

    this->connect(
        this->pBox3,
        SIGNAL(textChanged(QString)),
        this,
        SLOT(readTextBox3(QString))
        );

    this->connect(
        this->pCompute,
        SIGNAL(clicked()),
        this,
        SLOT(doCompute())
        );

    this->connect(
        pClear,
        SIGNAL(clicked()),
        this,
        SLOT(doClear())
        );

    this->connect(
        pClose,
        SIGNAL(clicked()),
        this,
        SLOT(close())
        );
    std::cout << "HERE 6" << std::endl;
    // Form layout of widges on container widget
    this->pInputEntry1 = new QHBoxLayout;
    this->pInputEntry1->addWidget(this->pL1);
    this->pInputEntry1->addWidget(this->pBox1);
    std::cout << "HERE 6.1" << std::endl;
    this->pInputEntry2 = new QHBoxLayout;
    this->pInputEntry2->addWidget(this->pL2);
    this->pInputEntry2->addWidget(this->pBox2);
    std::cout << "HERE 6.2" << std::endl;
    this->pInputEntry3 = new QHBoxLayout;
    this->pInputEntry3->addWidget(this->pL3);
    this->pInputEntry3->addWidget(this->pBox3);
    std::cout << "HERE 6.3" << std::endl;
    this->leftLayout = new QVBoxLayout;
    this->leftLayout->addLayout(this->pInputEntry1);
    this->leftLayout->addLayout(this->pInputEntry2);
    this->leftLayout->addLayout(this->pInputEntry3);
    this->leftLayout->addWidget(this->pOutput);
    std::cout << "HERE 6.4" << std::endl;
    this->rightLayout = new QVBoxLayout;
    this->rightLayout->addWidget(this->pCompute);
    this->rightLayout->addWidget(this->pClear);
    this->rightLayout->addWidget(this->pClose);
    this->rightLayout->addStretch();
    std::cout << "HERE 6.5" << std::endl;
    this->mainLayout = new QHBoxLayout;
    this->mainLayout->addLayout(this->leftLayout);
    this->mainLayout->addLayout(this->rightLayout);
    std::cout << "HERE 6.6" << std::endl;
    this->setLayout(mainLayout);
    std::cout << "HERE 7" << std::endl;
    // Set other attributes of dialog box such title, dimensions etc
    this->setWindowTitle(tr("Quadratic Equation Solver"));  // Set title
    this->setFixedHeight(this->sizeHint().height());        // Set fixed height
    std::cout << "HERE 8" << std::endl;
}


void QuadraticSolverDialog::readTextBox1(const QString& inputString)
{
    this->a = inputString.toDouble();
}


void QuadraticSolverDialog::readTextBox2(const QString& inputString)
{
    this->b = inputString.toDouble();
}


void QuadraticSolverDialog::readTextBox3(const QString& inputString)
{
    this->c = inputString.toDouble();
}


void QuadraticSolverDialog::doCompute()
{
    QString outputString;

    if(this->a == 0.0)
    {
        pOutput->setText(tr("Co-efficient of x^2 cannot be zero"));
        return;
    }

    if((this->b * this->b - 4 * this->a * this->c) < 0.0f)
    {
        pOutput->setText(tr("This eqn has no roots in the set of real numbers"));
        return;
    }

    if((this->b * this->b - 4 * this->a * this->c) == 0.0f)
    {
        double singleRoot = (-this->b/(2.0f * this->a));
        outputString.setNum(singleRoot, 'g');
        pOutput->setText(QString("The eqn has a single root:") + outputString);
        return;
    }

    if((this->b * this->b - 4 * this->a * this->c) > 0.0f)
    {
        double rootOne = (-this->b + sqrt(this->b * this->b - 4 * this->a * this->c))/(2.0f * this->a);
        double rootTwo = (-this->b - sqrt(this->b * this->b - 4 * this->a * this->c))/(2.0f * this->a);
        QString strRootOne, strRootTwo;
        strRootOne.setNum(rootOne, 'g');
        strRootTwo.setNum(rootTwo, 'g');
        pOutput->setText(QString("Root One:") + strRootOne + QString(" Root Two:") + strRootTwo);
        return;
    }
}

void QuadraticSolverDialog::doClear()
{
    this->pBox1->setText(tr(""));
    this->pBox2->setText(tr(""));
    this->pBox3->setText(tr(""));
    pOutput->setText(tr(""));
}
