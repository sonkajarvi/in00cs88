#include "mainwindow.h"

#define SET_NUM_CLICKED(btn, n)                                     \
    connect(btn, &QPushButton::clicked, this, [&]() {               \
        if (m_state == State::Result) { clear(); }                  \
        if (m_state == State::Op) {                                 \
            m_state = State::Num2;                                  \
            m_has_dot_already = false;                              \
        } if (m_state == State::Num1) {                             \
            m_num1->setText(m_num1->text() + QString::number(n));   \
        } else if (m_state == State::Num2) {                        \
            m_num2->setText(m_num2->text() + QString::number(n));   \
    }})

#define SET_OP_CLICKED(btn, op)                                     \
    connect(btn, &QPushButton::clicked, this, [&]() {               \
        if (m_state == State::Num1 || m_state == State::Op) {       \
            m_operand = op;                                         \
            m_state = State::Op;                                    \
        } else if (m_state == State::Num2) {                        \
            m_operand = op;                                         \
        }})

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_num1_label = new QLabel("Number 1");
    m_num2_label = new QLabel("Number 2");
    m_result_label = new QLabel("Result");

    m_num1 = new QLineEdit("");
    m_num2 = new QLineEdit("");
    m_res = new QLineEdit("");
    m_num1->setReadOnly(true);
    m_num2->setReadOnly(true);
    m_res->setReadOnly(true);

    m_n0 = new QPushButton("0");
    m_n1 = new QPushButton("1");
    m_n2 = new QPushButton("2");
    m_n3 = new QPushButton("3");
    m_n4 = new QPushButton("4");
    m_n5 = new QPushButton("5");
    m_n6 = new QPushButton("6");
    m_n7 = new QPushButton("7");
    m_n8 = new QPushButton("8");
    m_n9 = new QPushButton("9");
    
    m_add = new QPushButton("+");
    m_sub = new QPushButton("-");
    m_mul = new QPushButton("*");
    m_div = new QPushButton("/");
    m_dot = new QPushButton(".");
    m_sign = new QPushButton("+-");

    m_enter = new QPushButton("enter");
    m_clear = new QPushButton("clear");

    m_layout = new QGridLayout();
    m_layout->addWidget(m_num1_label, 0, 0, 1, 1);
    m_layout->addWidget(m_num2_label, 0, 1, 1, 1);
    m_layout->addWidget(m_result_label, 0, 2, 1, 1);

    m_layout->addWidget(m_num1, 1, 0, 1, 1);
    m_layout->addWidget(m_num2, 1, 1, 1, 1);
    m_layout->addWidget(m_res, 1, 2, 1, 1);

    m_layout->addWidget(m_n1, 2, 0, 1, 1);
    SET_NUM_CLICKED(m_n1, 1);
    m_layout->addWidget(m_n2, 2, 1, 1, 1);
    SET_NUM_CLICKED(m_n2, 2);
    m_layout->addWidget(m_n3, 2, 2, 1, 1);
    SET_NUM_CLICKED(m_n3, 3);
    m_layout->addWidget(m_add, 0, 3, 1, 1);
    SET_OP_CLICKED(m_add, Operand::Add);

    m_layout->addWidget(m_n4, 3, 0, 1, 1);
    SET_NUM_CLICKED(m_n4, 4);
    m_layout->addWidget(m_n5, 3, 1, 1, 1);
    SET_NUM_CLICKED(m_n5, 5);
    m_layout->addWidget(m_n6, 3, 2, 1, 1);
    SET_NUM_CLICKED(m_n6, 6);
    m_layout->addWidget(m_sub, 1, 3, 1, 1);
    SET_OP_CLICKED(m_sub, Operand::Sub);

    m_layout->addWidget(m_n7, 4, 0, 1, 1);
    SET_NUM_CLICKED(m_n7, 7);
    m_layout->addWidget(m_n8, 4, 1, 1, 1);
    SET_NUM_CLICKED(m_n8, 8);
    m_layout->addWidget(m_n9, 4, 2, 1, 1);
    SET_NUM_CLICKED(m_n9, 9);
    m_layout->addWidget(m_mul, 2, 3, 1, 1);
    SET_OP_CLICKED(m_mul, Operand::Mul);

    m_layout->addWidget(m_n0, 5, 0, 1, 1);
    SET_NUM_CLICKED(m_n0, 0);
    m_layout->addWidget(m_clear, 5, 1, 1, 1);
    connect(m_clear, &QPushButton::clicked, this, [&]() {
        clear();
    });
    m_layout->addWidget(m_enter, 5, 2, 1, 1);
    connect(m_enter, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Num2) {
            double num1_f = m_num1->text().toDouble();
            double num2_f = m_num2->text().toDouble();
            double result = 0;
            switch (m_operand) {
                case Operand::Add:
                    result = num1_f + num2_f;
                    break;
                case Operand::Sub:
                    result = num1_f - num2_f;
                    break;
                case Operand::Mul:
                    result = num1_f * num2_f;
                    break;
                case Operand::Div:
                    result = num1_f / num2_f;
                    break;
                default:
                    break;
            }
            m_res->setText(QString::number(result, 'f'));
            m_state = State::Result;
        }
    });
    m_layout->addWidget(m_div, 3, 3, 1, 1);
    SET_OP_CLICKED(m_div, Operand::Div);

    m_layout->addWidget(m_dot, 4, 3, 1, 1);
    connect(m_dot, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Num1 || m_state == State::Num2) {
            if (m_has_dot_already) return;
            else {
                if (m_state == State::Num1) {
                    m_num1->setText(m_num1->text() + ".");
                } else if (m_state == State::Num2) {
                    m_num2->setText(m_num2->text() + ".");
                }
                m_has_dot_already = true;
            }
        }
    });

    m_layout->addWidget(m_sign, 5, 3, 1, 1);
    connect(m_sign, &QPushButton::clicked, this, [&]() {
        if (m_state == State::Num1) {
            m_num1->setText(QString::number(m_num1->text().toDouble() * -1));
        } else if (m_state == State::Num2) {
            m_num2->setText(QString::number(m_num2->text().toDouble() * -1));
        }
    });

    m_ui = new QWidget();
    m_ui->setLayout(m_layout);
    setCentralWidget(m_ui);

    m_state = State::Num1;
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_layout;

    delete m_num1_label;
    delete m_num2_label;
    delete m_result_label;

    delete m_num1;
    delete m_num2;
    delete m_res;

    delete m_n0;
    delete m_n1;
    delete m_n2;
    delete m_n3;
    delete m_n4;
    delete m_n5;
    delete m_n6;
    delete m_n7;
    delete m_n8;
    delete m_n9;

    delete m_add;
    delete m_sub;
    delete m_mul;
    delete m_div;
    delete m_dot;
    delete m_sign;

    delete m_enter;
    delete m_clear;
}

void MainWindow::clear()
{
    m_num1->clear();
    m_num2->clear();
    m_res->clear();
    m_state = State::Num1;
    m_has_dot_already = false;
}
