#ifndef QUESTIONANSWERWIDGET_H
#define QUESTIONANSWERWIDGET_H

#include <QtWidgets>

class QuestionAnswerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QuestionAnswerWidget(QWidget *parent = 0);
    QPushButton *remove;
    QLineEdit *question;
    QLineEdit *answer1, *answer2, *answer3;
    QVBoxLayout *answerLayout;
    QHBoxLayout *mainLayout;

signals:

public slots:
};

#endif // QUESTIONANSWERWIDGET_H
