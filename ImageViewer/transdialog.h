#ifndef TRANSDIALOG_H
#define TRANSDIALOG_H

#include <QDialog>

namespace Ui {
class TransDialog;
}

class TransDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransDialog(QWidget *parent = nullptr);
    ~TransDialog();

private:
    Ui::TransDialog *ui;
};

#endif // TRANSDIALOG_H
