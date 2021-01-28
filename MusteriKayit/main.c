#include <stdio.h>
#include <stdlib.h>
struct musteriBilgileri
{

    char *musteriAdi;
    char *musteriSoyadi;
    int hesapNo;
    char *telNo;
    int bakiye;
    char musteriVeriBankasi;
    int Kazanc;
    int Kayip;
    int netMiktar;



} ;

int main()

{typedef musteriBilgileri musteriVerisi;
   FILE *musteriVerileri,*musteriBorcDurumu,*musteriKayitMetni,*musteriVerileriSilinecek;
    musteriVerileri=fopen("musteriVerisi.dat","a");
    fclose(musteriVerileri);
    int secim;
    do
    {
        printf("ISLEM MENUSU\n");
        printf("1-Yeni musteri kaydi yapmak icin\n");
        printf("2-Musteri bakiye durumunu guncellemek icin\n");
        printf("3-Varolan musteri kaydini silmek icin\n");
        printf("4-Musteri bilgilerini goruntulemek icin\n");
        printf("5-Tum kayitlari metin dosyasinda goruntulemek icin\n");
        printf("6-Musteri kayitlarini borc durumunu metin dosyasina yazdirmak icin(Lutfen once musteri bakiye durumunu guncelleyeniz)\n"); //CALÝSÝYOR
        printf("7-Cikis yapmak icin\n");

        printf("Yapmak istediginiz islemi seciniz\n");
        scanf("%d",&secim);

        switch (secim)
        {

        case 1:
        {



            musteriVerisi musteri;


                printf("Musteri hesap numarasi: \n");
                menu:
                scanf("%d",&musteri.hesapNo);
                if(musteri.hesapNo<0 || musteri.hesapNo>100){
                    printf("Lutfen 1-100 arasi bir deger giriniz\n");
                    goto menu;
                }
                musteri.musteriAdi=(char *)malloc(sizeof(char)*10);
                printf("Musteri adi: \n");
                scanf("%s",&musteri.musteriAdi);
                musteri.musteriSoyAdi=(char *)malloc(sizeof(char)*20);
                printf("Musteri soyadi: \n");
                scanf("%s",&musteri.musteriSoyadi);
                musteri.telNo=(char *)malloc(sizeof(char)*10);
                printf("Musteri telefon numarasi: \n");
                printf("Lutfen telefon numarasini basinda sifir olmadan yaziniz\n");
                scanf("%s",&musteri.telNo);

                printf("Musteri bakiyesi: \n");
                bak:
                scanf("%d",&musteriVerisi.bakiye);
                if(musteriVerisi.bakiye<-50000 || musteriVerisi.bakiye>50000){
                    printf("Lutfen bakiye durumunu -50000 ile +50000 arasýnda tutunuz");
                    goto bak;
                }
                printf("Isleminiz sona ermistir\n");


                fseek(musteriVerileri,filelength(fileno(musteriVerileri)),SEEK_SET);
                fwrite(&musteri,sizeof(struct musteriBilgileri),1,musteriVerileri);

            fclose(musteriVerileri);

            break;



        }


        case 2:
        {

            int dosyaUzunluk,islem,hesapnumarasi,anlik,kazanc,kayip;
            musteriVerileri=fopen("musteriVerisi.dat","rb+");


                printf("Bilgileri guncellenecek musterinin hesap numarasini giriniz\n");
                islem:
                scanf("%d",&hesapnumarasi);
                if(hesapnumarasi<0 || hesapnumarasi>100){
                    printf("Lutfen 1-100 arasi bir deger giriniz\n");
                    goto islem;
                }
                dosyaUzunluk = filelength(fileno(musteriVerileri)) / sizeof(struct musteriBilgileri);

                for(islem=0; islem<dosyaUzunluk; islem++)
                {
                    fseek(musteriVerileri,(islem*sizeof(struct musteriBilgileri)),SEEK_SET);
                    fread(&musteri,sizeof(struct musteriBilgileri),1,musteriVerileri);

                for (int kat=0;kat<islem;kat++){
                    if(strcmp(hesapnumarasi,musteri[kat].hesapNo)==0){

                    printf("Musteri bakiyesine anlik para gelirini eklemek icin 1'e, anlik para giderini eklemek icin 2'ye basiniz\n");
                    scanf("%d",&anlik);

                    if(anlik == 1){
                    printf("Musterinin anlik para geliri: \n");
                    kaz:
                    scanf("%d",&kazanc);
                    if(kazanc <= 0 || kazanc > 50000){
                        printf("Lutfen 0-50000 arasi bir deger giriniz\n");
                        goto kaz;
                    }
                    musteriVerisi.Kazanc+=kazanc;
                    musteriVerisi.bakiye+=musteriVerisi.Kazanc;
                    printf("Musteri anlik bakiyesi: %d\n",musteriVerisi.bakiye);
                    fseek(musteriVerileri,(islem*sizeof(struct musteriBilgileri)),SEEK_SET);
                    fwrite(&musteriVerisi,sizeof(struct musteriBilgileri),1,musteriVerileri);
                    printf("Musteri kaydi tamamlanmistir\n");
                    }
                    else if(anlik == 2){
                    printf("Musterinin anlik para gideri: \n");
                    kay:
                    scanf("%d",&kayip);
                    if(kayip <= 0 || kayip >50000){
                        printf("Lutfen 1-50000 arasi bir deger giriniz\n");
                        goto kay;
                    }
                    musteriVerisi.Kayip-=kayip;
                    musteriVerisi.bakiye+=musteriVerisi.Kayip;
                    printf("Musteri anlik bakiyesi: %d\n",musteriVerisi.bakiye);
                    fseek(musteriVerileri,(islem*sizeof(struct musteriBilgileri)),SEEK_SET);
                    fwrite(&musteriVerisi,sizeof(struct musteriBilgileri),1,musteriVerileri);
                    printf("Musteri kaydi tamamlanmistir\n");
                    }

                }
                }
            }
            fclose(musteriVerileri);
            break;







        }
        case 3 :
        {

            int hesapNumarasi,dosyaUzunluk,islem,silme=0;
            printf("Silmek istediginiz musteri hesap numarasini giriniz\n");
            hes:
            scanf("%d",&hesapNumarasi);
            if(hesapNumarasi <= 0 || hesapNumarasi > 100){
                printf("Lutfen 0-100 arasi bir deger giriniz\n");
                goto hes;
            }
            musteriVerileri = fopen("musteriVerisi.dat","rb+");
            musteriVerileriSilinecek = fopen("musteriVerisiSilinecek.dat","wb+");
            if((musteriVerileri = fopen("musteriVerisi.dat","rb+"))== NULL)
            {
                printf("Dosya acilamadi");
            }

            dosyaUzunluk = filelength(fileno(musteriVerileri)) / sizeof(struct musteriBilgileri);
            for(islem=0; islem<dosyaUzunluk; islem++)
            {
                fseek(musteriVerileri,(islem*sizeof(struct musteriBilgileri)),SEEK_SET);
                fread(&musteriVerisi,sizeof(struct musteriBilgileri),1,musteriVerileri);
                if( musteriVerisi.hesapNo != hesapNumarasi)
                {
                    fwrite(&musteriVerisi,sizeof(struct musteriBilgileri),1,musteriVerileriSilinecek);

                }
                fclose(musteriVerileri);
                fclose(musteriVerileriSilinecek);
                do{

                    remove("musteriVerisi.dat");
                    rename("musteriVerileriSilinecek.dat","musteriVerisi.dat");
                    printf("Islem gerceklestirilmistir.Musteri kaydi silindi.\n");


                }while(silme == 1);
            }










            break;

        }
        case 4:
        {

            int islem,dosyaUzunluk,hesapNumarasi;
            musteriVerileri = fopen("musteriVerisi.dat","rb+");
            if((musteriVerileri = fopen("musteriVerisi.dat","rb+")) == NULL)
            {
                printf("Dosya acilamadi\n");
            }
            printf("Musteri hesap numarasini giriniz: ");
            scanf("%d",&hesapNumarasi);
            if(hesapNumarasi <= 0 || hesapNumarasi>100){
                printf("Lutfen 0-100 arasi bir deger giriniz\n");
            }
            dosyaUzunluk = filelength(fileno(musteriVerileri)) / sizeof(struct musteriBilgileri);
            for(islem=0; islem<dosyaUzunluk; islem++)
            {
                fseek(musteriVerileri,(islem*sizeof(struct musteriBilgileri)),SEEK_SET);
                fread(&musteriVerisi,sizeof(struct musteriBilgileri),1,musteriVerileri);
                if(strcmp(musteri.hesapNo,hesapnumarasi)==0){
                {
                    printf("Musteri Adi: %s",&musteriVerisi.musteriAdi);
                    printf("\n");
                    printf("Musteri Soyadi: %s",&musteriVerisi.musteriSoyadi);
                    printf("\n");
                    printf("Musteri Telefon Numarasi: %s",&musteriVerisi.telNo);
                    printf("\n");
                    printf("Musteri Bakiyesi: %d",&musteriVerisi.bakiye);
                    printf("\n");

                }

            }

            fclose(musteriVerileri);
            break;


        }
        case 5:
        {

            int dosyaUzunluk,hesapNumarasi,islem;

            musteriVerileri=fopen("musteriVerisi.dat","rb+");
            musteriKayitMetni=fopen("musteriKayitMetni.txt","w+");
            musteriVerisi musteri;
            musteri.telNo=(char *)malloc(sizeof(char)*10);
            musteri.musteriAdi=(char *)malloc(sizeof(char)*10);
            musteri.musteriSoyAdi=(char *)malloc(sizeof(char)*20);
            dosyaUzunluk=filelength(fileno(musteriVerileri)) / sizeof(struct musteriBilgileri);
            for(islem=0; islem<dosyaUzunluk; islem++)
            {

                fseek(musteriVerileri,(islem*sizeof(struct musteriBilgileri)),SEEK_SET);
                fread(&musteri,sizeof(struct musteriBilgileri),1,musteriVerileri);
                while(!feof(musteriVerileri))
                {
                    fprintf(musteriKayitMetni,"Musteri adi: %s\n",musteriVerisi.musteriAdi);
                    fprintf(musteriKayitMetni,"Musteri soyadi: %s\n",musteriVerisi.musteriSoyadi);
                    fprintf(musteriKayitMetni,"Musteri hesap numarasi: %d\n",musteriVerisi.hesapNo);
                    fprintf(musteriKayitMetni,"Musteri telefon numarasi: %s\n",musteriVerisi.telNo);
                    fprintf(musteriKayitMetni,"Musteri bakiyesi: %d\n",musteriVerisi.bakiye);

                }
            }



            break;

        }

        case 6:
        {
            int dosyaUzunluk,hesapNumarasi,islem,kazanc,kayip;

            musteriVerileri=fopen("musteriVerisi.dat","rb+");
            musteriBorcDurumu=fopen("musteriBorcDurumu.txt","w+");

            dosyaUzunluk=filelength(fileno(musteriVerileri)) / sizeof(struct musteriBilgileri);
            for(islem=0; islem<dosyaUzunluk; islem++)
            {

                fseek(musteriVerileri,(islem*sizeof(struct musteriBilgileri)),SEEK_SET);
                fread(&musteriVerisi,sizeof(struct musteriBilgileri),1,musteriVerileri);

                if(musteriVerisi.musteriVeriBankasi='*')
                {


                    if(musteriVerisi.bakiye >= 0)
                    {
                        fprintf(musteriBorcDurumu,"Musteri adi: %s\n",musteri.musteriAdi);
                        fprintf(musteriBorcDurumu,"Musteri soyadi: %s\n",musteri.musteriSoyadi);
                        fprintf(musteriBorcDurumu,"Musteri hesap numarasi: %d\n",musteri.hesapNo);
                        fprintf(musteriBorcDurumu,"Musteri telefon numarasi: %s\n",musteri.telNo);
                        fprintf(musteriBorcDurumu,"Musteri kalan bakiyesi: %d\n",musteri.bakiye);
                        fprintf(musteriBorcDurumu,"Musteri borclu degildir\n");
                    }
                    else
                    {
                        fprintf(musteriBorcDurumu,"Musteri adi: %s\n",musteri.musteriAdi);
                        fprintf(musteriBorcDurumu,"Musteri soyadi: %s\n",musteri.musteriSoyadi);
                        fprintf(musteriBorcDurumu,"Musteri hesap numarasi: %d\n",musteri.hesapNo);
                        fprintf(musteriBorcDurumu,"Musteri telefon numarasi: %s\n",musteri.telNo);
                        fprintf(musteriBorcDurumu,"Musteri kalan bakiyesi: %d\n",musteri.bakiye);
                        fprintf(musteriBorcDurumu,"Musteri borcludur.\n");

                    }


                }
            }
            fclose(musteriVerileri);
            fclose(musteriBorcDurumu);
            break;
        }

        default:
        {
            printf("Lutfen 1-7 arasi islemlerden birini seciniz");
            break;
        }
        }
    }
    while(secim!=7);
    return 0;
}
