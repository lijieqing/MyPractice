//
// Created by lijie52 on 2021/11/26.
//
#include "lesson00.h"
#include "stdio.h"
#include "math.h"

void add(jint x, jint y){
    printf("%d + %d = %d",x,y,x+y);
}

bool isPrime(int x){
    if (x==2) return true;
    int newValue = (int)sqrt(x);
    printf("new value = %d", newValue);

}