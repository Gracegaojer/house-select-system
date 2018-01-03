#ifndef HOUSE_H
#define HOUSE_H

typedef struct house_{//房屋编号、户型、面积、公摊率和价格
    char blockid[20];
    char buildingid[20];
    char houseid[20];
    char housetype[20];//a住宅 b公寓 c商铺 d写字楼 e小户型 f精装房 g学区房 h其他
    float size;
    float rate;
    float price;
    int hot;
    struct house_* next;
}house;

typedef struct building_{//楼栋编号、单元和楼层
    char blockid[20];
    char buildingid[20];
    int unit;
    int floor;
    struct building_* next;
    house* househead;
    house* housetrail;
}building;

typedef struct block_{//楼盘编号、楼盘名称、楼盘地址、开发商和物业公司
    char blockid[20];
    char blockname[20];
    char blockadd[10];
    char developer[20];
    char promgr[20];
    char blockdeadd[100];
    char phonenum[15];
    char time[20];
    struct block_* next;
    building * buildinghead;
    building * buildingtrail;
}block;

block* newblock(char* blockid,char* blockname,char* blockadd,char *developer,char *promgr,char blockdeadd[],char phonenum[],char time[]);
int * insertblock(block* blo);
int delblock(char* blockid);
block* searchblock(char * blockid);
int updateblock(char* blockid,char* blockname,char* blockadd,char *developer,char *promgr,char blockdeadd[],char phonenum[],char time[]);
building* newbuilding(char blockid[],char buildingid[],int unit,int floor);
int * insertbuilding(building* bui);
int delbuilding(char blockid[],char buildingid[]);
int updatebuilding(char blockid[],char buildingid[],int unit,int floor);
house* newhouse(char * blockid,char* buildingid,char* houseid,char* housetype,float size,float rate,float price);
int inserthouse(house* hou);
int delhouse(char * blockid,char* buildingid,char* houseid);
int updatehouse(char * blockid,char* buildingid,char* houseid,char *housetype,float size,float rate,float price);
int findhouse(char* blockid,char* buildingid,char* houseid,block** block1,building** build1,house** house1);
block* QUIKSORT_time(block* head,block* trail);


typedef struct hou_{
    house* housenode;
    block* blocknode;
    building* buildnode;
    struct hou_* next;
}houselink;
houselink* newhouselink(houselink* head,houselink* trail);
houselink* QUIKSORT_price(houselink* head,houselink* trail);
houselink* QUIKSORT_hot(houselink* head,houselink* trail);
#endif // HOUSE_H
