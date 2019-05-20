#ifndef APPEARANCE_H
#define APPEARANCE_H

#include <QTextEdit>
#include <QMainWindow>

class Appearance : public QMainWindow
{
    Q_OBJECT
public:
    explicit Appearance(QWidget *parent = nullptr);

signals:

public slots:
    void textColor(QColor color, QTextEdit* txt);
    void bgColor(QColor color, QTextEdit* txt);
    void font(QFont font, QTextEdit* txt);
    void highlight(QColor color, QTextEdit* txt);
};

#endif // APPEARANCE_H
