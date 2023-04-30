#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "temperature.h"

void mainMenu(){
	printf("\n------- Menu Konversi Suhu -------\n");
    printf("1. Konversi Celcius (c) \n");
    printf("2. Konversi Reamur (r) \n");
    printf("3. Konversi Fahrenheit (F) \n");
    printf("4. Konversi Kelvin (K) \n");
    printf("5. Keluar program \n");
    printf("------------------------------\n");
    printf("Pilih satuan suhu awal yang ingin di konversi : ");
}

void countCelcius(){
	float c, r, f, k;
	printf("Masukkan nilai Celcius: ");
    scanf("%f", &c);
    fflush(stdin);
    r = c*4/5;
    f = (c*9/5)+32;
    k = c+273.16;
    printf("Celsius dalam Reamur adalah %.2f\n", r);
    printf("Celcius dalam Fahrenheit adalah %.2f\n", f);
    printf("Celcius dalam Kelvin adalah %.2f\n",k);
    printf("\n");
}

void countReamur(){
	float c, r, f, k;
	printf("Masukkan nilai Reamur: ");
    scanf("%f",&r);
    fflush(stdin);
    c = r*5/4;
    f = (r*9/4)+32;
    k = (r*5/4)+273.16;
    printf("Nilai Reamur dalam Celcius adalah %.2f\n", c);
    printf("Nilai Reamur dalam Fahrenheit adalah %.2f\n", f);
    printf("Nilai Reamur dalam Kelvin adalah %.2f\n", k);
    printf("\n");
    
}

void countFahrenheit(){
	float c, r, f, k;
    printf("Masukkan nilai Fahrenheit: ");
    scanf("%f", &f);
    fflush(stdin);
    c = (f*5/9)-32;
    r = (f*4/9)-32;
    k = (f-32)*5/9+273.16;
    printf("Nilai Fahrenheit dalam Celcius adalah %.2f\n",c);
    printf("Nilai Fahrenheit dalam Reamur adalah %.2f\n",r);
    printf("Nilai Fahrenheit dalam Kelvin adalah %.2f\n",k);
    printf("\n");
    
}

void countKelvin(){
	float c, r, f, k;
    printf("Masukkan nilai Kelvin: ");
    scanf("%f", &k);
    fflush(stdin);
    c = k-273.16;
    r = (k-273.16)*4/5;
    f = (k-273.16)*9/5+32;
    printf("Nilai Kelvin dalam Celcius adalah %.2f\n",c);
    printf("Nilai Kelvin dalam Reamur adalah %.2f\n",r);
    printf("Nilai Kelvin dalam Fahrenheit adalah %.2f\n",f);
    printf("\n");
}
