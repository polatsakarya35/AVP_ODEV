/*
 Proje: Uzay Simülasyonu
 Ders: Algoritmalar ve Programlama
 Hazırlayan: Polat Sakarya
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265359
#define GEZEGEN_SAYISI 8

// Gezegen isimleri
const char *gezegen_isimleri[] = {
    "Merkür", "Venüs", "Dünya", "Mars", 
    "Jüpiter", "Satürn", "Uranüs", "Neptün"
};

// Gezegenlerin yerçekimi ivmeleri
double g_degerleri[GEZEGEN_SAYISI] = {
    3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.87, 11.15
};

// Fonksiyon prototipleri
void menu_goster();
int menu_secimi_al();
double deger_al(const char* mesaj);
double negatif_kontrol(double deger);
void sonuclari_yazdir(char* bilim_insani, const char* deney_adi, double* sonuclar, const char* birim);

void serbest_dusme(char* bilim_insani, double* g_ptr);
void yukari_atis(char* bilim_insani, double* g_ptr);
void agirlik_deneyi(char* bilim_insani, double* g_ptr);
void potansiyel_enerji(char* bilim_insani, double* g_ptr);
void hidrostatik_basinc(char* bilim_insani, double* g_ptr);
void arsimet_kaldirma(char* bilim_insani, double* g_ptr);
void basit_sarkac(char* bilim_insani, double* g_ptr);
void ip_gerilmesi(char* bilim_insani, double* g_ptr);
void asansor_deneyi(char* bilim_insani, double* g_ptr);

int main() {
    char bilim_insani[100];
    int secim;
    
    // Pointer kullanıyoruz
    double *g_ptr = g_degerleri;
    
    printf("UZAY SİMÜLASYONU PROGRAMI\n");
    printf("---------------------------\n");
    printf("Bilim insanının adını giriniz: ");
    fgets(bilim_insani, sizeof(bilim_insani), stdin);
    // fgets newline karakterini de alır, onu kaldırıyoruz
    size_t len = strlen(bilim_insani);
    if (len > 0 && bilim_insani[len - 1] == '\n') {
        bilim_insani[len - 1] = '\0';
    }
    
    printf("\nHoş geldiniz %s!\n", bilim_insani);
    printf("Fizik deneylerini yapabilirsiniz.\n\n");
    
    do {
        menu_goster();
        secim = menu_secimi_al();
        
        if (secim == 0) {
            printf("\nProgram sonlandırılıyor. İyi çalışmalar, %s!\n", bilim_insani);
            break;
        }
        
        printf("\n--- DENEY BAŞLIYOR ---\n");
        
        switch(secim) {
            case 1:
                serbest_dusme(bilim_insani, g_ptr);
                break;
            case 2:
                yukari_atis(bilim_insani, g_ptr);
                break;
            case 3:
                agirlik_deneyi(bilim_insani, g_ptr);
                break;
            case 4:
                potansiyel_enerji(bilim_insani, g_ptr);
                break;
            case 5:
                hidrostatik_basinc(bilim_insani, g_ptr);
                break;
            case 6:
                arsimet_kaldirma(bilim_insani, g_ptr);
                break;
            case 7:
                basit_sarkac(bilim_insani, g_ptr);
                break;
            case 8:
                ip_gerilmesi(bilim_insani, g_ptr);
                break;
            case 9:
                asansor_deneyi(bilim_insani, g_ptr);
                break;
            default:
                printf("Geçersiz seçim! Lütfen 1-9 arası bir değer giriniz.\n");
        }
        
        printf("\nDevam etmek için Enter'a basınız...");
        getchar();
        getchar();
        printf("\n");
        
    } while(secim != 0);
    
    return 0;
}

// Menü gösterimi
void menu_goster() {
    printf("\n--- DENEY MENÜSÜ ---\n");
    printf("1. Serbest Düşme Deneyi\n");
    printf("2. Yukarı Atış Deneyi\n");
    printf("3. Ağırlık Deneyi\n");
    printf("4. Kütleçekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basınç Deneyi\n");
    printf("6. Arşimet Kaldırma Kuvveti Deneyi\n");
    printf("7. Basit Sarkaç Periyodu Deneyi\n");
    printf("8. Sabit İp Gerilmesi Deneyi\n");
    printf("9. Asansör Deneyi\n");
    printf("0. Çıkış\n");
}

// Menü seçimi alma
int menu_secimi_al() {
    int secim;
    printf("\nDeney numarasını seçiniz (1-9, çıkış için 0): ");
    
    if (scanf("%d", &secim) != 1) {
        // Geçersiz giriş yapıldı
        while(getchar() != '\n'); // Buffer'ı temizliyoruz
        return -1;
    }
    
    if (secim < 0 || secim > 9) {
        printf("Hata: Lütfen 0 ile 9 arasında bir değer giriniz.\n");
        return -1;
    }
    
    return secim;
}

// Değer alma fonksiyonu
double deger_al(const char* mesaj) {
    double deger;
    printf("%s", mesaj);
    
    while(scanf("%lf", &deger) != 1) {
        printf("Geçersiz giriş! Lütfen bir sayı giriniz: ");
        while(getchar() != '\n'); // Buffer'ı temizliyoruz
    }
    
    return deger;
}

// Negatif değerleri pozitife çevirme (ternary operatör kullanıyoruz - zorunlu)
double negatif_kontrol(double deger) {
    // Ternary operatör ile mutlak değer alıyoruz
    double sonuc = (deger < 0) ? -deger : deger;
    
    if (deger < 0) {
        printf("UYARI: Negatif değer girdiniz. Mutlak değer (%.2f) kullanılacak.\n", sonuc);
    }
    
    return sonuc;
}

// Sonuçları yazdırma fonksiyonu (pointer kullanıyoruz - zorunlu)
void sonuclari_yazdir(char* bilim_insani, const char* deney_adi, double* sonuclar, const char* birim) {
    printf("\n--- DENEY SONUÇLARI ---\n");
    printf("Bilim İnsanı: %s\n", bilim_insani);
    printf("Deney: %s\n", deney_adi);
    printf("\n");
    printf("Gezegen          Sonuç\n");
    printf("------------------------\n");
    
    // Pointer ile diziye erişiyoruz (zorunlu)
    const char** isim_ptr = gezegen_isimleri;
    double* sonuc_ptr = sonuclar;
    
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        printf("%-15s %.6f %s\n", *isim_ptr, *sonuc_ptr, birim);
        isim_ptr++;
        sonuc_ptr++;
    }
    printf("------------------------\n");
}

// 1. Serbest Düşme Deneyi: h = (1/2) * g * t^2
void serbest_dusme(char* bilim_insani, double* g_ptr) {
    double t;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Serbest Düşme Deneyi ---\n");
    t = deger_al("Düşme süresini giriniz (saniye): ");
    t = negatif_kontrol(t);
    
    // Her gezegen için hesaplama (pointer aritmetiği ile)
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = 0.5 * (*(g_ptr + i)) * t * t;
    }
    
    sonuclari_yazdir(bilim_insani, "Serbest Düşme Deneyi", sonuclar, "m");
}

// 2. Yukarı Atış Deneyi: h_max = v0^2 / (2*g)
void yukari_atis(char* bilim_insani, double* g_ptr) {
    double v0;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Yukarı Atış Deneyi ---\n");
    v0 = deger_al("Başlangıç hızını giriniz (m/s): ");
    v0 = negatif_kontrol(v0);
    
    // Her gezegen için hesaplama
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = (v0 * v0) / (2.0 * (*(g_ptr + i)));
    }
    
    sonuclari_yazdir(bilim_insani, "Yukarı Atış Deneyi", sonuclar, "m");
}

// 3. Ağırlık Deneyi: G = m * g
void agirlik_deneyi(char* bilim_insani, double* g_ptr) {
    double m;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Ağırlık Deneyi ---\n");
    m = deger_al("Cismin kütlesini giriniz (kg): ");
    m = negatif_kontrol(m);
    
    // Her gezegen için hesaplama
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = m * (*(g_ptr + i));
    }
    
    sonuclari_yazdir(bilim_insani, "Ağırlık Deneyi", sonuclar, "N");
}

// 4. Kütleçekimsel Potansiyel Enerji: Ep = m * g * h
void potansiyel_enerji(char* bilim_insani, double* g_ptr) {
    double m, h;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Kütleçekimsel Potansiyel Enerji Deneyi ---\n");
    m = deger_al("Cismin kütlesini giriniz (kg): ");
    m = negatif_kontrol(m);
    
    h = deger_al("Yüksekliği giriniz (metre): ");
    h = negatif_kontrol(h);
    
    // Her gezegen için hesaplama
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = m * (*(g_ptr + i)) * h;
    }
    
    sonuclari_yazdir(bilim_insani, "Kütleçekimsel Potansiyel Enerji Deneyi", sonuclar, "J");
}

// 5. Hidrostatik Basınç: P = ρ * g * h
void hidrostatik_basinc(char* bilim_insani, double* g_ptr) {
    double rho, h;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Hidrostatik Basınç Deneyi ---\n");
    rho = deger_al("Sıvının yoğunluğunu giriniz (kg/m³): ");
    rho = negatif_kontrol(rho);
    
    h = deger_al("Derinliği giriniz (metre): ");
    h = negatif_kontrol(h);
    
    // Her gezegen için hesaplama
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = rho * (*(g_ptr + i)) * h;
    }
    
    sonuclari_yazdir(bilim_insani, "Hidrostatik Basınç Deneyi", sonuclar, "Pa");
}

// 6. Arşimet Kaldırma Kuvveti: Fk = ρ * g * V
void arsimet_kaldirma(char* bilim_insani, double* g_ptr) {
    double rho, V;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Arşimet Kaldırma Kuvveti Deneyi ---\n");
    rho = deger_al("Sıvının yoğunluğunu giriniz (kg/m³): ");
    rho = negatif_kontrol(rho);
    
    V = deger_al("Cismin batan hacmini giriniz (m³): ");
    V = negatif_kontrol(V);
    
    // Her gezegen için hesaplama
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = rho * (*(g_ptr + i)) * V;
    }
    
    sonuclari_yazdir(bilim_insani, "Arşimet Kaldırma Kuvveti Deneyi", sonuclar, "N");
}

// 7. Basit Sarkaç Periyodu: T = 2π * sqrt(L/g)
void basit_sarkac(char* bilim_insani, double* g_ptr) {
    double L;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Basit Sarkaç Periyodu Deneyi ---\n");
    L = deger_al("Sarkacın ip uzunluğunu giriniz (metre): ");
    L = negatif_kontrol(L);
    
    // Her gezegen için hesaplama
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = 2.0 * PI * sqrt(L / (*(g_ptr + i)));
    }
    
    sonuclari_yazdir(bilim_insani, "Basit Sarkaç Periyodu Deneyi", sonuclar, "s");
}

// 8. Sabit İp Gerilmesi: T = m * g
void ip_gerilmesi(char* bilim_insani, double* g_ptr) {
    double m;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Sabit İp Gerilmesi Deneyi ---\n");
    m = deger_al("Cismin kütlesini giriniz (kg): ");
    m = negatif_kontrol(m);
    
    // Her gezegen için hesaplama
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        sonuclar[i] = m * (*(g_ptr + i));
    }
    
    sonuclari_yazdir(bilim_insani, "Sabit İp Gerilmesi Deneyi", sonuclar, "N");
}

// 9. Asansör Deneyi: T = m * (g + a)
void asansor_deneyi(char* bilim_insani, double* g_ptr) {
    double m, a;
    double sonuclar[GEZEGEN_SAYISI];
    
    printf("\n--- Asansör Deneyi ---\n");
    m = deger_al("Cismin kütlesini giriniz (kg): ");
    m = negatif_kontrol(m);
    
    a = deger_al("Asansörün ivmesini giriniz (m/s², yukarı pozitif, aşağı negatif): ");
    // Negatif ivme de olabilir (asansör aşağı gidiyorsa)
    // O yüzden negatif kontrolü yapmıyoruz
    
    // Her gezegen için hesaplama yapıyoruz
    // Formül: T = m(g + a)
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double g = *(g_ptr + i);
        // Formül: T = m(g + a)
        sonuclar[i] = m * (g + a);
        
        // Negatif ağırlık olamaz, 0 yapıyoruz
        if (sonuclar[i] < 0) {
            sonuclar[i] = 0;
        }
    }
    
    sonuclari_yazdir(bilim_insani, "Asansör Deneyi", sonuclar, "N");
}
