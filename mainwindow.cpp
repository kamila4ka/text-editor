#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QColor>
#include <QPalette>
#include "appearance.h"
#include "files.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    pFiles = new Files();
    pAppear = new Appearance();

    connect(ui->actiontext, &QAction::triggered, this, &MainWindow::on_actiontext_triggered);
    connect(ui->actionpick_font, &QAction::triggered, this, &MainWindow::on_actionpick_font_triggered);
    connect(ui->actionhighlighter, &QAction::triggered, this, &MainWindow::on_actionhighlighter_triggered);
    connect(ui->actionbackground, &QAction::triggered, this, &MainWindow::on_actionbackground_triggered);
    connect(ui->actionReadFile, &QAction::triggered, this, &MainWindow::on_actionReadFile_triggered);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::on_actionSaveAs_triggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::on_actionSave_triggered);
    connect(ui->actionNew_file, &QAction::triggered, this, &MainWindow::on_actionNew_file_triggered);

//    ui->actionNew_file->setShortcut(QKeySequence(tr("Ctrl+N","New file")));
//    ui->actionSave->setShortcut(QKeySequence(tr("Ctrl+S","Save file")));
//    ui->actionCut->setShortcut(QKeySequence(tr("Ctrl+X","Cut")));
//    ui->actionCopy->setShortcut(QKeySequence(tr("Ctrl+C","Copy")));
//    ui->textEdit->paste().setShortcut(QKeySequence(tr("Ctrl+V","Paste")));
//    ui->actionSelect_all->setShortcut(QKeySequence(tr("Ctrl+A","Select all")));
//    ui->actionSaveAs->setShortcut(QKeySequence("Ctrl+Shift+S"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionReadFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "open a file", QDir::homePath());
    filepath = filename;
    pFiles->read(filename, ui->textEdit);

}


void MainWindow::on_actionSaveAs_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "open a file", QDir::homePath());
    filepath = filename;

    pFiles->saveAs(filename, ui->textEdit);

}

void MainWindow::on_actionSave_triggered()
{
    pFiles->save(filepath, ui->textEdit);
}

void MainWindow::on_actionpick_font_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
        pAppear->font(font, ui->textEdit);
    else return;
}

void MainWindow::on_actiontext_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid())
        pAppear->textColor(color, ui->textEdit);
}

void MainWindow::on_actionbackground_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid())
        pAppear->bgColor(color, ui->textEdit);
}

void MainWindow::on_actionhighlighter_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid())
        pAppear->highlight(color, ui->textEdit);

}

void MainWindow::on_actionNew_file_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "open a file", QDir::homePath());
    filepath=filename;
    pFiles->create(filename);
}
