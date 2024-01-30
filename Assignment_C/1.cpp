#include <stdio.h>
#define PRINT(i, limit) do \
                        { \
                            if ((i++) < limit) \
                            { \
                                printf("GeeksQuizn"); \
                                printf("%d", i);\
                            } \
                            else break;\
                        }while(1)
 
int main()
{
		int i = 0;                        

    PRINT(i, 3);
    return 0;
}
//#include <stdio.h>
//#define PRINT(i, limit) do { if (i++ < limit) { printf("GeeksQuiz\n"); } } while(1)
//
//int main()
//{
//    int i = 0;
//    PRINT(i, 3);
//    return 0;
//}

