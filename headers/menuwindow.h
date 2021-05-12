#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "headers/gamewindow.h"
#include <QWidget>
#include <QStackedWidget>
#include <QApplication>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>

class MenuWindow : public QWidget
{
public:
    explicit MenuWindow() = default;
    explicit MenuWindow(QWidget* parent,QStackedWidget* widgets);
    void SetUpMenuScene();
public slots:
    void OnHumanPressed();
    void OnComputerPressed();
    void OnExitPressed();
private:
    QWidget* parent_;
    QStackedWidget* widgets_;
    GameWindow* game_window_;
};

#endif // MENUWINDOW_H
