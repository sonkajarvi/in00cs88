#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_ui = new QWidget();
    m_display = new QLineEdit("0");
    m_display->setReadOnly(true);

    m_count = new QPushButton("Count");
    connect(m_count, &QPushButton::clicked, this, [&]() {
        m_number++;
        m_display->setText(QString::number(m_number));
    });

    m_reset = new QPushButton("Reset");
    connect(m_reset, &QPushButton::clicked, this, [&]() {
        m_number = 0;
        m_display->setText(QString::number(m_number));
    });

    m_layout = new QGridLayout();
    m_layout->setSizeConstraint(QLayout::SetFixedSize);
    m_layout->addWidget(m_display, 0, 1, 1, 1);
    m_layout->addWidget(m_count, 0, 0, 1, 1);
    m_layout->addWidget(m_reset, 1, 0, 1, 1);

    m_ui->setLayout(m_layout);
    setCentralWidget(m_ui);
}

MainWindow::~MainWindow()
{
    delete m_count;
    delete m_reset;
    delete m_display;
    delete m_layout;
    delete m_ui;
}
