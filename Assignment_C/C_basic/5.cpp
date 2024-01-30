#include <stdio.h>
 
int main()
{
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
 	
 	printf("%d %d %d %d %d\n",ptr1, ptr1+1, ptr1+2, ptr1+3, ptr1+4);
 	
    printf("%f \n", *ptr2);
    printf("%d\n", ptr2 - ptr1);
 
   return 0;
}
