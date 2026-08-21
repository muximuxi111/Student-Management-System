#include "controller.h"
int student_login_verification(Stulistptr list, int id)
{
    int times = 0;
    char password[20];
    Studentptr p = search_student(list, id);
    if (p == NULL)
    {
        printf("not find this student\n");
        return -2;
    }
    while (times < 3)
    {
        printf("please input your password:");
        input_password(password);
        printf("\n");
        if (strcmp(password, p->password) == 0)
        {
            printf("login student system successful\n");
            return 0;
        }
        else
        {
            if (times == 2)
            {
                printf("Login failed due to too many incorrect password\n");
                return -1;
            }
            printf("password input error,please input again\n");
        }
        times++;
    }
}

void student_controller(Stulistptr list)
{
    int flag = 1;
    int id;

    printf("please input your id:");
    scanf("%d", &id);
    clear_buffer();

    if (student_login_verification(list, id) != 0)
    {
        return;
    }

    while (flag)
    {
        system("cls");
        int choice;
        show_student_menu();
        scanf("%d", &choice);
        clear_buffer();

        switch (choice)
        {
        case 1:
        {
            printf("please input id:");
            int id;
            scanf("%d", &id);
            clear_buffer();
            modify_password_student(list, id);
            system("pause");
            break;
        }

        case 2:
        {
            printf("please input id:");
            int id;
            scanf("%d", &id);
            clear_buffer();
            search_information_student(list, id);
            system("pause");
            break;
        }

        case 0:
        {
            printf("exit student system\n");
            flag = 0;
            break;
        }

        default:
        {
            printf("choice error\n");
            break;
        }
         }
    }
}