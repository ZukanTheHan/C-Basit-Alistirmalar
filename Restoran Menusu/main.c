#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("MENU\t\tSIPARIS KODU\tFIYATI\n");
    printf("Baslangic\t\t1\t5.50 TL\n");
    printf("Ara sicak\t\t2\t7.00 TL\n");
    printf("Salata\t\t\t3\t2.50 TL\n");
    printf("Tatli\t\t\t4\t3.50 TL\n");
    printf("Ana yemek\t\t5\t17.00 TL\n");
    printf("Icecekler\t\t6\t2.00 TL\n");

    int siparisKodu;
    float toplamTutar;
    float porsiyon;


menu:
    printf("Lutfen siparis vermek istediginiz urunun siparis kodunu giriniz...\n");
    printf("Cikmak icin -1'i tuslayiniz\n ");

    scanf("%d",&siparisKodu);

    if(siparisKodu == -1)
    {
        goto cikis;
    }
    if(siparisKodu>0 && siparisKodu <7)
    {
        printf("Lutfen porsiyon belirleyiniz\n");
        scanf("%f",&porsiyon);
    }


    switch(siparisKodu)
    {
    case 1:
        if(porsiyon>0)
        {
            toplamTutar+=porsiyon*5.50;
            printf("Toplam Tutar: %f\n",toplamTutar);

        }
        else
        {
            printf("Lutfen 0'dan buyuk bir deger giriniz...\n");
        }

        break;
    case 2:
        if(porsiyon>0)
        {

            toplamTutar+=porsiyon*7.00;
            printf("Toplam Tutar: %f\n",toplamTutar);
        }
        else
        {
            printf("Lutfen 0'dan buyuk bir deger giriniz...\n");
        }
        break;
    case 3:
        if(porsiyon>0)
        {
            toplamTutar+=porsiyon*2.50;
            printf("Toplam Tutar: %f\n",toplamTutar);
        }
        else
        {
            printf("Lutfen 0'dan buyuk bir deger giriniz...\n");
        }

        break;
    case 4:
        if(porsiyon>0)
        {
            toplamTutar+=porsiyon*3.50;
            printf("Toplam Tutar: %f\n",toplamTutar);

        }
        else
        {
            printf("Lutfen 0'dan buyuk bir deger giriniz...\n");

        }

        break;
    case 5:
        if(porsiyon>0)
        {
            toplamTutar+=porsiyon*17.00;
            printf("Toplam Tutar: %f\n",toplamTutar);
        }
        else
        {
            printf("Lutfen 0'dan buyuk bir deger giriniz...\n");
        }

        break;
    case 6:
        if(porsiyon>0)
        {
            toplamTutar+=porsiyon*2.00;
            printf("Toplam Tutar: %f\n",toplamTutar);
        }
        else
        {
            printf("Lutfen 0'dan buyuk bir deger giriniz...\n");
        }

        break;
    default:
        printf("Lutfen 1-6 arasi bir secim yapiniz...\n");
        break;


    }
    goto menu;
cikis:
    printf("Siparisiniz tamamlandi\n");
    printf("Toplam tutar: %f\n",toplamTutar);

    return 0;
}
