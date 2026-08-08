#ifndef ADMIN_H
#define ADMIN_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"teacher.h"

typedef struct Admin
{
    char name[20];
    char password[20];
}Admin,*Adminptr;

//初始化唯一管理员
Adminptr create_admin();

//修改密码
int  modify_password_admin(Adminptr t);


#endif