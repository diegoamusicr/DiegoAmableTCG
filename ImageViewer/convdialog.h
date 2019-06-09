#ifndef CONVDIALOG_H
#define CONVDIALOG_H

#include <QDialog>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

namespace Ui {
class ConvDialog;
}

class ConvDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConvDialog(QWidget *parent = nullptr);
    ~ConvDialog();

private slots:
    void on_pushButtonCancelar_clicked();

    void on_spinBoxFilas_valueChanged(int arg1);

    void on_spinBoxColumnas_valueChanged(int arg1);

    void on_tableConv_cellClicked(int row, int column);

    void on_pushButtonAplicar_clicked();

private:
    Ui::ConvDialog *ui;
    int centerRow;
    int centerColumn;
};

#endif // CONVDIALOG_H
