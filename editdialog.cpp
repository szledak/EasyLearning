#include "editdialog.h"
#include "ui_editdialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    addDataToQTableWidget(readFile(filename));
    this->setFixedSize(this->width(),this->height());

    checkRowCount();
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
        QMessageBox::warning(NULL, "Empty field", "You did not enter a word!", "OK");
    else
    {
        ui->edtSiteA->clear();
        ui->edtSiteB->clear();

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(siteA));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(siteB));

        checkRowCount();
    }
}

void EditDialog::on_btnSave_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    int columnCount = ui->tableWidget->columnCount();
    QList<QTableWidgetItem*> itemList;

    for(int i = 0; i < rowCount; i++)
    {
        for(int k = 0; k < columnCount; k++)
        {
            QTableWidgetItem* item = ui->tableWidget->item(i, k);
            itemList.append(item);

            item = 0;
        }
    }

    QFile file("C:/Users/Sonia/Desktop/el_database/" + filename);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    int tmp = 0;
    for(int i = 0; i < itemList.length(); i++)
    {
        if(tmp == 2)
        {
            out << "\n";
            tmp = 0;
        }
        out << itemList.at(i)->text();

        if(tmp == 0)
            out << " ";

        tmp++;
    }

    file.flush();
    file.close();

    QMessageBox::information(NULL, "Save file", "Save file: " + filename, "OK");
}

QVector<QString> EditDialog::readFile(QString fileName){

    QVector<QString> vRead;

    QFile file("C:/Users/Sonia/Desktop/el_database/" + fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QStringList fields;

    while(!in.atEnd()) {
        QString line = in.readLine();
        fields = line.split(" ");

        for(int i = 0; i < fields.size(); i++){
            vRead.append(fields.at(i));
        }
    }

    file.close();
    return vRead;
}

void EditDialog::addDataToQTableWidget(QVector<QString> vector)
{
    int j = 0;
    for(int i = 0; i < vector.length()/2; i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int k = 0; k < 2; k++){

            ui->tableWidget->setItem(i, k, new QTableWidgetItem(vector.at(j)));

            j++;
        }
    }

    qDebug() << ui->tableWidget->rowCount();
}

void EditDialog::on_btnDelete_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());

    checkRowCount();
}

void EditDialog::checkRowCount()
{
    int rowCount = ui->tableWidget->rowCount();

    if(rowCount == 0)
    {
        ui->btnDelete->setEnabled(false);
        ui->btnSave->setEnabled(false);
    }
    else
    {
        ui->btnDelete->setEnabled(true);
        ui->btnSave->setEnabled(true);
    }
}
