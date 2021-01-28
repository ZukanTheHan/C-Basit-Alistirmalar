#include <stdio.h>
#include <stdlib.h>

struct tumBilgiler
{

    char musteriAdi[100];
    char musteriSoyadi[100];
    int musteriNo;
    char telNo[100];
    int bakiye;
    char musteriAdresi[100];
    char veriBankasi;
    int ekBakiye;
    int eksilenStok;
    int odenecekTutar;
    int netMiktar;
    char urunIsmi [100];
    int urunKodu;
    int urunFiyati;
    int stokMiktari;
    char temp;


} veri;



int main()
{
    FILE *musteriKaydi,*urunKaydi,*Fatura;
    musteriKaydi=fopen("musteriBilgisi.dat","a");
    fclose(musteriKaydi);
    urunKaydi=fopen("urunBilgisi.dat","a");
    fclose(urunKaydi);
    int secim;
    do
    {
        printf("ONLINE SATIS PROGRAMI\n");
        printf("1-Musteri kaydi\n");
        printf("2-Tum musterileri listele\n");
        printf("3-Kayitli olan musteriyi isme gore arama\n");
        printf("4-Kayitli olan musteriyi musteri numarasina gore arama\n");
        printf("5-Musteri kaydi guncelleme\n");
        printf("6-Musteriye bakiye ekleme\n");
        printf("7-Yeni urun kaydi\n");
        printf("8-Kayitli urunu isme gore arama\n");
        printf("9-Kayitli urunu numarasina gore arama\n");
        printf("10-Urun bilgilerini guncelleme\n");
        printf("11-Urun siparisi vermek\n");
        printf("12-Cikis\n");

        printf("Yapmak istediginiz islemi seciniz\n");
        scanf("%d",&secim);

        switch (secim)
        {

        case 1:
        {
            int girdiUzunluk,olcum;
            if((musteriKaydi=fopen("musteriBilgisi.dat","rb+"))==NULL)
            {
                printf("Dosya acilmadi");
            }


            numara:
            printf("Musteri numarasi: \n");
            scanf("%d",&veri.musteriNo);


            printf("Musteri adi: \n");
            scanf("%s",&veri.musteriAdi);
            printf("Musteri soyadi: \n");
            scanf("%s",&veri.musteriSoyadi);
            printf("Musteri telefon numarasi: \n");
            scanf("%s",&veri.telNo);
            printf("Musteri adresi: \n");
            scanf("%c",&veri.temp);
            scanf("%[^\n]",&veri.musteriAdresi);
            printf("Musteri bakiyesi: \n");
            scanf("%d",&veri.bakiye);

            printf("Isleminiz sona ermistir\n");

            veri.veriBankasi = '*';
            fseek(musteriKaydi,filelength(fileno(musteriKaydi)),SEEK_SET);
            fwrite(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);

            fclose(musteriKaydi);

            break;
        }

        case 2:
        {
            int girdiUzunluk,olcum;

            musteriKaydi=fopen("musteriBilgisi.dat","rb+");


            girdiUzunluk=filelength(fileno(musteriKaydi)) / sizeof(struct tumBilgiler);
            for(olcum=0; olcum<girdiUzunluk; olcum++)
            {

                fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                fread(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                if(veri.veriBankasi='*')
                {
                    printf("Musteri adi: %s\n",veri.musteriAdi);
                    printf("Musteri soyadi: %s\n",veri.musteriSoyadi);
                    printf("Musteri numarasi: %d\n",veri.musteriNo);
                    printf("Musteri telefon numarasi: %s\n",veri.telNo);
                    printf("Musteri adresi: %s\n",veri.musteriAdresi);
                    printf("Musteri bakiyesi: %d\n",veri.bakiye);

                }
            }


            fclose(musteriKaydi);
            break;
        }
        case 3:
        {
            int girdiUzunluk,olcum;
            char isim[100];
            musteriKaydi=fopen("musteriBilgisi.dat","rb+");
            printf("Musteri ismini giriniz: \n");
            scanf("%s",&isim);
            girdiUzunluk=filelength(fileno(musteriKaydi)) / sizeof(struct tumBilgiler);
            for(olcum=0; olcum<girdiUzunluk; olcum++)
            {
                fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                fread(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                if(veri.veriBankasi == '*' && !strcmp(veri.musteriAdi,isim))
                {
                    printf("Musteri Numarasi: %d\n",veri.musteriNo);
                    printf("Musteri Adi: %s\n",&veri.musteriAdi);
                    printf("Musteri Soyadi: %s\n",&veri.musteriSoyadi);
                    printf("Musteri Adresi: %s\n",&veri.musteriAdresi);
                    printf("Musteri Telefon Numarasi: %s\n",&veri.telNo);
                    printf("Musteri Bakiyesi: %d\n",veri.bakiye);

                }
            }
            fclose(musteriKaydi);
            break;
        }
        case 4:
        {
            int girdiUzunluk,olcum,musNumarasi;

            musteriKaydi=fopen("musteriBilgisi.dat","rb+");
            mustnum:
            printf("Musteri numarasini giriniz: \n");
            scanf("%d",&musNumarasi);
            girdiUzunluk=filelength(fileno(musteriKaydi)) / sizeof(struct tumBilgiler);
            for(olcum=0; olcum<girdiUzunluk; olcum++)
            {
                fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                fread(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                if(veri.veriBankasi == '*' && veri.musteriNo == musNumarasi)
                {
                    printf("Musteri Adi: %s",&veri.musteriAdi);
                    printf("\n");
                    printf("Musteri Soyadi: %s",&veri.musteriSoyadi);
                    printf("\n");
                    printf("Musteri Telefon Numarasi: %s",&veri.telNo);
                    printf("\n");
                    printf("Musteri Bakiyesi: %d",&veri.bakiye);
                    printf("\n");
                    printf("Musteri Adresi: %s",&veri.musteriAdresi);
                    printf("\n");
                }

            }
            fclose(musteriKaydi);
            break;
        }
        case 5:
        {
            int girdiUzunluk,olcum,musNumarasi;
            musteriKaydi=fopen("musteriBilgisi.dat","rb+");
            printf("Lutfen musteri numrasini giriniz: \n");
            scanf("%d",&musNumarasi);
            girdiUzunluk=filelength(fileno(musteriKaydi)) / sizeof(struct tumBilgiler);
            for(olcum=0; olcum<girdiUzunluk; olcum++)
            {
                fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                fread(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                if(veri.veriBankasi == '*' && veri.musteriNo == musNumarasi)
                {
                    printf("Musterinin yeni telefon numarasini giriniz: \n");
                    scanf("%s",&veri.telNo);
                    printf("Musterinin yeni adresini giriniz: \n");
                    scanf("%c",&veri.temp);
                    scanf("%[^\n]",&veri.musteriAdresi);
                    fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                    fwrite(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                }

            }
        fclose(musteriKaydi);
        break;
        }
        case 6:
            {
                int girdiUzunluk,olcum,musNumarasi,eklenecekMiktar;
                musteriKaydi=fopen("musteriBilgisi.dat","rb+");
                printf("Lutfen musteri numrasini giriniz: \n");
                scanf("%d",&musNumarasi);
                girdiUzunluk=filelength(fileno(musteriKaydi)) / sizeof(struct tumBilgiler);
                for(olcum=0; olcum<girdiUzunluk; olcum++){
                    fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                    fread(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                    if(veri.veriBankasi == '*' && veri.musteriNo == musNumarasi){
                        printf("Musterinin bakiyesine eklenecek miktari giriniz: \n");
                        scanf("%d",&eklenecekMiktar);

                        veri.ekBakiye+=eklenecekMiktar;
                        veri.bakiye+=veri.ekBakiye;
                        printf("Musterinin guncellenmis bakiye durumu: %d\n",veri.bakiye);
                        fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                        fwrite(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                        printf("Musteri bakiye guncellemesi tamamlanmistir. \n");
                    }
                }
                fclose(musteriKaydi);
                break;
            }
        case 7:
            {

            urunKaydi=fopen("urunBilgisi.dat","rb+");






            printf("Urun kodu: \n");

            scanf("%d",&veri.urunKodu);


            printf("Urun adi: \n");
            scanf("%s",&veri.urunIsmi);
            printf("Urun fiyati: \n");
            scanf("%d",&veri.urunFiyati);
            printf("Urun stok miktari: \n");
            scanf("%d",&veri.stokMiktari);

            printf("Isleminiz sona ermistir\n");

            veri.veriBankasi = '*';
            fseek(musteriKaydi,filelength(fileno(urunKaydi)),SEEK_SET);
            fwrite(&veri,sizeof(struct tumBilgiler),1,urunKaydi);

            fclose(urunKaydi);

            break;
            }
        case 8:
            {
            int girdiUzunluk,olcum;
            char urun[100];
            urunKaydi=fopen("urunBilgisi.dat","rb+");
            printf("Urun ismini giriniz: ");
            printf("\n");
            scanf("%s",&urun);
            girdiUzunluk=filelength(fileno(urunKaydi)) / sizeof(struct tumBilgiler);
            for(olcum=0; olcum<girdiUzunluk; olcum++)
            {
                fseek(urunKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                fread(&veri,sizeof(struct tumBilgiler),1,urunKaydi);
                if(veri.veriBankasi == '*' && !strcmp(veri.urunIsmi,urun))
                {
                    printf("Urun Kodu: %d\n",veri.urunKodu);
                    printf("Urun Adi: %s\n",&veri.urunIsmi);
                    printf("Urun Fiyati: %d\n",veri.urunFiyati);
                    printf("Urun Stok Miktari: %d\n",veri.stokMiktari);


                }
            }
            fclose(urunKaydi);
            break;
            }
        case 9:
            {
               int girdiUzunluk,olcum,urKod;

            urunKaydi=fopen("urunBilgisi.dat","rb+");
            printf("Urun kodunu giriniz: \n");
            scanf("%d",&urKod);
            girdiUzunluk=filelength(fileno(urunKaydi)) / sizeof(struct tumBilgiler);
            for(olcum=0; olcum<girdiUzunluk; olcum++)
            {
                fseek(urunKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                fread(&veri,sizeof(struct tumBilgiler),1,urunKaydi);
                if(veri.veriBankasi == '*' && veri.urunKodu == urKod)
                {
                    printf("Urun Adi: %s",&veri.urunIsmi);
                    printf("\n");
                    printf("Urun Fiyati: %d",veri.urunFiyati);
                    printf("\n");
                    printf("Urun Stok Miktari: %d",veri.stokMiktari);
                    printf("\n");
                    printf("Urun Kodu: %d",veri.urunKodu);
                    printf("\n");
                }
            }
            fclose(urunKaydi);
            break;
            }
        case 10:
            {
              int girdiUzunluk,olcum,urKod;
            urunKaydi=fopen("urunBilgisi.dat","rb+");
            printf("Lutfen urun kodunu giriniz: \n");
            scanf("%d",&urKod);
            girdiUzunluk=filelength(fileno(urunKaydi)) / sizeof(struct tumBilgiler);
            for(olcum=0; olcum<girdiUzunluk; olcum++)
            {
                fseek(urunKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                fread(&veri,sizeof(struct tumBilgiler),1,urunKaydi);
                if(veri.veriBankasi == '*' && veri.urunKodu == urKod)
                {
                    printf("Urunun yeni stok miktarini giriniz: \n");
                    scanf("%d",&veri.urunKodu);
                    printf("Urunun yeni fiyatini giriniz: \n");
                    scanf("%d",&veri.urunFiyati);
                    fseek(urunKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                    fwrite(&veri,sizeof(struct tumBilgiler),1,urunKaydi);
                }

            }
        fclose(urunKaydi);
        break;
            }
        case 11:
            {
                int girdiUzunluk,olcum,musNumarasi,urKod,urAdet;
                char karakter;
                musteriKaydi=fopen("musteriBilgisi.dat","rb+");
                urunKaydi=fopen("urunBilgisi.dat","rb+");
                Fatura=fopen("fatura.txt","w+");
                printf("Lutfen musteri numarasini giriniz: \n");
                scanf("%d",&musNumarasi);

                girdiUzunluk=filelength(fileno(musteriKaydi)) / sizeof(struct tumBilgiler);
                for(olcum=0; olcum<girdiUzunluk; olcum++){
                    fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                    fread(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                    if(veri.veriBankasi == '*' && veri.musteriNo == musNumarasi){

                        printf("Almak istediginiz urunun kodunu giriniz: \n");
                        scanf("%d",&urKod);
                        girdiUzunluk=filelength(fileno(musteriKaydi)) / sizeof(struct tumBilgiler);
                        for(olcum=0; olcum<girdiUzunluk; olcum++){
                            fseek(urunKaydi, (olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                            fread(&veri,sizeof(struct tumBilgiler),1,urunKaydi);
                            if(veri.veriBankasi == '*' && veri.urunKodu == urKod){
                               printf("Almak istediginiz adeti giriniz: \n");
                               scanf("%d",&urAdet);
                               veri.eksilenStok+=urAdet;
                               veri.stokMiktari-=veri.eksilenStok;
                               veri.odenecekTutar+=veri.urunFiyati*urAdet;
                               veri.bakiye-=veri.odenecekTutar;

                               fseek(musteriKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                               fwrite(&veri,sizeof(struct tumBilgiler),1,musteriKaydi);
                               fseek(urunKaydi,(olcum*sizeof(struct tumBilgiler)),SEEK_SET);
                               fwrite(&veri,sizeof(struct tumBilgiler),1,urunKaydi);

                               fprintf(Fatura,"Alinan urunun kodu: %d\n",veri.urunKodu);
                               fprintf(Fatura,"Alinan urun adedi: %d\n",veri.eksilenStok);
                               fprintf(Fatura,"Odenecek tutar: %d\n",veri.odenecekTutar);

                            }



                            }
                        }

                    }
                    fclose(urunKaydi);
                    fclose(musteriKaydi);
                    fclose(Fatura);
                    break;
                }


            }







    }
    while(secim!=12);
    return 0;
}
