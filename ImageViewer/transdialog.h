#ifndef TRANSDIALOG_H
#define TRANSDIALOG_H

#include <QDialog>
#include <QVector>
#include <QPointF>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <Eigen/Dense>
#include <QLabel>

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "meshscene.h"

using namespace std;
using namespace cv;

typedef Eigen::Matrix<double, 2, 4> Matrix24d;

namespace Ui {
class TransDialog;
}

class TransDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransDialog(QWidget *parent = nullptr, QLabel * image = nullptr);
    ~TransDialog();
    Matrix24d solveBilinear(QPointF[4], QPointF[4]);
    Eigen::Matrix3d solvePerspective(QPointF[4], QPointF[4]);
    void TransformBilinear(Mat&, Mat&, Matrix24d&);

private slots:
    void on_pushButtonAplicar_clicked();

    void on_pushButtonCancelar_clicked();

private:
    Ui::TransDialog *ui;
    MeshScene *scene;
};

#endif // TRANSDIALOG_H
