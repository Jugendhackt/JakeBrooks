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
    int getListsize();
    int getQListsize(){
        return questionList.size();
    }

    textFormat formatLAt(int i){
        return formatList.at(i);
    }
    QString textLAt(int i){
        return textList.at(i);
    }
    QA questionLAt(int i){
        return questionList.at(i);
    }

    QString background, audio, time;
    QList<textFormat> formatList;
    QList<QString> textList, levels;
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

    QString level;
    QFile *levelFile;
    QTextStream *input;
    int currentLevel = 0;
    bool eof;
};

#endif // LEVELREADER_H
