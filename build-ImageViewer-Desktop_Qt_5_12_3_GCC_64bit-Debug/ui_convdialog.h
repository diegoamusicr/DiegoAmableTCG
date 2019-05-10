/********************************************************************************
** Form generated from reading UI file 'convdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVDIALOG_H
#define UI_CONVDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConvDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBoxFilas;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxColumnas;
    QTableWidget *tableConv;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonCancelar;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonAplicar;

    void setupUi(QDialog *ConvDialog)
    {
        if (ConvDialog->objectName().isEmpty())
            ConvDialog->setObjectName(QString::fromUtf8("ConvDialog"));
        ConvDialog->resize(240, 320);
        verticalLayout = new QVBoxLayout(ConvDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ConvDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBoxFilas = new QSpinBox(ConvDialog);
        spinBoxFilas->setObjectName(QString::fromUtf8("spinBoxFilas"));
        spinBoxFilas->setMinimum(1);
        spinBoxFilas->setMaximum(10);

        horizontalLayout->addWidget(spinBoxFilas);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(ConvDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxColumnas = new QSpinBox(ConvDialog);
        spinBoxColumnas->setObjectName(QString::fromUtf8("spinBoxColumnas"));
        spinBoxColumnas->setMinimum(1);
        spinBoxColumnas->setMaximum(100);

        horizontalLayout_2->addWidget(spinBoxColumnas);


        verticalLayout->addLayout(horizontalLayout_2);

        tableConv = new QTableWidget(ConvDialog);
        tableConv->setObjectName(QString::fromUtf8("tableConv"));
        tableConv->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableConv->horizontalHeader()->setVisible(false);
        tableConv->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableConv);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonCancelar = new QPushButton(ConvDialog);
        pushButtonCancelar->setObjectName(QString::fromUtf8("pushButtonCancelar"));

        horizontalLayout_3->addWidget(pushButtonCancelar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonAplicar = new QPushButton(ConvDialog);
        pushButtonAplicar->setObjectName(QString::fromUtf8("pushButtonAplicar"));

        horizontalLayout_3->addWidget(pushButtonAplicar);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(ConvDialog);

        QMetaObject::connectSlotsByName(ConvDialog);
    } // setupUi

    void retranslateUi(QDialog *ConvDialog)
    {
        ConvDialog->setWindowTitle(QApplication::translate("ConvDialog", "Convoluci\303\263n", nullptr));
        label->setText(QApplication::translate("ConvDialog", "Filas:", nullptr));
        label_2->setText(QApplication::translate("ConvDialog", "Columnas:", nullptr));
        pushButtonCancelar->setText(QApplication::translate("ConvDialog", "Cancelar", nullptr));
        pushButtonAplicar->setText(QApplication::translate("ConvDialog", "Aplicar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvDialog: public Ui_ConvDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVDIALOG_H
