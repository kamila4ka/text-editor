#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanager.h"
#include "appearance.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readFile();

    void saveFileAs();

    void saveFile();

    void pickFont();

    void changeTextColor();

    void changeBackground();

    void changeTextBackground();

    void createNewFile();

private:
    Ui::MainWindow *ui;

    QString filepath;

    FileManager *pFiles;

    Appearance *pAppear;
};

#endif 
