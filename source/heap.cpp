#include "headers/heap.h"

#include <QMouseEvent>
#include <QApplication>
#include <QPainterPath>
#include <QList>

void Heap::setCount(int count) {
    bool is_start = false;
    if(count_ == 0) {
        is_start = true;
    }
    count_ = count;
    QString buffer = QString::fromStdString(std::to_string(count_));
    count_label->setPlainText(buffer);
    if(!is_start) {
        emit ValueChanged();
    }

}

Heap::Heap(QGraphicsScene* scene,QPointF point,Bucket* bucket,int id) {
    scene_ = scene;
    id_ = id;
    bucket_ = bucket;
    QImage img;
    img.load(":/media/images/heap.png");
    if(id == 1) {
        img = img.mirrored(true,false);
    }
    image.convertFromImage(img);

    image = image.scaled(scene_->width() * 0.25,scene->height() * 0.3,Qt::IgnoreAspectRatio);

    w = image.width();
    h = image.height();


    x_ = point.x();
    y_ = point.y();

    count_label = new QGraphicsTextItem();
    QFont font = count_label->font();
    font.setPixelSize(24);
    count_label->setFont(font);

    count_label->setPos(QPointF(x_ + w / 2,y_+ h));
    QString buffer = QString::fromUtf8(std::to_string(count_));
    count_label->setPlainText(buffer);

    scene->addItem(count_label);

    rock = new Rock(QPointF(x_,y_),id);
    scene_->addItem(rock);
    rock->hide();
}

QRectF Heap::boundingRect() const
{
    return QRectF (0,0,w,h);
}

void Heap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,image);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Heap::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!used_) {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        rock->show();
        this->setZValue(0);
        rock->setZValue(1);

        QPointF cursor_pos = event->scenePos();
        cursor_pos.rx() -= rock->getWidth() / 2;
        cursor_pos.ry() -= rock->getHeight() / 2;
        rock->setPos(cursor_pos);

        QString buffer = QString::fromUtf8(std::to_string(count_));
        count_label->setPlainText(buffer);
    }
    return;
}

void Heap::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF cursor_pos = event->scenePos();
    cursor_pos.rx() -= rock->getWidth() / 2;
    cursor_pos.ry() -= rock->getHeight() / 2;
    rock->setPos(cursor_pos);

    return;
}


void Heap::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
        this->setCursor(QCursor(Qt::ArrowCursor));

        QPointF cursor_pos = mapToScene(event->pos());

        QPointF bucket_pos = bucket_->pos();

        int bucket_h = bucket_->boundingRect().height();
        int bucket_w = bucket_->boundingRect().width();
        QRectF bucket_hitbox= QRectF(bucket_pos,QSize(bucket_w,bucket_h));

        bool bucket_reached = bucket_hitbox.contains(cursor_pos);
        if(bucket_reached && !used_) {
            used_ = true;
            if(!turn_btn->isEnabled() && count_ - grab_amount_ >= 0) {
                turn_btn->setDisabled(false);
            }
            rock->hide();
            if(count_ - grab_amount_ >= 0) {
                this->setCount(count_ - grab_amount_);
            }
            QString buffer = QString::fromUtf8(std::to_string(count_));
            count_label->setPlainText(buffer);
        } else {
            rock->hide();
        }

    return;
}
