#include "editdialog.h"
#include "ui_editdialog.h"
#include <QDebug>
#include <QMessageBox>

EditDialog::EditDialog(QString fName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    filename = fName;
    ui->setupUi(this);
    this->setWindowTitle(filename);

    QStringList list;
    list << "Site A" << "Site B";
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(list);

    //    int place = ui->tableWidget->rowCount() - 1;


}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_btnAdd_clicked()
{
    QString siteA = ui->edtSiteA->text();
    QString siteB = ui->edtSiteB->text();

    if(siteA.isEmpty() || siteB.isEmpty())
        QMessageBox::warning(NULL, "Empty filename", "You did not enter a word!", "OK");
    else
    {
        vector.append(siteA);
        vector.append(siteB);

        ui->edtSiteA->clear();
        ui->edtSiteB->clear();

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(siteA));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(siteB));
    }
}
