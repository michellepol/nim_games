#ifndef BUCKET_H
#define BUCKET_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Bucket : public QGraphicsItem
{
public:
    explicit Bucket() = default;
    explicit Bucket(QGraphicsScene* scene);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int getWidth();
    int getHeigth();
private:
    QGraphicsScene* scene_;
    QPixmap image_;
    int w_,h_;
};

#endif // BUCKET_H
