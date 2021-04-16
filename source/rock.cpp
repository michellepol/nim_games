#include "headers/rock.h"

Rock::Rock(QPointF pos,int id)
{
    pos_ = pos;
    pos_.rx() = pos_.x() - 15;
    pos_.ry() = pos_.y() - 15;
    this->setPos(pos_);
    if(id == 0) {
        image = QPixmap(":/media/images/rock1.png");
    } else {
        image = QPixmap(":/media/images/rock2.png");
    }
    image = image.scaled(150,150,Qt::IgnoreAspectRatio);

    w_ = image.width();
    h_ = image.height();
}


QRectF Rock::boundingRect() const
{
    return QRectF (0,0,w_,h_);
}

void Rock::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,image);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


