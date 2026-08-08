#include "public.h"

void clear_buffer()
{
    int c;

    while((c=getchar())!='\n' && c!=EOF);
}