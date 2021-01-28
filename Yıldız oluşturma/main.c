#include <stdio.h>
#include <stdlib.h>

int main()
{ //MERDÝVEN ÇIKTISI
    int sayi,sutun,satir;
    printf("Lutfen bir sayi giriniz\n");    //iLK FOR DÖNGÜSÜYLE SAYACI BAÞLATIYORUZ VE ÝKÝNCÝ FOR DÖNGÜSÜ ÝLE KOÞULU KONTROL
    scanf("%d",&sayi);                      //ETTÝKTEN SONRA ÝLK VE BÝR TANE YILDIZIMIZI BASTIRIYORUZ.
    for(satir=1;satir<=sayi;satir++){       //DAHA SONRA SATIR ÝFADESÝ ARTTIKÇA HER SATIRDA YAZILACAK YILDIZ SAYISIDA BÝRER
                                            //BÝRER ARTIYOR.
        for(sutun=1;sutun<=satir;sutun++){

            printf("*");
        }
        printf("\n");
    }

    // BAKLAVA DÝLÝMÝ ÇIKTISI
    int sayi,sutun,satir,yildiz,bosluk;
    yildiz=1;
    printf("Lutfen bir sayi giriniz\n");        //ÝLK ÝKÝ FOR DÖNGÜSÜNDE SOLDAN GÝRÝLEN SAYININ BÝR EKSÝÐÝ ÞEKLÝNDE BOÞLUK BIRAKACAK
    scanf("%d",&sayi);                          //ÇÜNKÜ SAYI DEÐERÝNDE YILDIZ BASILACAK. MESELA GÝRÝLEN DEÐER 6 ÝSE 5 BOÞLUK BIRAKIP
    bosluk=sayi-1;                              //ALTINCI KÜMEDE YILDIZ BASACAK. YILDIZI ÝKÝÞER ÝKÝÞER ARTTIRMA NEDENÝM ÝSE
                                                //HER SATIRDA ÝKÝÞER ARTARAK VE BOSLUK SAYISI BÝR AZALARAK YILDIZ BASIYOR.
    for(satir=1;satir<=sayi;satir++){
        for(sutun=1;sutun<=bosluk;sutun++){
            printf(" ");
        }
        for(sutun=1;sutun<=yildiz;sutun++){
            printf("*");
        }
        printf("\n");
        yildiz+=2;
        bosluk--;

    }


    yildiz=(sayi*2)-3;                          //YILDIZI,GÝRÝLÝNEN SAYININ 2 KATININ 3 EKSÝÐÝ ÝLE BAÞLATMAMIN NEDENÝ ÝSE YUKARIDA
    bosluk=1;                                   //YAZDIÐIM KOD GÝRÝLEN SAYÝ KADAR SATIRA SAHÝP BÝR ÜÇGEN OLUÞTURUYOR, BUNUNLA BERABER
                                                //SON SATIRDAKÝ YILDIZ SAYISININ ÝKÝ EKSÝÐÝ ÞEKLÝNDE DEVAM ETMESÝ GEREKÝYOR.
    for(satir=1;satir<=sayi;satir++){           //MESELA 5 SAYISI GÝRÝLDÝ. ÜSTTEKÝ KODDA 5 SATIRLI VE SON SATIRINDA 9 YILDIZ OLAN
        for(sutun=1;sutun<=bosluk;sutun++){     //BÝR ÜÇGEN BASIYOR.BU KOD ÝSE SON BASILAN SATIRDAKÝ YILDIZ SAYISININ ÝKÝ EKSÝÐÝ
            printf(" ");                        //YANÝ (5*2)-3=7 TANE YILDIZ BASIYOR VE YILDIZ SAYISI ÝKÝ EKSÝLEREK AYNI ZAMANDA
        }                                       // BOÞLUK SAYISI SOLDAN ÝTÝBAREN BÝRER BÝRER ARTARAK 4 SATIRLI TERS ÜÇGEN ELDE
        for(sutun=1;sutun<=yildiz;sutun++){     // EDÝLÝYOR.BAKLAVA DÝLÝMÝNÝ DE BU ÞEKÝLDE ELDE ETTÝM.
            printf("*");
        }
        printf("\n");
        yildiz-=2;
        bosluk++;

    }



    // Y ÇIKTISI ÝÇÝN
    int sagTaraf,solTaraf,sayi,satir,sutun;             //BÝR SONRAKÝ DEÐÝÞKEN TANIMALAMASINA KADAR OLAN KISIM SADECE V HARFÝNÝ
    printf("Lutfen bir sayi giriniz\n");                //BASIYOR.ÝKÝ ÞEKLÝ BÝRLEÞTÝRDÝM. SOL VE SAG TARAF DEÐÝÞKENLERÝ V HARFÝNÝN
    scanf("%d",&sayi);                                  //ÝKÝ KOLUNUN BÝTÝMÝNDEKÝ NOKTADAN ÝTÝBAREN BÝRÝ SOLUNU DÝÐERÝ SAÐINI KONTROL
    solTaraf=1;                                         //EDÝYOR. BUNU BÝR ÖRNEKLE AÇIKLAYAYIM. MESELA 4 DEÐERÝ GÝRÝLDÝ. FOR KOÞULUNDA
    sagTaraf=(sayi*2)-1;                                //SATIR BÝR DEÐERÝNÝ ALACAK, SUTUNDA 1 DEÐERÝNÝ ALACAK VE ÝF KOÞULUNU YERÝNE
    for(satir=1;satir<=sayi;satir++){                   //GETÝRDÝÐÝ ÝÇÝN YILDIZI BASACAK. SUTUN 2,3,4,5,6 DEÐERLERÝNDE ELSE KOÞULUNU
        for(sutun=1;sutun<=sayi*2;sutun++){             //YERÝNE GETÝRECEÐÝ ÝÇÝN BOÞLUK BASACAK. SONRA SUTUNUN 7 DEÐERÝNDE TEKRAR YILDIZ
                                                        //VE ÝLK SATIR BÝTMÝÞ OLACAK. SOL TARAF 2 DEÐERÝNÝ ALIRKEN, SAÐ TARAF 6 DEÐERÝNÝ
            if(sutun == solTaraf || sutun == sagTaraf){ //ALACAK.SUTUN BÝR DAHA DÖNGÜYE GÝRDÝÐÝNDE BU SEFER 2 VE 6 ALTI DEÐERLERÝ ÝÇÝN
                printf("*");                            //YILDIZ BASACAK VE BÖYLE DEVAM EDECEK.
            }
            else{
                printf(" ");
            }


         }
         solTaraf++;
         sagTaraf--;
         printf("\n");

    }
    int i,j,cikartma;                               //BURADA ÝSE OLDUKÇA BASÝT BÝR ÞEKÝLDE, ÝLK FOR DÖNGÜSÜ SAYAÇ OLUP
    cikartma=1;                                     // DÝÐER FOR ÝLE BOÞLUK OLUÞTURDUM VE BÝTÝMÝNDE ALTTAKÝ FOR DÖNGÜSÜ
    for(i=1;i<=sayi;i++){
        for(j=1;j<=sayi-1;j++){                     //ÝLE YILDIZ BASTIRDIM.HER SATIRA BÝR TANE OLDUÐU ÝÇÝN ÇIKARTMAYA 1
            printf(" ");                            //DEÐERÝNÝ VERDÝM.
        }
        for(j=1;j<=cikartma;j++){
        printf("*");

    }
    printf("\n");

    }

   // TERS ÜÇGEN ÇIKTISI
   int sayi;
   printf("Lutfen bir sayi giriniz\n");         //ÖNCE SOLDAN BOÞLUK ATAMASINI SIFIR VERDÝM. DAHA SONRA GÝRÝLEN DEÐER KADAR YILDIZ
   scanf("%d",&sayi);                           //BASTIRDIM.HER DÖNGÜDE ÝKÝÞER ÝKÝÞER YILDIZ SAYISINI AZALTIP, BOÞLUK SAYISINI SOLDAN
   int yildiz=sayi;                             //BÝR BÝR ARTTIRDIM.
   int bosluk=0;
   int satir,sutun;
   for(satir=1;satir<=sayi;satir++){
        for(sutun=1;sutun<=bosluk;sutun++){
            printf(" ");
        }
        for(sutun=1;sutun<=yildiz;sutun++){
            printf("*");
        }
        printf("\n");
        yildiz-=2;
        bosluk++;

   }




















    return 0;
}
