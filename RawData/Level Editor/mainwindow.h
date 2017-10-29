#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString filename = "", QWidget *parent = 0);
    ~MainWindow();
public slots:
    void nextLevel();
private:
    Ui::MainWindow *ui;
    QFile *file;
};

#endif // MAINWINDOW_H
