#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "ui_mainwindow.h"
#include <QMainWindow>
#include "files.h"
#include "appearance.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionReadFile_triggered();

    void on_actionSaveAs_triggered();

    void on_actionSave_triggered();

    void on_actionpick_font_triggered();

    void on_actiontext_triggered();

    void on_actionbackground_triggered();

    void on_actionhighlighter_triggered();

    void on_actionNew_file_triggered();

private:
    Ui::MainWindow *ui;
    QString filepath;
    Files *pFiles;
    Appearance *pAppear;
};

#endif // MAINWINDOW_H
