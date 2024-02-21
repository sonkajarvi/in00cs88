#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

enum class State
{
    Selecting,
    Playing,
    Paused
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // void begin_game();
    void end_game();
    void update_clock_and_progress_bars();
    virtual void timerEvent(QTimerEvent *event) override;

    unsigned m_player1_time = 0;
    unsigned m_player2_time = 0;
    unsigned m_total_time = 0;
    unsigned m_current_player = 0;
    State m_state = State::Selecting;
    int m_timer_id = 0;

    QWidget *m_main_widget;
    QGridLayout *m_layout;

    QLabel *m_status;
    QLabel *m_clock;
    QPushButton *m_start;
    QPushButton *m_stop;
    QPushButton *m_short;
    QLineEdit *m_custom;
    QPushButton *m_long;
    QPushButton *m_switch_player1;
    QPushButton *m_switch_player2;
    QProgressBar *m_player1_progress;
    QProgressBar *m_player2_progress;
};
