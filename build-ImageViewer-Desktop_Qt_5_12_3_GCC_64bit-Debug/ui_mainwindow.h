/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *imgLabel;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelBrillo;
    QSlider *brilloSlider;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelCont;
    QSlider *contSlider;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *labelRH;
    QLabel *labelGH;
    QLabel *labelBH;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(729, 477);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imgLabel = new QLabel(centralWidget);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imgLabel->sizePolicy().hasHeightForWidth());
        imgLabel->setSizePolicy(sizePolicy);
        imgLabel->setFrameShape(QFrame::NoFrame);
        imgLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(imgLabel);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelBrillo = new QLabel(centralWidget);
        labelBrillo->setObjectName(QString::fromUtf8("labelBrillo"));

        verticalLayout_2->addWidget(labelBrillo);

        brilloSlider = new QSlider(centralWidget);
        brilloSlider->setObjectName(QString::fromUtf8("brilloSlider"));
        brilloSlider->setMinimum(-100);
        brilloSlider->setMaximum(100);
        brilloSlider->setOrientation(Qt::Horizontal);
        brilloSlider->setTickPosition(QSlider::TicksAbove);

        verticalLayout_2->addWidget(brilloSlider);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelCont = new QLabel(centralWidget);
        labelCont->setObjectName(QString::fromUtf8("labelCont"));

        verticalLayout_3->addWidget(labelCont);

        contSlider = new QSlider(centralWidget);
        contSlider->setObjectName(QString::fromUtf8("contSlider"));
        contSlider->setMinimum(0);
        contSlider->setMaximum(200);
        contSlider->setSingleStep(1);
        contSlider->setValue(100);
        contSlider->setOrientation(Qt::Horizontal);
        contSlider->setTickPosition(QSlider::TicksAbove);

        verticalLayout_3->addWidget(contSlider);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelRH = new QLabel(centralWidget);
        labelRH->setObjectName(QString::fromUtf8("labelRH"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelRH->sizePolicy().hasHeightForWidth());
        labelRH->setSizePolicy(sizePolicy1);
        labelRH->setFrameShape(QFrame::NoFrame);
        labelRH->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelRH);

        labelGH = new QLabel(centralWidget);
        labelGH->setObjectName(QString::fromUtf8("labelGH"));
        sizePolicy1.setHeightForWidth(labelGH->sizePolicy().hasHeightForWidth());
        labelGH->setSizePolicy(sizePolicy1);
        labelGH->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelGH);

        labelBH = new QLabel(centralWidget);
        labelBH->setObjectName(QString::fromUtf8("labelBH"));
        sizePolicy1.setHeightForWidth(labelBH->sizePolicy().hasHeightForWidth());
        labelBH->setSizePolicy(sizePolicy1);
        labelBH->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelBH);


        verticalLayout_4->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ImageViewer", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open File", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        imgLabel->setText(QString());
        labelBrillo->setText(QApplication::translate("MainWindow", "Brillo", nullptr));
        labelCont->setText(QApplication::translate("MainWindow", "Contraste", nullptr));
        labelRH->setText(QString());
        labelGH->setText(QString());
        labelBH->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
