#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString filename, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file = new QFile(filename);
    file->open(QIODevice::Append|QIODevice::Text);
    connect(ui->nextLevelButton, SIGNAL(clicked(bool)), this, SLOT(nextLevel()));
}

MainWindow::~MainWindow()
{
    delete ui;
    QFile programm("./LevelMaker");
    programm.remove();
    file->close();
}

void MainWindow::nextLevel()
{
    QByteArray level;
    level.append(ui->metaDataWidget->timeEdit->text()+"|"+\
                 ui->metaDataWidget->backGroundFileEdit->text()+"|"+\
                 ui->metaDataWidget->audioFileEdit->text()+"|");
    for(int i = 0; i < ui->textWidgets.size(); i++){
        level.append(ui->textWidgets.at(i)->fontComboBox->currentText()+"-"+\
                     ui->textWidgets.at(i)->textColor.name()+"-"+\
                     QString::number(ui->textWidgets.at(i)->textSizeSpinBox->value())+"-"+\
                     QString::number(ui->textWidgets.at(i)->timeSpinBox->value())+"-"+\
                     QString::number(ui->textWidgets.at(i)->alphaSpinBox->value())+":");
    }
    level.remove(level.size()-1, 1);
    level.append(";");
    for(int i = 0; i < ui->textWidgets.size(); i++){
        level.append(ui->textWidgets.at(i)->input->text()+"|");
    }
    level.remove(level.size()-1, 1);
    level.append(";");
    for(int i = 0; i < ui->questionWidgets.size(); i++){
        level.append(ui->questionWidgets.at(i)->question->text()+"(");
        level.append(ui->questionWidgets.at(i)->answer1->text()+":");
        level.append(ui->questionWidgets.at(i)->answer2->text()+":");
        level.append(ui->questionWidgets.at(i)->answer3->text()+")"+"|");
    }
    level.remove(level.size()-1, 1);
    qDebug()<<level;
    file->write(level);
}









