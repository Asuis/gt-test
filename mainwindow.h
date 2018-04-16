#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_0_clicked();

    void on_Button_6_clicked();

    void on_Button_5_clicked();

    void on_Button_4_clicked();

    void on_Button_9_clicked();

    void on_Button_8_clicked();

    void on_Button_7_clicked();

    void on_Button_dot_clicked();

    void on_Button_mod_clicked();

    void on_Button_div_clicked();

    void on_Button_mul_clicked();

    void on_Button_m_clicked();

    void on_Button_add_clicked();

    void on_Button_left_c_clicked();

    void on_Button_rigth_c_clicked();

    void on_Button_pow2_clicked();

    void on_Button_sq_clicked();

    void on_Button_eq_clicked();

    void on_Button_back_clicked();

    void on_Button_ac_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
