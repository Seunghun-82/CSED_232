#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_watch = new QTimer(this);
    timer_timer = new QTimer(this);
    timer_stopwatch = new QTimer(this);

    on_tabWidget_tabBarClicked(0);

    stopwatch = 0;

    timer_hour = 0;
    timer_minute = 0;
    timer_second = 0;

    mmsec = 0;
    second = 0;
    minute = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    QDateTime time = QDateTime::currentDateTime();
    QString time_text = time.toString("hh : mm : ss A");
    QString date_text = time.toString("ddd , MMMM dd , yyyy");
    ui->label->setText((time_text));
    ui->label_2->setText((date_text));
    ui->tab->show();
}

void MainWindow::update_time()
{
    mmsec++;
    if(mmsec == 100)
    {
        mmsec = mmsec - 100;
        second++;
    }
    if(second == 60)
    {
        second = second - 60;
        minute++;
    }
    if(minute == 60)
    {
        resetClicked();
    }
    QString text = QString("%1 : %2 . %3 ").arg(minute).arg(second).arg(mmsec);
    ui->stop_watch->setText(text);
    ui->tab_2->show();

}

void MainWindow::stopClicked()
{
    timer_stopwatch->stop();
    disconnect(timer_stopwatch, SIGNAL(timeout()),this, SLOT(update_time()));
}

void MainWindow::resetClicked()
{

    minute = 0;
    second = 0;
    mmsec = 0;

    QString stop_text;
    stop_text = QString("%1 : %2 . %3 ").arg(minute).arg(second).arg(mmsec);
    ui->stop_watch->setText(stop_text);

    ui->tab_2->show();
    timer_stopwatch->stop();
    disconnect(timer_stopwatch, SIGNAL(timeout()),this, SLOT(update_time()));
}

void MainWindow::startClicked()
{
    disconnect(timer_stopwatch, SIGNAL(timeout()),this, SLOT(update_time()));
    connect(timer_stopwatch, SIGNAL(timeout()),this, SLOT(update_time()));
    timer_stopwatch->start(10);
}

void MainWindow::on_Watch_button_clicked()
{
    timer_timer->stop();
    timer_stopwatch->stop();
    connect (timer_watch, SIGNAL(timeout()),this,SLOT(myfunction()));
    timer_watch->start(1000);
}

void MainWindow::alram_on()
{
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/alarm.wav"));
    player->setVolume(100);
    player->play();
}

void MainWindow::timer_update()
{
    timer_second = timer_second - 1;
    if(timer_second <= -1)
    {
        timer_second = 59;
        timer_minute = timer_minute - 1;
    }
    if(timer_minute <= -1)
    {
        timer_minute = 59;
        timer_hour = timer_hour - 1;
    }
    if(timer_hour == 0 && timer_minute == 0 && timer_second == 0)
    {
        alram_on();
        timer_resetClicked();
    }

    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();
}

void MainWindow::timer_hour_upClicked()
{
    timer_hour++;
    if(timer_hour == 24)
    {
        timer_hour = 0;
    }

    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();

}

void MainWindow::timer_hour_downClicked()
{
    timer_hour--;
    if(timer_hour == -1)
    {
        timer_hour = 23;
    }

    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();
}

void MainWindow::timer_min_upClicked()
{
    timer_minute++;
    if(timer_minute == 60)
    {
        timer_minute = 0;
    }

    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();
}

void MainWindow::timer_min_downClicked()
{
    timer_minute--;
    if(timer_minute == -1)
    {
        timer_minute = 59;
    }

    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();
}

void MainWindow::timer_sec_upClicked()
{
    timer_second++;
    if(timer_second == 60)
    {
        timer_second = 0;
    }

    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();
}

void MainWindow::timer_sec_downClicked()
{
    timer_second = timer_second - 1;
    if(timer_second == -1)
    {
        timer_second = 59;
    }

    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();
}

