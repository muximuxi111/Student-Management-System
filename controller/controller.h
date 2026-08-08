#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "viewer.h"


void student_controller(Stulistptr list);

void teacher_controller(Tealistptr T_list,Stulistptr S_list);

void admin_controller(Tealistptr list,Adminptr admin);


#endif