#include "headers/bucket.h"

QRectF Bucket::boundingRect() const {
    return QRectF (0,0,w_,h_);

}

int Bucket::getWidth() {
    return w_;
}
int Bucket::getHeigth() {
    return h_;
}

Bucket::Bucket(QGraphicsScene* scene) {
    scene_ = scene;
    image_ = QPixmap(":/media/images/bucket.png");

    image_ = image_.scaled(scene_->width() * 0.25,scene_->height() * 0.3,Qt::IgnoreAspectRatio);

    w_ = image_.width();
    h_ = image_.height();
}

void Bucket::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    painter->drawPixmap(0,0,image_);
    Q_UNUSED(option);
    Q_UNUSED(widget)

}
