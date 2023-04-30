#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "temperature.h"

void calcMenu(){
	printf("\n------- Menu Aplikasi ClevCalc -------\n");
    printf("1. Kalkulator Ilmiah \n");
    printf("2. Suhu Konverter \n");
    printf("3. Cara Penggunaan \n");
    printf("4. Keluar \n");
    printf("------------------------------\n");
    printf("Pilih nomor menu: ");
}
void displayExpression(){
	printf("\n------- Menu Aplikasi ClevCalc -------\n");
    printf("\t Kalkulator Ilmiah \n");
    printf("---------------------------------------\n");
    printf("Masukan ekspresi matematika :");
}
void aboutCalc(){
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
void runCalc(){
	char pil;
	char cobaLagi;
	AppMenu:
	calcMenu();
	scanf("%c",&pil);
    fflush(stdin);
    if(isdigit(pil) != 0){
		    if(pil=='1'){
		        char expression[200];
		        displayexpression:
		        displayExpression();
		        scanf("%s",expression);
		        fflush(stdin);
		        printf("ekspresi yang kamu masukan : %s\n",expression);
		        struct calcTree* binaryTree=(struct calcTree *)malloc(sizeof(struct calcTree));
		        binaryTree = makeTree(expression,0,strlen(expression)-1);
		        printf("Hasil nya adalah : %d\n",count(binaryTree));
		        tryAgain:
		        printf("Apakah ingin mencoba lagi ? (Y/N):");
		        scanf("%c", &cobaLagi);
		        fflush(stdin);
		        if(cobaLagi =='Y'||cobaLagi=='y'){
		        	system("cls");
		        	goto displayexpression;
				}
				else if(cobaLagi =='N'||cobaLagi=='n'){
					system("cls");
					goto AppMenu;
				}
				else{
					system("cls");
					printf("Maaf, perintah yang Anda masukkan tidak dapat diproses. \nMohon untuk memasukkan sesuai dengan instruksi.\nTerima kasih.\n");
					goto tryAgain;
				}
			}
			else if(pil=='2'){
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
			else if(pil=='3'){
				aboutCalc();
				system("cls");
				goto AppMenu;
			}
			else if(pil=='4'){
			printf("Terimakasih Telah Menggunakan ClevCalc");
			exit(0);	
			}
	}else {
		system("cls");
		printf("Maaf, perintah yang Anda masukkan tidak dapat diproses. \nMohon untuk memilih menu dengan angka yang sesuai dengan opsi yang tersedia.\nTerima kasih.\n");
		goto AppMenu;
	}
}
