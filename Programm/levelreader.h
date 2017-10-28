#ifndef LEVELREADER_H
#define LEVELREADER_H

#include <QObject>
#include <QColor>
#include <QDebug>
#include <QFont>
#include <QFile>
#include <QTextStream>

struct textFormat{
    QFont font;
    QColor color;
    double textsize, time;
    int alpha;
};

struct QA{
    QString question;
    QString a1, a2, a3;
};

class LevelReader : public QObject
{
    Q_OBJECT
public:
    explicit LevelReader(QString filename, QObject *parent = 0);
    bool isEOF();
    void readLevel(int index);

    QString background, audio, time;
    QString level;
    QList<textFormat> formatList;
    QList<QString> textList;
    QList<QA> questionList;

signals:

public slots:

private:
    void clear(){
        background.clear();
        audio.clear();
        time.clear();
        level.clear();
        formatList.clear();
        textList.clear();
        questionList.clear();
    }

    QFile *levelFile;
    QTextStream *input;
    int currentLevel = 0;
    bool eof;
};

#endif // LEVELREADER_H
