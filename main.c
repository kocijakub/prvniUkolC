#include <stdio.h>


float circleAreaCalc(float radius){
    return 3.14 * radius * radius;
}

int main(void) {
    printf("napis vypocet:");
    float first,second;
    char operation;
    scanf("%f %c %f",&first, &operation, &second);
    switch(operation){
        case '+':
            printf("%f",first+second);
            break;
        case '-':
            printf("%f",first-second);
            break;
        case '*':
            printf("%f",first*second);
            break;
        case '/':
            printf("%f",first/second);
    }
    return 0;
}
