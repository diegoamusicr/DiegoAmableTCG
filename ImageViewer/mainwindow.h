#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFile>
#include <QFileDialog>

#include <iostream>

#include "convdialog.h"
#include "transdialog.h"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage Mat2QImage(Mat&);
    void CalculateUpdateImage();
    void UpdateImageLabel(QLabel*, QImage);
    void UpdateHistograms(Mat&);
    void TransformLinear(Mat&, Mat&, double, int);
    void TransformGamma(Mat&, Mat&, double);
    void InvertColor(Mat&, Mat&);
    void Convolution(Mat&, int, int);
    void AddPadding(Mat&, Mat&, int, int, int, int);
    void EnableImageModifiers();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_brilloSlider_valueChanged(int value);

    void on_contSlider_valueChanged(int value);

    void on_sliderGamma_valueChanged(int value);

    void on_actionInvertir_color_triggered();

    void on_actionConvolucion_triggered();

    void on_actionTransformaci_n_geom_trica_triggered();

private:
    Ui::MainWindow *ui;
    ConvDialog *ConvDiag;
    TransDialog *TransDiag;
    QString filename;
    Mat imageOriginal;
    Mat imageEdited;
};

#endif // MAINWINDOW_H
