#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 

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

    // verilen ilk parametre "topla" ya da "cikar" olmalıdır
    if(strcmp("topla",argv[0]) == 0 || strcmp("cikar", argv[0]) == 0){
        //verilen ikinci ve üçüncü parametler sayı olmalılardır
        if(sayiMi(argv[1]) && sayiMi(argv[2])){
            //islem sınıfına gelen parametleri bir sonraki sınıfa aktarmak için yeni bir diziye atıyorum
            char *newargv[3];
            newargv[0] = argv[1];
            newargv[1] = argv[2];
            newargv[2] = NULL;
            int i;
            //
            int f = fork();
            if(f==0)
            {
                //
                i = execv(argv[0], newargv);
                perror("execv failed\n");
            }
            else 
            {
                //
                wait(&i); 
            }
        }else{
            //ikinci ve üçüncü parametler sayı olmazsa bu satır çalışır
            printf("yanlış bir seçim yaptınız");

        }
    }
    else{
        // verilen ilk parametre "topla" ya da "cikar" olmazsa bu satır çalışır
        printf("yanlış bir seçim yaptınız");

    }
    

	
    return 0;
} 
