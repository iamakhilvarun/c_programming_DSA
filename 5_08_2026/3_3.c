#include <stdio.h>

int main()
{
    int degree;
    int poly1[100];
    int poly2[100];
    int sum[100];
    
        printf("Enter the maximum no of degree: ");
        scanf("%d", &degree);

        //input of the polynomial 1
        for (int i = 0; i <= degree; i++)
        {
            printf("Enter the coefficient of poly1 x^%d: ",i);
            scanf("%d", &poly1[i]);
        }
        printf("\n");
        //input of the polynomial 2
        for (int i = 0; i <= degree; i++)
        {
            printf("Enter the coefficient of poly2 x^%d: ",i);
            scanf("%d", &poly2[i]);
        }

        // code for sum
        for (int i = 0; i <= degree; i++)
        {
            sum[i]=poly1[i]+poly2[i];
        }

        // printing the sum of the polynomial
        for(int i=0;i<=degree;i++){
            printf("%d",sum[i]);

            if (i>0){
                printf("x^%d",i);
            }
            if (i<degree){
                printf("+");
            }
        }
        
        return 0;
    }