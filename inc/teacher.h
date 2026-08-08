#ifndef TEACHER_H
#define TEACHER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"public.h"
#include"student.h"

typedef struct Teacher
{
    char name[20];
    char password[20];
    int work_id;
    Sex sex;
    char birthday[20];
    struct Teacher *next;
}Teacher,*Teacherptr;

typedef struct Thaed
{
    Teacherptr head;
    int count; 
}Teacherlist,*Tealistptr;

//修改密码
int  modify_password_teacher(Tealistptr list,int work_id);
//查阅自身信息
Teacherptr search_information_teacher(Tealistptr list,int work_id);

// 创建教师链表
Tealistptr create_teacherlist();
// 创建教师节点
Teacherptr create_teacher();

//添加新教师
int add_teacher(Tealistptr list);
//查看所有教师
int show_all_teacher(Tealistptr list);
//删除教师
int delete_teacher(Tealistptr list,int work_id);
//修改教师信息
int modify_teacher(Tealistptr list,int work_id);
//查找老师
Teacherptr search_teacher(Tealistptr list,int work_id);
//存储老师信息
int save_teacher(Tealistptr list);
//从文件读取老师信息
int load_teacher(Tealistptr list);
//销毁老师链表
int destroy_teacher(Tealistptr list);
#endif