#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int hour=0;
    int min=0;
    int sec=0;
    QTimer* timer1=new QTimer;

    void reflesh();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void timer_count();
    void on_StartButton_clicked();
    void on_ResetButton_clicked();
    void on_HourBox_valueChanged(int arg1);
    void on_MinuteBox_valueChanged(int arg1);
    void on_SecBox_valueChanged(int arg1);
};

#endif // MAINWINDOW_H
