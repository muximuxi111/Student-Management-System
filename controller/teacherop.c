#include"controller.h"
void teacher_controller(Tealistptr T_list,Stulistptr S_list)
{
    int flag=1;
    while(flag)
    {
        int choice;
        show_teacher_menu();

        scanf("%d",&choice);
        clear_buffer();

        switch(choice)
        {
            case 1:
                add_student(S_list);
                break;

            case 2:
            {
                printf("please input id:");
                int id;
                scanf("%d",&id);
                clear_buffer();
                delete_student(S_list,id);
                break;
            }

            case 3:
            {
                printf("please input id:");
                int id;
                scanf("%d",&id);
                clear_buffer();
                modify_student(S_list,id);
                break;
            }

            case 4:
            {
                show_student(S_list);
                break;
            }

            case 5:
            {
                sort_student_mathscore(S_list);
                break;
            }

            case 6:
            {
                sort_student_chinesescore(S_list);
                break;
            }


            case 7:
            {
                sort_student_englishscore(S_list);
                break;
            }

            case 8:
            {
                sort_student_overallscore(S_list);
                break;
            }

            case 9:
            {
                sort_student_id(S_list);
                break;
            }
            
            case 10:
            {
                printf("please input id:");
                int id;
                scanf("%d", &id);
                clear_buffer();
                modify_password_teacher(T_list,id);
                break;
            }

            case 11:
            {
                printf("please input id:");
                int id;
                scanf("%d", &id);
                clear_buffer();
                search_information_teacher(T_list,id);
                break;
            }

            case 0:
            {
                printf("exit teacher system\n");
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