#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const double Pi=3.14159;
void deneyler(){
printf("1-Serbest Dusme Deneyi\n2-Yukari Atis Deneyi\n3-Agirlik Deneyi\n4-Kutlecekimsel Potansiyel Enerji Deneyi\n5-Hidrostatik basinc Deneyi\n6-Arsimet Kaldirma Kuvveti Deneyi\n7-Basit Sarkac Periyodu Deneyi\n8-Sabit Ip Gerilmesi Deneyi\n9-Asansor Deneyi");}

void serbest_dusme(double *g,int *gezegensayisi,double *t,double *h );
void yukari_atis(double *g,int *gezegensayisi,double*v0,double*hmax);
void agirlik(double *g,int *gezegensayisi,double *m,double *G);
void potansiyel(double *g, int *gezegensayisi, double *m, double *h,double *ep);
void hidrostatik(double *g, int *gezegensayisi,double *rho, double *derinlik,double *p);
void kaldirma_kuvveti(double *g,int *gezegensayisi,double *rho,double *V,double *P);
void periyod(double *g, int *gezegensayisi,double *L,double *T);
void ip_gerilmesi(double *g,int *gezegensayisi,double *m,double *gerilme);
void asansor(double *g,int *gezegensayisi,double *m,double *a,int *yon,double* F);

void secim(int *no);
int main()
{
    double g[]={3.703,8.872,9.8067,1.625,3.728,25.93,11.19,9.01,11.28};

    char *gezegenler[]={"Merkur","Venus","Dunya","Ay","Mars","Jupiter","Saturn","Uranus","Neptun"};

    double h[9],t,v0,m,G,yukseklik,rho,derinlik,V,L,a;
    int no,gezegensayisi=9,yon;
    char name[50];
    printf("UZAY SIMULASYONU UYGULAMASI\n");
    printf("Lutfen isminizi giriniz:");
    scanf("%s",name);
    printf("Merhaba %s ! Asagida numaralandirilmis halde bulunan deneylerden birini secmek icin deney numarasi tuslaman yeterli.\n",name);
    printf("Tekrar tekrar islemler yapabilirsin eger programi durdurmak istersen -1 tuslaman yeterli.\n");
    printf("\n");

     do{
        deneyler();
        printf("\n");
        secim(&no);

        switch(no){
            case 1:
                printf("\n%s icin deney 1 sonuclari:",name);
                printf("\nSaniye cinsinden sureyi giriniz:");
                scanf("%lf",&t);

                t=(t<0)?-t:t;

                serbest_dusme(g,&gezegensayisi,&t,h);
                int i;
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin alinan yol: %lf metre\n",
                            *(gezegenler+i),
                            *(h+i));
                }
                printf("\n");
            break;

            case 2:
                printf("\n%s icin deney 2 sonuclari:",name);
                printf("\nBaslangic hizini giriniz (m/s):");
                scanf("%lf",&v0);

                v0=(v0<0)?-v0:v0;

                yukari_atis(g,&gezegensayisi,&v0,h);
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin maksimum yukseklik: %lf metre\n",
                    *(gezegenler +i),
                    *(h+i));
                }
                printf("\n");
                break;

            case 3:
                printf("\n%s icin deney 3 sonuclari:",name);
                printf("\nKilogram cinsinden kutleyi giriniz:");
                scanf("%lf",&m);

                m=(m<0)?-m:m;

                agirlik(g,&gezegensayisi,&m,h);
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin agirlik: %lf Newton\n",
                    *(gezegenler +i),
                    *(h+i));
                }
                printf("\n");
                break;

            case 4:
                printf("\n%s icin deney 4 sonuclari:",name);
                printf("\nKilogram cinsinden kutleyi giriniz:");
                scanf("%lf",&m);
                printf("Metre cinsinden yuksekligi giriniz:");
                scanf("%lf",&yukseklik);

                m=(m<0)?-m:m;
                yukseklik=(yukseklik<0)?-yukseklik:yukseklik;

                potansiyel(g,&gezegensayisi,&m,&yukseklik,h);
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin potansiyel enerji: %lf Joule\n",
                    *(gezegenler +i),
                    *(h+i));
                }
                printf("\n");
                break;

            case 5:
               printf("\n%s icin deney 5 sonuclari:",name);
               printf("\nSivi yogunlugunu giriniz:");
               scanf("%lf",&rho);
               printf("Metre cinsinden derinligi giriniz:");
               scanf("%lf",&derinlik);

               rho=(rho<0)?-rho:rho;
               derinlik=(derinlik<0)?-derinlik:derinlik;

               hidrostatik(g,&gezegensayisi,&rho,&derinlik,h);
               for(i=0;i<gezegensayisi;i++){
                    printf("%s icin hidrostatik basinc: %lf Pascal\n",
                    *(gezegenler +i),
                    *(h+i));
                }
                printf("\n");
                break;

            case 6:
                printf("\n%s icin deney 6 sonuclari:",name);
                printf("\nSivinin yogunlugunu giriniz:");
                scanf("%lf",&rho);
                printf("Sivinin batan hacmini giriniz:");
                scanf("%lf",&V);

                rho=(rho<0)?-rho:rho;
                V=(V<0)?-V:V;

                kaldirma_kuvveti(g,&gezegensayisi,&rho,&V,h);
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin kaldirma kuvveti: %lf Newton\n",
                    *(gezegenler +i),
                    *(h+i));
                }
                printf("\n");
                break;

            case 7:
                printf("\n%s icin deney 7 sonuclari:",name);
                printf("\nMetre cinsinden sarkacin uzunlugu giriniz:");
                scanf("%lf",&L);

                L=(L<0)?-L:L;

                periyod(g,&gezegensayisi,&L,h);
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin basit sarkac periyodu: %lf saniye\n",
                           *(gezegenler+i),
                           *(h+i));
                }
                printf("\n");
                break;

            case 8:
                printf("\n%s icin deney 8 sonuclari:",name);
                printf("\nKilogram cinsinden kutleyi giriniz:");
                scanf("%lf",&m);

                m=(m<0)?-m:m;

                ip_gerilmesi(g,&gezegensayisi,&m,h);
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin basit ip gerilmesi: %lf Newton\n",
                           *(gezegenler+i),
                           *(h+i));
                }
                printf("\n");
                break;

            case 9:
                printf("\n%s icin deney 9 sonuclari:",name);
                printf("\nKilogram cinsinden kutleyi giriniz:");
                scanf("%lf",&m);
                printf("Asansorun ivmesini giriniz:");
                scanf("%lf",&a);

                 m=(m<0)?-m:m;
                 a=(a<0)?-a:a;

                printf("Hareket yonu yukari ise 1,asagi ise -1 giriniz:");
                scanf("%d",&yon);
                asansor(g,&gezegensayisi,&m,&a,&yon,h);
                for(i=0;i<gezegensayisi;i++){
                    printf("%s icin etkin agirlik %lf Newton\n",
                           *(gezegenler+i),
                           *(h+i));
                }
                printf("\n");
                break;

            case -1:
                printf("Program sonlandirildi");
                break;

            default:
                printf("Gecersiz deney numarasi!\n");

            }
     }while(no!=-1);

    return 0;
}
void secim(int *no){
    printf("Deney numarasini giriniz:");
    scanf("%d",no);
}



