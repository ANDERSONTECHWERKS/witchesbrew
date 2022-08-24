#include <stdio.h>

void echo(char* input){
    printf("%s",input);
}

void userInput(){
    char input1[20];
    char input2[20];
    printf("Please enter two strings, separated by whitespace (Up to 20 characters):\n");
    scanf("%s %s", &input1, &input2);
    printf("You entered:\nInput1: %s\nInput2: %s",input1,input2);
}

char* userInputAllocator(){

    char* result = calloc(20 ,sizeof(char));
    printf("Please enter one string to be stored in memory:\n");
    scanf("%s", result);

    return result;
}

void numbawang(){
    int i = 69;
    int* x = &i;
    int ** y = &x;
}

void main(){

    char* userInputResult;
    
    userInputResult = userInputAllocator();
    numbawang();
    userInput();
}

