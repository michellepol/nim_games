#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QWidget>
#include <QTextBrowser>
#include <QFrame>
#include <QHBoxLayout>

class RulesWindow : public QWidget
{
public:
    explicit RulesWindow();
    void RulesCalledHandler();
private:
    QTextBrowser* rules_;
    const QString rules = "Ним – игра, в которой два игрока по очереди берут предметы, разложенные на несколько кучек.\n"
"\n"
"За один ход можно вытаскивать 1 камень из одной, либо 1 камень из другой кучи, либо по одному камню из каждой кучи. \n"
"\n"
"В игре 4 раунда: \n"
"1. Игрок 1 начинает и проигравшим считается тот, кто взял последний камень\n"
"2. Игрок 1 начинает и выигравшим считается тот, кто взял последний камень\n"
"3. Игрок 2 начинает и проигравшим считается тот, кто взял последний камень\n"
"4. Игрок 2 начинает и выигравшим считается тот, кто взял последний камень\n"
"\n"
"В нашей игре мы предлагаем вам два режима: против игрока и против компьютера.";
};

#endif // RULESWINDOW_H
