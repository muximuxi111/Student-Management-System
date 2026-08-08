#ifndef STUDENT_H
#define STUDENT_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"public.h"
#define STUDENT_MAX 1000

typedef struct Student
{
    char name[20];
    char password[20];
    int ID;
    Sex sex;
    char birthday[20];
    double math_score;
    double chinese_score;
    double english_score;
    double overall_score;
    struct Student *next;
}Student,*Studentptr;

typedef struct Head
{
    Studentptr head;
    int count; 
}Studentlist,*Stulistptr;

//修改密码
int modify_password_student(Stulistptr list,int id);
//查阅自身信息
Studentptr search_information_student(Stulistptr list,int id);
//创造学生链表
Stulistptr create_studentlist();
//创建学生节点
Studentptr create_student();
//添加学生
int add_student(Stulistptr list);
//删除学生
int delete_student(Stulistptr list,int id);
//修改学生
int modify_student(Stulistptr list,int id);
//查找学生
Studentptr search_student(Stulistptr list,int id);
//展示所有学生
int show_student(Stulistptr list);
//排序查找
//id排序
int sort_student_id(Stulistptr list);
//数学成绩排序
int sort_student_mathscore(Stulistptr list);
//语文成绩排序
int sort_student_chinesescore(Stulistptr list);
//英语成绩排序
int sort_student_englishscore(Stulistptr list);
//总成绩排序
int sort_student_overallscore(Stulistptr list);
// 存储学生信息
int save_student(Stulistptr list);
// 从文件读取学生信息
int load_student(Stulistptr list);
//销毁学生链表
int destroy_studentlist(Stulistptr list);

#endif