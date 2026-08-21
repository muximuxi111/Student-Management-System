#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "viewer.h"


void student_controller(Stulistptr list);

void teacher_controller(Tealistptr T_list,Stulistptr S_list);

void admin_controller(Tealistptr list,Adminptr admin);

//登录验证
int admin_login_verification(Adminptr list);

int teacher_login_verification(Tealistptr list,int work_id);

int student_login_verification(Stulistptr list,int id);



#endif