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

private:
    Ui::MainWindow *ui;
signals:
    void quit();//退出信号
    void showdetail();//显示主窗口信号
    void showchoose();
private slots:
    //与login中发射的信号关联的槽函数
    void on_MainWindow_mainshow();
    void choosereset();
    void on_action_5_triggered();
    void on_action_6_triggered();
    void on_action_7_triggered();
    void on_action_2_triggered();
    void on_action_triggered();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_action_3_triggered();
    void on_building_clicked(const QModelIndex &index);
    void on_block_activated(const QModelIndex &index);
    void on_block_clicked(const QModelIndex &index);
};
#endif // MAINWINDOW_H
