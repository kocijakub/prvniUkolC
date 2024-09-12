#include <stdio.h>
#include <windows.h>

int main(void) {
    SetConsoleOutputCP(65001);
    printf("napiš výpočet:");
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
            if(second == 0){
                fprintf(stderr,"ty možná umíš dělit nulou ale tenhle program fakt ne");
            }else{
                printf("%f",first/second);
            }
    }
    return 0;
}
