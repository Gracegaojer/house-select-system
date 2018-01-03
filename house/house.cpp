#include"house.h"
#include<string>
#include<malloc.h>
#include<qdebug.h>

extern block* blockhead;
extern block* blocktrail;

block* newblock(char* blockid,char* blockname,char* blockadd,char *developer,char *promgr,char blockdeadd[],char phonenum[],char time[]){
    block* p=(block*)malloc(sizeof(block));
    strcpy(p->blockid,blockid);
    strcpy(p->blockname,blockname);
    strcpy(p->blockadd,blockadd);
    strcpy(p->developer,developer);
    strcpy(p->promgr,promgr);
    strcpy(p->blockdeadd,blockdeadd);
    strcpy(p->phonenum,phonenum);
    strcpy(p->time,time);
    p->next=NULL;
    p->buildinghead=(building*)malloc(sizeof(building));
    p->buildingtrail=p->buildinghead;
    p->buildinghead->next=NULL;
    blocktrail->next=p;
    blocktrail=blocktrail->next;
    return p;
}
int * insertblock(block* blo){
    blocktrail->next=blo;
    blocktrail=blo;
    blocktrail->next=NULL;
    blocktrail->buildinghead=(building*)malloc(sizeof(building));
    blocktrail->buildingtrail=blocktrail->buildinghead;
    return 0;
}

int delblock(char* blockid){
    block* p=blockhead;
    block* del;
    building* buidel,*buitmp;
    house* houdel,*houtmp;
    while(p->next!=NULL){
        if(strcmp(p->blockid,blockid)){
            //delthisone
            del=p->next;
            p->next=p->next->next;
            buidel=del->buildinghead;
            while(buidel->next!=NULL){
                houdel=buidel->next->househead;
                while(houdel->next!=NULL){
                    houtmp=houdel;
                    houdel=houdel->next;
                    free(houtmp);
                }
                free(houdel);
                buitmp=buidel;
                buidel=buidel->next;
                free(buitmp);
            }
            free(buidel);
            free(del);
            break;
        }
        p=p->next;
    }
    if(p->next==NULL){
        qDebug()<<"No this block[delblock]\n";
        return 1;
    }
    return 0;
}

block* searchblock(char * blockid){
    block* p=blockhead->next;
    while(p!=NULL){
        if(strcmp(p->blockid,blockid)==0){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int updateblock(char* blockid,char* blockname,char* blockadd,char *developer,char *promgr,char blockdeadd[],char phonenum[],char time[]){
    block* p=blockhead->next;
    while(p!=NULL){
        if(strcmp(p->blockid,blockid)==0){
            strcpy(p->blockname,blockname);
            strcpy(p->blockadd,blockadd);
            strcpy(p->developer,developer);
            strcpy(p->promgr,promgr);
            strcpy(p->blockdeadd,blockdeadd);
            strcpy(p->phonenum,phonenum);
            strcpy(p->time,time);
            return 0;
        }
        p=p->next;
    }
    qDebug()<<"No this block[update]\n";
    return 1;
}

building* newbuilding(char blockid[],char buildingid[],int unit,int floor){
    block* blo=searchblock(blockid);
    building* bui=(building*)malloc(sizeof(building));
    strcpy(bui->blockid,blockid);
    strcpy(bui->buildingid,buildingid);
    bui->unit=unit;
    bui->floor=floor;
    bui->househead=(house*)malloc(sizeof(house));
    bui->housetrail=bui->househead;
    bui->househead->next=NULL;
    bui->next=NULL;
    blo->buildingtrail->next=bui;
    blo->buildingtrail=blo->buildingtrail->next;
}
int * insertbuilding(building* bui){
    block* blo=searchblock(bui->blockid);
    blo->buildingtrail->next=bui;
    blo->buildingtrail=bui;
    blo->buildingtrail->househead=(house*)malloc(sizeof(house));
    blo->buildingtrail->housetrail=blo->buildingtrail->househead;
    blo->buildingtrail->next=NULL;
    return 0;
}
int delbuilding(char blockid[],char buildingid[]){
    block* p=blockhead;
    block* del;
    building* buidel,*buitmp;
    house* houdel,*houtmp;
    while(p->next!=NULL){
        if(strcmp(p->blockid,blockid)){
            //delthisone
            del=p->next;
            buidel=del->buildinghead;
            while(buidel->next!=NULL){
                if(strcmp(buidel->next->buildingid,buildingid)==0){
                    houdel=buidel->next->househead;
                    while(houdel->next!=NULL){
                        houtmp=houdel;
                        houdel=houdel->next;
                        free(houtmp);
                    }
                    free(houdel);
                    buitmp=buidel->next;
                    if(buitmp->next!=NULL)
                        buidel->next=buitmp->next;
                    else buidel->next=NULL;
                    free(buitmp);
                    return 0;
                }
                buidel=buidel->next;
            }
        }
        p=p->next;
    }
    if(p->next==NULL){
        qDebug()<<"No this building[delblock]\n";
    }
    return 1;
}
int updatebuilding(char blockid[],char buildingid[],int unit,int floor){
    block* blo=blockhead;
    building* bui;
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,blockid)==0){
            bui=blo->buildinghead;
            while(bui->next!=NULL){
                if(strcmp(bui->next->buildingid,buildingid)==0){
                    bui->unit=unit;
                    bui->floor=floor;
                    return 0;
                }
            }
        }
        blo=blo->next;
    }
    return 1;
}

