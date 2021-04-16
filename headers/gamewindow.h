#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "headers/heap.h"
#include "headers/ai.h"
#include "headers/ruleswindow.h"
#include "headers/winnerwindow.h"
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow() = default;
    explicit GameWindow(QStackedWidget* widgets,bool computer);
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
        delete widgets_;
        delete player_label_;
        delete ai_;
    }
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
    std::array<RoundSettings,4> rounds_;
    int current_round{-1};

    WinnerWindow* winner_window_{nullptr};
    RulesWindow* rules_window_{nullptr};

    QFont font_;

    int view_min_width_{1000};
    int view_min_height_{800};

    bool player_turn_{false};
    bool restart_{false};
    bool fst_turn_{false};
    bool computer_{false};

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

    AI* ai_;
};

#endif // GAMEWINDOW_H
