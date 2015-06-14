#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QTextStream>
#include <QStringListModel>
#include <QDebug>
#include "testdialog.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    vGlobal.resize(0);
   // vMyWords.resize(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSelectDB_clicked()
{
    tvModel = new QStandardItemModel(0,0,this);
    tvModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Site A")));
    tvModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Site B")));

    model = new QStringListModel(this);

    QString fileName = getFileName();
    QVector<QString> vRead = readFile(fileName);

    for(int i = 0; i < vRead.length(); i++)
        vGlobal.append(vRead.at(i));

    vRead.clear();

    showDataInTableView(tvModel, vGlobal);

    setListViewElements(fileName);

    ui->tableView->setModel(tvModel);
    model->setStringList(list);
    ui->listView->setModel(model);

//    for(int i = 0; i < vGlobal.size(); i++)
//        qDebug() << i << " " << vGlobal.at(i);

}

void MainWindow::on_btnRemove_clicked()
{
    QModelIndexList selected = ui->listView->selectionModel()->selectedIndexes();
       if (!selected.isEmpty())
       {
          QString str = list.at(selected.first().row());

          QVector<QString> vRemove = readFile(str);

          for(int i = 0; i < vGlobal.length(); i++)
              for(int k = 0; k < vRemove.length(); k++)
          {
              if(vGlobal.at(i) == vRemove.at(k))
              {
                vGlobal.removeAt(i);
                showDataInTableView(tvModel, vGlobal);
                ui->tableView->setModel(tvModel);
              }
          }

           QStandardItemModel *tModel = new QStandardItemModel(0,0,this);
           tModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Site A")));
           tModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Site B")));

           showDataInTableView(tModel, vGlobal);
           ui->tableView->setModel(tModel);

              for(int i = 0; i < vGlobal.size(); i++)
                  qDebug() << i << " " << vGlobal.at(i);


          list.removeAt(selected.first().row());
          ((QStringListModel*) ui->listView->model())->setStringList(list);


          qDebug() << str;
          vRemove.clear();
       }
}

void MainWindow::setListViewElements(QString fileName){
    if(list.isEmpty())
        list << fileName;
    else
        list.append(fileName);
}

void MainWindow::showDataInTableView(QStandardItemModel *tvModel,  QVector<QString> vGlobal){
     int j = 0;
     for(int i = 0; i < vGlobal.length()/2; i++)
     {
         for(int k = 0; k < 2; k++){
           QStandardItem *item = new QStandardItem(vGlobal.at(j));
           tvModel->setItem(i, k, item);
           j++;
         }
     }


}

QVector<QString> MainWindow::readFile(QString fileName){

    QVector<QString> vector;
  //  vector.resize(0);

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

    file.close();
    return vector;
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

void MainWindow::on_btnStart_clicked()
{
//    int k = 0;

//    for(int i = 0; i < vGlobal.length()/2; i++){
//        vMyWords.at(i).setSiteA(vGlobal.at(i));
//        k= i+1;
//        vMyWords.at(i).setSiteB(vGlobal.at(k));
//    }


//        for(int i = 0; i < vMyWords.size(); i++)
//            qDebug()  << "A: " << vMyWords.at(i).getSiteA()<< "B: " << vMyWords.at(i).getSiteB();

    TestDialog testDialog(vGlobal);

    testDialog.setModal(true);
    testDialog.exec();
}
