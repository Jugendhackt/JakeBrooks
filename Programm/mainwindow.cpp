#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->answer1->hide();
    ui->answer2->hide();
    ui->answer3->hide();
    levelReader = new LevelReader("levels.csv");
    gameTimer = new QTimer(this);
    myThread = new QThread(this);
    this->moveToThread(myThread);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playLevel()
{
    while(!levelReader->isEOF()){
        levelReader->readLevel(index);
        qDebug()<<"read succsesfull"<<levelReader->getListsize();
        ui->backGround->setPixmap(QPixmap::fromImage(QImage(levelReader->background)));
        music = new QSound(levelReader->audio, this);
        music->play();
        for(int i =0; i < levelReader->getListsize(); i++){
            QFont font = levelReader->formatLAt(i).font;
            QString color = levelReader->formatLAt(i).color.name();
            QString text = levelReader->textLAt(i);
            ui->foreGround->setFont(font);
            QColor textcolor(color);
            textcolor.setAlpha(levelReader->formatLAt(i).alpha);
            QPalette p(ui->foreGround->palette());
            p.setColor(QPalette::Text, textcolor);
            ui->foreGround->setPalette(p);
            ui->foreGround->setText(text);
            int pause = levelReader->formatLAt(i).time*1000;
            qDebug()<<font<<color<<text<<p;
            qDebug()<<"Pause:"<<pause;
            myThread->msleep(pause);
        }
        for(int i =0; i < levelReader->getQListsize(); i++){
            ui->answer1->show();
            ui->answer2->show();
            ui->answer3->show();
            ui->foreGround->setText(levelReader->questionLAt(i).question);
            ui->answer1->setText(levelReader->questionLAt(i).a1);
            ui->answer2->setText(levelReader->questionLAt(i).a2);
            ui->answer3->setText(levelReader->questionLAt(i).a3);
            myThread->msleep(15000);
            if(ui->answer1->isChecked())
                index +=1;
            else if(ui->answer1->isChecked())
                index +=2;
            else if(ui->answer1->isChecked())
                index +=3;
            else
                lost();
        }
    }
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->hide();
    playLevel();
}

void MainWindow::on_quitButton_clicked()
{
    qApp->quit();
}

void MainWindow::displayText()
{

}

void MainWindow::lost()
{

}
















