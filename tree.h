#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct treeNode{
    char isOperator;
    int data;//isOperator=0 
    char mathOperator;//isOperator=1
    struct treeNode * lChild;//Left child 
    struct treeNode * rChild;//Right child 
};

int count(struct treeNode *root);
//Method untuk menghitung total dari proses proses dalam tree
int check(char mathExpression[], int firstIndex, int lastIndex);
//Method untuk memeriksa apakah inputan mengandung operator atau hanya angka.
struct treeNode * makeTree(char mathExpression[], int firstIndex, int lastIndex);
//Method untuk membuat tree
