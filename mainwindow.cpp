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
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(gameTimer_timeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playLevel()
{
    //while(!levelReader->isEOF()){
        levelReader->readLevel(1);
        ui->backGround->setPixmap(QPixmap::fromImage(QImage(levelReader->background)));
    //}
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

void MainWindow::gameTimer_timeout()
{

}














