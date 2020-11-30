#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){

	//Çıkarma işlemi yapılan sınıf

	//İşlem sınıfından gönderilen parametreleri değişkenlere atadım
	//ve çıkarma işlemini yaptım
	int ilkSayi = atoi(argv[0]);
	int ikinciSayi =  atoi(argv[1]);
	int fark =  ilkSayi - ikinciSayi;
	//işlem sonucunu ekrana bastım
	printf("%d - %d = %d\n",ilkSayi,ikinciSayi,fark);
	return 0;
} 
