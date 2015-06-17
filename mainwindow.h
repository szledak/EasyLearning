#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QFileInfo>
#include<QModelIndexList>
#include<QMap>
#include <QStandardItemModel>
#include "myword.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnSelectDB_clicked();
    void on_btnRemove_clicked();
    QVector<QString> readFile(QString fileName);
    QString getFileName();
    void setListViewElements(QString filename);
    void showDataInTableView(QStandardItemModel *tvModel,  QVector<QString> vRead);
    void setComboBoxItems(QFileInfoList);
    void on_btnStart_clicked();
    QFileInfoList getAllFileNames();
    void on_btnCreate_clicked();

    void on_btnDelete_clicked();

    void on_btnEdit_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringList list;
    QVector<QString> vGlobal;
    QVector<MyWord> vMyWords;
    QStandardItemModel *tvModel;
};

#endif // MAINWINDOW_H
