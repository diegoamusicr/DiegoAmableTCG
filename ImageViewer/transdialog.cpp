#include "transdialog.h"
#include "ui_transdialog.h"

TransDialog::TransDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransDialog)
{
    ui->setupUi(this);
}

TransDialog::~TransDialog()
{
    delete ui;
}
