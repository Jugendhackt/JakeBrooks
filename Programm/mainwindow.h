#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QSound>
#include <QTimer>
#include <QThread>
#include "levelreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void playLevel();

private slots:
    void on_quitButton_clicked();
    void on_startButton_clicked();
    void displayText();
    void lost();
private:

    QThread *myThread;
    int index = 1;
    Ui::MainWindow *ui;
    LevelReader *levelReader;
    QTimer *gameTimer;
    QSound *music;

};

#endif // MAINWINDOW_H
