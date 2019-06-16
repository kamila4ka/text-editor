#ifndef FILES_H
#define FILES_H

#include <QTextEdit>

class FileManager: public QObject
{
    Q_OBJECT

public:
    FileManager();

public slots:
    void createNewFile(QString filename);
    void readFile(QString filename, QTextEdit* txt);
    void saveFile(QString filename, QTextEdit* txt);
    void saveFileAs(QString filename, QTextEdit* txt);

};

#endif // FILES_H
