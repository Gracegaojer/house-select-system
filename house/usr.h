#ifndef USR_H
#define USR_H
typedef struct usr_{
    char usrid[20];
    char passwd[20];
    char blockid[20][20];
    char buildid[20][20];
    char houseid[20][20];//一个用户只能标记20个
    int starnum;
    struct usr_ * next;
}usr;

typedef struct mgr_{
    char mgrid[20];
    char passwd[20];
    struct mgr_ * next;
}mgr;

int newusr(char * name,char * pswd);
int delusr(char * name);
int validateusr(char* name,char* pass);
int insertusr(usr* u);
usr* findusr(char* usrid);
int newmgr(char * name,char * pswd);
int delmgr(char * name);
int insertmgr(mgr* m);
int validatemgr(char* name,char* pass);
#endif // USR_H
