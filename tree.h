#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct data{
	int angka;
	char mathOperator;
};

typedef struct calcTree{
	struct data isi_data;
    struct calcTree * lChild;//Left child 
    struct calcTree * rChild;//Right child 
};

int count(struct calcTree *root);
//Method untuk menghitung total dari proses proses dalam tree
int check(char mathExpression[], int firstIndex, int lastIndex);
//Method untuk memeriksa apakah inputan mengandung operator atau hanya angka.
struct calcTree * makeTree(char mathExpression[], int firstIndex, int lastIndex);
//Method untuk membuat tree
char isOperator(struct calcTree *root);
//Method untuk mengecek opetator atau bukan