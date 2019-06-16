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
#include "filemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    pFiles = new FileManager();
    pAppear = new Appearance();

    connect(ui->actiontext, &QAction::triggered, this, &MainWindow::changeTextColor);
    connect(ui->actionpick_font, &QAction::triggered, this, &MainWindow::pickFont);
    connect(ui->actionhighlighter, &QAction::triggered, this, &MainWindow::changeTextBackground);
    connect(ui->actionbackground, &QAction::triggered, this, &MainWindow::changeBackground);
    connect(ui->actionReadFile, &QAction::triggered, this, &MainWindow::readFile);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionNew_file, &QAction::triggered, this, &MainWindow::createNewFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "open a file", QDir::homePath());
    filepath = filename;
    pFiles->readFile(filename, ui->textEdit);

}


void MainWindow::saveFileAs()
{
    QString filename = QFileDialog::getSaveFileName(this, "open a file", QDir::homePath());
    filepath = filename;

    pFiles->saveFileAs(filename, ui->textEdit);

}

void MainWindow::saveFile()
{
    pFiles->saveFile(filepath, ui->textEdit);
}

void MainWindow::pickFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
        pAppear->pickFont(font, ui->textEdit);
    else return;
}

void MainWindow::changeTextColor()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid())
        pAppear->changeTextColor(color, ui->textEdit);
}

void MainWindow::changeBackground()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid())
        pAppear->changeBackgroundColor(color, ui->textEdit);
}

void MainWindow::changeTextBackground()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid())
        pAppear->changeTextBackground(color, ui->textEdit);

}

void MainWindow::createNewFile()
{
    QString filename = QFileDialog::getSaveFileName(this, "open a file", QDir::homePath());
    filepath=filename;
    pFiles->createNewFile(filename);
}
