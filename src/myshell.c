#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 

//exec işlemi için bu fonksiyon kullanılır
void calistir(char* kelimeler[]) 
{ 
    //parametleri bir sonraki sınıfa aktarmak için yeni bir diziye atıyorum
    char *argv[4];
    argv[0] = kelimeler[1];
    argv[1] = kelimeler[2];
    argv[2] = kelimeler[3];
    argv[3] = NULL;
    int i; 
    //
    int f= fork();
    if(f==0)
    {
        //
        i = execv(kelimeler[0], argv);
        if(i<0){
          //çalıştırılamayacak bir işlem istendiğinde
            printf("yanlış bir seçim yaptınız");

        }
    }
    else
    { 
        //
    	wait(&i);
    	
    }
} 
//kullanıcıdan input almak için bu fonksiyon kullanılır
int girdiAl(char* girdi) 
{ 
    char* satir; 
    //readline ile kullanıcıdan veri alınır
    satir = readline("\nmyshell>> ");
    if (strlen(satir) != 0) 
    { 
        add_history(satir); 
        //alınan inputu parametre olarak verilen değere kopyalar
        strcpy(girdi, satir); 
        return 0; 
    } 
    else
    { 
        return 1; 
    } 
} 
//parametre olarak verilen metni boşluk ile böler
//ve parametre olarak verilen diğer diziye atar
void KomutuBol(char* komut, char** kelimeler) 
{ 
    int i; 
    for (i = 0; i < 100; i++)
    { 
        kelimeler[i] = strsep(&komut, " "); 
        if (kelimeler[i] == NULL) 
            break; 
        if (strlen(kelimeler[i]) == 0) 
            i--; 
    } 
} 
//parametre olarak verilen metni or işareti ile böler
//ve parametre olarak verilen diğer diziye atar
void SatiriBol(char* girdi, char** komutlar) 
{ 
    int i; 
    for (i = 0; i < 100; i++) { 
        komutlar[i] = strsep(&girdi, "|"); 
        if (komutlar[i] == NULL) 
            break; 
        if (strlen(komutlar[i]) == 0) 
            i--; 
    } 
} 
//verilen stringin uzunluğunu bulur
int uzunluk(char* metin[]){
    int metinUzunlugu = 0;
    while (metin[metinUzunlugu] != '\0')
    {
        metinUzunlugu++;
    }
    return metinUzunlugu;
}

int main(){

	char girdi[1000]; // girilen inputu alan dizi
	char* kelimeler[100]; //girilen inputun kelimelerini tutan dizi
	char* komutlar[100]; //girilen inputun komutlarını tutan dizi
	int cikis = 0; //exit girilince 1 olur 

	while(1){
        int i;
        girdiAl(girdi); // input alınır
        SatiriBol(girdi, komutlar); // input komutlara bölünür
        for(i = 0; i<uzunluk(komutlar); i++){ //tüm komutlar tek tek dönülür
            KomutuBol(komutlar[i], kelimeler); //her bir komut kelimelere bölünür
            if(strcmp(kelimeler[0],"exit") == 0) //girilen komutun exit komutu olması kontrolü
            {
                cikis = 1; 
                break;
            }
            else if(strcmp(kelimeler[0],"clear") == 0) //girilen komutun clear komutu olması kontrolü
            {
                printf("\033[H\033[J"); // clear komutunun işlevi yapılır
            }
            else if(strcmp(kelimeler[0],"cat") == 0) //girilen komutun cat komutu olması kontrolü
            {	
            	char* catt[3]; 
                catt[0] = "cat";
                catt[1] = kelimeler[1]; //okunacak dosya
                catt[2] = NULL; 
                int fork1;
                fork1 = fork();
                if(fork1==0)
                {
		        
		        execv("/bin/cat", catt);
                }
            }
            else
            {
            
            	calistir(kelimeler);
                
            }
        }
        if(cikis){ // exit komutunun son işlemi
            break;
        }	
	}
	return 0;
}


