#ifndef HEAP_H
#define HEAP_H

#include "headers/rock.h"
#include "headers/bucket.h"
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsScene>
#include <QtCore>
#include <QPushButton>

class Heap : public QGraphicsObject
{
    Q_OBJECT
public:
    static int used_id;

    explicit Heap() = default;
    explicit Heap(QGraphicsScene* scene,QPointF point,Bucket* bucket,int id);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setCount(int count);
    int getWidth() {
        return w;
    }
    int getHeigth() {
        return h;
    }
    int getCount() const {
        return count_;
    }
    int getWidth() const{
        return w;
    }
    void setGrabAmount(int grab_amount) {
        grab_amount_ = grab_amount;
    }
    void setButton(QPushButton* button) {
        turn_btn = button;
    }
signals:
    void ValueChanged();
private:
    int x_,y_,w,h;
    QPushButton* turn_btn;
    QGraphicsTextItem* count_label;
    QPixmap image;
    Rock* rock;
    const Bucket* bucket_{nullptr}; //warning
    int grab_amount_{1};
    QGraphicsScene* scene_;
    int count_{0};
    int id_{0};
};

#endif // HEAP_H
