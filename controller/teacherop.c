#include "controller.h"
int teacher_login_verification(Tealistptr list, int id)
{
    int times = 0;
    char password[20];
    Teacherptr p = search_teacher(list, id);
    if (p == NULL)
    {
        printf("not find this teacher\n");
        return -2;
    }
    while (times < 3)
    {
        printf("please input your password:");
        input_password(password);
        printf("\n");
        if (strcmp(password, p->password) == 0)
        {
            printf("login teacher system successful\n");
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

void teacher_controller(Tealistptr T_list, Stulistptr S_list)
{
    int flag = 1;
    int id;

    printf("please input your work_id:");
    scanf("%d", &id);
    clear_buffer();

    if (teacher_login_verification(T_list, id) != 0)
    {
        return;
    }

    while(flag)
    {
        int choice;

        system("cls");
        show_teacher_menu();

        scanf("%d", &choice);
        clear_buffer();

        switch(choice)
        {
        case 1:
        {
            add_student(S_list);
            system("pause");
            break;
        }

        case 2:
        {
            printf("please input id:");
            int id;
            scanf("%d", &id);
            clear_buffer();
            delete_student(S_list, id);
            system("pause");
            break;
        }

        case 3:
        {
            printf("please input id:");
            int id;
            scanf("%d", &id);
            clear_buffer();
            modify_student(S_list, id);
            system("pause");
            break;
        }

        case 4:
        {
            show_student(S_list);
            system("pause");
            break;
        }

        case 5:
        {
            sort_student_mathscore(S_list);
            printf("sort successful\n");
            system("pause");
            break;
        }

        case 6:
        {
            sort_student_chinesescore(S_list);
            printf("sort successful\n");
            system("pause");
            break;
        }

        case 7:
        {
            sort_student_englishscore(S_list);
            printf("sort successful\n");
            system("pause");
            break;
        }

        case 8:
        {
            sort_student_overallscore(S_list);
            printf("sort successful\n");
            system("pause");
            break;
        }

        case 9:
        {
            sort_student_id(S_list);
            printf("sort successful\n");
            system("pause");
            break;
        }

        case 10:
        {
            printf("please input id:");
            int id;
            scanf("%d", &id);
            clear_buffer();
            modify_password_teacher(T_list, id);
            system("pause");
            break;
        }

        case 11:
        {
            printf("please input id:");
            int id;
            scanf("%d", &id);
            clear_buffer();
            search_information_teacher(T_list, id);
            system("pause");
            break;
        }

        case 0:
        {
            printf("exit teacher system\n");
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