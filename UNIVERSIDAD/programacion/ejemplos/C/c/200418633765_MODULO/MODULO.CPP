#include <stdio.h>
#include <conio.h>


main()
{
 int i,n,j,c=0,a[1000];

 clrscr();
 window(0, 0, 80, 25);
 textcolor(14);
 cprintf("Dime cuantos modulos quieres obtener \r\n");
 scanf("%d",&i);
 cprintf("Dame tu numero para obtener los modulos \r\n");
 scanf("%d",&n);
 clrscr();
 cprintf("*   tu numero es %4d   *\r\n",n);
 cprintf("*************************\r\n");
 cprintf("*      mod     resid    *\r\n");
 cprintf("*************************\r\n");

 for (j=0;j<i;j++)
     {
       a[j]=n%(j+1);

       if(a[j]!=1){
       textcolor(14);
       cprintf("       %d         %d     \r\n",j+1,a[j]);
       cprintf("*************************\r\n");
       }
       else{
       textcolor(RED+128);
       cprintf("       %d         %d     \r\n",j+1,a[j]);
       cprintf("*************************\r\n");
       }
      getch();
     }
return 0;
}
