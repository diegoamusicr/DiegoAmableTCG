#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFile>
#include <QFileDialog>
#include <QLabel>

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "convdialog.h"

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

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_brilloSlider_valueChanged(int value);

    void on_contSlider_valueChanged(int value);

    void on_sliderGamma_valueChanged(int value);

    void on_actionInvertir_color_triggered();

    void on_actionConvolucion_triggered();

private:
    Ui::MainWindow *ui;
    ConvDialog *ConvDiag;
    QString filename;
    Mat imageOriginal;
    Mat imageEdited;
};

#endif // MAINWINDOW_H
