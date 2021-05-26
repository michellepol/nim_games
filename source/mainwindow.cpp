
#include "headers/mainwindow.h"
#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>

#include <QLabel>
#include <QScreen>
#include <QSpinBox>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
        QScreen* screen = QGuiApplication::primaryScreen();
        QRect screen_geometry = screen->geometry();
        this->setMaximumSize(screen_geometry.width() - 100,screen_geometry.height() - 100);

        widgets_ = new QStackedWidget(this);
        menu_window_ = new MenuWindow(this,widgets_);

        QHBoxLayout* main_box = new QHBoxLayout(this);
        widgets_->addWidget(menu_window_);

        main_box->addWidget(widgets_);


        widgets_->setCurrentIndex(0);
        setLayout(main_box);
    }











