#include "mainwindow.h"

#include <QIntValidator>

#define STATUS_SELECT "Select playtime and press start game!"
#define STATUS_PLAYING "Game ongoing"
#define STATUS_PAUSED "Game paused"
#define STATUS_P1_WON "Player 1 WON!!"
#define STATUS_P2_WON "Player 2 WON!!"
#define BTN_START "START GAME"
#define BTN_PAUSE "PAUSE GAME"
#define BTN_STOP "STOP GAME"
#define BTN_CONTINUE "CONTINUE GAME"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_layout = new QGridLayout();

    // Progress bars and clock
    m_player1_progress = new QProgressBar();
    m_player1_progress->setValue(0);
    m_player1_progress->setEnabled(false);
    m_layout->addWidget(m_player1_progress, 0, 0);
    
    m_player2_progress = new QProgressBar();
    m_player2_progress->setValue(0);
    m_player2_progress->setEnabled(false);
    m_layout->addWidget(m_player2_progress, 0, 4);

    m_clock = new QLabel("- : -");
    m_clock->setAlignment(Qt::AlignmentFlag::AlignCenter);
    m_layout->addWidget(m_clock, 0, 2);

    // Switch players
    m_switch_player1 = new QPushButton("Switch player");
    m_switch_player1->setMinimumSize(QSize(100, 50));
    m_switch_player1->setEnabled(false);
    connect(m_switch_player1, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Playing) {
            // Switch current player and disable the button
            m_current_player = 2;
            m_switch_player1->setEnabled(false);
            m_switch_player2->setEnabled(true);
        }
    });
    m_layout->addWidget(m_switch_player1, 1, 0);

    m_switch_player2 = new QPushButton("Switch player");
    m_switch_player2->setMinimumSize(QSize(100, 50));
    m_switch_player2->setEnabled(false);
    connect(m_switch_player2, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Playing) {
            // Switch current player and disable the button
            m_current_player = 1;
            m_switch_player2->setEnabled(false);
            m_switch_player1->setEnabled(true);
        }
    });
    m_layout->addWidget(m_switch_player2, 1, 4);

    // Status
    m_status = new QLabel(STATUS_SELECT);
    m_status->setAlignment(Qt::AlignmentFlag::AlignCenter);
    setStyleSheet("QLabel{font-size:18pt;}");
    m_layout->addWidget(m_status, 2, 2);

    // Select playtime
    m_short = new QPushButton("120 sec");
    connect(m_short, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Selecting) {
            m_player1_time = 120;
            m_player2_time = 120;
            m_total_time = 120;
            m_start->setEnabled(true);
            update_clock_and_progress_bars();
        }
    });
    m_layout->addWidget(m_short, 3, 1);

    m_custom = new QLineEdit("");
    m_custom->setValidator(new QIntValidator(1, 99999, this));
    connect(m_custom, &QLineEdit::textChanged, this, [&]() {
        if (m_state == State::Selecting) {
            m_player1_time = m_custom->text().toInt();
            m_player2_time = m_custom->text().toInt();
            m_total_time = m_custom->text().toInt();
            m_start->setEnabled(true);

            if (!m_custom->text().isEmpty())
                update_clock_and_progress_bars();
        }
    });
    m_layout->addWidget(m_custom, 3, 2);

    m_long = new QPushButton("5 min");
    connect(m_long, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Selecting) {
            m_player1_time = 300;
            m_player2_time = 300;
            m_total_time = 300;
            m_start->setEnabled(true);
            update_clock_and_progress_bars();
        }
    });
    m_layout->addWidget(m_long, 3, 3);

    // Start and stop buttons
    m_start = new QPushButton(BTN_START);
    m_start->setMinimumSize(QSize(100, 50));
    m_start->setEnabled(false);
    connect(m_start, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Selecting) {
            // Start timer and enable widgets
            m_timer_id = startTimer(1000);

            m_player1_progress->setEnabled(true);
            m_player2_progress->setEnabled(true);
            m_switch_player1->setEnabled(true);

            m_state = State::Playing;
            m_current_player = 1;
            update_clock_and_progress_bars();

            m_start->setEnabled(false);
            m_stop->setEnabled(true);
            m_short->setEnabled(false);
            m_custom->setEnabled(false);
            m_long->setEnabled(false);
        }
        else if (m_state == State::Paused) {
            m_state = State::Playing;

            m_start->setEnabled(false);
            m_stop->setText(BTN_PAUSE);
        }
        m_status->setText(STATUS_PLAYING);
    });
    m_layout->addWidget(m_start, 4, 1);

    m_stop = new QPushButton(BTN_PAUSE);
    m_stop->setMinimumSize(QSize(100, 50));
    m_stop->setEnabled(false);
    connect(m_stop, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Playing) {
            // Enable start button and change its text
            m_start->setEnabled(true);
            m_start->setText(BTN_CONTINUE);

            m_stop->setText(BTN_STOP);

            m_state = State::Paused;
            m_status->setText(STATUS_PAUSED);
        }
        else if (m_state == State::Paused) {
            m_status->setText("Game stopped. " STATUS_SELECT);
            end_game();
        }
    });
    m_layout->addWidget(m_stop, 4, 3);

    m_main_widget = new QWidget();
    m_main_widget->setLayout(m_layout);
    setCentralWidget(m_main_widget);
    setMinimumHeight(500);
}

MainWindow::~MainWindow()
{
    if (m_timer_id)
        killTimer(m_timer_id);

    delete m_status;
    delete m_clock;
    delete m_start;
    delete m_stop;
    delete m_short;
    delete m_custom;
    delete m_long;
    delete m_switch_player1;
    delete m_switch_player2;
    delete m_player1_progress;
    delete m_player2_progress;

    delete m_layout;
    delete m_main_widget;
}

void MainWindow::end_game()
{
    m_state = State::Selecting;

    m_stop->setEnabled(false);
    m_stop->setText(BTN_PAUSE);
    m_start->setEnabled(false);
    m_start->setText(BTN_START);

    m_switch_player1->setEnabled(false);
    m_switch_player2->setEnabled(false);

    m_short->setEnabled(true);
    m_custom->setEnabled(true);
    m_long->setEnabled(true);

    killTimer(m_timer_id);
    m_timer_id = 0;
}

void MainWindow::update_clock_and_progress_bars()
{
    m_clock->setText(QString::number(m_player1_time) + " : " + QString::number(m_player2_time));

    int p1 = 100 * m_player1_time / m_total_time;
    m_player1_progress->setValue(p1);

    int p2 = 100 * m_player2_time / m_total_time;
    m_player2_progress->setValue(p2);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (m_state == State::Playing) {
        if (m_current_player == 1) {
            m_player1_time--;

            if (m_player1_time == 0) {
                m_status->setText(STATUS_P2_WON);
                end_game();
            }
        }
        else {
            m_player2_time--;

            if (m_player2_time == 0) {
                m_status->setText(STATUS_P1_WON);
                end_game();
            }
        }

        update_clock_and_progress_bars();
    }
}
