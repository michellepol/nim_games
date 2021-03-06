#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "headers/heap.h"
#include "headers/ai.h"
#include "headers/ruleswindow.h"
#include "headers/winnerwindow.h"
#include "headers/statwindow.h"
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>
#include <QPalette>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow() = default;
    explicit GameWindow(QWidget* parent,QStackedWidget* widgets,bool computer);
    ~GameWindow() {
        delete rules_window_;
        delete winner_window_;
        delete heap1_;
        delete heap2_;
        delete start_btn_;
        delete turn_btn_;
        delete scene_;
        delete graphics_view_;
        delete fst_heap_;
        delete scnd_heap_;  
        delete ai_;
    }
    void SetRounds(int curr_round);
    void Interface();
    void SetUpInGameMenuPolicy(QWidget* btn);
    void SetUpGameMenuButtons(QVBoxLayout* vbox);
    void SetUpGameSettings(QVBoxLayout* vbox);
    void SetUpGameLogic();
    void SetUpComputer(bool computer);
    void Start();
public slots:
    void OnTurnComputerPressed();
    void OnStartPressed();
    void OnInGameExitPressed();
    void OnTurnPressed();
    void OnRulesPressed();
    void CheckWinStatus();
private:
    struct RoundSettings {
        int start_player{-1};
        bool last_stone_win{false};
    };

    enum PLAYERS {
        PLAYER1 = 1,
        PLAYER2 = 2,
        COMPUTER = 3,
        HUMAN = 4
    };

    std::array<RoundSettings,4> rounds_;
    int current_round{-1};

    WinnerWindow* winner_window_{nullptr};
    RulesWindow* rules_window_{nullptr};
    StatWindow* stat_window_{nullptr};
    StatEntry stats;

    QGraphicsTextItem* round_label_;

    QFont font_;

    int view_min_width_{600};
    int view_min_height_{400};

    bool player_turn_{false};
    bool restart_{false};
    bool computer_{false};

    int player_number{0};
    int prev_player_number{0};

    Heap* heap1_;
    Heap* heap2_;

    QPushButton* start_btn_{nullptr};
    QPushButton* turn_btn_{nullptr};

    QGraphicsScene* scene_;
    QGraphicsView* graphics_view_{nullptr};

    QSpinBox* fst_heap_;
    QSpinBox* scnd_heap_;
    QStackedWidget* widgets_;
    QLabel* player_label_;

    QWidget* parent_;

    AI* ai_;
};

#endif // GAMEWINDOW_H
