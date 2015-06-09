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

    QString readFile(QStandardItemModel *tvModel);

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringList list;
};

#endif // MAINWINDOW_H
