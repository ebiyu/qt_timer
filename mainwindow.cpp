#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(timer1,SIGNAL(timeout()),this,SLOT(timer_count()));

    reflesh();
}

void MainWindow::timer_count(){
    sec--;
    if(sec<0){
        sec=59;
        min--;
        if(min<0){
            min=59;
            hour--;
            if(hour<0){
                sec=min=hour=0;
                timer1->stop();
            }

        }
    }
    reflesh();
}

void MainWindow::reflesh(){
    ui->lcdNumber->display(QString::number(hour).rightJustified(2,'0')+':'
                           +QString::number(min).rightJustified(2,'0')+':'
                           +QString::number(sec).rightJustified(2,'0'));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartButton_clicked()
{
    if(ui->StartButton->text()=="Start"){
        timer1->start(1000);
        ui->StartButton->setText("Stop");
        ui->ResetButton->setEnabled(false);
    }else{
        timer1->stop();
        ui->StartButton->setText("Start");
        ui->ResetButton->setEnabled(true);
    }
    reflesh();
}

void MainWindow::on_ResetButton_clicked()
{
    hour=ui->HourBox->value();
    min=ui->MinuteBox->value();
    sec=ui->SecBox->value();
    reflesh();
}

void MainWindow::on_HourBox_valueChanged(int arg1)
{
    hour=ui->HourBox->value();
    reflesh();
}

void MainWindow::on_MinuteBox_valueChanged(int arg1)
{
    min=ui->MinuteBox->value();
    reflesh();
}

void MainWindow::on_SecBox_valueChanged(int arg1)
{
    sec=ui->SecBox->value();
    reflesh();
}
