#include "headers/ruleswindow.h"

RulesWindow::RulesWindow()
{
    QHBoxLayout* hbox = new QHBoxLayout(this);

    rules_ = new QTextBrowser();
    rules_->setMinimumSize(QSize(600,300));
    rules_->setText(rules);

    QFont font = rules_->font();
    font.setPixelSize(24);
    rules_->setFont(font);

    hbox->addWidget(rules_);
}



