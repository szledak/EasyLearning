#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QStandardItemModel>

//using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSelectDB_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Add database"),
                "C://Users//Sonia//Desktop",
                "*.txt"
                );

    model = new QStringListModel(this);
    QFileInfo info(filename);


    if(list.isEmpty())
    {
        list << info.baseName();
    }
    else
    {
        list.append(info.baseName());
    }


    strMap["Monday"]    = "1";
    strMap["Tuesday"]   = "2";
    strMap["Wednesday"] = "3";
    strMap["Thursday"]  = "4";
    strMap["Friday"]    = "5";
    strMap["Saturday"]  = "6";



    QStandardItemModel *tvModel = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
    tvModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    tvModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    tvModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));

    ui->tableView->setModel(tvModel);

//    QMap<string, string>::ConstIterator ii;
//    for( ii = strMap.constBegin(); ii != strMap.constEnd(); ++ii )
//    {
//        tableWidget->setItem(ii, ii,  new QTableWidgetItem("ii.key()"));
//        //tableWidget->setItem(ii, ii+1, new QTableWidgetItem("ii.value()"));
//    }

    model->setStringList(list);
    ui->listView->setModel(model);
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
