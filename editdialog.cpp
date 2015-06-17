#include "editdialog.h"
#include "ui_editdialog.h"
#include <QDebug>

EditDialog::EditDialog(QString fName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    filename = fName;
    ui->setupUi(this);

    this->setWindowTitle(filename);
}

EditDialog::~EditDialog()
{
    delete ui;
}
