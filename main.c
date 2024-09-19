#include <stdio.h>
#include <windows.h>

void drawWalls(int size, int height, int fenceSize){
    size = size % 2 == 0 ? size + 1 : size;
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < size; j++){
            if(i == 0 || i == height-1 || j == 0 || j == size-1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        if(i != 0){
            int endingNum;
            for (int j = 0; j < fenceSize; ++j) {
                if(j % 2 == 0){
                    printf("-");
                }else{
                    printf("|");
                }
                if(j == fenceSize - 1) endingNum = j;
            }
            if(endingNum % 2 == 0)printf("|");

        }
        printf("\n");
    }
}
void drawRoof(int size){
    int center = size / 2;
    int j = 0;
    for(int height = 0; height < size / 2 + 1; height++){
        for(int index = 0; index <= size; index++){
            if(index == center + j ||index == center - j){
                printf("*");
            }else{
                printf(" ");
            }
        }
        j++;
        printf("\n");
    }
}
int main(void) {
    int roofSize;
    int houseHeight;
    int fenceSize;
    printf("napis velikost strechy: \n");
    scanf("%d",&roofSize);
    printf("napis velikost domu: \n");
    scanf("%d", &houseHeight);
    printf("napis velikost plotu: \n");
    scanf("%d",&fenceSize);
    drawRoof(roofSize);
    drawWalls(roofSize,houseHeight,fenceSize);
}
