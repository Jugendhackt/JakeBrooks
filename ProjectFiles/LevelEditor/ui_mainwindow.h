/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets>
#include <QObject>
#include "metadatawidget.h"
#include "textwidget.h"
#include "questionanswerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow : public QObject
{
    Q_OBJECT

public:
    Ui_MainWindow(QObject *parent = 0) : QObject(parent){}
    QWidget *centralWidget;
    MetaDataWidget *metaDataWidget;
    QList<TextWidget*> textWidgets;
    QList<QuestionAnswerWidget*> questionWidgets;
    QVBoxLayout *textLayout, *questionLayout, *mainLayout;

    QPushButton *nextLevelButton, *newQuestionButton, *newTextButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(425, 414);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainLayout = new QVBoxLayout(centralWidget);
        textLayout = new QVBoxLayout();
        questionLayout = new QVBoxLayout();
        metaDataWidget = new MetaDataWidget(centralWidget);
        nextLevelButton = new QPushButton(centralWidget);
        nextLevelButton->setObjectName(QStringLiteral("nextLevelButton"));
        nextLevelButton->setGeometry(QRect(20, 350, 381, 22));
        newQuestionButton = new QPushButton(centralWidget);
        newTextButton = new QPushButton(centralWidget);

        mainLayout->addWidget(metaDataWidget);
        mainLayout->addLayout(textLayout);
        mainLayout->addWidget(newTextButton);
        mainLayout->addLayout(questionLayout);
        mainLayout->addWidget(newQuestionButton);
        mainLayout->addWidget(nextLevelButton);

        connect(newTextButton, SIGNAL(clicked(bool)), this, SLOT(newText()));
        connect(newQuestionButton, SIGNAL(clicked(bool)), this, SLOT(newQuestion()));


        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
    }

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        nextLevelButton->setText(QApplication::translate("MainWindow", "Save Level and Next", 0));
        newTextButton->setText(QApplication::translate("MainWindow", "Text Hinzufügen"));
        newQuestionButton->setText(QApplication::translate("MainWindow", "Frage Hinzufügen"));
    }
public slots:
    void newText(){
        textWidgets.append(new TextWidget(centralWidget));
        textLayout->addWidget(textWidgets.last());
        connect(textWidgets.last()->removeButton, SIGNAL(clicked(bool)), this, SLOT(removeTextWidget()));
    }
    void newQuestion(){
        questionWidgets.append(new QuestionAnswerWidget(centralWidget));
        questionLayout->addWidget((questionWidgets.last()));
        connect(questionWidgets.last()->remove, SIGNAL(clicked(bool)), this, SLOT(removeQuestionWidget()));
    }
    void removeTextWidget(){
        textWidgets.last()->hide();
        textWidgets.removeLast();
    }
    void removeQuestionWidget(){
        questionWidgets.last()->hide();
        questionWidgets.removeLast();
    }

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
