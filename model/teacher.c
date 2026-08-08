#include "teacher.h"

// 修改密码
int modify_password_teacher(Tealistptr list, int work_id)
{
    if (list == NULL)
    {
        printf("Teacher p error\n");
        return -1;
    }
    Teacherptr p = list->head;
    while (p != NULL)
    {
        if (p->work_id == work_id)
        {
            break;
        }
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Teacher not found\n"); // 边界查询
        return -3;
    }

    printf("please input you old_password:");
    char t[20] = "";
    char new1[20] = "";
    char new2[20] = "";

    fgets(t, sizeof(t), stdin); // 输入旧密码
    t[strcspn(t, "\n")] = '\0';

    if (strcmp(t, p->password) != 0)
    { // 确认密码是否输入正确
        printf("password input error\n");
        return -2;
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
            strcpy(p->password, new2);
            save_teacher(list);
            printf("update password successful\n");
            break;
        }
        else
        {
            printf("The enter password is not same,please input again\n");
        }
    }
    return 0;
}

// 查阅自身信息
Teacherptr search_information_teacher(Tealistptr list, int work_id)
{
    if (list == NULL)
    {
        printf("Teacher p error\n");
        return NULL;
    }

    Teacherptr p = list->head;

    while(p != NULL)
    {
        if(p->work_id == work_id)
        {
            break;
        }

        p = p->next;
    }

    if(p == NULL)
    {
        printf("Teacher not found\n");
        return NULL;
    }

    printf("\n");
    printf("=========== Teacher Information ===========\n");

    printf("%-12s%-20s%-12s%-15s\n",
           "ID",
           "Name",
           "Sex",
           "Birthday");

    printf("%-12d",p->work_id);

    printf("%-20s",p->name);

    if(p->sex == MALE)
    {
        printf("%-12s","Male");
    }
    else if(p->sex == FEMALE)
    {
        printf("%-12s","Female");
    }

    printf("%-15s",p->birthday);

    printf("\n");

    printf("============================================\n");

    return p;
}

// 存储老师信息
int save_teacher(Tealistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    FILE *fp = fopen("teacher.dat", "wb");
    if (fp == NULL)
    {
        printf("open teacher file error\n");
        return -2;
    }

    char s1[20] = "MALE";
    char s2[20] = "FEMALE";

    Teacherptr p = list->head;

    while (p != NULL)
    {
        fwrite(p->name, sizeof(p->name), 1, fp);

        fwrite(&p->work_id, sizeof(p->work_id), 1, fp);

        if (p->sex == 0)
        {
            fwrite(s1, sizeof(s1), 1, fp);
        }
        else
        {
            fwrite(s2, sizeof(s2), 1, fp);
        }

        fwrite(p->password,sizeof(p->password),1,fp);

        fwrite(p->birthday, sizeof(p->birthday), 1, fp);

        p = p->next;
    }
    fclose(fp);
    return 0;
}

// 从文件读取老师信息
int load_teacher(Tealistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }

    FILE *fp = fopen("teacher.dat", "rb");

    if (fp == NULL)
    {
        printf("open teacher file error\n");
        return -2;
    }

    while (1)
    {
        Teacherptr p = malloc(sizeof(Teacher));
        if (p == NULL)
        {
            printf("teacher node error\n");
            fclose(fp);
            return -3;
        }

        p->next=NULL;   //避免next指针是随机分配的垃圾值

        char sex[20];

        if (fread(p->name, sizeof(p->name), 1, fp) != 1)
        {
            free(p);
            break;
        }

        fread(&p->work_id, sizeof(p->work_id), 1, fp);

        fread(sex, sizeof(sex), 1, fp);

        fread(p->password, sizeof(p->password), 1, fp);

        fread(p->birthday, sizeof(p->birthday), 1, fp);

        if (strcmp(sex, "MALE") == 0)
        {
            p->sex = 0;
        }
        else
        {
            p->sex = 1;
        }

        Teacherptr tail = list->head;
        if (list->head == NULL)
        {
            list->head = p;
        }
        else
        {
            while (tail->next != NULL)
            {
                tail = tail->next;
            }

            tail->next=p;
        }
    }

    fclose(fp);

    return 0;
}

