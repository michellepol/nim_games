#include "headers/gamewindow.h"

void GameWindow::Interface() {
    font_ = QFont("Helvetica");
    font_.setPixelSize(24);

    graphics_view_ = new QGraphicsView();
    graphics_view_->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    graphics_view_->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    graphics_view_->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graphics_view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    graphics_view_->setMinimumSize(QSize(view_min_width_,view_min_height_));

    QHBoxLayout* mainbox = new QHBoxLayout(this);
    QVBoxLayout* vbox = new QVBoxLayout();

    scene_ = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene_->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
    scene_->setSceneRect(0,0,view_min_width_,view_min_height_); // Устанавливаем размер сцены

    graphics_view_->setScene(scene_);  // Устанавливаем графическую сцену в graphicsView
    mainbox->addWidget(graphics_view_,1,Qt::AlignLeft);

    SetUpGameMenuButtons(vbox);
    SetUpGameSettings(vbox);

    mainbox->addLayout(vbox);
}

GameWindow::GameWindow(QStackedWidget* widgets,bool computer)
{
    computer_ = computer;
    widgets_ = widgets;
    rules_window_ = new RulesWindow();

    rounds_[0] = (RoundSettings{1,false});
    rounds_[1] = (RoundSettings{1,true});
    rounds_[2] = (RoundSettings{2,false});
    rounds_[3] = (RoundSettings{2,true});

    Interface();
}

void GameWindow::SetUpComputer(bool computer) {
    computer_ = computer;
}

void GameWindow::SetUpGameLogic() {
    Bucket* bucket = new Bucket(scene_);
    bucket->setPos(QPoint(graphics_view_->width() * 0.5 - (bucket->getWidth() / 2),
                          graphics_view_->height() * 0.75 - (bucket->getHeigth() / 2)));

    int margin = 75;

    QPointF point1 = QPointF(margin,graphics_view_->height() * 0.25 - 150);
    heap1_ = new Heap(scene_,point1,bucket,0);
    heap1_->setPos(point1);


    QPointF point2 = QPointF(graphics_view_->width() - margin - 300,graphics_view_->height() * 0.25 - 150);
    heap2_ = new Heap(scene_,point2,bucket,1);
    heap2_->setPos(point2);


    heap1_->setButton(turn_btn_);
    heap2_->setButton(turn_btn_);
    ai_ = new AI(heap1_,heap2_);

    scene_->addItem(heap1_);
    scene_->addItem(bucket);
    scene_->addItem(heap2_);

    connect(heap1_,&Heap::ValueChanged,this,&GameWindow::CheckWinStatus);
    connect(heap2_,&Heap::ValueChanged,this,&GameWindow::CheckWinStatus);
}

void GameWindow::SetUpGameSettings(QVBoxLayout* vbox) {
    QLabel* game_settings = new QLabel();
    game_settings->setText("Настройки");
    SetUpInGameMenuPolicy(game_settings);
    vbox->addWidget(game_settings);

    QLabel* fst_heap_label = new QLabel();
    fst_heap_label->setText("1-ая куча");
    SetUpInGameMenuPolicy(fst_heap_label);
    vbox->addWidget(fst_heap_label);

    fst_heap_ = new QSpinBox();
    fst_heap_->setValue(1);
    fst_heap_->setMinimum(1);
    SetUpInGameMenuPolicy(fst_heap_);
    vbox->addWidget(fst_heap_);

    QLabel* scnd_heap_label = new QLabel();
    scnd_heap_label->setText("2-ая куча");
    SetUpInGameMenuPolicy(scnd_heap_label);
    vbox->addWidget(scnd_heap_label);

    scnd_heap_ = new QSpinBox();
    scnd_heap_->setValue(1);
    scnd_heap_->setMinimum(1);
    SetUpInGameMenuPolicy(scnd_heap_);
    vbox->addWidget(scnd_heap_);

}

