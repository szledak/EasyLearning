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

   startTest();

    this->setFixedSize(this->width(),this->height());
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::startTest()
{
    ui->lblCorrectWord->setText("");
    ui->lblCorrectCount->setText("Correct: 0" );
    ui->lblWrongCount->setText("Wrong: 0" );
    ui->btnNext->setEnabled(true);
    ui->edtAnswer->setEnabled(true);

    correct = 0;
    wrong = 0;
    count = 0;
    testCount = 1;

    ui->lblCount->setText("Word: 1/" + QString::number(testSize));

    showQuestion();
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
        ui->lblCorrectWord->setStyleSheet("QLabel { color : red; }");
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
        ui->lblCount->setText("Word: " + QString::number(testCount) + "/" + QString::number(testSize));

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
        this->setWindowTitle("Site A");
    }

    else
    {
        ui->lblQuestion->setText(dGlobal.at(count+1));
        this->setWindowTitle("Site B");
    }

}

void TestDialog::on_pushButton_clicked()
{
    startTest();
}
