#include<stdio.h> 
int  main() 
{ 
signed short k = 10;
printf("%d", k);
   unsigned int x = -1; 
   int y = ~0; 
   printf("%d", y);
   if (x == y) 
      printf("same"); 
   else
      printf("not same"); 
   return 0; 
}
