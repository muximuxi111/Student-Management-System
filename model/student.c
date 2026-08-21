#include "student.h"

// 修改密码
int modify_password_student(Stulistptr list, int id)
{
    if (list == NULL)
    {
        printf("studentnode error\n");
        return -1;
    }
    Studentptr p = list->head;
    while (p != NULL)
    {
        if (p->ID == id)
        {
            break;
        }
        p = p->next;
    }

    if (p == NULL)
    {
        printf("student not found\n"); // 边界查询
        return -3;
    }

    printf("please input you old_password:");
    char s[20] = "";
    char new1[20] = "";
    char new2[20] = "";

    input_password(s);       // 输入旧密码
    printf("\n");

    if (strcmp(s, p->password) != 0)
    { // 确认密码是否输入正确
        printf("password input errot\n");
        return -2;
    }
    printf("input password correctly\n");

    while (1)
    {
        printf("please input you new password:");
        input_password(new1);          // 输入新密码
        printf("\n");

        printf("please confirm you new password:");
        input_password(new2);    // 确认新密码
        printf("\n");

        if (strcmp(new1, new2) == 0)
        { // 更换新密码
            strcpy(p->password, new2);
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
Studentptr search_information_student(Stulistptr list, int id)
{
    if (list == NULL)
    {
        printf("student list error\n");
        return NULL;
    }

    Studentptr p = list->head;

    while (p != NULL)
    {
        if (p->ID == id)
        {
            break;
        }

        p = p->next;
    }

    if (p == NULL)
    {
        printf("student not found\n");
        return NULL;
    }

    printf("\n");
    printf("================ Student Information ================\n");

    printf("%-12s%-18s%-12s%-15s%-12s%-12s%-12s%-12s\n",
           "ID",
           "Name",
           "Sex",
           "Birthday",
           "Math",
           "Chinese",
           "English",
           "Total");

    printf("%-12d", p->ID);

    printf("%-18s", p->name);

    if (p->sex == MALE)
    {
        printf("%-12s", "Male");
    }
    else if (p->sex == FEMALE)
    {
        printf("%-12s", "Female");
    }

    printf("%-15s", p->birthday);

    printf("%-12.2lf", p->math_score);

    printf("%-12.2lf", p->chinese_score);

    printf("%-12.2lf", p->english_score);

    printf("%-12.2lf\n", p->overall_score);

    printf("=====================================================\n");

    return p;
}

// 存储学生信息
int save_student(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }

    FILE *fp = fopen("student.dat", "wb");
    if (fp == NULL)
    {
        printf("open student file error\n");
        return -2;
    }

    char s1[20] = "MALE";
    char s2[20] = "FEMALE";

    Studentptr p = list->head;

    while (p != NULL)
    {
        fwrite(p->name, sizeof(p->name), 1, fp);

        fwrite(&p->ID, sizeof(p->ID), 1, fp);

        if (p->sex == 0)
        {
            fwrite(s1, sizeof(s1), 1, fp);
        }
        else
        {
            fwrite(s2, sizeof(s2), 1, fp);
        }

        fwrite(p->password, sizeof(p->password), 1, fp);

        fwrite(p->birthday, sizeof(p->birthday), 1, fp);

        fwrite(&p->math_score, sizeof(p->math_score), 1, fp);

        fwrite(&p->chinese_score, sizeof(p->chinese_score), 1, fp);

        fwrite(&p->english_score, sizeof(p->english_score), 1, fp);

        fwrite(&p->overall_score, sizeof(p->overall_score), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return 0;
}

// 从文件读取学生信息
int load_student(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }

    FILE *fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("open student file error\n");
        return -2;
    }

    while (1)
    {
        Studentptr p = malloc(sizeof(Student));
        if (p == NULL)
        {
            printf("teacher node error\n");
            fclose(fp);
            return -3;
        }

        p->next = NULL; // 避免next指针是随机分配的垃圾值

        char sex[20];

        if (fread(p->name, sizeof(p->name), 1, fp) != 1) // 文件读取内容为空就停止读取
        {
            free(p);
            break;
        }

        fread(&p->ID, sizeof(p->ID), 1, fp);

        fread(sex, sizeof(sex), 1, fp);

        fread(p->password, sizeof(p->password), 1, fp);

        fread(p->birthday, sizeof(p->birthday), 1, fp);

        fread(&p->math_score, sizeof(p->math_score), 1, fp);

        fread(&p->chinese_score, sizeof(p->chinese_score), 1, fp);

        fread(&p->english_score, sizeof(p->english_score), 1, fp);

        fread(&p->overall_score, sizeof(p->overall_score), 1, fp);

        if (strcmp(sex, "MALE") == 0)
        {
            p->sex = 0;
        }
        else
        {
            p->sex = 1;
        }

        Studentptr tail = list->head;
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

            tail->next = p;
        }
    }

    fclose(fp);

    return 0;
}

// 创造学生链表
Stulistptr create_studentlist()
{
    Stulistptr list = malloc(sizeof(Studentlist));
    if (list == NULL)
    {
        printf("create stulistptr error\n");
        return NULL;
    }
    list->count = 0;
    list->head = NULL;
    return list;
}

// 创建学生节点
Studentptr create_student()
{
    Studentptr s = malloc(sizeof(Student));
    if (s == NULL)
    {
        printf("create studentptr error\n");
        return NULL;
    }
    memset(s, 0, sizeof(Student));
    strcpy(s->password, "123456"); // 初始化密码

    printf("please input name:\n");
    scanf("%19s", s->name);

    printf("please input ID:\n");
    scanf("%d", &s->ID);

    printf("please input sex(0:MALE  1:FEMALE):\n");
    scanf("%d", &s->sex);
    if (s->sex == 0)
    {
        s->sex = MALE;
    }
    else if (s->sex == 1)
    {
        s->sex = FEMALE;
    }
    else
    {
        printf("sex input error\n");
    }
    printf("please input birthday:\n");
    scanf("%19s", s->birthday);

    printf("please input math_score:\n");
    scanf("%lf", &s->math_score);

    printf("please input chinese_score:\n");
    scanf("%lf", &s->chinese_score);

    printf("please input english_score:\n");
    scanf("%lf", &s->english_score);

    s->overall_score = (s->math_score + s->chinese_score + s->english_score);
    s->next = NULL;
    return s;
}

// 添加学生
int add_student(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr p = create_student();
    if (p == NULL)
    {
        printf(" new student node error\n");
        return -2;
    }
    //判断id唯一性
    if(search_student(list,p->ID)!=NULL)
    {
        printf("this id is exist,please input student information again\n");
        free(p);
        return -3;
    }
    p->next = list->head;
    list->head = p;
    list->count++;
    save_student(list);
    printf("add student successful\n");
    return 0;
}

// 删除学生
int delete_student(Stulistptr list, int id)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr del = search_student(list, id);
    if (del == NULL)
    {
        printf(" del student node error\n");
        return -2;
    }
    Studentptr p = list->head;
    if (p == NULL)
    {
        printf(" student node error\n");
        return -3;
    }
    if (p == del) // 第一个节点是删除节点的情况
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
    save_student(list);
    printf("delete student successful\n");
    return 0;
}

