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
    explicit TestDialog(QVector<QString> vGlobal, bool flag = true, QWidget *parent = 0);
    ~TestDialog();

private slots:
    void on_btnNext_clicked();
    void checkAnswer(QString str);
    void showQuestion();

private:
    Ui::TestDialog *ui;
    QVector<QString> dGlobal;
    int correct;
    int wrong;
    int count;
    int testCount;
    int testSize;
    bool siteA;

};

#endif // TESTDIALOG_H
