#include <stdio.h>
#include <stdbool.h>

int main() {
   
    char a = 'A';
    unsigned char b = 255;
    short c = 100;
    int d = 1000;
    unsigned int e = 5000;
    long f = 100000L;
    long long g = 9000000000LL;
    float h = 1.5f;
    double i = 3.1415;
    long double j = 2.718L;
    bool k = true;
   printf("VARIABLE         VALOR           DIRECCION (DECIMAL)\n");
    printf("------------------------------------------------------------\n");

  
    printf("char a:          %c               %20llu\n", a, (unsigned long long)&a);
    printf("u_char b:        %u             %20llu\n", b, (unsigned long long)&b);
    printf("short c:         %d             %20llu\n", c, (unsigned long long)&c);
    printf("int d:           %d            %20llu\n", d, (unsigned long long)&d);
    printf("u_int e:         %u            %20llu\n", e, (unsigned long long)&e);
    printf("long f:          %ld          %20llu\n", f, (unsigned long long)&f);
    printf("long long g:     %lld      %20llu\n", g, (unsigned long long)&g);
    printf("float h:         %.1f             %20llu\n", h, (unsigned long long)&h);
    printf("double i:        %.4f          %20llu\n", i, (unsigned long long)&i);
    printf("long double j:   %Lf        %20llu\n", j, (unsigned long long)&j);
    printf("bool k:          %d               %20llu\n", k, (unsigned long long)&k);

    return 0;
}