void  serbest_dusme(double *g,int *gezegensayisi,double *t,double *h ){

    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(h+i)=0.5*(*(g+i))*(*t)*(*t);
    }
}
void yukari_atis(double *g,int *gezegensayisi,double*v0,double*hmax){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(hmax + i)=(*v0)*(*v0)/(2*(*(g+i)));
    }
}

void agirlik(double *g,int *gezegensayisi,double *m,double *G){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(G+i)=(*(g+i))*(*m);
    }
}

void potansiyel(double *g, int *gezegensayisi, double *m, double *h,double *ep){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(ep+i)=(*m)*(*(g+i))*(*h);
    }
}

void hidrostatik(double *g, int *gezegensayisi,double *rho, double *derinlik,double *p){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(p+i)=(*rho)*(*(g+i))*(*derinlik);
    }
}

void kaldirma_kuvveti(double *g,int *gezegensayisi,double *rho,double *V,double *P){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(P+i)=(*rho)*(*(g+i))*(*V);
    }
}

void periyod(double *g, int *gezegensayisi,double *L,double *T){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(T+i)=2*Pi*sqrt((*L)/(*(g+i)));
    }
}

void ip_gerilmesi(double *g,int *gezegensayisi,double *m,double *gerilme){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        *(gerilme+i)=(*m)*(*(g+i));
    }
}

void asansor(double *g,int *gezegensayisi,double *m,double *a,int *yon,double* F){
    int i;
    for(i=0;i<*gezegensayisi;i++){
        double g_etkin=(*yon==1)?(*(g+i)+*a):(*(g+i)-*a);
        *(F +i)=(*m)*g_etkin;
    }
}
