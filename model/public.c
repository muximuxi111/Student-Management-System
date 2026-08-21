#include "public.h"

// 吸收垃圾字符
void clear_buffer()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// 密码加密
void input_password(char *password)
{
    char ch;
    int i = 0;
    while (1)
    {
        ch = _getch(); // 不显示输入字符
        if (ch == '\r')
        {
            password[i] = '\0';
            break;
        }
        if (ch == '\b')
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            password[i++] = ch;
            printf("*");
        }
    }
}