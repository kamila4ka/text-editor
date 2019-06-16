#include "appearance.h"
#include <QTextEdit>
#include <QColor>
#include <QFont>

Appearance::Appearance(QWidget *parent) : QMainWindow(parent) {}

void Appearance::changeTextColor(QColor color, QTextEdit* txt) {
        txt->setTextColor(color);
}

void Appearance::changeBackgroundColor(QColor color, QTextEdit* txt) {
        QPalette p(palette());
        p.setColor(QPalette::Base, color);
        txt->setPalette(p);
}

void Appearance::pickFont(QFont font, QTextEdit* txt) {
    txt->setFont(font);
}

void Appearance::changeTextBackground(QColor color, QTextEdit* txt) {
    txt->setTextBackgroundColor(color);
}
