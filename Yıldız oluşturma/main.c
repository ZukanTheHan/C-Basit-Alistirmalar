#include <stdio.h>
#include <stdlib.h>

int main()
{ //MERD�VEN �IKTISI
    int sayi,sutun,satir;
    printf("Lutfen bir sayi giriniz\n");    //iLK FOR D�NG�S�YLE SAYACI BA�LATIYORUZ VE �K�NC� FOR D�NG�S� �LE KO�ULU KONTROL
    scanf("%d",&sayi);                      //ETT�KTEN SONRA �LK VE B�R TANE YILDIZIMIZI BASTIRIYORUZ.
    for(satir=1;satir<=sayi;satir++){       //DAHA SONRA SATIR �FADES� ARTTIK�A HER SATIRDA YAZILACAK YILDIZ SAYISIDA B�RER
                                            //B�RER ARTIYOR.
        for(sutun=1;sutun<=satir;sutun++){

            printf("*");
        }
        printf("\n");
    }

    // BAKLAVA D�L�M� �IKTISI
    int sayi,sutun,satir,yildiz,bosluk;
    yildiz=1;
    printf("Lutfen bir sayi giriniz\n");        //�LK �K� FOR D�NG�S�NDE SOLDAN G�R�LEN SAYININ B�R EKS��� �EKL�NDE BO�LUK BIRAKACAK
    scanf("%d",&sayi);                          //��NK� SAYI DE�ER�NDE YILDIZ BASILACAK. MESELA G�R�LEN DE�ER 6 �SE 5 BO�LUK BIRAKIP
    bosluk=sayi-1;                              //ALTINCI K�MEDE YILDIZ BASACAK. YILDIZI �K��ER �K��ER ARTTIRMA NEDEN�M �SE
                                                //HER SATIRDA �K��ER ARTARAK VE BOSLUK SAYISI B�R AZALARAK YILDIZ BASIYOR.
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


    yildiz=(sayi*2)-3;                          //YILDIZI,G�R�L�NEN SAYININ 2 KATININ 3 EKS��� �LE BA�LATMAMIN NEDEN� �SE YUKARIDA
    bosluk=1;                                   //YAZDI�IM KOD G�R�LEN SAY� KADAR SATIRA SAH�P B�R ��GEN OLU�TURUYOR, BUNUNLA BERABER
                                                //SON SATIRDAK� YILDIZ SAYISININ �K� EKS��� �EKL�NDE DEVAM ETMES� GEREK�YOR.
    for(satir=1;satir<=sayi;satir++){           //MESELA 5 SAYISI G�R�LD�. �STTEK� KODDA 5 SATIRLI VE SON SATIRINDA 9 YILDIZ OLAN
        for(sutun=1;sutun<=bosluk;sutun++){     //B�R ��GEN BASIYOR.BU KOD �SE SON BASILAN SATIRDAK� YILDIZ SAYISININ �K� EKS���
            printf(" ");                        //YAN� (5*2)-3=7 TANE YILDIZ BASIYOR VE YILDIZ SAYISI �K� EKS�LEREK AYNI ZAMANDA
        }                                       // BO�LUK SAYISI SOLDAN �T�BAREN B�RER B�RER ARTARAK 4 SATIRLI TERS ��GEN ELDE
        for(sutun=1;sutun<=yildiz;sutun++){     // ED�L�YOR.BAKLAVA D�L�M�N� DE BU �EK�LDE ELDE ETT�M.
            printf("*");
        }
        printf("\n");
        yildiz-=2;
        bosluk++;

    }



    // Y �IKTISI ���N
    int sagTaraf,solTaraf,sayi,satir,sutun;             //B�R SONRAK� DE���KEN TANIMALAMASINA KADAR OLAN KISIM SADECE V HARF�N�
    printf("Lutfen bir sayi giriniz\n");                //BASIYOR.�K� �EKL� B�RLE�T�RD�M. SOL VE SAG TARAF DE���KENLER� V HARF�N�N
    scanf("%d",&sayi);                                  //�K� KOLUNUN B�T�M�NDEK� NOKTADAN �T�BAREN B�R� SOLUNU D��ER� SA�INI KONTROL
    solTaraf=1;                                         //ED�YOR. BUNU B�R �RNEKLE A�IKLAYAYIM. MESELA 4 DE�ER� G�R�LD�. FOR KO�ULUNDA
    sagTaraf=(sayi*2)-1;                                //SATIR B�R DE�ER�N� ALACAK, SUTUNDA 1 DE�ER�N� ALACAK VE �F KO�ULUNU YER�NE
    for(satir=1;satir<=sayi;satir++){                   //GET�RD��� ���N YILDIZI BASACAK. SUTUN 2,3,4,5,6 DE�ERLER�NDE ELSE KO�ULUNU
        for(sutun=1;sutun<=sayi*2;sutun++){             //YER�NE GET�RECE�� ���N BO�LUK BASACAK. SONRA SUTUNUN 7 DE�ER�NDE TEKRAR YILDIZ
                                                        //VE �LK SATIR B�TM�� OLACAK. SOL TARAF 2 DE�ER�N� ALIRKEN, SA� TARAF 6 DE�ER�N�
            if(sutun == solTaraf || sutun == sagTaraf){ //ALACAK.SUTUN B�R DAHA D�NG�YE G�RD���NDE BU SEFER 2 VE 6 ALTI DE�ERLER� ���N
                printf("*");                            //YILDIZ BASACAK VE B�YLE DEVAM EDECEK.
            }
            else{
                printf(" ");
            }


         }
         solTaraf++;
         sagTaraf--;
         printf("\n");

    }
    int i,j,cikartma;                               //BURADA �SE OLDUK�A BAS�T B�R �EK�LDE, �LK FOR D�NG�S� SAYA� OLUP
    cikartma=1;                                     // D��ER FOR �LE BO�LUK OLU�TURDUM VE B�T�M�NDE ALTTAK� FOR D�NG�S�
    for(i=1;i<=sayi;i++){
        for(j=1;j<=sayi-1;j++){                     //�LE YILDIZ BASTIRDIM.HER SATIRA B�R TANE OLDU�U ���N �IKARTMAYA 1
            printf(" ");                            //DE�ER�N� VERD�M.
        }
        for(j=1;j<=cikartma;j++){
        printf("*");

    }
    printf("\n");

    }

   // TERS ��GEN �IKTISI
   int sayi;
   printf("Lutfen bir sayi giriniz\n");         //�NCE SOLDAN BO�LUK ATAMASINI SIFIR VERD�M. DAHA SONRA G�R�LEN DE�ER KADAR YILDIZ
   scanf("%d",&sayi);                           //BASTIRDIM.HER D�NG�DE �K��ER �K��ER YILDIZ SAYISINI AZALTIP, BO�LUK SAYISINI SOLDAN
   int yildiz=sayi;                             //B�R B�R ARTTIRDIM.
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
