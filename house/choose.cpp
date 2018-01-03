#include "choose.h"
#include "ui_choose.h"
#include"house.h"
#include"qdebug.h"
extern block* blockhead;
QString choose_name;
QString choose_add;
QString choose_type;
float choose_price[2];
float choose_size[2];

choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
}

choose::~choose()
{
    delete ui;
}

void choose::chooseshow(){
    QStringList add;
    add<<"无限制";
    add<<"东湖高新";
    add<<"洪山";
    add<<"武昌";
    add<<"汉阳";
    add<<"江汉";
    add<<"硚口";
    add<<"江岸";
    add<<"长江新城";
    add<<"东西湖";
    add<<"江夏";
    add<<"经开";
    add<<"青山";
    ui->comboBox_4->addItems(add);
    QStringList price;
    price<<"无限制";
    price<<"0.6~1万";
    price<<"1~1.2万";
    price<<"1.2~1.5万";
    price<<"1.5~2万";
    price<<"2~3万";
    price<<"3万以上";
    ui->comboBox->addItems(price);
    QStringList type;
    type<<"无限制";
    type<<"一居室";
    type<<"二居室";
    type<<"三居室";
    type<<"四居室";
    type<<"其他";
    ui->comboBox_2->addItems(type);
    QStringList size;
    size<<"无限制";
    size<<"0~60㎡";
    size<<"60~80㎡";
    size<<"80~100㎡";
    size<<"100~120㎡";
    size<<"120~140㎡";
    size<<"140~200㎡";
    size<<"200㎡以上";
    ui->comboBox_3->addItems(size);
    this->show();
}

void choose::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    this->hide();
}

void choose::on_pushButton_clicked()
{
    choose_name=ui->lineEdit->text();
    choose_add=ui->comboBox_4->currentText();//add
    qDebug()<<choose_add;
    qDebug()<<choose_name;
    choose_type=ui->comboBox_2->currentText();
    if(ui->comboBox->currentIndex()==0){//price
        choose_price[0]=0;
        choose_price[1]=5.00;
    }
    else if(ui->comboBox->currentIndex()==6){
        choose_price[0]=3;
        choose_price[1]=5.00;
    }
    else
        sscanf(ui->comboBox->currentText().toLatin1().data(),"%f~%f",&choose_price[0],&choose_price[1]);
    if(ui->comboBox_3->currentIndex()==0){//size
        choose_size[0]=0;
        choose_size[1]=500;
    }
    else if(ui->comboBox_3->currentIndex()==7){
        choose_size[0]=200;
        choose_size[1]=500;
    }
    else
        sscanf(ui->comboBox_3->currentText().toLatin1().data(),"%f~%f%",&choose_size[0],&choose_size[1]);
    on_pushButton_2_clicked();
    resetmain();
}
