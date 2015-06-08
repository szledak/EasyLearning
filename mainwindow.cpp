#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QStandardItemModel>

using namespace std;

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

    QStandardItemModel *tvModel = new QStandardItemModel(0,2,this);
    tvModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    tvModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));

    QStandardItem *item = new QStandardItem(QString("bluh"));

    tvModel->appendRow(item);

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
