#include "detail.h"
#include "ui_detail.h"
#include "house.h"
#include<QStringListModel>
#include<qdebug.h>
#include <QTextCodec>
#include"usr.h"

extern QString detail_bloid;
extern QString detail_buiid;
extern QString detail_houid;
extern QString currusrid;
extern usr* usrhead;
extern block* blockhead;
extern block* blocktrail;

detail::detail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detail)
{
    ui->setupUi(this);

}

detail::~detail()
{
    delete ui;
}

void detail::detailshow(){
    block* blo=blockhead;
    building* bui;
    house* hou;
    QStringList housedetail;
    char buf[10];
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,detail_bloid.toLatin1().data())==0){
            bui=blo->next->buildinghead;
            while(bui->next!=NULL){
                if(strcmp(bui->next->buildingid,detail_buiid.toLatin1().data())==0){
                    hou=bui->next->househead;
                    while(hou->next!=NULL){
                        if(strcmp(hou->next->houseid,detail_houid.toLatin1().data())==0){
                            QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); // 改为GBK编码
                            housedetail<<"楼盘名称："+QString::fromLocal8Bit(blo->next->blockname);
                            housedetail<<"楼盘位置："+QString::fromLocal8Bit(blo->next->blockadd);
                            housedetail<<"开发商："+QString::fromLocal8Bit(blo->next->developer);
                            housedetail<<"物业："+QString::fromLocal8Bit(blo->next->promgr);
                            housedetail<<"详细地址："+QString::fromLocal8Bit(blo->next->blockdeadd);
                            housedetail<<"咨询热线："+QString::fromLocal8Bit(blo->next->phonenum);
                            housedetail<<"开盘时间："+QString::fromLocal8Bit(blo->next->time);
                            sprintf(buf,"%d",bui->next->unit);
                            housedetail<<"单元："+QString(QLatin1String(buf));
                            sprintf(buf,"%d",bui->next->floor);
                            housedetail<<"层数："+QString(QLatin1String(buf));
                            housedetail<<"房型："+QString::fromLocal8Bit(hou->next->housetype);
                            sprintf(buf,"%.2f",hou->next->price);
                            housedetail<<"价格："+QString(QLatin1String(buf));
                            sprintf(buf,"%.2f",hou->next->size);
                            housedetail<<"面积："+QString(QLatin1String(buf));
                            sprintf(buf,"%.2f",hou->next->rate);
                            housedetail<<"容积率："+QString(QLatin1String(buf));
                        }
                        hou=hou->next;
                    }
                }
                bui=bui->next;
            }
        }
        blo=blo->next;
    }
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(housedetail);
    qDebug()<<housedetail;
    ui->listView->setModel(model);
    if(currusrid==""){
        ui->pushButton_2->hide();
    }
    this->show();
}

void detail::on_pushButton_2_clicked()//收藏
{
    usr* u=usrhead;
    while(u->next!=NULL){
        if(strcmp(u->next->usrid,currusrid.toLatin1().data())==0){
            strcpy(u->next->blockid[u->next->starnum],detail_bloid.toLatin1().data());
            strcpy(u->next->buildid[u->next->starnum],detail_buiid.toLatin1().data());
            strcpy(u->next->houseid[u->next->starnum],detail_houid.toLatin1().data());
            u->next->starnum++;
            break;
        }
        u=u->next;
    }
    qDebug()<<u->next->blockid[u->next->starnum-1];
    block* blo;
    building* bui;
    house* hou;
    findhouse(detail_bloid.toLatin1().data(),detail_buiid.toLatin1().data(),detail_houid.toLatin1().data(),&blo,&bui,&hou);
    hou->hot++;
}

void detail::on_pushButton_clicked()
{
    this->hide();
}
