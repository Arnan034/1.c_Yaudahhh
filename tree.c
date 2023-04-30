#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "tree.h"
#define MAX 0x3f3f3f3f
char isOperator(struct calcTree *root){
	char temp;
	if(root->isi_data.mathOperator == NULL){
		temp = '0';
		return temp; 
	}else{
		temp = '1';
		return temp;
	}
}
int count(struct calcTree *root){
    if(isOperator(root)=='1'){
        switch(root->isi_data.mathOperator){
            case '+':{
                return count(root->lChild)+count(root->rChild);
                break;
            }
            case '-':{
                return count(root->lChild)-count(root->rChild);
                break;
            }
            case '/':{
                return count(root->lChild)/count(root->rChild);
                break;
            }
            case '*':{
                return count(root->lChild)*count(root->rChild);
                break;
            }
            case '^':{
                return pow(count(root->lChild),count(root->rChild));
                break;
            }
        }
	}
    return root->isi_data.angka;
}
int check(char mathExpression[],int firstIndex,int lastIndex){
    int i;
    int sum=0;
    int isOperator=1;
    if(mathExpression[firstIndex]=='-'){
        isOperator=-1;
        firstIndex++;
    }
    for(i=firstIndex;i<=lastIndex;i++){
        if(!isdigit(mathExpression[i])){
			return MAX;	
			//Kalau masuk kesini berarti itu tandanya operator (Fahri)
		}
        sum=sum*10+mathExpression[i]-'0';
        //ini merepresentasikan operandnya, kenapa gini? karena misalkan 30 atau 100, nanti hasilnya akan 30 atau 100, tidak hanya 3 saja atau 1 saja (Fahri)
    }
    return sum*isOperator;
}
void postOrder(struct calcTree *root){
    if(root){
        postOrder(root->lChild);
        postOrder(root->rChild);
        if(isOperator(root) == '0'){
            printf("%d ",root->isi_data.angka);
        }
        else{
            printf("%c ",root->isi_data.mathOperator);
        }       
    }
} 
struct calcTree * makeTree(char mathExpression[],int firstIndex,int lastIndex){
   	struct calcTree * root=(struct calcTree *)malloc(sizeof(struct calcTree));
    int posPlusOrSub=0;//Posisi dari operator penjumlahan (-) dan pengurangan (-) 
    int numPlusOrSub=0;//Jumlah dari operator penjumlahan(+) dan pengurangan (-) 
    int posDivOrMul=0;//Posisi dari operator perkalian(*) dan pembagian (/) 
    int numDivOrMul=0;//Jumlah dari operator perkalian (*) dan pembagian(/)
	int posExp=0;//Posisi dari operator pangkat (^)
	int numExp=0;//Jumlah operator pangkat (^)
    int num;
    num=check(mathExpression,firstIndex,lastIndex);
	//Memeriksa jika hanya angka yang menjadi input 
	//Kalau hasil num yang sudah tadi masuk modul check berisi nilai MAX maka dia itu operator, yang mana dia tidak adakn masuk ke pengkondisian atau if (Fahri)
	//Sebaliknya jika num tersebut bukan berisi dari hasil MAX, maka dia itu operand yang nantinya akan masuk ke pengkondisian atau ifnya (Fahri)    
    if(num!=MAX){
    	//root->isOperator='0';
        root->isi_data.mathOperator=NULL;
        root->isi_data.angka=num;
        root->lChild=NULL;
        root->rChild=NULL;
        return root;
    }
    //There are operators 
    int in_brackets=0;//Identifiers not in parentheses
	int k;
    for(k=firstIndex;k<=lastIndex;k++){
        if(mathExpression[k]=='('){
            in_brackets++;
        }
        else if(mathExpression[k]==')'){
            in_brackets--;
        }
        //Bracket akan diskip terlebih dahulu, karena hirarkinya terbalik dalam tree itu, dari root itu yang paling belakangan dihitungnya (Fahri)
        if(!in_brackets){//Outside the brackets 
            if(mathExpression[k]=='+'||mathExpression[k]=='-'){
                posPlusOrSub=k;
                numPlusOrSub++;
            }
            else if(mathExpression[k]=='*'||mathExpression[k]=='/'){
                posDivOrMul=k;
                numDivOrMul++;
            }
            else if(mathExpression[k]=='^'){
                posExp=k;
                numExp++;
            }
        }
    }
    int pos_root;
    
    //Mencari root dengan node penjumlahan dan pengurangan
    if(numPlusOrSub){
        pos_root=posPlusOrSub;
    }
    //Mencari root dengan node penjumlahan dan pengurangan
    else if(numDivOrMul){
        pos_root=posDivOrMul;
    }
    //Mencari root dengan node perpangkatan
    else if(numExp){
        pos_root=posExp;
    }
    //Jika root tidak dapat ditemukan
    else{
        return makeTree(mathExpression,firstIndex+1,lastIndex-1);
    }
	//root->isOperator='1';
    root->isi_data.mathOperator=mathExpression[pos_root];
    root->lChild = makeTree(mathExpression,firstIndex,pos_root-1);
    root->rChild = makeTree(mathExpression,pos_root+1,lastIndex);
    return root;
}
