#include"usr.h"
#include<malloc.h>
#include <string.h>

extern usr* usrhead;
extern mgr* mgrhead;
extern usr* usrtrail;
extern mgr* mgrtrail;

int newusr(char * name,char * pswd){//new one usr&insert in the trail
    usr* s=usrhead;
    while(s->next!=NULL){
        if(strcmp(s->next->usrid,name)==0){//已有用户名
            return 0;
        }
        s=s->next;
    }
    usr* p=(usr*)malloc(sizeof(usr));
    strcpy(p->usrid,name);
    strcpy(p->passwd,pswd);
    p->starnum=0;
    p->next=NULL;
    usrtrail->next=p;
    usrtrail=usrtrail->next;
    return 1;
}

int insertusr(usr* u){
    usrtrail->next=u;
    usrtrail=u;
    u->next=NULL;
    return 0;
}
int delusr(char * name){
      usr* p=usrhead;
      usr* del;
    while(p->next!=NULL){
        if(strcmp(p->next->usrid,name)==0){
            del=p->next;
            p->next=p->next->next;
            free(del);
            break;
        }
        p=p->next;
    }
    if(p->next==NULL){
        return 1;
        //qDebug()<<"No such usr!";
    }
    return 0;
}
int validateusr(char* name,char* pass){
      usr* p=usrhead;
    while(p->next!=NULL){
        if(strcmp(p->next->usrid,name)==0){
            if(strcmp(p->next->passwd,pass)==0){
                //loginin
                return 1;
            }
            else{
                //wrong passwd
                return 0;
            }
        }
        p=p->next;
    }
    return 0;
}
usr* findusr(char* usrid){
    usr* u=usrhead;
    while (u->next!=NULL) {
        if(strcmp(u->next->usrid,usrid)==0){
            return u->next;
        }
        u=u->next;
    }
}
int newmgr(char * name,char * pswd){//new one usr&insert in the trail
    mgr* s=mgrhead;
    while(s->next!=NULL){
        if(strcmp(s->next->mgrid,name)==0){//已有用户名
            return 0;
        }
        s=s->next;
    }
    mgr* p=(mgr*)malloc(sizeof(mgr));
    strcpy(p->mgrid,name);
    strcpy(p->passwd,pswd);
    p->next=NULL;
    mgrtrail->next=p;
    mgrtrail=mgrtrail->next;
    return 1;
}
int insertmgr(mgr* m){
    mgrtrail->next=m;
    mgrtrail=m;
    m->next=NULL;
    return 0;
}
int delmgr(char * name){
    mgr* p=mgrhead;
    mgr* del;
    while(p->next!=NULL){
        if(strcmp(p->next->mgrid,name)==0){
            del=p->next;
            p->next=p->next->next;
            free(del);
            break;
        }
        p=p->next;
    }
    if(p->next==NULL){
        return 1;
        //qDebug()<<"No such usr!";
    }
    return 0;
}

int validatemgr(char* name,char* pass){
    mgr* p=mgrhead;
    while(p->next!=NULL){
        if(strcmp(p->next->mgrid,name)==0){
            if(strcmp(p->next->passwd,pass)==0){
                //loginin
                return 1;
            }
            else{
                //wrong passwd
                return 0;
            }
        }
        p=p->next;
    }
    return 0;
}
