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
    QString rules = "Ним – игра, в которой два игрока по очереди берут предметы, разложенные на несколько кучек.\n"
"\n"
"За один ход может быть взято любое количество предметов (большее нуля) из одной кучки. \n"
"\n"
"Выигрывает игрок, взявший последний предмет. \n"
"\n"
"В нашей игре мы предлагаем вам два режима: против игрока и против компьютера.";
};

#endif // RULESWINDOW_H
