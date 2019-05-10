#ifndef CONVDIALOG_H
#define CONVDIALOG_H

#include <QDialog>

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

private:
    Ui::ConvDialog *ui;
};

#endif // CONVDIALOG_H
