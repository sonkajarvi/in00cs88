#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

enum class State
{
    None,
    Num1,
    Op,
    Num2,
    Result
};

enum class Operand
{
    None,
    Add,
    Sub,
    Mul,
    Div
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void clear();

    bool m_has_dot_already = false;
    State m_state = State::None;
    Operand m_operand = Operand::None;

    QWidget *m_ui;
    QGridLayout *m_layout;
    QLabel *m_num1_label, *m_num2_label, *m_result_label;
    QLineEdit *m_num1, *m_num2, *m_res;
    QPushButton *m_n0, *m_n1, *m_n2, *m_n3, *m_n4, *m_n5, *m_n6, *m_n7, *m_n8, *m_n9;
    QPushButton *m_add, *m_sub, *m_mul, *m_div, *m_dot, *m_sign;
    QPushButton *m_enter, *m_clear;
};

#endif // MAINWINDOW_H
