#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    size_t m_number = 0;
    QWidget *m_ui;
    QGridLayout *m_layout;
    QLineEdit *m_display;
    QPushButton *m_count, *m_reset;
};

#endif // MAINWINDOW_H
