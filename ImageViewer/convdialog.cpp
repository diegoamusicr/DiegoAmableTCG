#include "convdialog.h"
#include "ui_convdialog.h"
#include "mainwindow.h"

ConvDialog::ConvDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvDialog)
{
    ui->setupUi(this);
    ui->tableConv->setRowCount(ui->spinBoxFilas->value());
    ui->tableConv->setColumnCount(ui->spinBoxColumnas->value());
    this->centerRow = ui->spinBoxFilas->value()-1;
    this->centerColumn = ui->spinBoxColumnas->value()-1;
    ui->tableConv->setItem(centerRow, centerColumn, new QTableWidgetItem("1.0", 0));
    ui->tableConv->item(centerRow, centerColumn)->setBackground(QBrush(Qt::blue, Qt::BDiagPattern));
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
    for (int i=0; i < ui->tableConv->columnCount(); i++)
    {
        ui->tableConv->setItem(ui->spinBoxFilas->value()-1, i, new QTableWidgetItem("1.0", 0));
    }
}

void ConvDialog::on_spinBoxColumnas_valueChanged(int arg1)
{
    ui->tableConv->setColumnCount(ui->spinBoxColumnas->value());
    for (int i=0; i < ui->tableConv->rowCount(); i++)
    {
        ui->tableConv->setItem(i, ui->spinBoxColumnas->value()-1, new QTableWidgetItem("1.0", 0));
    }
}

void ConvDialog::on_tableConv_cellClicked(int row, int column)
{
    ui->tableConv->item(this->centerRow, this->centerColumn)->setBackground(QBrush(Qt::white, Qt::SolidPattern));
    this->centerRow = row;
    this->centerColumn = column;
    ui->tableConv->item(centerRow, centerColumn)->setBackground(QBrush(Qt::blue, Qt::BDiagPattern));
}

void ConvDialog::on_pushButtonAplicar_clicked()
{
    Mat mask(ui->spinBoxFilas->value(), ui->spinBoxColumnas->value(), CV_64FC1);
    for (int i=0; i < ui->spinBoxFilas->value(); i++)
        for (int j=0; j < ui->spinBoxColumnas->value(); j++)
            mask.at<double>(i,j) = (ui->tableConv->item(i,j)->text()).toDouble();
    mask = mask * ui->spinBoxConst->value();
    MainWindow* pMainWindow = qobject_cast<MainWindow*>(this->parent());
    pMainWindow->Convolution(mask, this->centerRow, this->centerColumn);
    this->close();
}
