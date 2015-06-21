#include "testdialog.h"
#include "ui_testdialog.h"
#include <QDebug>

TestDialog::TestDialog(QVector<QString> vGlobal, bool flag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    dGlobal = vGlobal;
    ui->setupUi(this);
    siteA = flag;
    testSize = dGlobal.size()/2;

    correct = 0;
    wrong = 0;
    count = 0;
    testCount = 1;

    ui->lblCount->setText("1/" + QString::number(testSize));
    this->setFixedSize(this->width(),this->height());

    showQuestion();
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::checkAnswer(QString str){

    QString answer = ui->edtAnswer->text();

    int x = QString::compare(str, answer, Qt::CaseInsensitive);

    if(x == 0)
    {
        ++correct;
        ui->lblCorrectCount->setText("Correct: " + QString::number(correct));
    }
    else
    {
        ++wrong;
        ui->lblWrongCount->setText("Wrong: " + QString::number(wrong));
        ui->lblCorrectWord->setText(str);
    }

    ui->edtAnswer->clear();
}

void TestDialog::on_btnNext_clicked()
{
    if(siteA == true)
        checkAnswer(dGlobal.at(count+1));
    else
        checkAnswer(dGlobal.at(count));

    if(testCount != testSize)
    {
        testCount++;
        count = count+2;
        ui->lblCount->setText(QString::number(testCount) + "/" + QString::number(testSize));

        showQuestion();
    }
    else
    {
        ui->btnNext->setEnabled(false);
        ui->edtAnswer->setEnabled(false);
    }
}

void TestDialog::showQuestion(){
    if(siteA == true)
    {
        ui->lblQuestion->setText(dGlobal.at(count));
        ui->lblSite->setText("Site A");
    }

    else
    {
        ui->lblQuestion->setText(dGlobal.at(count+1));
        ui->lblSite->setText("Site B");
    }

}
