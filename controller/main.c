#include "controller.h"

int main()
{
    Stulistptr S_list = create_studentlist();

    load_student(S_list);

    Tealistptr T_list = create_teacherlist();

    load_teacher(T_list);

    Adminptr admin = create_admin();

    int flag = 1;
    while (flag)
    {
        system("cls");
        int choice;
        printf("==========Student_Management_System==========\n");
        printf("1.admin\n");
        printf("2.teacher\n");
        printf("3.student\n");
        printf("0.exit system\n");
        printf("==============================================\n");
        printf("please input:");

        scanf("%d", &choice);
        clear_buffer();

        switch (choice)
        {
        case 1:
            admin_controller(T_list, admin);
            system("pause");
            break;

        case 2:
            teacher_controller(T_list, S_list);
            system("pause");
            break;

        case 3:
            student_controller(S_list);
            system("pause");
            break;

        case 0:
        {
            printf("exit Student Management System \n");
            flag = 0;
            break;
        }
        default:
            printf("choice error\n");
            break;
        }

        if (flag == 0)
        {
            break;
        }
    }
    return 0;
}
