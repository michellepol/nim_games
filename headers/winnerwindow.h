#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QWidget>
#include <QTextBrowser>
#include <QFrame>
#include <QHBoxLayout>

class WinnerWindow : public QWidget
{
public:
    WinnerWindow() = default;
    WinnerWindow(QString winner);
    void WinnerCalledHandler();
private:
    QTextBrowser* final_message_;
    QString winner_;
    QString message_;

};

#endif // WINNERWINDOW_H
