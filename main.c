#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char * scanStr(){
    char c;
    int sizeOfArr = 0;
    char * str = malloc(sizeof(char) * 4);
    while(c != '.'){
        scanf("%c",&c);
        char * temp =   realloc(str,(sizeOfArr + 1) * sizeof(char));
        str = temp;
        str[sizeOfArr] = c;
        sizeOfArr++;
    }

    return str;
}
int addToNum(int finalNum,int num, char op){
    switch(op){
        case '+':
            finalNum += num;
            break;
        case '-':
            finalNum -= num;
            break;
        case '*':
            finalNum *= num;
            break;
        case '/':
            finalNum /= num;
            break;
    }
    return finalNum;
}

char changeOp(char newOp){
    if(newOp == '+' || newOp == '-' || newOp == '*' || newOp == '/'){
        return newOp;
    }else{
        printf("wrong input");
        exit(0);
    }
}
int calculate(char * input){
    char numbers[] = {'*','*','*','\0'};
    size_t numSize = sizeof numbers;
    int finalNum = 0;
    char op = '+';
    int num = 0;
    for (int i = 0; input[i] != '.'; i++){
        if(isdigit(input[i])){
            for (int j = 0; j < numSize; j++) {
                if(numbers[j] == '*'){
                    numbers[j] = input[i];
                    break;
                }
            }
        }else{
            for(int j = 0; numbers[j] != '\0'; j++){
                if(isdigit(numbers[j])){
                    num = num * 10 + (numbers[j] - '0');
                    numbers[j] = '*';
                }
            }
            finalNum = addToNum(finalNum,num,op);
            num = 0;
            op = changeOp(input[i]);
        }
    }
    for(int j = 0; numbers[j] != '\0'; j++){
        if(isdigit(numbers[j])){
            num = num * 10 + (numbers[j] - '0');
            numbers[j] = '*';
        }
    }
    finalNum = addToNum(finalNum,num,op);
    return(finalNum);
}
int main() {
    printf("napis matematickou ulohu, nezapomen ji ukoncit teckou!\n");
    char * input = scanStr();
    int num = calculate(input);
    printf("%d",num);
}