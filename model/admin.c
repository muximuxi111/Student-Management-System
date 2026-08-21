#include"admin.h"

//初始化唯一管理员
Adminptr create_admin(){
    Adminptr t=malloc(sizeof(Admin));
    if(t==NULL){
        printf("create Admin error\n");
        return NULL;
    }
    
    //初始化管理员姓名
    strcpy(t->name,"muxi");

    //初始化密码
    strcpy(t->password,"123456");

    return t;
}


//修改密码
int  modify_password_admin(Adminptr t)
{
    if(t==NULL)
    {
        printf("admin error\n");
        return -1;
    }
    char old[20]="";
    char new1[20]="";
    char new2[20]="";
    printf("please input old passworld:");
    input_password(old);
    printf("\n");
    if(strcmp(old,t->password)!=0)
    {
        printf("password input error,please input again\n");
        return -1;
    }
    printf("input password correctly\n");

    while (1)
    {
        printf("please input you new password:");
        input_password(new1);            // 输入新密码
        printf("\n");
        printf("please confirm you new password:");
        input_password(new2);              // 确认新密码
        printf("\n");
        if (strcmp(new1, new2) == 0)
        { // 更换新密码
            strcpy(t->password, new2);
            printf("update password successful\n");
            break;
        }
        else
        {
            printf("The enter password is not same,please input again:\n");
        }
    }
    return 0;
}