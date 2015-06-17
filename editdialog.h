#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QString fName, QWidget *parent = 0);
    ~EditDialog();

private slots:
    void on_btnAdd_clicked();

    void on_btnSave_clicked();

    QVector<QString> readFile(QString fileName);

    void addDataToQTableWidget(QVector<QString> vector);

    void on_btnDelete_clicked();

private:
    Ui::EditDialog *ui;
    QString filename;
    QString vector;
};

#endif // EDITDIALOG_H
