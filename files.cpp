#include "files.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTextEdit>

Files::Files(QWidget *parent) : QMainWindow(parent)
{

}


void Files::create(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.close();
}

void Files::read(QString filename, QTextEdit* txt)
{

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    txt->setText(text);
    file.close();
}

void Files::save(QString filename, QTextEdit* txt)
{
    QFile file(filename);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream out(&file);
    QString text = txt->toPlainText();
    txt->setText(text);
    out << text;
    file.flush();
    file.close();
}

void Files::saveAs(QString filename, QTextEdit* txt)
{
    QFile file(filename);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "title", "file not open");
    }
    QTextStream out(&file);
    QString text = txt->toPlainText();
    txt->setText(text);
    out << text;
    file.flush();
    file.close();
}
