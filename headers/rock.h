#ifndef ROCK_H
#define ROCK_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QPainter>
#include <QPixmap>

class Rock : public QGraphicsObject
{
public:
    explicit Rock() = default;
    explicit Rock(QPointF pos,int id);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int getWidth() {
        return w_;
    }
    int getHeight() {
        return h_;
    }
private:
    QPointF pos_;
    QPixmap image;
    int w_,h_;
};

#endif // ROCK_H
