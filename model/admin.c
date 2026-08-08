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
    fgets(old,sizeof(old),stdin);
    old[strcspn(old,"\n")]='\0';
    if(strcmp(old,t->password)!=0)
    {
        printf("password input error,please input again\n");
        return -1;
    }
    printf("input password correctly\n");

    while (1)
    {
        printf("please input you new password:");
        fgets(new1, sizeof(new1), stdin); // 输入新密码
        new1[strcspn(new1, "\n")] = '\0';
        printf("please confirm you new password:");
        fgets(new2, sizeof(new2), stdin); // 确认新密码
        new2[strcspn(new2, "\n")] = '\0';
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