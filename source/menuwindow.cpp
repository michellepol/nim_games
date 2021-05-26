#include "headers/menuwindow.h"

MenuWindow::MenuWindow(QWidget* parent,QStackedWidget* widgets)
{
    parent_ = parent;
    widgets_ = widgets;

    QWidget* set_up = this;

    this->setMaximumSize(parent_->maximumSize());

    QPixmap bkgnd;
    bkgnd.load(":/media/images/human.jpg");
    bkgnd = bkgnd.scaled(parent_->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    parent_->setPalette(palette);

    QVBoxLayout* hbox = new QVBoxLayout(set_up);

    QFont font = QFont();
    font.setFamily("Helvetica");
    font.setPixelSize(24);

    //creating menu buttons
    QPushButton* start_btn = new QPushButton("Игрок против игрока",set_up);
    start_btn->setFont(font);
    start_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    start_btn->setMinimumSize(parent_->maximumSize().width() * 0.8,parent_->maximumSize().height() * 0.1);
    start_btn->setMaximumSize(parent_->maximumSize().width() * 0.8,parent_->maximumSize().height() * 0.2);
    start_btn->setStyleSheet("background-color: rgba(255, 255, 255, 60);");
    //start_btn->setStyleSheet("QPushButton{background: transparent;}");
    hbox->addWidget(start_btn,1,Qt::AlignHCenter);

    QPushButton* start_bot_btn = new QPushButton("Игрок против компьютера",set_up);
    start_bot_btn->setFont(font);
    start_bot_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    start_bot_btn->setMinimumSize(parent_->maximumSize().width() * 0.8,parent_->maximumSize().height() * 0.1);
    start_bot_btn->setMaximumSize(parent_->maximumSize().width() * 0.8,parent_->maximumSize().height() * 0.2);
    //start_bot_btn->setStyleSheet("QPushButton{background: transparent;}");
    hbox->addWidget(start_bot_btn,1,Qt::AlignHCenter);

    QPushButton* ext_btn = new QPushButton("Выход",set_up);
    ext_btn->setFont(font);
    ext_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    ext_btn->setMinimumSize(parent_->maximumSize().width() * 0.8,parent_->maximumSize().height() * 0.1);
    ext_btn->setMaximumSize(parent_->maximumSize().width() * 0.8,parent_->maximumSize().height() * 0.2);
    //ext_btn->setStyleSheet("QPushButton{background: transparent;}");
    hbox->addWidget(ext_btn,1,Qt::AlignHCenter);

    setLayout(hbox);

    //linking buttons with methods
    connect(start_btn, &QPushButton::clicked, this, &MenuWindow::OnHumanPressed);
    connect(start_bot_btn, &QPushButton::clicked, this, &MenuWindow::OnComputerPressed);
    connect(ext_btn, &QPushButton::clicked, this, &MenuWindow::OnExitPressed);
}

void MenuWindow::OnHumanPressed() {
    game_window_ = new GameWindow(parent_,widgets_, false);
    widgets_->addWidget(game_window_);
    widgets_->setCurrentWidget(game_window_);
}

void MenuWindow::OnComputerPressed() {
    game_window_ = new GameWindow(parent_,widgets_, true);
    widgets_->addWidget(game_window_);
    widgets_->setCurrentWidget(game_window_);
}


void MenuWindow::OnExitPressed() {
    QApplication::quit();
}
