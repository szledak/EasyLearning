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


    strMap.insert("Monday", "1");

    strMap.insert("Tuesday", "2");
    strMap.insert("Wednesday", "3");
    strMap.insert("Thursday", "4");
    strMap.insert("Friday", "5");
    strMap.insert("Saturday", "6");

    QStandardItemModel *tvModel = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
    tvModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    tvModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    tvModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));

    QMap<string, string>::ConstIterator i;

    for( i = strMap.constBegin(); i != strMap.constEnd(); ++i )
    {
        tvModel->setItem(i, i,  i.key());
        tvModel->setItem(i, i+1, i.value());
    }
    ui->tableView->setModel(tvModel);
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
