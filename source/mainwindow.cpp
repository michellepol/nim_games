
#include "headers/mainwindow.h"
#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>

#include <QLabel>
#include <QSpinBox>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
        widgets_ = new QStackedWidget(this);
        menu_window_ = new MenuWindow(widgets_);

        QHBoxLayout* main_box = new QHBoxLayout(this);
        widgets_->addWidget(menu_window_);

        main_box->addWidget(widgets_);

        widgets_->setCurrentIndex(0);
        setLayout(main_box);
    }











