#ifndef STATWINDOW_H
#define STATWINDOW_H

#include <QWidget>
#include <QTextBrowser>
#include <QFrame>
#include <QHBoxLayout>

struct StatEntry {
    StatEntry() {
        winners = std::vector<int>(4);
    }
    int heap1_amount;
    int heap2_amount;
    std::vector<int> winners;
    bool computer;
};

class StatWindow : public QWidget
{
    Q_OBJECT
public:
    StatWindow(StatEntry stats);
private:
    StatEntry stats_;
    QTextBrowser* stats_text;

signals:

};

#endif // STATWINDOW_H
