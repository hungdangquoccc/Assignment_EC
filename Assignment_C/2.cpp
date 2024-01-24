#include <stdio.h>
//int X = 3; 
//#define X 3
#if X == 0
    #define Y 3
#else
    #define Y 5
#endif
 
int main()
{
//	printf("%d\n", X);
	
    printf("%d", Y);
    return 0;
}
