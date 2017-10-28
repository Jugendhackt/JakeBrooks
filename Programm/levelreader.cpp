#include "levelreader.h"

LevelReader::LevelReader(QString filename, QObject *parent) : QObject(parent)
{
    levelFile = new QFile(filename);
    levelFile->open(QIODevice::ReadOnly|QIODevice::Text);
    input = new QTextStream(levelFile);
    levels = input->readAll().split('\n');
}

bool LevelReader::isEOF()
{
    return eof;
}

void LevelReader::readLevel(int index)
{
    clear();
//    level = input->readAll();
    level = levels.at(index);
    qDebug()<<level;
    QList<QString> leveldata = level.split(";");
    QList<QString> metadata = leveldata.first().split("|");
    QList<QString> texts = leveldata.at(1).split("|");
    QList<QString> questions = leveldata.last().split("|");

    time = metadata.at(1);
    background = metadata.at(2);
    audio = metadata.at(3);
    QList<QString> tmp = metadata.last().split(":");
    for(int i = 0; i < tmp.size(); i++){
        QList<QString> formats = tmp.at(i).split("-");
        textFormat format;
        format.font = QFont(formats.first());
        format.color = QColor(formats.at(1));
        format.textsize = formats.at(2).toDouble();
        format.time = formats.at(3).toDouble();
        format.alpha = formats.at(4).toInt();
        formatList.append(format);
    }

    textList = texts;

    for(int i = 0; i < questions.size(); i++){
        tmp = questions.at(i).split("(").last().split(")").first().split(":");
        QA qa;
        qa.question = questions.at(i).split("(").first();
        qa.a1 = tmp.at(0);
        qa.a2 = tmp.at(1);
        qa.a3 = tmp.at(2);
        questionList.append(qa);
    }

}

int LevelReader::getListsize()
{
    return textList.size();
}













