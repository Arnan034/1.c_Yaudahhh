#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "temperature.h"

void clevCalcMenu(){
	printf("\n------- Menu Aplikasi ClevCalc -------\n");
    printf("1. Kalkulator Ilmiah \n");
    printf("2. Suhu Konverter \n");
    printf("3. Cara Penggunaan \n");
    printf("4. Keluar \n");
    printf("------------------------------\n");
    printf("Pilih nomor menu: ");
}
void calculatorMenu(){
	printf("\n------- Menu Aplikasi ClevCalc -------\n");
    printf("\t Kalkulator Ilmiah \n");
    printf("---------------------------------------\n");
    printf("Masukan ekspresi matematika :");
}
void aboutCalculator(){
	char rules[255];
	FILE *in=fopen("howto.txt","r");//perintah untuk membuka file dengan mode r / read
	system("cls");
	printf("\n");
    while(!feof(in)){
        fscanf(in,"%[^\n]\n", &rules);fflush(stdin);   
        // %[^\n] artinya kita menyimpan bagian dari string dalam file sampai tanda \n atau newline. 
        // Kita tidak menggunnakan %s karena aturan mengandung spasi
        printf("%s\n", rules);
    }
	fclose(in);//perintah untuk menutup file yang tadi dibuka
	printf("\nTekan tombol apapun untuk kembali ke menu utama.....");
	getch();
}
void runCalculator(){
	int pil;
	char cobaLagi;
	AppMenu:
	clevCalcMenu();
	scanf("%d",&pil);
    fflush(stdin);
    if(pil==1){
        char expression[200];
        CalculatorMenu:
        calculatorMenu();
        scanf("%s",expression);
        fflush(stdin);
        printf("ekspresi yang kamu masukan : %s\n",expression);
        struct treeNode* binaryTree=(struct treeNode *)malloc(sizeof(struct treeNode));
        binaryTree = makeTree(expression,0,strlen(expression)-1);
        printf("Hasil nya adalah : %d\n",count(binaryTree));
        printf("Apakah ingin mencoba lagi ? : ");
        scanf("%c", &cobaLagi);
        fflush(stdin);
        if(cobaLagi =='Y'||cobaLagi=='y'){
        	system("cls");
        	goto CalculatorMenu;
		}
		system("cls");
		goto AppMenu;
	}
	else if(pil==2){
		char cobaLagiKonversi;
		int pilMenuKonversi;
		ConversionMenu:
		mainMenu();
		scanf("%d", &pilMenuKonversi);
		fflush(stdin);
		switch (pilMenuKonversi){
			case 1:
				countCelcius();
				break;
			case 2:
				countReamur();
				break;
			case 3:
				countFahrenheit();
				break;
			case 4:
				countKelvin();
				break;
			case 5:
				goto AppMenu;
				break;
			default :
				goto ConversionMenu;
				break;
		}
		printf("Apakah ingin mencoba lagi ? : ");
		scanf("%c", &cobaLagiKonversi);
        fflush(stdin);
		if(cobaLagiKonversi == 'Y'||cobaLagiKonversi=='y'){
			system("cls");
        	goto ConversionMenu;
		}
		system("cls");
		goto AppMenu;
	}
	else if(pil==3){
		aboutCalculator();
		system("cls");
		goto AppMenu;
	}
	else{
		printf("Terimakasih Telah Menggunakan ClevCalc");
		exit(0);
	}
}
