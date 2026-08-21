#ifndef PUBLIC_H
#define PUBLIC_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
typedef enum {
    MALE,
    FEMALE
}Sex;

void clear_buffer();

//密码加密
void input_password(char *password);
#endif