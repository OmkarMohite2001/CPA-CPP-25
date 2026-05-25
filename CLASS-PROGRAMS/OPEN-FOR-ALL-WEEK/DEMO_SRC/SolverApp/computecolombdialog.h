#ifndef COMPUTECOLOMBDIALOG_H
#define COMPUTECOLOMBDIALOG_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ComputeColombDialog : public QDialog
{
    Q_OBJECT
public:
    ComputeColombDialog(QWidget* parent = nullptr);
public slots:
    void readTextBox_1(const QString& str);
    void readTextBox_2(const QString& str);
    void readTextBox_3(const QString& str);
    void doCompute();
private:
    QLabel* pLabel_1;
    QLabel* pLabel_2;
    QLabel* pLabel_3;
    QLabel* pLabel_4;
    QLineEdit* pLineEdit_1;
    QLineEdit* pLineEdit_2;
    QLineEdit* pLineEdit_3;
    QPushButton* pComputeButton;
    QPushButton* pCloseButton;
    QHBoxLayout* entry_1;
    QHBoxLayout* entry_2;
    QHBoxLayout* entry_3;
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
    QHBoxLayout* mainLayout;
    double q1;
    double q2;
    double r;
};

#endif // COMPUTECOLOMBDIALOG_H
