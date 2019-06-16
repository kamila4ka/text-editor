#ifndef APPEARANCE_H
#define APPEARANCE_H

#include <QTextEdit>
#include <QMainWindow>

class Appearance : public QMainWindow {
    Q_OBJECT

public:

    Appearance(QWidget *parent = nullptr);

public slots:

    void changeTextColor(QColor color, QTextEdit* txt);

    void changeBackgroundColor(QColor color, QTextEdit* txt);

    void pickFont(QFont font, QTextEdit* txt);

    void changeTextBackground(QColor color, QTextEdit* txt);
};

#endif // APPEARANCE_H