void MainWindow::timer_startClicked()
{
    if(timer_hour == 0 && timer_minute == 0 && timer_second == 0)
    {

    }
    else
    {
    disconnect(timer_timer, SIGNAL(timeout()), this, SLOT(timer_update()));
    timer_timer->start(1000);
    connect(timer_timer, SIGNAL(timeout()), this, SLOT(timer_update()));
    }
}

void MainWindow::timer_stopClicked()
{
    timer_timer->stop();
    disconnect(timer_timer, SIGNAL(timeout()), this, SLOT(timer_update()));
}

void MainWindow::timer_resetClicked()
{

    timer_minute = 0;
    timer_second = 0;
    timer_hour = 0;


    QString stop_text;
    stop_text = QString("%1 : %2 : %3").arg(timer_hour).arg(timer_minute).arg(timer_second);
    ui->label_3->setText(stop_text);

    ui->tab_3->show();

    timer_timer->stop();

    disconnect(timer_timer, SIGNAL(timeout()), this, SLOT(timer_update()));

}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0)
    {
        disconnect(timer_timer, SIGNAL(timeout()), this, SLOT(timer_update()));
        disconnect (timer_watch, SIGNAL(timeout()),this,SLOT(myfunction()));
        disconnect(timer_stopwatch, SIGNAL(timeout()),this, SLOT(update_time()));
        timer_timer->stop();
        timer_stopwatch->stop();
        connect (timer_watch, SIGNAL(timeout()),this,SLOT(myfunction()));
        QDateTime time = QDateTime::currentDateTime();
        QString time_text = time.toString("hh : mm : ss A");
        QString date_text = time.toString("ddd , MMMM dd , yyyy");
        ui->label->setText((time_text));
        ui->label_2->setText((date_text));
        ui->tab->show();
        timer_watch->start(1000);
    }
    else if(index == 1)
    {
        disconnect(timer_timer, SIGNAL(timeout()), this, SLOT(timer_update()));
        disconnect (timer_watch, SIGNAL(timeout()),this,SLOT(myfunction()));
        disconnect(timer_stopwatch, SIGNAL(timeout()),this, SLOT(update_time()));
        disconnect(ui->pushButton, SIGNAL(clicked()),this,SLOT(startClicked()));
        disconnect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(stopClicked()));
        disconnect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(resetClicked()));
        timer_watch->stop();
        timer_timer->stop();

        QString text = QString("%1 : %2 . %3 ").arg(minute).arg(second).arg(mmsec);
        ui->stop_watch->setText(text);
        ui->tab_2->show();

        connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(startClicked()));
        connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(stopClicked()));
        connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(resetClicked()));

    }
    else
    {
        disconnect(timer_stopwatch, SIGNAL(timeout()),this, SLOT(update_time()));
        disconnect(timer_watch, SIGNAL(timeout()),this,SLOT(myfunction()));
        disconnect(timer_timer, SIGNAL(timeout()), this, SLOT(timer_update()));
        disconnect(ui->pushButton_10, SIGNAL(clicked()),this,SLOT(timer_startClicked()));
        disconnect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(timer_stopClicked()));
        disconnect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(timer_resetClicked()));
        disconnect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(timer_hour_upClicked()));
        disconnect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(timer_min_upClicked()));
        disconnect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(timer_sec_upClicked()));
        disconnect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(timer_hour_downClicked()));
        disconnect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(timer_min_downClicked()));
        disconnect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(timer_sec_downClicked()));
        timer_watch->stop();
        timer_stopwatch->stop();

        QString text = QString("%1 : %2 . %3 ").arg(timer_hour).arg(timer_minute).arg(timer_minute);
        ui->label_3->setText(text);
        ui->tab_3->show();

        connect(ui->pushButton_10, SIGNAL(clicked()),this,SLOT(timer_startClicked()));
        connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(timer_stopClicked()));
        connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(timer_resetClicked()));
        connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(timer_hour_upClicked()));
        connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(timer_min_upClicked()));
        connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(timer_sec_upClicked()));
        connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(timer_hour_downClicked()));
        connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(timer_min_downClicked()));
        connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(timer_sec_downClicked()));


    }
}
