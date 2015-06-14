#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestDialog( QVector<QString> vGlobal, QWidget *parent = 0);
    ~TestDialog();
   // void getDialogVector(QVector<QString> vGlobal);

private slots:
    void on_btnNext_clicked();

private:
    Ui::TestDialog *ui;
    QVector<QString> dGlobal;
};

#endif // TESTDIALOG_H
