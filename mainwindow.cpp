#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QTextStream>
#include <QStringListModel>

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
    QStandardItemModel *tvModel = new QStandardItemModel(0,0,this);
    tvModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Site A")));
    tvModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Site B")));

    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Add database"),
                "C://Users//Sonia//Desktop",
                "*.txt"
                );

    model = new QStringListModel(this);

    QFileInfo info(filename);

    QFile file("C:/Users/Sonia/Desktop/" + info.baseName() + ".txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QStringList fields;

    int k = 0;

    while(!in.atEnd()) {
        QString line = in.readLine();
        fields = line.split(" ");

        for(int i = 0; i < fields.size(); i++){
            QStandardItem *item = new QStandardItem(fields.at(i));
            tvModel->setItem(k, i, item);
            //tvModel->setItem(1+k, i, item);

        }
        k++;
    }

    file.close();

    if(list.isEmpty())
    {
        list << info.baseName();
    }
    else
    {
        list.append(info.baseName());
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
