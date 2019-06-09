#ifndef MESHELLIPSE_H
#define MESHELLIPSE_H

#include <iostream>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

using namespace std;

class MeshEllipse: public QGraphicsEllipseItem
{
public:
    MeshEllipse(QGraphicsItem * parent = nullptr);
    MeshEllipse(const QRectF &rect, QGraphicsItem * parent = nullptr);
    MeshEllipse(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QVariant itemChange(GraphicsItemChange, const QVariant &);
    bool Pressed;
    qreal pos_x();
    qreal pos_y();
    qreal last_pos_x();
    qreal last_pos_y();
    void AddControlLine(QGraphicsLineItem*, bool);
    void MoveLines();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QVector<QGraphicsLineItem*> controlLinesAssociated;
    QVector<bool> whichPointAssociated;
    qreal posx;
    qreal posy;
    qreal width;
    qreal height;
};

#endif // MESHELLIPSE_H
