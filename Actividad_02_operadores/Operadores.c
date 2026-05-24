#include <stdio.h>
#include <stdlib.h>

int main()
{

   int a=3;
    int b=4;
    int c=a++ + --b;
    printf("%d %d %d \n",a,b,c);

int x=10;
int y=3;
printf("%d \n",x+y*2);
printf("%d \n",(x+y)*2);

int i=5;
printf("%d \n",i++);
printf("%d \n",++i);

int A=5, B=2;
float r=A/B;
printf("%.2f \n",r);

int X=5,Y=3;
  if (X>Y){ //faltaba abrir la llave de del if
       printf("X es mayor");
} //faltaba cerrar la llave del if
  else{ //faltaba abri la llave del else
        printf("Y es mayor");
        }  //faltaba cerrar la llave del else
  printf("\n fin"); //Se pone fuera del else para que se impima en ambos casos y \n para dar un salto de liea
  /*el codigo anterior declara dos vaiables eteras
y despues las compara con un if, siendo que si x
es mayor imprimirá x es mayor y si no impimira y es
 mayor y fin en ambos casos* Ademas faltaba ideacion/
return 0;
}
