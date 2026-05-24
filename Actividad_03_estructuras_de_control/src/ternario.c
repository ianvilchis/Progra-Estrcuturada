#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    int b=2;
    int c=30;
    int d=0;
    d=a<(b||--c)?1:0;
    d+=10;
    d=d|++b;
    d++;
    printf("d vale:%d",--d);
    return 0;
}
