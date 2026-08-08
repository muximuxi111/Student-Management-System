#include"controller.h"
void admin_controller(Tealistptr list,Adminptr admin)
{
    int flag=1;
    while(flag)
    {
        int choice;
        show_admin_menu();

        scanf("%d",&choice);
        clear_buffer();

        switch(choice)
        {
            case 1:
                add_teacher(list);
                break;

            case 2:
            {
                printf("please input work_id\n");
                int id;
                scanf("%d",&id);
                clear_buffer();
                delete_teacher(list,id);
                break;
            }

            case 3:
            {
                printf("please input work_id\n");
                int id;
                scanf("%d",&id);
                clear_buffer();
                modify_teacher(list,id);
                break;
            }

            case 4:
            {
                show_all_teacher(list);
                break;
            }

            case 5:
            {
                modify_password_admin(admin);
                break;
            }


            case 0:
            {
                printf("exit admin system\n");
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