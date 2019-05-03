#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::Mat2QImage(Mat &M)
{
    return QImage(M.data, M.cols, M.rows, M.step, QImage::Format_RGB888).rgbSwapped();
}

void MainWindow::UpdateImageLabel(QLabel * label, QImage img)
{
    label->setPixmap(QPixmap::fromImage(img));
    label->show();
}

void MainWindow::UpdateHistograms(Mat &M)
{
    vector<Mat> bgr_planes;
    split(M, bgr_planes);

    /// Establish the number of bins
    int histSize = 256;

    /// Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };

    bool uniform = true; bool accumulate = false;

    Mat b_hist, g_hist, r_hist;

    /// Compute the histograms:
    calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

    // Draw the histograms for B, G and R
    int hist_w = 256; int hist_h = 180;
    int bin_w = cvRound( (double) hist_w/histSize );

    Mat histImageB( hist_h, hist_w, CV_8UC3, Scalar( 255,255,255) );
    Mat histImageG( hist_h, hist_w, CV_8UC3, Scalar( 255,255,255) );
    Mat histImageR( hist_h, hist_w, CV_8UC3, Scalar( 255,255,255) );

    /// Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histImageB.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImageG.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImageR.rows, NORM_MINMAX, -1, Mat() );

    /// Draw for each channel
    for( int i = 1; i < histSize; i++ )
    {
        line( histImageB, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                       Scalar( 255, 0, 0), 2, 8, 0  );
        line( histImageG, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                       Scalar( 0, 255, 0), 2, 8, 0  );
        line( histImageR, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                       Scalar( 0, 0, 255), 2, 8, 0  );
    }
    this->UpdateImageLabel(ui->labelBH, this->Mat2QImage(histImageB));
    this->UpdateImageLabel(ui->labelGH, this->Mat2QImage(histImageG));
    this->UpdateImageLabel(ui->labelRH, this->Mat2QImage(histImageR));
}

void MainWindow::TransformImage(Mat & src, Mat & dest, double a, int b)
{
    dest = src * a + Scalar(b, b, b);
    threshold(dest, dest, 255, 255, CV_THRESH_TRUNC);
    dest = max(dest, 0);
}

void MainWindow::on_actionOpen_triggered()
{
    this->filename = QFileDialog::getOpenFileName(this, "Open File", "", "Image files (*.jpg *.jpeg *.png *.gif)");
    this->imageOriginal = imread(this->filename.toStdString(), CV_LOAD_IMAGE_COLOR);   // Read the file
    if(!this->imageOriginal.data)                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
    }
    this->UpdateImageLabel(ui->imgLabel, this->Mat2QImage(this->imageOriginal));
    this->UpdateHistograms(this->imageOriginal);
    ui->brilloSlider->setValue(0);
    ui->contSlider->setValue(100);
}

void MainWindow::on_brilloSlider_valueChanged(int value)
{
    if (this->imageOriginal.data)
    {
        this->TransformImage(this->imageOriginal, this->imageEdited, ui->contSlider->value()/100.0, value);
        this->UpdateImageLabel(ui->imgLabel, this->Mat2QImage(this->imageEdited));
        this->UpdateHistograms(this->imageEdited);
    }
}

void MainWindow::on_contSlider_valueChanged(int value)
{
    if (this->imageOriginal.data)
    {
        this->TransformImage(this->imageOriginal, this->imageEdited, value/100.0, ui->brilloSlider->value());
        this->UpdateImageLabel(ui->imgLabel, this->Mat2QImage(this->imageEdited));
        this->UpdateHistograms(this->imageEdited);
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (this->imageEdited.data)
    {
        QString savefile = QFileDialog::getSaveFileName(this, "Save File", "", "Image files (*.jpg *.jpeg *.png *.gif)");
        imwrite(savefile.toStdString(), this->imageEdited);
    }
}
