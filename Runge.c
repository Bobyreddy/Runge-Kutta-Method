#include<stdio.h>

float f(float X, float Y);

void main(){
    float y0, x0, x, h, K[50], n, F;
    char s;
    printf(" enter Y(0):");
    scanf("%f", &y0);
    printf(" enter X :");
    scanf("%f", &x);
    x0 = 0;
    h = x - x0;
    printf("enter number of iterations to be performed: ");
    scanf("%f", &n);
    for(int i = 1; i <= n; i++){
        if(i == 1){
            K[i] = h * f(x0, y0);
            printf("k%d = %.4f \n", i, K[i]);
        }
        
        else if(i>1 && i<4){
            K[i] = h * f(x0 + (h/2), y0 + (K[i-1]/2));
            printf("k%d = %.4f \n", i, K[i]);
        }
        else if(i == 4){
            K[i] = h * f(x0 + h, y0 +K[i-1]);
            printf("k%d = %.4f \n", i, K[i]);
        }
    }

    F = y0 + (((K[1]) + (2.0 * K[2]) + (2.0 * K[3]) + (K[4]))/6);
    printf("Y(%.2f) = %.4f is the required solution\n", x0+h, F);
}

float f(float X, float Y){
    float z;
    z = 3 * X + Y ;
    return z; 
}