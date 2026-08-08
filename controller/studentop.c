#include"controller.h"
void student_controller(Stulistptr list)
{
    int flag=1;
    while(flag)
    {
        int choice;
        show_student_menu();

        scanf("%d",&choice);
        clear_buffer();

        switch(choice)
        {
            case 1:
                printf("please input id:");
                int id;
                scanf("%d", &id);
                clear_buffer();
                modify_password_student(list,id);
                break;

            case 2:
            {
                printf("please input id:");
                int id;
                scanf("%d",&id);
                clear_buffer();
                search_information_student(list,id);
                break;
            }

            case 0:
            {
                printf("exit student system\n");
                flag = 0;
                break;
            }

            default:
                printf("choice error\n");
                break;

        }

        if(flag==0){
            break;
        }
    }
}