// 创建教师链表
Tealistptr create_teacherlist()
{
    Tealistptr list = malloc(sizeof(Teacherlist));
    if (list == NULL)
    {
        printf("creatre Teacherlist error\n");
        return NULL;
    }
    list->count = 0;
    list->head = NULL;
    return list;
}

// 创建教师节点
Teacherptr create_teacher()
{
    Teacherptr t = malloc(sizeof(Teacher));
    if (t == NULL)
    {
        printf("create teacher p error\n");
        return NULL;
    }
    memset(t, 0, sizeof(Teacher));
    strcpy(t->password, "123456"); // 初始化密码
    printf("please input name:\n");
    scanf("%19s", t->name);

    printf("please input ID:\n");
    scanf("%d", &t->work_id);

    printf("please input sex(0:MALE  1:FEMALE):\n");
    scanf("%d", &t->sex);
    if (t->sex == 0)
    {
        t->sex = MALE;
    }
    else if (t->sex == 1)
    {
        t->sex = FEMALE;
    }
    else
    {
        printf("sex input error\n");
    }

    printf("please input birthday:\n");
    scanf("%19s", t->birthday);

    t->next = NULL;
    return t;
}

// 添加新教师
int add_teacher(Tealistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Teacherptr p = create_teacher();
    if (p == NULL)
    {
        printf(" new teacher p error\n");
        return -2;
    }
    p->next = list->head;
    list->head = p;
    list->count++;

    save_teacher(list);
    printf("add teacher successful\n");
    return 0;
}

// 查看所有教师
int show_all_teacher(Tealistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }

    Teacherptr p = list->head;

    printf("%-12s%-15s%-12s%-15s\n",
           "WORK_ID",
           "Name",
           "Sex",
           "Birthday");

    while(p != NULL)
    {
        printf("%-12d", p->work_id);

        printf("%-15s", p->name);

        if(p->sex == MALE)
        {
            printf("%-12s", "Male");
        }
        else if(p->sex == FEMALE)
        {
            printf("%-12s", "Female");
        }

        printf("%-15s", p->birthday);

        printf("\n");

        p=p->next;
    }

    return 0;
}

// 删除教师
int delete_teacher(Tealistptr list, int work_id)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }

    Teacherptr del = search_teacher(list, work_id);
    if (del == NULL)
    {
        printf("teacher not found\n");
        return -2;
    }

    Teacherptr p = list->head;
    if (del == list->head)
    {
        list->head = del->next;
    }
    else
    {
        while (p->next != del)
        {
            p = p->next;
        }
        p->next = del->next;
    }

    free(del);
    list->count--;

    // 删除链表节点后同步文件
    save_teacher(list);

    printf("delete teacher p successful\n");
    return 0;
}
// 修改教师信息
int modify_teacher(Tealistptr list, int work_id)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Teacherptr p = search_teacher(list, work_id);
    if (p == NULL)
    {
        printf(" teacher p error\n");
        return -2;
    }
    int chioce;
    printf("1.name\n");
    printf("2.sex\n");
    printf("3.birthday\n");
    scanf("%d", &chioce);
    switch (chioce)
    {
    case 1:
        printf("please input name:\n");
        scanf("%19s", p->name);
        break;
    case 2:
        printf("please input sex(0:MALE  1:FEMALE):\n");
        scanf("%d", &p->sex);
        if (p->sex == 0)
        {
            p->sex = MALE;
        }
        else if (p->sex == 1)
        {
            p->sex = FEMALE;
        }
        else
        {
            printf("sex input error\n");
        }
        break;
    case 3:
        printf("please input birthday:\n");
        scanf("%19s", p->birthday);
        break;
    default:
        printf("choice error\n");
        return -3;
    }
    // 修改教师信息后重新写入文件
    save_teacher(list);
    printf("update teacher informathion succssful\n");
    return 0;
}
// 查找老师
Teacherptr search_teacher(Tealistptr list, int work_id)
{
    if (list == NULL)
    {
        printf("list error\n");
        return NULL;
    }
    Teacherptr p = list->head;
    while (p != NULL)
    {
        if (p->work_id == work_id)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}



// 销毁老师链表
int destroy_teacher(Tealistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Teacherptr p = list->head;
    while (p != NULL)
    {
        Teacherptr del = p;
        p = p->next;
        free(del);
    }
    free(list);
    printf("destroy teacherlist successful\n");
    return 0;
}
