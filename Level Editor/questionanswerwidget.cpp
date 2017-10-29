#include "questionanswerwidget.h"

QuestionAnswerWidget::QuestionAnswerWidget(QWidget *parent) : QWidget(parent)
{
    remove = new QPushButton(this);
    question = new QLineEdit(this);
    answer1 = new QLineEdit(this);
    answer2 = new QLineEdit(this);
    answer3 = new QLineEdit(this);
    answerLayout = new QVBoxLayout();
    mainLayout = new QHBoxLayout(this);
    remove->setText("Löschen");
    answerLayout->addWidget(answer1);
    answerLayout->addWidget(answer2);
    answerLayout->addWidget(answer3);
    mainLayout->addWidget(question);
    mainLayout->addLayout(answerLayout);
    mainLayout->addWidget(remove);
}
