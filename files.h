#ifndef FILES_H
#define FILES_H

#include <QMainWindow>
#include <QTextEdit>

class Files : public QMainWindow
{
    Q_OBJECT
public:
    explicit Files(QWidget *parent = nullptr);

signals:

public slots:
    void create(QString filename);
    void read(QString filename, QTextEdit* txt);
    void save(QString filename, QTextEdit* txt);
    void saveAs(QString filename, QTextEdit* txt);

};

#endif // FILES_H
