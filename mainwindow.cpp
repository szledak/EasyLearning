#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QTextStream>
#include <QStringListModel>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vector.resize(0);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSelectDB_clicked()
{
    QStandardItemModel *tvModel = new QStandardItemModel(0,0,this);
    tvModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Site A")));
    tvModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Site B")));


    QString fileName = getFileName();
    readFile(tvModel, fileName);

    setListViewElements(fileName);

    ui->tableView->setModel(tvModel);
    model->setStringList(list);
    ui->listView->setModel(model);

    for(int i = 0; i < vector.size(); i++)
        qDebug() << i << " " << vector.at(i);
}

void MainWindow::on_btnRemove_clicked()
{
    QModelIndexList selected = ui->listView->selectionModel()->selectedIndexes();
       if (!selected.isEmpty())
       {
          list.removeAt(selected.first().row());
          ((QStringListModel*) ui->listView->model())->setStringList(list);
       }
}

void MainWindow::setListViewElements(QString fileName){
    if(list.isEmpty())
        list << fileName;
    else
        list.append(fileName);
}

void MainWindow::readFile(QStandardItemModel *tvModel, QString fileName){
    model = new QStringListModel(this);

    QFile file("C:/Users/Sonia/Desktop/" + fileName + ".txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QStringList fields;

    while(!in.atEnd()) {
        QString line = in.readLine();
        fields = line.split(" ");

        for(int i = 0; i < fields.size(); i++){  
            vector.append(fields.at(i));
        }
    }

    int j = 0;
    for(int i = 0; i < vector.length()/2; i++)
    {
        for(int k = 0; k < 2; k++){
          QStandardItem *item = new QStandardItem(vector.at(j));
          tvModel->setItem(i, k, item);
          j++;
        }
    }
    file.close();
}

QString MainWindow::getFileName(){
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("Add database"),
                "C://Users//Sonia//Desktop",
                "*.txt"
                );

    QFileInfo info(fileName);
    QString name = info.baseName();
    return name;
}
