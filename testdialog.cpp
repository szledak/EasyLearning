#include "testdialog.h"
#include "ui_testdialog.h"
#include <QDebug>

TestDialog::TestDialog(QVector<QString> vGlobal, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    dGlobal = vGlobal;
    ui->setupUi(this);

    testSize = dGlobal.size()/2;


    correct = 0;
    wrong = 0;
    count = 0;
    testCount = 1;

    ui->lblCount->setText("1/" + QString::number(testSize));

    ui->lblQuestion->setText(dGlobal.at(count));
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::on_btnNext_clicked()
{
    QString answer = ui->edtAnswer->text();
        int x = QString::compare(dGlobal.at(count+1), answer, Qt::CaseInsensitive);

        if(x == 0)
        {
            ++correct;
            ui->lblCorrectCount->setText("Correct: " + QString::number(correct));
        }
        else
        {
            ++wrong;
            ui->lblWrongCount->setText("Wrong: " + QString::number(wrong));
            ui->lblCorrectAnswer->setText("Correct answer: \n" + dGlobal.at(count+1));
        }

        ui->edtAnswer->clear();

        if(testCount != testSize)
        {
            testCount++;
            count = count+2;
            ui->lblCount->setText(QString::number(testCount) + "/" + QString::number(testSize));
            ui->lblQuestion->setText(dGlobal.at(count));
        }
        else
        {
            ui->btnNext->setEnabled(false);
            ui->edtAnswer->setEnabled(false);
        }



}