// 修改学生
int modify_student(Stulistptr list, int id)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr p = search_student(list, id);
    if (p == NULL)
    {
        printf(" student node error\n");
        return -3;
    }
    int c;
    printf("1.name\n");
    printf("2.sex\n");
    printf("3.birthday\n");
    printf("4.math\n");
    printf("5.chinese\n");
    printf("6.english\n");
    scanf("%d", &c);
    switch (c)
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
    case 4:
        printf("please input math_score:\n");
        scanf("%lf", &p->math_score);
        break;

    case 5:
        printf("please input chinese_score:\n");
        scanf("%lf", &p->chinese_score);
        break;

    case 6:
        printf("please input english_score:\n");
        scanf("%lf", &p->english_score);
        break;

    default:
        printf("choice error\n");
        return -3;
    }
    p->overall_score = (p->math_score + p->chinese_score + p->english_score);
    save_student(list);
    printf("update student informathion succssful\n");
    return 0;
}
// 查找学生
Studentptr search_student(Stulistptr list, int id)
{
    if (list == NULL)
    {
        printf("list error\n");
        return NULL;
    }
    Studentptr p = list->head;
    while (p != NULL)
    {
        if (p->ID == id)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

// 展示所有学生
int show_student(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }

    Studentptr p = list->head;

    printf("%-12s%-18s%-12s%-15s%-12s%-12s%-12s%-12s\n",
           "ID",
           "Name",
           "Sex",
           "Birthday",
           "Math",
           "Chinese",
           "English",
           "Total");

    while (p != NULL)
    {
        printf("%-12d", p->ID);

        printf("%-18s", p->name);

        if (p->sex == MALE)
        {
            printf("%-12s", "Male");
        }
        else if (p->sex == FEMALE)
        {
            printf("%-12s", "Female");
        }

        printf("%-15s", p->birthday);

        printf("%-12.2lf", p->math_score);

        printf("%-12.2lf", p->chinese_score);

        printf("%-12.2lf", p->english_score);

        printf("%-12.2lf\n", p->overall_score);

        p = p->next;
    }

    return 0;
}

// 排序遍历
// id排序
int sort_student_id(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr i = list->head;
    Studentptr j = list->head;
    Student temp;
    for (i = list->head; i != NULL; i = i->next)
    {
        Studentptr max = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (max->ID > j->ID)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = *i;
            *i = *max;
            *max = temp;
        }

        Studentptr next = i->next; //  因为结构体Student里有next指针交换后需要再交换回来
        i->next = max->next;
        max->next = next;
    }
    show_student(list);
    return 0;
}

