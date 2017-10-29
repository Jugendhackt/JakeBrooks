/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *backGround;
    QVBoxLayout *verticalLayout_2;
    QLabel *foreGround;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *answer1;
    QCheckBox *answer2;
    QCheckBox *answer3;
    QPushButton *quitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        backGround = new QLabel(MainWindow);
        backGround->setObjectName(QStringLiteral("backGround"));
        verticalLayout_2 = new QVBoxLayout(backGround);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        foreGround = new QLabel(backGround);
        foreGround->setObjectName(QStringLiteral("foreGround"));
        foreGround->setAttribute(Qt::WA_TranslucentBackground);
        foreGround->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(foreGround);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        startButton = new QPushButton(foreGround);
        startButton->setObjectName(QStringLiteral("startButton"));
        backGround->setScaledContents(true);
        verticalLayout->addWidget(startButton);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        verticalLayout->addItem(verticalSpacer);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        verticalLayout->addItem(verticalSpacer_2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        answer1 = new QCheckBox(foreGround);
        answer1->setObjectName(QStringLiteral("answer1"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(answer1->sizePolicy().hasHeightForWidth());
        answer1->setSizePolicy(sizePolicy);
        horizontalLayout->addWidget(answer1);
        answer2 = new QCheckBox(foreGround);
        answer2->setObjectName(QStringLiteral("answer2"));
        sizePolicy.setHeightForWidth(answer2->sizePolicy().hasHeightForWidth());
        answer2->setSizePolicy(sizePolicy);
        horizontalLayout->addWidget(answer2);
        answer3 = new QCheckBox(foreGround);
        answer3->setObjectName(QStringLiteral("answer3"));
        sizePolicy.setHeightForWidth(answer3->sizePolicy().hasHeightForWidth());
        answer3->setSizePolicy(sizePolicy);
        horizontalLayout->addWidget(answer3);
        verticalLayout->addLayout(horizontalLayout);
        quitButton = new QPushButton(foreGround);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        verticalLayout->addWidget(quitButton);
        verticalLayout_2->addWidget(foreGround);
        MainWindow->setCentralWidget(backGround);
        retranslateUi(MainWindow);
        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        startButton->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        answer1->setText(QString("a"));
        answer2->setText(QString("b"));
        answer3->setText(QString("c"));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        quitButton->setShortcut(QApplication::translate("MainWindow", "Esc", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
