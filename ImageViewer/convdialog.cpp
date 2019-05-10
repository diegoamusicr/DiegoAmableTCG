#include "convdialog.h"
#include "ui_convdialog.h"

ConvDialog::ConvDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvDialog)
{
    ui->setupUi(this);
    ui->tableConv->setRowCount(ui->spinBoxFilas->value());
    ui->tableConv->setColumnCount(ui->spinBoxColumnas->value());
}

ConvDialog::~ConvDialog()
{
    delete ui;
}

void ConvDialog::on_pushButtonCancelar_clicked()
{
    this->close();
}

void ConvDialog::on_spinBoxFilas_valueChanged(int arg1)
{
    ui->tableConv->setRowCount(ui->spinBoxFilas->value());
}

void ConvDialog::on_spinBoxColumnas_valueChanged(int arg1)
{
    ui->tableConv->setColumnCount(ui->spinBoxColumnas->value());
}