house* newhouse(char * blockid,char* buildingid,char* houseid,char* housetype,float size,float rate,float price){
    block* blo=blockhead;
    building* bui;
    house* hou=(house*)malloc(sizeof(house));
    strcpy(hou->blockid,blockid);
    strcpy(hou->buildingid,buildingid);
    strcpy(hou->houseid,houseid);
    strcpy(hou->housetype,housetype);
    hou->size=size;
    hou->rate=rate;
    hou->price=price;
    hou->hot=0;
    hou->next=NULL;
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,blockid)==0){
            bui=blo->next->buildinghead;
            while(bui->next!=NULL){
                if(strcmp(bui->next->buildingid,buildingid)==0){
                    bui->next->housetrail->next=hou;
                    bui->next->housetrail=bui->next->housetrail->next;
                }
                bui=bui->next;
            }
        }
        blo=blo->next;
    }
    return hou;
}
int inserthouse(house* hou){
    block* blo=searchblock(hou->blockid);
    building* bui=blo->buildinghead;
    while(bui->next!=NULL){
        if(strcmp(bui->next->buildingid,hou->buildingid)==0){
            bui->next->housetrail->next=hou;
            bui->next->housetrail=hou;
            bui->next->housetrail->next=NULL;
            return 0;
        }
        bui=bui->next;
    }
    return 1;
}
int delhouse(char * blockid,char* buildingid,char* houseid){
    block* blo=blockhead;
    building* bui;
    house* hou,*del;
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,blockid)==0){
            bui=blo->next->buildinghead;
            while(bui->next!=NULL){
                if(strcmp(bui->next->buildingid,buildingid)==0){
                    hou=bui->next->househead;
                    while(hou->next!=NULL){
                        if(strcmp(hou->next->houseid,houseid)==0){
                            del=hou->next;
                            if(hou->next->next!=NULL) hou->next=hou->next->next;
                            else hou->next=NULL;
                            free(del);
                            return 0;
                        }
                    }
                }
                bui=bui->next;
            }
        }
        blo=blo->next;
    }
    if(blo->next==NULL){
        qDebug()<<"No such house[del]\n";
    }
    return 1;
}
int updatehouse(char * blockid,char* buildingid,char* houseid,char *housetype,float size,float rate,float price){
    block* blo=blockhead;
    building* bui;
    house* hou;
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,blockid)==0){
            bui=blo->next->buildinghead;
            while(bui->next!=NULL){
                if(strcmp(bui->next->buildingid,buildingid)==0){
                    hou=bui->next->househead;
                    while(hou->next!=NULL){
                        if(strcmp(hou->next->houseid,houseid)==0){
                            strcpy(hou->next->blockid,blockid);
                            strcpy(hou->next->buildingid,buildingid);
                            strcpy(hou->next->houseid,houseid);
                            strcpy(hou->next->housetype,housetype);
                            hou->next->size=size;
                            hou->next->rate=rate;
                            hou->next->price=price;
                            return 0;
                        }
                    }
                }
                bui=bui->next;
            }
        }
        blo=blo->next;
    }
    if(blo->next==NULL){
        qDebug()<<"No such house[del]\n";
    }
    return 1;
}
int findhouse(char* blockid,char* buildingid,char* houseid,block** block1,building** build1,house** house1){
    block* blo=blockhead;
    building* bui;
    house* hou;
    while(blo->next!=NULL){
        if(strcmp(blo->next->blockid,blockid)==0){
            bui=blo->next->buildinghead;
            while(bui->next!=NULL){
                if(strcmp(bui->next->buildingid,buildingid)==0){
                    hou=bui->next->househead;
                    while(hou->next!=NULL){
                        if(strcmp(hou->next->houseid,houseid)==0){
                            *block1=blo->next;
                            *build1=bui->next;
                            *house1=hou->next;
                            return 0;
                        }
                        hou=hou->next;
                    }
                }
                bui=bui->next;
            }
        }
        blo=blo->next;
    }
    return 1;
}

