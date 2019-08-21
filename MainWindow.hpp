#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QPushButton* btn_open  = nullptr;
    QPushButton* btn_close = nullptr;

public:

    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

};

#endif // MAIN_WINDOW_HPP
