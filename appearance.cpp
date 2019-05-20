#include "appearance.h"
#include <QTextEdit>
#include <QColor>
#include <QFont>

Appearance::Appearance(QWidget *parent) : QMainWindow(parent)
{

}

void Appearance::textColor(QColor color, QTextEdit* txt)
{
        txt->setTextColor(color);
}

void Appearance::bgColor(QColor color, QTextEdit* txt)
{
        QPalette p(palette());
        p.setColor(QPalette::Base, color);
        txt->setPalette(p);
}

void Appearance::font(QFont font, QTextEdit* txt)
{
    txt->setFont(font);
}

void Appearance::highlight(QColor color, QTextEdit* txt)
{
    txt->setTextBackgroundColor(color);
}
