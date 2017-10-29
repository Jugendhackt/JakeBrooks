#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QPixmap>
int i = 0, idx = 0;
bool start = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->answer1->hide();
    ui->answer2->hide();
    ui->answer3->hide();
    ui->answer1->setCheckable(true);
    ui->answer2->setCheckable(true);
    ui->answer3->setCheckable(true);
    levelReader = new LevelReader("levels.csv");
    gameTimer = new QTimer(this);
    connect(gameTimer, SIGNAL(timeout()), this , SLOT(gametick()));
    myThread = new QThread(this);
    this->moveToThread(myThread);
    ui->foreGround->setText("hallo");
    ui->backGround->setPixmap(QPixmap::fromImage(QImage("./Textures/startscreen.png").scaled(width(), height())));
    ui->quitButton->setStyleSheet("background: darkgray");
    ui->startButton->setStyleSheet("background: darkgray");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playLevel()
{
    if(!levelReader->isEOF()){
        levelReader->readLevel(index);
        qDebug()<<"read succsesfull"<<levelReader->getListsize();
        QString background = levelReader->background, audio = levelReader->audio;
        qDebug()<<background<<endl<<audio;
        ui->backGround->setPixmap(QPixmap::fromImage(QImage(background.toLatin1().data()).scaled(width(), height())));
        music = new QSound(audio.toLatin1().data(), this);
        music->play();
        gameTimer->start(100);
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

void MainWindow::lost()
{
    qDebug()<<"verloren\n\n\n"<<endl<<endl;
}
void MainWindow::gametick()
{
    i++;
    if(modus == text){
        if(i%10==0){
            if(idx < levelReader->getListsize()){
                QFont font = levelReader->formatLAt(idx).font;
                QString text = levelReader->textLAt(idx);
                double size = levelReader->formatLAt(idx).textsize;
                QColor textcolor(levelReader->formatLAt(idx).color.name());
                textcolor.setAlpha(levelReader->formatLAt(idx).alpha);
                QPalette p(ui->foreGround->palette());
                p.setColor(QPalette::WindowText, textcolor);
                font.setPointSize(size);
                ui->foreGround->setFont(font);
                ui->foreGround->setPalette(p);
                ui->foreGround->setText(text);
                qDebug()<<levelReader->formatLAt(idx).time<<i;
                if(levelReader->formatLAt(idx).time*10 <= i){
                    idx++;
                    i = 0;
                    qDebug()<<"next";
                }
                qDebug()<<text<<font<<textcolor<<p<<endl<<i<<endl;
                ui->foreGround->repaint();
            }
            else if(!levelReader->questionList.isEmpty()){
                modus = quest;
                idx = 0;
                i = 99;
            }
            else{
                gameTimer->stop();
                start = false;
                modus = text;
                i = 0;
                idx = 0;
                music->stop();
                qDebug()<<"next Level";
                playLevel();
            }
        }
    }
    else if(modus == quest){
        if(i%50==0){
            qDebug()<<idx << levelReader->getQListsize();
            if(idx < levelReader->getQListsize()){
                if(start){
                    qDebug()<<"123"<<levelReader->questionLAt(idx).a1<<levelReader->questionLAt(idx).a2<<levelReader->questionLAt(idx).a3;
                    ui->answer1->show();
                    ui->answer2->show();
                    ui->answer3->show();
                    QFont font;
                    font.setPointSize(30);
                    QPalette p(ui->foreGround->palette());
                    p.setColor(QPalette::WindowText, QColor(Qt::white));
                    ui->foreGround->setFont(font);
                    ui->foreGround->setText(levelReader->questionLAt(idx).question);
                    ui->answer1->setText(levelReader->questionLAt(idx).a1);
                    ui->answer2->setText(levelReader->questionLAt(idx).a2);
                    ui->answer3->setText(levelReader->questionLAt(idx).a3);
                    start = false;
                }
            }
            else{
                gameTimer->stop();
                start = false;
                modus = text;
                i = 0;
                idx = 0;
                music->stop();
                qDebug()<<"next Level";
                playLevel();
            }
        }
        if(!start){
            if(ui->answer1->isChecked() && !levelReader->questionLAt(idx).a1.isEmpty()){
                index +=1;
                idx +=1;
                start = true;
                ui->answer1->setChecked(false);
                ui->answer1->hide();
            }
            else if(ui->answer2->isChecked() && !levelReader->questionLAt(idx).a2.isEmpty()){
                index +=2;
                idx +=1;
                start = true;
                ui->answer2->setChecked(false);
                ui->answer2->hide();
            }
            else if(ui->answer3->isChecked() && !levelReader->questionLAt(idx).a3.isEmpty()){
                index +=3;
                idx +=1;
                start = true;
                ui->answer3->setChecked(false);
                ui->answer3->hide();
            }
        }
        qDebug()<<start;
    }
}

















