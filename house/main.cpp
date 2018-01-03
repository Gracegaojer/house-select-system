#include"usr.h"
#include "mainwindow.h"
#include <QApplication>
#include"login.h"
#include"house.h"
#include"detail.h"
#include<qtextcodec.h>
#include"choose.h"
#include<qdebug.h>

usr * usrhead=(usr *)malloc(sizeof(usr));
usr * usrtrail=usrhead;
mgr * mgrhead=( mgr *)malloc(sizeof(mgr));
mgr * mgrtrail=mgrhead;
block* blockhead=(block*)malloc(sizeof(block));
block* blocktrail=blockhead;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    usrhead->next=NULL;
    mgrhead->next=NULL;
    blockhead->next=NULL;
/*    //usr
    char name[20]="sanji0";
    char pass[20]="000";
    newusr(name,pass);
    strcpy(name,"sanji1");
    strcpy(pass,"111");
    newusr(name,pass);
    //mgr
    char name_2[20]="mgr";
    char pass_2[20]="mgr";
    newmgr(name_2,pass_2);
*/
    //block
  /*  char blockid[20]="dh000000000001";//jh江汉区,ja江岸区,qk硚口区,wc武昌区,hs洪山区,qs青山区,hy汉阳区,dx东西湖区,hp黄陂区,dh东湖高新区,jx江夏区,jk武汉经开,cd蔡甸区,hn汉南区,xz新洲区
    char blockname[20]="金地本座";
    char blockadd[10]="东湖";
    char developer[20]="金地房地产";
    char promgr[20]="虹景花园物业";
    char blockdeadd[100]=" 东湖高新区荣院路与康泰路交汇处";
    char phone[15]="4000271717";
    char time[20]="20161029";
    newblock(blockid,blockname,blockadd,developer,promgr,blockdeadd,phone,time);

    char buildingid[20]="jdbz000000000001";
    int unit=1;
    int floor=32;
    newbuilding(blockid,buildingid,unit,floor);

    char houseid[20]="000000000000000001";
    char housetype[10]="一居室";
    float size=49.00;
    float rate=7.05;
    float price=1.54;
    newhouse(blockid,buildingid,houseid,housetype,size,rate,price);
    strcpy(houseid,"000000000000000002");
    strcpy(housetype,"一居室");
    size=36.00;
    rate=7.05;
    price=1.55;
    newhouse(blockid,buildingid,houseid,housetype,size,rate,price);

    //block
    strcpy(blockid,"wc000000000001");//jh江汉区,ja江岸区,qk硚口区,wc武昌区,hs洪山区,qs青山区,hy汉阳区,dx东西湖区,hp黄陂区,dh东湖高新区,jx江夏区,jk武汉经开,cd蔡甸区,hn汉南区,xz新洲区
    strcpy(blockname,"东湖楚天府");
    strcpy(blockadd,"武昌");
    qDebug()<<blockadd;
    strcpy(developer,"湖北强涛置业");
    strcpy(promgr,"世邦魏理仕");
    strcpy(blockdeadd," 洪山区八一路340号");
    strcpy(phone,"4000271717");
    strcpy(time,"20140918");
    newblock(blockid,blockname,blockadd,developer,promgr,blockdeadd,phone,time);

    strcpy(buildingid,"dhct000000000001");
    unit=3;
    floor=29;
    newbuilding(blockid,buildingid,unit,floor);

    strcpy(houseid,"000000000000000003");
    strcpy(housetype,"三居室");
    size=125.00;
    rate=4.0;
    price=2.1;
    newhouse(blockid,buildingid,houseid,housetype,size,rate,price);

    strcpy(buildingid,"dhct000000000002");
    unit=5;
    floor=32;
    newbuilding(blockid,buildingid,unit,floor);
    strcpy(houseid,"000000000000000004");
    strcpy(housetype,"二居室");
    size=100.00;
    rate=4.0;
    price=2.5;
    newhouse(blockid,buildingid,houseid,housetype,size,rate,price);
*/
  /*  //block
    strcpy(blockid,"wc000000000003");//jh江汉区,ja江岸区,qk硚口区,wc武昌区,hs洪山区,qs青山区,hy汉阳区,dx东西湖区,hp黄陂区,dh东湖高新区,jx江夏区,jk武汉经开,cd蔡甸区,hn汉南区,xz新洲区
    strcpy(blockname,"保利城");
    strcpy(blockadd,"武昌");
    qDebug()<<blockadd;
    strcpy(developer,"保利普提金");
    strcpy(promgr,"湖北保利物业");
    strcpy(blockdeadd,"武昌徐东团结大道与铁机路交汇处");
    strcpy(phone,"4000271717");
    strcpy(time,"20170729");
    newblock(blockid,blockname,blockadd,developer,promgr,blockdeadd,phone,time);

    strcpy(buildingid,"blc000000000001");
    unit=31;
    floor=33;
    newbuilding(blockid,buildingid,unit,floor);

    strcpy(houseid,"000000000000000005");
    strcpy(housetype,"三居室");
    size=132.00;
    rate=3.6;
    price=1.37;
    newhouse(blockid,buildingid,houseid,housetype,size,rate,price);

    strcpy(buildingid,"blc000000000002");
    unit=32;
    floor=33;
    newbuilding(blockid,buildingid,unit,floor);

    strcpy(houseid,"000000000000000006");
    strcpy(housetype,"四居室");
    size=174.00;
    rate=3.6;
    price=1.37;
    newhouse(blockid,buildingid,houseid,housetype,size,rate,price);

    strcpy(houseid,"000000000000000007");
    strcpy(housetype,"三居室");
    size=130.00;
    rate=3.6;
    price=1.36;
    newhouse(blockid,buildingid,houseid,housetype,size,rate,price);
*/


    //文件系统
    usr* usr_file=(usr*)malloc(sizeof(usr));
    mgr* mgr_file=(mgr*)malloc(sizeof(mgr));
    block* block_file=(block*)malloc(sizeof(block));
    building* building_file=(building*)malloc(sizeof(building));
    house* house_file=(house*)malloc(sizeof(house));

    int sizeusr=sizeof(usr)-sizeof(void*);
    int sizemgr=sizeof(mgr)-sizeof(void*);
    int size1=sizeof(block)-3*sizeof(void*);//除去指针外的相应结构体的大小
    int size2=sizeof(building)-3*sizeof(void*);
    int size3=sizeof(house)-sizeof(void*);
    FILE* fp1,*fp2,*fp3,*fp4,*fp5;
    fp1=fopen("./data_usr","rb+");
    if(!fp1){//找不到文件
        fp1=fopen("./data_usr","wb+");
    }
    fp2=fopen("./data_mgr","rb+");
    if(!fp2){//找不到文件
        fp2=fopen("./data_mgr","wb+");
    }
    fp3=fopen("./data_block","rb+");
    if(!fp3){//找不到文件
        fp3=fopen("./data_block","wb+");
    }
    fp4=fopen("./data_building","rb+");
    if(!fp4){//找不到文件
        fp4=fopen("./data_building","wb+");
    }
    fp5=fopen("./data_house","rb+");
    if(!fp5){//找不到文件
        fp5=fopen("./data_house","wb+");
    }

    while(fread(usr_file,sizeusr,1,fp1)!=0){
        qDebug()<<usr_file->usrid;
        insertusr(usr_file);
        usr_file=(usr*)malloc(sizeof(usr));

    }
    while(fread(mgr_file,sizemgr,1,fp2)!=0){
        qDebug()<<mgr_file->mgrid;
        insertmgr(mgr_file);
        mgr_file=(mgr*)malloc(sizeof(mgr));

    }
    while(fread(block_file,size1,1,fp3)!=0){
        qDebug()<<block_file->blockname;
        insertblock(block_file);
        block_file=(block*)malloc(sizeof(block));

    }
    while(fread(building_file,size2,1,fp4)!=0){
        //qDebug()<<"build"<<building_file->buildingid;
        insertbuilding(building_file);
        building_file=(building*)malloc(sizeof(building));

    }
    while(fread(house_file,size3,1,fp5)!=0){
        qDebug()<<"house"<<house_file->housetype;
        inserthouse(house_file);
        house_file=(house*)malloc(sizeof(house));
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
/*
    char blockid[20]="dh000000000001";//jh江汉区,ja江岸区,qk硚口区,wc武昌区,hs洪山区,qs青山区,hy汉阳区,dx东西湖区,hp黄陂区,dh东湖高新区,jx江夏区,jk武汉经开,cd蔡甸区,hn汉南区,xz新洲区
    char blockname[20]="金地本座";
        char blockadd[10]="东湖";
        char developer[20]="金地房地产";
        char promgr[20]="虹景花园物业";
        char blockdeadd[100]=" 东湖高新区荣院路与康泰路交汇处";
        char phone[15]="4000271717";
        char time[20]="20161029";
    updateblock(blockid,blockname,blockadd,developer,promgr,blockdeadd,phone,time);
*/
    MainWindow w;
    login w1;
    detail w2;
    choose w3;
    w1.show();
    QObject::connect(&w1,SIGNAL(showmainwindow()),&w,SLOT(on_MainWindow_mainshow()));
    QObject::connect(&w,SIGNAL(showdetail()),&w2,SLOT(detailshow()));
    QObject::connect(&w,SIGNAL(showchoose()),&w3,SLOT(chooseshow()));
    QObject::connect(&w3,SIGNAL(resetmain()),&w,SLOT(choosereset()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));//把退出信号发给app
    QObject::connect(&w1,SIGNAL(quit()),&a,SLOT(quit()));//把退出信号发给app

    a.exec();

    fp1=fopen("./data_usr","wb+");
    fp2=fopen("./data_mgr","wb+");
    fp3=fopen("./data_block","wb+");
    fp4=fopen("./data_building","wb+");
    fp5=fopen("./data_house","wb+");
    //写文件
    usr_file=usrhead;
    while(usr_file->next!=NULL){
        fwrite(usr_file->next,sizeusr,1,fp1);
        usr_file=usr_file->next;
    }
    fclose(fp1);
    mgr_file=mgrhead;
    while(mgr_file->next!=NULL){
        fwrite(mgr_file->next,sizemgr,1,fp2);
        mgr_file=mgr_file->next;
    }
    fclose(fp2);

    block_file=blockhead;
    while(block_file->next!=NULL){
        qDebug()<<"I wrote a block info into fp3\n";
        fwrite(block_file->next,size1,1,fp3);
        building_file=block_file->next->buildinghead;
        while(building_file->next!=NULL){
            qDebug()<<"I wrote a building info into fp4\n";
            fwrite(building_file->next,size2,1,fp4);
            house_file=building_file->next->househead;
            while(house_file->next!=NULL){
                qDebug()<<"I wrote a house info into fp5\n";
                fwrite(house_file->next,size3,1,fp5);
                house_file=house_file->next;
            }
            building_file= building_file->next;
        }
        block_file=block_file->next;
    }

    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    return 0;
}