// 数学成绩排序
int sort_student_mathscore(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr i = list->head;
    Studentptr j = list->head;
    Student temp;
    for (i = list->head; i != NULL; i = i->next)
    {
        Studentptr max = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (max->math_score < j->math_score)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = *i;
            *i = *max;
            *max = temp;
        }

        Studentptr next = i->next; //  因为结构体Student里有next指针交换后需要再交换回来
        i->next = max->next;
        max->next = next;
    }
    show_student(list);
    return 0;
}

// 语文成绩排序
int sort_student_chinesescore(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr i = list->head;
    Studentptr j = list->head;
    Student temp;
    for (i = list->head; i != NULL; i = i->next)
    {
        Studentptr max = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (max->chinese_score < j->chinese_score)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = *i;
            *i = *max;
            *max = temp;
        }

        Studentptr next = i->next; //  因为结构体Student里有next指针交换后需要再交换回来
        i->next = max->next;
        max->next = next;
    }
    show_student(list);
    return 0;
}

// 按英语成绩排序
int sort_student_englishscore(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr i = list->head;
    Studentptr j = list->head;
    Student temp;
    for (i = list->head; i != NULL; i = i->next)
    {
        Studentptr max = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (max->english_score < j->english_score)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = *i;
            *i = *max;
            *max = temp;
        }

        Studentptr next = i->next; //  因为结构体Student里有next指针交换后需要再交换回来
        i->next = max->next;
        max->next = next;
    }
    show_student(list);
    return 0;
}

// 按总成绩排序
int sort_student_overallscore(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr i = list->head;
    Studentptr j = list->head;
    Student temp;
    for (i = list->head; i != NULL; i = i->next)
    {
        Studentptr max = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (max->overall_score < j->overall_score)
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = *i;
            *i = *max;
            *max = temp;
        }

        Studentptr next = i->next; //  因为结构体Student里有next指针交换后需要再交换回来
        i->next = max->next;
        max->next = next;
    }
    show_student(list);
    return 0;
}

// 销毁学生链表
int destroy_studentlist(Stulistptr list)
{
    if (list == NULL)
    {
        printf("list error\n");
        return -1;
    }
    Studentptr p = list->head;
    while (p != NULL)
    {
        Studentptr del = p;
        p = p->next;
        free(del);
    }
    free(list);
    printf("destroy studentlist successful\n");
    return 0;
}