void GameWindow::SetUpGameMenuButtons(QVBoxLayout* vbox){
    start_btn_ = new QPushButton("Старт",this);
    vbox->addWidget(start_btn_,1);
    SetUpInGameMenuPolicy(start_btn_);

    if(computer_) {
        turn_btn_ = new QPushButton("Сменить ход",this);
        connect(turn_btn_,&QPushButton::clicked, this, &GameWindow::OnTurnComputerPressed);
    } else {
        turn_btn_ = new QPushButton("Сменить ход",this);
        connect(turn_btn_,&QPushButton::clicked, this, &GameWindow::OnTurnPressed);
    }
    vbox->addWidget(turn_btn_ ,1);
    SetUpInGameMenuPolicy(turn_btn_);
    turn_btn_->setDisabled(true);

    if(!computer_) {
        player_label_ = new QLabel();
        SetUpInGameMenuPolicy(player_label_ );
        vbox->addWidget(player_label_,0,Qt::AlignCenter);
    }


    QPushButton* rules_btn = new QPushButton("Правила",this);
    vbox->addWidget(rules_btn,1);
    SetUpInGameMenuPolicy(rules_btn);

    QPushButton* ingame_ext_btn = new QPushButton("Выход",this);
    vbox->addWidget(ingame_ext_btn,1);
    SetUpInGameMenuPolicy(ingame_ext_btn);

    //linking buttons with methods
    connect(start_btn_,&QPushButton::clicked, this, &GameWindow::OnStartPressed);
    connect(rules_btn, &QPushButton::clicked, this, &GameWindow::OnRulesPressed);
    connect(ingame_ext_btn, &QPushButton::clicked, this, &GameWindow::OnInGameExitPressed);
}

void GameWindow::SetUpInGameMenuPolicy(QWidget *btn) {
    btn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    btn->setFont(font_);
}

void GameWindow::OnStartPressed() {
    Start();
}

void GameWindow::OnTurnPressed() {
    Heap::used_id = -1;
    if(!fst_turn_) {
        player_label_->setText("Ход 1 игрока");
        turn_btn_->setDisabled(true);
        fst_turn_ = true;
    } else {
        player_label_->setText("Ход 2 игрока");
        turn_btn_->setDisabled(true);
        fst_turn_ = false;
    }
}

void GameWindow::CheckWinStatus() {
    if(heap1_->getCount() == 0 && heap2_->getCount() == 0) {
        std::string winner;
        if(rounds_[current_round].last_stone_win && !fst_turn_) {
            winner = "the second player";
        } else if(rounds_[current_round].last_stone_win && fst_turn_){
            winner = "the first player";
        } else if(!rounds_[current_round].last_stone_win && fst_turn_) {
            winner = "the second player";
        } else if(!rounds_[current_round].last_stone_win && !fst_turn_) {
            winner = "the first player";
        } else {
            winner = "some error occured";
        }
        winner_window_ = new WinnerWindow(QString::fromStdString(winner));
        winner_window_->show();
        fst_heap_->setDisabled(false);
        scnd_heap_->setDisabled(false);
        start_btn_->setDisabled(false);
        turn_btn_->setDisabled(true);
    }
}

void GameWindow::OnTurnComputerPressed() {
    Heap::used_id = -1;
    if(player_turn_) {
        player_turn_ = false;
        turn_btn_->setDisabled(true);
    } else {
        ai_->make_move_ai();
        player_turn_ = true;
        OnTurnComputerPressed();
    }
}

void GameWindow::OnRulesPressed() {
    rules_window_->show();
}

void GameWindow::Start() {
        if(winner_window_) {
            winner_window_->close();
        }
        if(current_round == -1) {
             SetUpGameLogic();
             current_round = 0;
        }
        if(current_round < 3) {
            start_btn_->setText("Следующий раунд");
            if(rounds_[current_round].start_player == 1 && !computer_) {
                fst_turn_ = true;
                player_label_ ->setText("Ход 1 игрока");
            } else if(!computer_) {
                player_label_ ->setText("Ход 2 игрока");
                fst_turn_ = false;
            }
            if(rounds_[current_round].start_player == 1 && computer_) {
                player_turn_ = true;
            } else {
                player_turn_ = false;
            }
            current_round++;
        } else {
            start_btn_->setText("Перезапуск");
            current_round = 0;
            start_btn_->setDisabled(true);
        }
        Heap::used_id = -1;
        //block game settings
        fst_heap_->setDisabled(true);
        scnd_heap_->setDisabled(true);

        //take info from game settings
        heap1_->setCount(fst_heap_->value());
        heap2_->setCount(scnd_heap_->value());

        turn_btn_->setDisabled(true);
        start_btn_->setDisabled(true);
        fst_turn_ = true;
}

void GameWindow::OnInGameExitPressed() {
    widgets_->removeWidget(this);
    widgets_->setCurrentIndex(0);
    if(rules_window_) {
        rules_window_->close();
    }
}

