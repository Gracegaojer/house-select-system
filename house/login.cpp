#include "login.h"
#include "ui_login.h"
#include "usr.h"
#include<QMessageBox>
#include<QDebug>

extern usr* usrhead;
extern mgr* mgrhead;
QString currusrid;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    ui->buttonGroup->setId(ui->radioButton,0);
    ui->buttonGroup->setId(ui->radioButton_2,1);
    int type=ui->buttonGroup->checkedId();
    if(type==0){//usr
        bool login=validateusr(ui->lineEdit->text().toLatin1().data(),ui->lineEdit_2->text().toLatin1().data());
        if(login==true){//用户验证通过
            currusrid=ui->lineEdit->text();
            qDebug()<<currusrid;
            this->hide();
            emit showmainwindow();
        }else{
            QMessageBox::warning(0, qApp->tr("WARNING!"),tr("请输入正确的账号密码!"), QMessageBox::Cancel);
        }
    }
    else if(type==1){
        bool login=validatemgr(ui->lineEdit->text().toLatin1().data(),ui->lineEdit_2->text().toLatin1().data());
        if(login==true){//用户验证通过
            this->hide();
            emit showmainwindow();
        }else{
            QMessageBox::warning(0, qApp->tr("WARNING!"),tr("请输入正确的账号密码!"), QMessageBox::Cancel);
        }
    }
    else{
        QMessageBox::warning(0, qApp->tr("WARNING!"),tr("请选择用户身份!"), QMessageBox::Cancel);
    }
}