block* QUIKSORT_time(block* head,block* trail){
    block* tmp;
    block* left=head;
    block* middle=head;
    int lntime,mtime;
    while(left->next!=NULL&&left!=trail){
        sscanf(left->next->time,"%d",&lntime);
        sscanf(middle->time,"%d",&mtime);
        if(lntime>mtime){
            tmp=left->next;
            if(left->next->next!=NULL)
                left->next=left->next->next;
            else left->next=NULL;
            tmp->next=head;//头插法
            head=tmp;
            continue;
        }
        left=left->next;
    }
    if(head->next!=middle&&head!=middle){
        block* head1=QUIKSORT_time(head,middle);
        head=head1;
    }
    if(middle->next!=NULL&&middle->next!=trail){
        block* head2=middle->next;
        middle->next=QUIKSORT_time(head2,trail);
    }
    return head;
}


houselink* newhouselink(houselink* linkhead,houselink* linktrail){
    linkhead=(houselink*)malloc(sizeof(houselink));
    linktrail=linkhead;
    block* blo=blockhead;
    building* bui;
    house* hou;
    while(blo->next!=NULL){//得到链表数组
        bui=blo->next->buildinghead;
        while(bui->next!=NULL){
            hou=bui->next->househead;
            while(hou->next!=NULL){
                linktrail->next=(houselink*)malloc(sizeof(houselink));
                linktrail=linktrail->next;
                linktrail->next=NULL;
                linktrail->blocknode=blo->next;
                linktrail->buildnode=bui->next;
                linktrail->housenode=hou->next;
                hou=hou->next;
            }
            bui=bui->next;
        }
        blo=blo->next;
    }
    return linkhead;
}

houselink* QUIKSORT_price(houselink* head,houselink* trail){
    houselink* tmp;
    houselink* left=head;
    houselink* middle=head;
    float lnprice,mprice;
    while(left->next!=NULL&&left!=trail){
        lnprice=left->next->housenode->price;
        mprice=middle->housenode->price;
        if(lnprice<mprice){
            tmp=left->next;
            if(left->next->next!=NULL)
                left->next=left->next->next;
            else left->next=NULL;
            tmp->next=head;//头插法
            head=tmp;
            continue;
        }
        left=left->next;
    }
    if(head->next!=middle&&head!=middle){
        houselink* head1=QUIKSORT_price(head,middle);
        head=head1;
    }
    if(middle->next!=NULL&&middle->next!=trail){
        houselink* head2=middle->next;
        middle->next=QUIKSORT_price(head2,trail);
    }
    return head;
}

houselink* QUIKSORT_hot(houselink* head,houselink* trail){
    houselink* tmp;
    houselink* left=head;
    houselink* middle=head;
    float lnhot,mhot;
    while(left->next!=NULL&&left!=trail){
        lnhot=left->next->housenode->hot;
        mhot=middle->housenode->hot;
        if(lnhot>mhot){
            tmp=left->next;
            if(left->next->next!=NULL)
                left->next=left->next->next;
            else left->next=NULL;
            tmp->next=head;//头插法
            head=tmp;
            continue;
        }
        left=left->next;
    }
    if(head->next!=middle&&head!=middle){
        houselink* head1=QUIKSORT_hot(head,middle);
        head=head1;
    }
    if(middle->next!=NULL&&middle->next!=trail){
        houselink* head2=middle->next;
        middle->next=QUIKSORT_hot(head2,trail);
    }
    return head;
}
