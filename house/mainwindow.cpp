#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "house.h"
#include"usr.h"
#include<qstandarditemmodel.h>
#include<qmessagebox.h>
#include<string.h>
#include<qdebug.h>

QString detail_bloid;
QString detail_buiid;
QString detail_houid;
extern QString currusrid;

extern block* blockhead;
extern block* blocktrail;

extern QString choose_name;
extern QString choose_add;
extern QString choose_type;
extern float choose_price[2];
extern float choose_size[2];
QStandardItemModel  *blockmodel = new QStandardItemModel();
 QStandardItemModel  *housemodel = new QStandardItemModel();
   QStandardItemModel  *buildingmodel = new QStandardItemModel();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_MainWindow_mainshow(){
    ui->stackedWidget->setCurrentIndex(0);//楼盘名称、楼盘地址、户型、面积、价格、公摊率、开发商和物业公司、单元和楼层

    QStandardItemModel  *housemodel = new QStandardItemModel();
    housemodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("名称")));
    housemodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("地址")));
    housemodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("户型")));
    housemodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("面积(m2)")));
    housemodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格(万元)")));

    int i;
    i=0;
    char buf[20];
    block* blo=blockhead;
    building* bui;
    house* hou;
    while(blo->next!=NULL){
        bui=blo->next->buildinghead;
        while(bui->next!=NULL){
            hou=bui->next->househead;
            while(hou->next!=NULL) {
                housemodel->setItem(i,0,new QStandardItem(blo->next->blockname));
                housemodel->setItem(i,1,new QStandardItem(blo->next->blockadd));
                housemodel->setItem(i,2,new QStandardItem(hou->next->housetype));
                sprintf(buf,"%.2f",hou->next->size);
                housemodel->setItem(i,3,new QStandardItem(buf));
                sprintf(buf,"%.2f",hou->next->price);
                housemodel->setItem(i,4,new QStandardItem(buf));
                //不显示的标记信息
                housemodel->setItem(i,5,new QStandardItem(blo->next->blockid));
                housemodel->setItem(i,6,new QStandardItem(bui->next->buildingid));
                housemodel->setItem(i,7,new QStandardItem(hou->next->houseid));
                i++;
                qDebug()<<buf;
                qDebug()<<hou->next->size;
                hou=hou->next;
            }
            bui=bui->next;
        }
        blo=blo->next;
    }

    ui->tableView->setModel(housemodel);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);

    qDebug()<<currusrid;
    if(currusrid!=""){
        ui->action_3->setVisible(false);
        qDebug()<<"check!";
    }
    else{
        ui->pushButton_5->setVisible(false);
    }
    this->show();
}

void MainWindow::on_action_5_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);//修改用户
}

void MainWindow::on_action_6_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);//修改楼盘数据
}

void MainWindow::on_action_7_triggered()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_action_2_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_action_triggered()//quit
{
    emit(quit());
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)//双击显示详细信息
{
    int row=index.row();
    detail_bloid=ui->tableView->model()->data(ui->tableView->model()->index(row,5)).toString();
    detail_buiid=ui->tableView->model()->data(ui->tableView->model()->index(row,6)).toString();
    detail_houid=ui->tableView->model()->data(ui->tableView->model()->index(row,7)).toString();
    emit(showdetail());
}

void MainWindow::on_pushButton_clicked()
{
    showchoose();
}

void MainWindow::choosereset(){

    QStandardItemModel  *housemodel = new QStandardItemModel();
    housemodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("名称")));
    housemodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("地址")));
    housemodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("户型")));
    housemodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("面积(m2)")));
    housemodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格(万元)")));

    int i;
    i=0;
    char buf[20];
    block* blo=blockhead;
    building* bui;
    house* hou;
    while(blo->next!=NULL){
        if((choose_name==""||strcmp(blo->next->blockname,choose_name.toUtf8().data())==0)&&((strcmp(choose_add.toUtf8().data(),"无限制")==0)||strcmp(blo->next->blockadd,choose_add.toUtf8().data())==0)){
            bui=blo->next->buildinghead;
            while(bui->next!=NULL){
                hou=bui->next->househead;
                while(hou->next!=NULL) {
                    if((strcmp(choose_type.toUtf8().data(),"无限制")==0||strcmp(choose_type.toUtf8().data(),hou->next->housetype)==0)&&hou->next->price>choose_price[0]&&hou->next->price<choose_price[1]&&hou->next->size>choose_size[0]&&hou->next->size<choose_size[1]){
                        housemodel->setItem(i,0,new QStandardItem(blo->next->blockname));
                        housemodel->setItem(i,1,new QStandardItem(blo->next->blockadd));
                        housemodel->setItem(i,2,new QStandardItem(hou->next->housetype));
                        sprintf(buf,"%.2f",hou->next->size);
                        housemodel->setItem(i,3,new QStandardItem(buf));
                        sprintf(buf,"%.2f",hou->next->price);
                        housemodel->setItem(i,4,new QStandardItem(buf));
                    //不显示的标记信息
                        housemodel->setItem(i,5,new QStandardItem(blo->next->blockid));
                        housemodel->setItem(i,6,new QStandardItem(bui->next->buildingid));
                        housemodel->setItem(i,7,new QStandardItem(hou->next->houseid));
                        i++;
                    }
                    hou=hou->next;
                }
                bui=bui->next;
            }
        }
        blo=blo->next;
    }

    ui->tableView->setModel(housemodel);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);


}


