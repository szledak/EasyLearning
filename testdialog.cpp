#include "testdialog.h"
#include "ui_testdialog.h"
#include <QDebug>

TestDialog::TestDialog(QVector<QString> vGlobal, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    dGlobal = vGlobal;
    ui->setupUi(this);
}

TestDialog::~TestDialog()
{
    delete ui;
}
//void TestDialog::getDialogVector(QVector<QString> vGlobal){
//    //dGlobal = vGlobal;

//}

void TestDialog::on_btnNext_clicked()
{
    for(int i = 0; i < dGlobal.size(); i++)
        qDebug() << i << " " << dGlobal.at(i);
}
