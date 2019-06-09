#include "meshellipse.h"

MeshEllipse::MeshEllipse(QGraphicsItem *parent): QGraphicsEllipseItem (parent)
{
    Pressed = false;
    setFlag(ItemIsMovable);
    setFlag(ItemSendsScenePositionChanges);
}

MeshEllipse::MeshEllipse(const QRectF &rect, QGraphicsItem *parent): QGraphicsEllipseItem (rect, parent)
{
    Pressed = false;
    this->posx = rect.topLeft().rx();
    this->posy = rect.topLeft().ry();
    this->width = rect.width();
    this->height = rect.height();
    setFlag(ItemIsMovable);
    setFlag(ItemSendsScenePositionChanges);
}

MeshEllipse::MeshEllipse(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent): QGraphicsEllipseItem(x, y, width, height, parent)
{
    Pressed = false;
    this->posx = x + width/2;
    this->posy = y + height/2;
    this->width = width;
    this->height = height;
    setFlag(ItemIsMovable);
    setFlag(ItemSendsScenePositionChanges);
}

void MeshEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush(Qt::green);

    if (Pressed)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::green);
    }
    painter->setBrush(brush);
    painter->drawEllipse(boundingRect());
}

QVariant MeshEllipse::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == this->ItemPositionChange && this->scene())
    {
        this->posx = value.toPointF().rx() + rect().x() + this->width/2;
        this->posy = value.toPointF().ry() + rect().y() + this->height/2;
        this->MoveLines();
    }
    return QGraphicsItem::itemChange(change, value);
}

qreal MeshEllipse::pos_x()
{
    return this->posx;
}

qreal MeshEllipse::pos_y()
{
    return this->posy;
}

void MeshEllipse::AddControlLine(QGraphicsLineItem * line, bool isP1)
{
    this->controlLinesAssociated.push_back(line);
    this->whichPointAssociated.push_back(isP1);
}

void MeshEllipse::MoveLines()
{
    QPointF center(this->posx, this->posy);
    for (int i=0; i < this->controlLinesAssociated.size(); i++)
    {
        QGraphicsLineItem * line = this->controlLinesAssociated[i];
        QPointF p1 = this->whichPointAssociated[i] ? center : line->line().p1();
        QPointF p2 = this->whichPointAssociated[i] ? line->line().p2() : center;

        line->setLine(QLineF(p1, p2));
    }
}

void MeshEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MeshEllipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

