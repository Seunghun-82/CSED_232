#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QMediaPlayer>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int stopwatch;
    int minute;
    int second;
    int mmsec;
    void alram_on();

private slots:
    void myfunction();
    void on_Watch_button_clicked();
    void startClicked();
    void stopClicked();
    void resetClicked();
    void update_time();

    void timer_startClicked();
    void timer_stopClicked();
    void timer_resetClicked();
    void timer_hour_upClicked();
    void timer_min_upClicked();
    void timer_sec_upClicked();
    void timer_hour_downClicked();
    void timer_min_downClicked();
    void timer_sec_downClicked();
    void timer_update();
    void on_tabWidget_tabBarClicked(int index);

signals:
void destroyed ( QObject * obj = 0 );

private:
    Ui::MainWindow *ui;
    QTimer *timer_watch;
    QTimer *timer_stopwatch;
    QTimer *timer_timer;
    QMediaPlayer* player;

    int timer_hour;
    int timer_minute;
    int timer_second;

};
#endif // MAINWINDOW_H
