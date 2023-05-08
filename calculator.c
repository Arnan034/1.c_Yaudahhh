#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "temperature.h"
#include <stdbool.h>
#include <windows.h>

void gotoxy(int x, int y){
 	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TampilanMainMenu(){
	gotoxy(24,2);printf("010101   010   01     010101 01  01 01       010   01010101 010101 01010\n");//122 - 74 =
	gotoxy(24,3);printf("01      01 01  01     01     01  01 01      01 01     01    01  01 01  01\n");
	gotoxy(24,4);printf("01     0101010 01     01     01  01 01     0101010    01    01  01 01010\n");
	gotoxy(24,5);printf("01     01   01 01     01     01  01 01     01   01    01    01  01 01 01\n");
	gotoxy(24,6);printf("010101 01   01 010101 010101 010101 010101 01   01    01    010101 01  01\n");
	gotoxy(30,8);printf("010101 010101 01 010101 010  01 01010101 01 010101 01 010101\n");
	gotoxy(30,9);printf("01     01     01 01     0101 01    01    01 01     01 01\n");
	gotoxy(30,10);printf("010101 01     01 010101 01 0 01    01    01 010101 01 01\n");
	gotoxy(30,11);printf("    01 01     01 01     01 0101    01    01 01     01 01\n");
	gotoxy(30,12);printf("010101 010101 01 010101 01  010    01    01 01     01 010101\n");
	gotoxy(41,14);printf("1. Calculator                 Choose\n");
	gotoxy(41,15);printf("2. Batasan Program         +----------+    \n");
	gotoxy(41,16);printf("3. Konversi Suhu           |          |\n");
	gotoxy(41,17);printf("99. Exit                   +----------+    \n");
}
void TampilanKalkulator(){
	gotoxy(40,3);printf(" _________________________________________\n");
	gotoxy(40,4);printf("|  _____________________________________  |\n");
	gotoxy(40,5);printf("| | Choose Operator                     | |\n");
	gotoxy(40,6);printf("| |                                     | |\n");
	gotoxy(40,7);printf("| |_____________________________________| |\n");
	gotoxy(40,8);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,9);printf("| |   (   | |   )   | |   %%   | |   /   | |\n");
	gotoxy(40,10);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,11);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,12);printf("| |   7   | |   8   | |   9   | |   *   | |\n");
	gotoxy(40,13);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,14);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,15);printf("| |   4   | |   5   | |   6   | |   -   | |\n");
	gotoxy(40,16);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,17);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,18);printf("| |   1   | |   2   | |   3   | |       | |\n");
	gotoxy(40,19);printf("| |_______| |_______| |_______| |       | |\n");
	gotoxy(40,20);printf("|  _______   _______   _______  |   +   | |\n");
	gotoxy(40,21);printf("| |   .   | |   0   | |   =   | |       | |\n");
	gotoxy(40,22);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,23);printf("|_________________________________________|\n");
	gotoxy(40,25);printf("Operasi Yang Dimasukan : ");
	gotoxy(40,26);printf("Infix to Postfix : ");
	gotoxy(40,27); printf("Infix to Prefix  : ");
}
void TampilanBatasanProgram(){
	gotoxy(21,2);printf("+------------------------------------------------------------------------------+\n");
	gotoxy(21,3);printf("|a. Dalam program ini kami menggunakan tipe data float.                        |\n");
	gotoxy(21,4);printf("|b. User harus menginputkan dengan Angka agar bisa dikalkulasikan.             |\n");
	gotoxy(21,5);printf("|c. Sesuai dengan konsep matematika, program yang kita buat tidak bisa         |\n");
	gotoxy(21,6);printf("|   menampilkan hasil saat membagi suatu bilangan dengan angka 0.              |\n");
	gotoxy(21,7);printf("|d. Dalam penginputan ekspresi matematika, operator tidak boleh berhimpitan,   |\n");
	gotoxy(21,8);printf("|   hanya boleh ada tanda negatif untuk menunjukkan angka negatif.             |\n");
	gotoxy(21,9);printf("|e. Apabila memasukkan ekspresi matematika user tidak boleh menginputkan huruf.|\n");
	gotoxy(21,10);printf("|f. Akan menunjukkan error apabila user menginputkan ekspresi matematika dengan|\n");
	gotoxy(21,11);printf("|   tanda kurung yang tidak sesuai (kurungnya tidak ditutup atau kelebihan)    |\n");
	gotoxy(21,12);printf("|g. Tidak bisa menghitung ekspresi matematika seperti 4(5+20)                  |\n");
	gotoxy(21,13);printf("|h. Inputan harus berhimpitan / tidak boleh dipisahkan dengan spasi            |\n");
	gotoxy(21,14);printf("|i. Untuk operator perpangkatan belum ditambahkan di modul isValid dan         |\n"); 
	gotoxy(21,15);printf("|   perhtiungan di stacknya                                                    |\n");
	gotoxy(21,16);printf("|j. Apabila Ingin Menginputkan - (negatif) diawal maka harus diawali dengan () |\n");
	gotoxy(21,17);printf("|   seperti (-20)+10                                                           |\n");
	gotoxy(21,18);printf("+------------------------------------------------------------------------------+\n");
	gotoxy(21,20);system("pause");
}
void runCalc(){
	char pil;
	char cobaLagi;
	AppMenu:
	TampilanMainMenu();
	gotoxy(73,16);
	scanf("%c",&pil);
    fflush(stdin);
    if(isdigit(pil) != 0){
		    if(pil=='1'){
		        char expression[200];
		        displayexpression:
		        system("cls");
		        TampilanKalkulator();
				gotoxy(44,6);scanf("%s",expression);
		        fflush(stdin);
		        if(isValid(expression)){
		        	gotoxy(65,25); printf("%s", expression);
   			        struct calcTree* binaryTree=(struct calcTree *)malloc(sizeof(struct calcTree));
			        binaryTree = createTree(expression,0,strlen(expression)-1);
			        gotoxy(44,5); printf("Result                   ");
			        gotoxy(44,6); printf("                                    | |\n");
					gotoxy(44,6); printf("%f",count(binaryTree));
			        gotoxy(59,26); infixToPostfix(binaryTree);
			        gotoxy(59,27);infixToPrefix(binaryTree);
			        gotoxy(40,28);printf("Hasil pembulatan dua angka dibelakang koma : %0.2f",round_double(count(binaryTree),2));
				}else{
					gotoxy(38,2); printf("Ekspresi Matematika Yang Anda Masukkan Salah!!!");
				}
		        tryAgain:
		        gotoxy(44,30);printf("Apakah ingin mencoba lagi ? (Y/N):  ");
		        gotoxy(44+35,30);scanf("%c", &cobaLagi);
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
					gotoxy(38,30);
					printf("Maaf, perintah yang Anda masukkan tidak dapat diproses.");
					gotoxy(42,31);
					printf("Mohon untuk memasukkan sesuai dengan instruksi.");
					gotoxy(55,32);
					printf("Terima kasih.");
					goto tryAgain;
				}
			}
			else if(pil=='3'){
				mainMenu();
				goto AppMenu;
			}
			else if(pil=='2'){
				TampilanBatasanProgram();
				system("cls");
				goto AppMenu;
			}
			else if(pil=='4'){
			printf("Terimakasih Telah Menggunakan ClevCalc");
			return 0;;	
			}
	}else {
		gotoxy(34,19); printf("Maaf, perintah yang Anda masukkan tidak dapat diproses.");
		gotoxy(24,20); printf("Mohon untuk memilih menu dengan angka yang sesuai dengan opsi yang tersedia.");
		gotoxy(55,21); printf("Terima kasih.");
		goto AppMenu;
	}
}
