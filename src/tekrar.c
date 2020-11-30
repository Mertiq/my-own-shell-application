#include <stdio.h>
#include <stdlib.h>

//parametre olarak verilen bir string
//eğer sayıysa 1 değilse 0 döner 
int sayiMi(char* argv){
    int i = 0;
	while(argv[i] != '\0'){
		if(argv[i]  <'0' ||argv[i] >'9'){
			return 0;
		}
		i++;
	}
	return 1;
}

int main(int argc, char* argv[]){
	//verilen ikinci parametre sayı olmalıdır
	if(sayiMi(argv[1])){

		int i;
		//ikinci parametre olarak girilen sayı kadar döner
		for(i = 0; i< atoi(argv[1]);i++){
			//birinci parametre olarak girilen metni ekrana basar
			printf("%s",argv[0]);
			printf("\n");
		}
		printf("\n");

	}
	else{
		//ikinci parametre sayı olmazsa bu satır çalışır
        printf("yanlış bir seçim yaptınız");

    }
	
	
	return 0;
} 
