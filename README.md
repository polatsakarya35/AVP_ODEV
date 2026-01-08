# Uzay Simülasyonu Projesi

Bursa Teknik Üniversitesi Bilgisayar Mühendisliği Bölümü, Algoritmalar ve Programlama dersi kapsamında geliştirilmiş konsol tabanlı bir fizik simülasyonu uygulamasıdır.

## 📋 Proje Hakkında

Bu proje, bir bilim insanının Güneş Sistemindeki farklı gezegenlerde (Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün) temel fizik deneylerini simüle etmesini sağlar. Program tamamen C programlama dili ile geliştirilmiş olup, konsol tabanlı çalışmaktadır.

Program, kullanıcıdan bilim insanının adını alır ve 9 farklı fizik deneyi seçeneği sunar. Her deney, 8 gezegen için ayrı ayrı hesaplama yaparak sonuçları karşılaştırmalı olarak gösterir.

## 🔬 Deneyler ve Formüller

Program 9 farklı fizik deneyi içermektedir:

1. **Serbest Düşme Deneyi** - `h = (1/2) * g * t²`
   - Düşme süresi girilir, her gezegen için düşme mesafesi hesaplanır.

2. **Yukarı Atış Deneyi** - `h_max = v₀² / (2*g)`
   - Başlangıç hızı girilir, her gezegen için maksimum yükseklik hesaplanır.

3. **Ağırlık Deneyi** - `G = m * g`
   - Kütle girilir, her gezegen için ağırlık hesaplanır.

4. **Kütleçekimsel Potansiyel Enerji Deneyi** - `Ep = m * g * h`
   - Kütle ve yükseklik girilir, her gezegen için potansiyel enerji hesaplanır.

5. **Hidrostatik Basınç Deneyi** - `P = ρ * g * h`
   - Sıvı yoğunluğu ve derinlik girilir, her gezegen için basınç hesaplanır.

6. **Arşimet Kaldırma Kuvveti Deneyi** - `Fk = ρ * g * V`
   - Sıvı yoğunluğu ve batan hacim girilir, her gezegen için kaldırma kuvveti hesaplanır.

7. **Basit Sarkaç Periyodu Deneyi** - `T = 2π * √(L/g)`
   - İp uzunluğu girilir, her gezegen için sarkaç periyodu hesaplanır.

8. **Sabit İp Gerilmesi Deneyi** - `T = m * g`
   - Kütle girilir, her gezegen için ip gerilmesi hesaplanır.

9. **Asansör Deneyi** - `T = m * (g + a)`
   - Kütle ve asansör ivmesi girilir, her gezegen için gerilme kuvveti hesaplanır.

## 🪐 Gezegenler ve Yerçekimi İvmeleri

Program aşağıdaki gezegenlerin gerçek yerçekimi ivme değerlerini kullanır:

| Gezegen | Yerçekimi İvmesi (m/s²) |
|---------|------------------------|
| Merkür  | 3.7                    |
| Venüs   | 8.87                   |
| Dünya   | 9.81                   |
| Mars    | 3.71                   |
| Jüpiter | 24.79                  |
| Satürn  | 10.44                  |
| Uranüs  | 8.87                   |
| Neptün  | 11.15                  |

## 🚀 Kullanım

### Derleme

Programı derlemek için:

```bash
gcc uzay_simulasyonu.c -o uzay_simulasyonu -lm
```

**Not:** `-lm` parametresi matematik kütüphanesini (math.h) bağlamak için gereklidir.

### Çalıştırma

```bash
./uzay_simulasyonu
```

### Program Akışı

1. Program başladığında bilim insanının adı istenir.
2. Deney menüsü gösterilir.
3. Kullanıcı 1-9 arası bir deney seçer (çıkış için 0).
4. Seçilen deneye göre gerekli parametreler istenir.
5. Tüm gezegenler için sonuçlar hesaplanır ve tablo halinde gösterilir.
6. Devam etmek için Enter'a basılır ve menü tekrar gösterilir.

## 💻 Teknik Detaylar

### Programlama Özellikleri

- **Dil:** C
- **Derleyici:** GCC
- **Kütüphaneler:** 
  - `stdio.h` - Girdi/çıktı işlemleri
  - `math.h` - Matematiksel fonksiyonlar (sqrt, PI)
  - `stdlib.h` - Standart kütüphane
  - `string.h` - String işlemleri

### Kullanılan Programlama Teknikleri

- **Pointer Aritmetiği:** Dizilere pointer ile erişim ve işlem yapma
- **Modüler Programlama:** Her deney ayrı bir fonksiyon olarak tasarlanmış
- **Girdi Doğrulama:** Kullanıcı girdilerinin kontrolü ve hata yönetimi
- **Ternary Operatör:** Negatif değer kontrolünde kullanım
- **Fonksiyon Prototipleri:** Kod organizasyonu için önceden tanımlama

### Önemli Fonksiyonlar

- `menu_goster()` - Deney menüsünü gösterir
- `menu_secimi_al()` - Kullanıcıdan menü seçimi alır ve doğrular
- `deger_al()` - Kullanıcıdan sayısal değer alır ve doğrular
- `negatif_kontrol()` - Negatif değerleri pozitife çevirir (mutlak değer)
- `sonuclari_yazdir()` - Deney sonuçlarını tablo halinde yazdırır
- Her deney için ayrı fonksiyon (örn: `serbest_dusme()`, `yukari_atis()`, vb.)

## 📝 Özellikler

- ✅ 8 farklı gezegen için karşılaştırmalı hesaplama
- ✅ 9 farklı fizik deneyi
- ✅ Kullanıcı dostu menü sistemi
- ✅ Girdi doğrulama ve hata yönetimi
- ✅ Negatif değer kontrolü
- ✅ Detaylı sonuç tabloları
- ✅ Modüler ve okunabilir kod yapısı

## 👤 Hazırlayan

**Polat Sakarya**  
Öğrenci No: 24360859071  
Bursa Teknik Üniversitesi - Bilgisayar Mühendisliği

## 📚 Ders Bilgileri

- **Ders:** Algoritmalar ve Programlama
- **Dönem:** 2025-2026 Güz Dönemi
- **Ders Yürütücüleri:**
  - Arş. Gör. Hasibe Candan KADEM
  - Arş. Gör. Yusuf KAYIPMAZ
  - Arş. Gör. Zeynep BARUT

---

*Bu proje bireysel olarak geliştirilmiştir.*
