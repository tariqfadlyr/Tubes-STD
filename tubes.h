#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define Top(s) (s).Top
#define info(s) (s).info

typedef string infotype1;
typedef int infotype2;

struct Stack1 {
    infotype1 info[10];
    int Top;
};

struct Stack2 {
    infotype2 info[20];
    int Top;
};

void createStack(Stack1 &S);
void createStack2(Stack2 &S);
bool isEmpty(Stack1 S);
bool isEmpty2(Stack2 S);
bool isFull(Stack1 S);
bool isFull2(Stack2 S);
void push(Stack1 &S, infotype1 x);
void push2(Stack2 &S, infotype2 x);
infotype1 pop(Stack1 &S);
infotype2 pop2(Stack2 &S);
void print(Stack1 S);

bool isOperator(char x);
infotype1 postfixToPrefix(Stack1 S, string x);
void urut(infotype2 X[10], int n);
#endif // TUBES_H_INCLUDED
