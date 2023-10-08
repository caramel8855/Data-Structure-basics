#include <stdio.h>
#include <stdlib.h>
#define size 100

char stack[size], top = -1; //declare a global variable 

int isFull(){
if(top ==size-1){
    return 1;
}
else {
    return 0;
}
}

int isEmpty(){
    if(top ==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push (char val){
if(isFull()){
    printf("Stack is full\n");
}
else{
    top = top+1;
    stack[top] = val;
}
}

char pop (){
    char val;
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else {
        val = stack[top];
        top = top-1;
        return val;
    }

}

char peek (){
    char val;
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else {
        val = stack[top];

        return val;
    }

}

//function to check if parenthesis are balanced
int isitbalanced (char exp[]){
    for(int i = 0 ; exp[i]!='\0'; i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isEmpty()){
                return 0;
            }
            char popped = pop();
            if((exp[i]==')' && popped != '(')||
            (exp[i]=='}' && popped != '{')||
            (exp[i]==']' && popped != '[')){
                return 0;
            }
        }
    }
    if(!isEmpty()){
        return 0 ;
    }
}


int main (){
    char exp[size];
    printf("Enter an Expression u want to check :\n");
    scanf("%s", exp);

    if(isitbalanced(exp)){
        printf("balanced!\n");
    } else {
        printf("Unbalanced!\n");
    }
    
return 0;
}
