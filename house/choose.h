#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>

namespace Ui {
class choose;
}

class choose : public QDialog
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = 0);
    ~choose();
private slots:
    //与login中发射的信号关联的槽函数
    void chooseshow();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
signals:
    void resetmain();
private:
    Ui::choose *ui;
};

#endif // CHOOSE_H
