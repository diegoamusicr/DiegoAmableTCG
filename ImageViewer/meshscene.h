#ifndef MESHSCENE_H
#define MESHSCENE_H

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "meshellipse.h"

using namespace std;

class MeshScene: public QGraphicsScene
{
    Q_OBJECT
public:
    MeshScene(QObject * parent = nullptr);

    void AddImage(const QPixmap *);
    void CreateControlPoints(int rows = 4, int cols = 4);
    void DrawControlLines();

private:
    QVector<MeshEllipse*> controlPoints;
    QGraphicsPixmapItem * image;
    int gridRows;
    int gridCols;
    qreal radiusEllipse = 4;
};

#endif // MESHSCENE_H
