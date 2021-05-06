#include "headers/statwindow.h"
#include <iostream>
#include <string>

StatWindow::StatWindow(StatEntry stats)
{
    stats_ = stats;
    QHBoxLayout* hbox = new QHBoxLayout(this);

    stats_text = new QTextBrowser();
    stats_text->setMinimumSize(QSize(600,300));

    std::ostringstream out();

    out << "Количество камней в первой куче: " << stats_.heap1_amount << '\n'
        << "Количество камней в второй куче: " << stats.heap2_amount << '\n'
        << "Победитель в первом раунде: " << stats.winners[0] << " игрок\n"
        << "Победитель в втором раунде: " << stats.winners[1] << " игрок\n"
        << "Победитель в третьем раунде: " << stats.winners[2] << " игрок\n"
        << "Победитель в четвёртом раунде: " << stats.winners[3] << " игрок\n";

    QString stat_str = out.str();

    stats_text->setText(stat_str);

    QFont font = stats_text->font();
    font.setPixelSize(24);
    stats_text->setFont(font);

    hbox->addWidget(stats_text);
}
