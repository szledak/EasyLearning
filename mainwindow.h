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
    void setListViewElements(QString fileName);
    void showDataInTableView(QStandardItemModel *tvModel,  QVector<QString> vRead);

    void on_btnStart_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringList list;
    QVector<QString> vGlobal;
    QStandardItemModel *tvModel;
};

#endif // MAINWINDOW_H
