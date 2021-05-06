#include "headers/menuwindow.h"

MenuWindow::MenuWindow(QStackedWidget* widgets)
{
    widgets_ = widgets;
    this->resize(1325,818);

    QWidget* set_up = this;

    QVBoxLayout* hbox = new QVBoxLayout(set_up);

    QFont font = QFont();
    font.setFamily("Helvetica");
    font.setPixelSize(24);

    //creating menu buttons
    QPushButton* start_btn = new QPushButton("Игрок против игрока",set_up);
    start_btn->setFont(font);
    start_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hbox->addWidget(start_btn,1);


    QPushButton* start_bot_btn = new QPushButton("Игрок против компьютера",set_up);
    start_bot_btn->setFont(font);
    start_bot_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hbox->addWidget(start_bot_btn,1);

    QPushButton* ext_btn = new QPushButton("Выход",set_up);
    ext_btn->setFont(font);
    ext_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hbox->addWidget(ext_btn,1);

    setLayout(hbox);

    //linking buttons with methods
    connect(start_btn, &QPushButton::clicked, this, &MenuWindow::OnHumanPressed);
    connect(start_bot_btn, &QPushButton::clicked, this, &MenuWindow::OnComputerPressed);
    connect(ext_btn, &QPushButton::clicked, this, &MenuWindow::OnExitPressed);
}

void MenuWindow::OnHumanPressed() {
    game_window_ = new GameWindow(widgets_, false);
    widgets_->addWidget(game_window_);
    widgets_->setCurrentWidget(game_window_);
}

void MenuWindow::OnComputerPressed() {
    game_window_ = new GameWindow(widgets_, true);
    widgets_->addWidget(game_window_);
    widgets_->setCurrentWidget(game_window_);
}


void MenuWindow::OnExitPressed() {
    QApplication::quit();
}