void MainWindow::on_pushButton_2_clicked()
{
    if(blockhead->next!=NULL)
        blockhead->next=QUIKSORT_time(blockhead->next,blocktrail);
    on_MainWindow_mainshow();
}

void MainWindow::on_pushButton_3_clicked()
{
    houselink* head;
    houselink* trail;
    head=newhouselink(head,trail);
    head->next=QUIKSORT_price(head->next,trail);
    houselink* p=head;

    QStandardItemModel  *housemodel = new QStandardItemModel();
    housemodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("名称")));
    housemodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("地址")));
    housemodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("户型")));
    housemodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("面积(m2)")));
    housemodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格(万元)")));

    int i;
    i=0;
    char buf[20];
    while(p->next!=NULL){
        housemodel->setItem(i,0,new QStandardItem(p->next->blocknode->blockname));
        housemodel->setItem(i,1,new QStandardItem(p->next->blocknode->blockadd));
        housemodel->setItem(i,2,new QStandardItem(p->next->housenode->housetype));
        sprintf(buf,"%.2f",p->next->housenode->size);
        housemodel->setItem(i,3,new QStandardItem(buf));
        sprintf(buf,"%.2f",p->next->housenode->price);
        housemodel->setItem(i,4,new QStandardItem(buf));
        //不显示的标记信息
        housemodel->setItem(i,5,new QStandardItem(p->next->blocknode->blockid));
        housemodel->setItem(i,6,new QStandardItem(p->next->buildnode->buildingid));
        housemodel->setItem(i,7,new QStandardItem(p->next->housenode->houseid));
        p=p->next;
        i++;
    }
    ui->tableView->setModel(housemodel);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
}

void MainWindow::on_pushButton_4_clicked()//热度
{
    houselink* head;
    houselink* trail;
    head=newhouselink(head,trail);
    if(head->next!=NULL)
        head->next=QUIKSORT_hot(head->next,trail);
    houselink* p=head;

    QStandardItemModel  *housemodel = new QStandardItemModel();
    housemodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("名称")));
    housemodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("地址")));
    housemodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("户型")));
    housemodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("面积(m2)")));
    housemodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格(万元)")));
    housemodel->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("点击量(次)")));

    int i;
    i=0;
    char buf[20];
    while(p->next!=NULL){
        housemodel->setItem(i,0,new QStandardItem(p->next->blocknode->blockname));
        housemodel->setItem(i,1,new QStandardItem(p->next->blocknode->blockadd));
        housemodel->setItem(i,2,new QStandardItem(p->next->housenode->housetype));
        sprintf(buf,"%.2f",p->next->housenode->size);
        housemodel->setItem(i,3,new QStandardItem(buf));
        sprintf(buf,"%.2f",p->next->housenode->price);
        housemodel->setItem(i,4,new QStandardItem(buf));
        housemodel->setItem(i,5,new QStandardItem(p->next->housenode->hot));
        //不显示的标记信息
        housemodel->setItem(i,6,new QStandardItem(p->next->blocknode->blockid));
        housemodel->setItem(i,7,new QStandardItem(p->next->buildnode->buildingid));
        housemodel->setItem(i,8,new QStandardItem(p->next->housenode->houseid));
        p=p->next;
        i++;
    }
    ui->tableView->setModel(housemodel);
    ui->tableView->hideColumn(8);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
}

void MainWindow::on_pushButton_5_clicked()//我的标记
{

    housemodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("名称")));
    housemodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("地址")));
    housemodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("户型")));
    housemodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("面积(m2)")));
    housemodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格(万元)")));

    char currentusrid[20];
    strcpy(currentusrid,currusrid.toLatin1().data());
    usr* cu=findusr(currentusrid);
    qDebug()<<currentusrid;
    int i;
    block* blo;
    building* bui;
    house* hou;
    char buf[20];
    qDebug()<<"starnum:"<<cu->starnum;
    for(i=0;i<cu->starnum;i++){
        findhouse(cu->blockid[i],cu->buildid[i],cu->houseid[i],&blo,&bui,&hou);
        housemodel->setItem(i,0,new QStandardItem(blo->blockname));
        housemodel->setItem(i,1,new QStandardItem(blo->blockadd));
        housemodel->setItem(i,2,new QStandardItem(hou->housetype));
        sprintf(buf,"%.2f",hou->size);
        housemodel->setItem(i,3,new QStandardItem(buf));
        sprintf(buf,"%.2f",hou->price);
        housemodel->setItem(i,4,new QStandardItem(buf));
        //不显示的标记信息
        housemodel->setItem(i,5,new QStandardItem(blo->blockid));
        housemodel->setItem(i,6,new QStandardItem(bui->buildingid));
        housemodel->setItem(i,7,new QStandardItem(hou->houseid));
    }

    ui->tableView->setModel(housemodel);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
}

