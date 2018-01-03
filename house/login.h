#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
signals:
    void showmainwindow();//显示主窗口信号
    void quit();//退出信号
};

#endif // LOGIN_H
