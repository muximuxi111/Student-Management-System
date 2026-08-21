#include "controller.h"
int admin_login_verification(Adminptr list)
{
    int times = 0;
    char password[20];
    while (times < 3)
    {
        printf("please input admin password:");
        input_password(password);
        printf("\n");
        if (strcmp(password, list->password) == 0)
        {
            printf("login admin system successful\n");
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

void admin_controller(Tealistptr list, Adminptr admin)
{
    int flag = 1;

    if (admin_login_verification(admin) != 0)
    {
        return;
    }

    while (flag)
    {
        int choice;

        system("cls");   // 每次进入菜单清屏

        show_admin_menu();

        scanf("%d", &choice);
        clear_buffer();

        switch (choice)
        {

        case 1:
        {
            add_teacher(list);
            system("pause");
            break;
        }

        case 2:
        {
            printf("please input work_id\n");
            int id;
            scanf("%d", &id);
            clear_buffer();
            delete_teacher(list, id);
            system("pause");
            break;
        }

        case 3:
        {
            printf("please input work_id\n");
            int id;
            scanf("%d", &id);
            clear_buffer();
            modify_teacher(list, id);
            system("pause");
            break;
        }

        case 4:
        {
            show_all_teacher(list);
             system("pause");
            break;
        }

        case 5:
        {
            modify_password_admin(admin);
            system("pause");
            break;
        }

        case 0:
        {
            printf("exit admin system\n");
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