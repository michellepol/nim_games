#include "headers/winnerwindow.h"

WinnerWindow::WinnerWindow(QString winner)
{
    winner_ = winner;
    message_ = winner + " победил";
    QHBoxLayout* hbox = new QHBoxLayout(this);

    final_message_ = new QTextBrowser();
    final_message_->setMinimumSize(QSize(150,200));
    final_message_->setText(message_);

    QFont font = final_message_->font();
    font.setPixelSize(24);
    final_message_->setFont(font);

    hbox->addWidget(final_message_);
}
