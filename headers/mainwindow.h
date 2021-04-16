#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "headers/gamewindow.h"
#include "headers/menuwindow.h"
#include <QStackedWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QFrame>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow() {
    }

private:
    Ui::MainWindow* ui;
    GameWindow* game_window_;
    MenuWindow* menu_window_;
    QStackedWidget* widgets_;
};

#endif // MAINWINDOW_H
