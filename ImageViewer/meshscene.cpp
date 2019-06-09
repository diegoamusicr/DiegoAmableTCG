#include "meshscene.h"

MeshScene::MeshScene(QObject *parent): QGraphicsScene (parent)
{

}

void MeshScene::AddImage(const QPixmap * imgPix)
{
    image = new QGraphicsPixmapItem(*imgPix);
    this->addItem(image);
    image->setPos(0,0);
}

void MeshScene::CreateControlPoints(int rows, int cols)
{
    this->gridRows = rows+1;
    this->gridCols = cols+1;
    double image_width = image->boundingRect().right() - image->boundingRect().left();
    double image_height = image->boundingRect().bottom() - image->boundingRect().top();
    double x_delta = image_width/(cols);
    double y_delta = image_height/(rows);
    for (int i=0; i < this->gridRows; i++)
    {
        double pos_y = i * y_delta - this->radiusEllipse;
        for (int j=0; j < this->gridCols; j++)
        {
            double pos_x = j * x_delta - this->radiusEllipse;
            MeshEllipse * e = new MeshEllipse(pos_x, pos_y, this->radiusEllipse*2, this->radiusEllipse*2);
            if (i != 0 && i != rows && j != 0 && j != cols) this->addItem(e);
            this->controlPoints.push_back(e);
        }
    }
}

void MeshScene::DrawControlLines()
{
    for (int i=0; i < this->controlPoints.size(); i++)
    {
        int N_bottom = i + this->gridCols;
        int N_right = i + 1;
        QPen pen(QBrush(Qt::red), 0.8);
        if (N_bottom < this->controlPoints.size())
        {
            QGraphicsLineItem * line = new QGraphicsLineItem(this->controlPoints[i]->pos_x(), this->controlPoints[i]->pos_y(),
                                                             this->controlPoints[N_bottom]->pos_x(), this->controlPoints[N_bottom]->pos_y());
            line->setPen(pen);
            this->addItem(line);
            this->controlPoints[i]->AddControlLine(line, true);
            this->controlPoints[N_bottom]->AddControlLine(line, false);
        }
        if (i % this->gridCols != this->gridCols - 1)
        {
            QGraphicsLineItem * line = new QGraphicsLineItem(this->controlPoints[i]->pos_x(), this->controlPoints[i]->pos_y(),
                                                             this->controlPoints[N_right]->pos_x(), this->controlPoints[N_right]->pos_y());
            line->setPen(pen);
            this->addItem(line);
            this->controlPoints[i]->AddControlLine(line, true);
            this->controlPoints[N_right]->AddControlLine(line, false);
        }
    }
}

