#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){

	//Toplama işlemi yapılan sınıf

	//İşlem sınıfından gönderilen parametreleri değişkenlere atadım
	//ve toplama işlemini yaptım
	int ilkSayi = atoi(argv[0]);
	int ikinciSayi =  atoi(argv[1]);
	int toplam =  ilkSayi + ikinciSayi;
	//işlem sonucunu ekrana bastım
	printf("%d + %d = %d\n",ilkSayi,ikinciSayi,toplam);
	return 0;
} 
