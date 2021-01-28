#include <stdio.h>
#include <stdlib.h>

int main()
{
    int adet;
    float adetFiyati;
    printf("Lutfen alacaginiz urun adedini giriniz...\n");

    scanf("%d",&adet);

    if(adet>=400){
        adetFiyati=0.75;
    }
    else if(adet>=300 && adet<400){
        adetFiyati=1;
    }
    else if(adet>=200 && adet<300){
        adetFiyati=1.25;
    }
    else if(adet>=100 && adet<200){
        adetFiyati=1.50;
    }
    else if(adet>=1 && adet<100){
        adetFiyati=1.75;
    }
    else{
        printf("Lutfen en az 1 urun giriniz\n");
    }
    float toplamTutar=adet*adetFiyati;
    int toplamYuvarlama = toplamTutar;
    printf("Toplam odenecek tutar: %f",toplamTutar,toplamYuvarlama);

    float yapilanIndirim;
    yapilanIndirim = toplamTutar-toplamYuvarlama;
    printf("Toplam tutar: %f   Yapilan indirim: %f  Odenecek Tutar: %d",toplamTutar,yapilanIndirim,toplamYuvarlama);




















    return 0;
}
