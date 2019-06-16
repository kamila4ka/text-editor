#include "filemanager.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTextEdit>

FileManager::FileManager(){};


void FileManager::createNewFile(QString filename) {
    QFile file(filename);

    file.open(QIODevice::WriteOnly);
    file.close();
}

void FileManager::readFile(QString filename, QTextEdit* txt) {
    QFile file(filename);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(nullptr, "title", "file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    txt->setText(text);
    file.close();
}

void FileManager::saveFile(QString filename, QTextEdit* txt) {
    QFile file(filename);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(nullptr, "title", "file not open");
    }
    QTextStream out(&file);
    QString text = txt->toPlainText();
    txt->setText(text);
    out << text;
    file.flush();
    file.close();
}

void FileManager::saveFileAs(QString filename, QTextEdit* txt) {
    QFile file(filename);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(nullptr, "title", "file not open");
    }
    QTextStream out(&file);
    QString text = txt->toPlainText();
    txt->setText(text);
    out << text;
    file.flush();
    file.close();
}
