#include "viewer.h"



void show_admin_menu()
{
    printf("\n");
    printf("========== Admin ==========\n");
    printf("1. add teacher\n");
    printf("2. delete teacher\n");
    printf("3. modify teacher\n");
    printf("4. show teacher\n");
    printf("5. modify password\n");
    printf("0. exit\n");
    printf("===========================\n");

    printf("please input:");
}


void show_teacher_menu()
{
    printf("\n");
    printf("========== Teacher ==========\n");
    printf("1. add student\n");
    printf("2. delete student\n");
    printf("3. modify student\n");
    printf("4. show student\n");
    printf("5. sort math score\n");
    printf("6. sort chinese score\n");
    printf("7. sort english score\n");
    printf("8. sort overall score\n");
    printf("9. sort id\n");
    printf("10. modify password\n");
    printf("11. show my information\n");
    printf("0. exit\n");
    printf("=============================\n");

    printf("please input:");
}


void show_student_menu()
{
    printf("\n");
    printf("========== Student ==========\n");
    printf("1. modify password\n");
    printf("2. show my information\n");
    printf("0. exit\n");
    printf("=============================\n");

    printf("please input:");
}