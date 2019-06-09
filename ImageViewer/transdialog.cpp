#include "transdialog.h"
#include "ui_transdialog.h"

TransDialog::TransDialog(QWidget *parent, QLabel * image) :
    QDialog(parent),
    ui(new Ui::TransDialog)
{
    ui->setupUi(this);
    ui->graphicsViewImage->setFixedSize(image->pixmap()->width(), image->pixmap()->height());
    scene = new MeshScene(this);
    ui->graphicsViewImage->setScene(scene);

    scene->AddImage(image->pixmap());
    scene->CreateControlPoints();
    scene->DrawControlLines();
}

TransDialog::~TransDialog()
{
    delete ui;
}

Matrix24d TransDialog::solveBilinear(QPointF originPoints[], QPointF destPoints[])
{
    Eigen::Matrix4d A_xy;
    Eigen::Vector4d b_x;
    Eigen::Vector4d b_y;
    Eigen::Vector4d C1;
    Eigen::Vector4d C2;
    for (int point = 0; point < 4; point++)
    {
        A_xy(point, 0) = originPoints[point].x();
        A_xy(point, 1) = originPoints[point].y();
        A_xy(point, 2) = originPoints[point].x() * originPoints[point].y();
        A_xy(point, 3) = 1;

        b_x(point) = destPoints[point].x();
        b_y(point) = destPoints[point].y();
    }
    C1 = A_xy.colPivHouseholderQr().solve(b_x);
    C2 = A_xy.colPivHouseholderQr().solve(b_y);

    Matrix24d C;
    C << C1.transpose(), C2.transpose();

    return C;
}

Eigen::Matrix3d TransDialog::solvePerspective(QPointF originPoints[], QPointF destPoints[])
{
    //
}

void TransDialog::TransformBilinear(Mat &src, Mat &dest, Matrix24d & c)
{
    Mat C(2,4,CV_64F);
    eigen2cv(c, C);
    for (int i=0; i < src.rows; i++)
    {
        for (int j=0; j < src.cols; j++)
        {
            Vec4d A_xy(i, j, i*j, 1);
            Mat M = C * Mat(A_xy);
            M = max(M, 0);
            int x = M.at<double>(0) >= src.cols? src.cols-1 : M.at<double>(0);
            int y = M.at<double>(1) >= src.rows? src.rows-1 : M.at<double>(1);
            dest.at<Vec3b>(i,j) = src.at<Vec3b>(x, y);
        }
    }
}

void TransDialog::on_pushButtonAplicar_clicked()
{
    /*QPointF origen[4] = {QPointF(100,100),QPointF(100,102),QPointF(102,101),QPointF(102,102)};
    QPointF dest[4] = {QPointF(100,100),QPointF(102,104),QPointF(102,100),QPointF(103,104)};;
    Matrix24d C = solveBilinear(origen, dest);
    cout << C << endl;
    Mat A = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file
    Mat R(A.rows, A.cols, CV_8UC3, Scalar(255,255,255));
    this->TransformBilinear(A, R, C);
    imshow("Test", R);
    waitKey(0);*/
    this->close();
}

void TransDialog::on_pushButtonCancelar_clicked()
{
    this->close();
}
