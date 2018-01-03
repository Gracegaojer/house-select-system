#ifndef DETAIL_H
#define DETAIL_H

#include <QDialog>

namespace Ui {
class detail;
}

class detail : public QDialog
{
    Q_OBJECT

public:
    explicit detail(QWidget *parent = 0);
    ~detail();

private:
    Ui::detail *ui;
private slots:
    //与login中发射的信号关联的槽函数
    void detailshow();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // DETAIL_H