void MainWindow::on_pushButton_6_clicked()
{
    char currentusrid[20];
    strcpy(currentusrid,currusrid.toLatin1().data());
    usr* cu=findusr(currentusrid);

    if(strcmp(cu->passwd,ui->passwdold->text().toLatin1().data())!=0){
        QMessageBox::warning(0, qApp->tr("WARNING!"),tr("原密码错误!"), QMessageBox::Cancel);
    }
    else if(ui->passwd->text()!=ui->passwd2->text()){
        QMessageBox::warning(0, qApp->tr("WARNING!"),tr("两次密码输入不一致!"), QMessageBox::Cancel);
    }
    else{
        strcpy(cu->passwd,ui->passwd->text().toLatin1().data());
    }
}


void MainWindow::on_building_clicked(const QModelIndex &index)
{
    int row=index.row();
    //id
    QStandardItemModel  *housemodel = new QStandardItemModel();
    housemodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("编号")));
    housemodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("种类")));
    housemodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("面积(m2)")));
    housemodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("容积率")));
    housemodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("价格(万元)")));
    int i;
    i=0;
    char buf[20];
    block* blo=blockhead;
    building* bui;
    house* hou;
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,ui->building->model()->data(ui->building->model()->index(row,0)).toString().toLatin1().data())==0){
        bui=blo->next->buildinghead;
        while(bui->next!=NULL){
            if(strcmp(bui->next->buildingid,ui->building->model()->data(ui->building->model()->index(row,1)).toString().toLatin1().data())==0){
            hou=bui->next->househead;
            while(hou->next!=NULL) {
                housemodel->setItem(i,0,new QStandardItem(hou->next->houseid));
                housemodel->setItem(i,1,new QStandardItem(hou->next->housetype));
                sprintf(buf,"%.2f",hou->next->size);
                housemodel->setItem(i,2,new QStandardItem(buf));
                sprintf(buf,"%.2f",hou->next->rate);
                housemodel->setItem(i,3,new QStandardItem(buf));
                sprintf(buf,"%.2f",hou->next->price);
                housemodel->setItem(i,4,new QStandardItem(buf));
                //不显示的标记信息
                housemodel->setItem(i,5,new QStandardItem(blo->next->blockid));
                housemodel->setItem(i,6,new QStandardItem(bui->next->buildingid));
                housemodel->setItem(i,7,new QStandardItem(hou->next->houseid));
                i++;
                qDebug()<<buf;
                qDebug()<<hou->next->size;
                hou=hou->next;
            }
            }
            bui=bui->next;
        }
        }
        blo=blo->next;
    }
}

void MainWindow::on_block_activated(const QModelIndex &index)
{

}

void MainWindow::on_block_clicked(const QModelIndex &index)
{
    int row=index.row();


    buildingmodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("编号")));
    buildingmodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("单元")));
    buildingmodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("楼层")));

    int i;
    i=0;
    block* blo=blockhead;
    building* bui;
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,ui->block->model()->data(ui->block->model()->index(row,0)).toString().toLatin1().data())==0){
            bui=blo->next->buildinghead;
            while(bui->next!=NULL){
                buildingmodel->setItem(i,0,new QStandardItem(blo->next->blockid));
                buildingmodel->setItem(i,1,new QStandardItem(bui->next->buildingid));
                buildingmodel->setItem(i,2,new QStandardItem(bui->next->unit));
                buildingmodel->setItem(i,3,new QStandardItem(bui->next->floor));
                bui=bui->next;
            }
        }
        blo=blo->next;
    }
    ui->building->setModel(buildingmodel);
    ui->building->hideColumn(0);
    on_building_clicked(buildingmodel->index(0,0));
}

void MainWindow::on_action_3_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);//楼盘名称、楼盘地址、户型、面积、价格、公摊率、开发商和物业公司、单元和楼层


    blockmodel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("名称")));
    blockmodel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("地址")));
    blockmodel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("开发商")));
    blockmodel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("物业")));
    blockmodel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("电话")));
    int i;
    i=0;
    block* blo=blockhead;
    while(blo->next!=NULL){
        blockmodel->setItem(i,0,new QStandardItem(blo->next->blockname));
        blockmodel->setItem(i,1,new QStandardItem(blo->next->blockadd));
        blockmodel->setItem(i,2,new QStandardItem(blo->next->developer));
        blockmodel->setItem(i,3,new QStandardItem(blo->next->promgr));
        blockmodel->setItem(i,4,new QStandardItem(blo->next->phonenum));
        blo=blo->next;
    }

    ui->tableView->setModel(blockmodel);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    const QModelIndex index=blockmodel->index(0,0);
    on_block_clicked(index);
    //on_block_clicked(&index);
    ui->stackedWidget->setCurrentIndex(2);
}
