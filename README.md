# Uzay Simülasyonu Uygulaması

Bursa Teknik Üniversitesi Bilgisayar Mühendisliği Bölümü, Algoritmalar ve Programlama dersi kapsamında geliştirilmiş konsol tabanlı bir fizik simülasyonu uygulamasıdır.

## 📋 Proje Hakkında

Bu proje, bir bilim insanının farklı gök cisimlerinde (Merkür, Venüs, Dünya, Ay, Mars, Jüpiter, Satürn, Uranüs, Neptün) temel fizik deneylerini simüle etmesini sağlar. Program tamamen C programlama dili ile geliştirilmiş olup, konsol tabanlı çalışmaktadır.

## 🔬 Deneyler

Program 9 farklı fizik deneyi içermektedir:

1. **Serbest Düşme Deneyi** - Belirli bir süre boyunca serbest düşmeye bırakılan cismin aldığı yol
2. **Yukarı Atış Deneyi** - Cismin ilk hızı ile yukarı fırlatılması durumunda çıkabileceği maksimum yükseklik
3. **Ağırlık Deneyi** - Kütle ve yerçekimi ivmesine göre ağırlık hesaplama
4. **Kütleçekimsel Potansiyel Enerji Deneyi** - Cismin kütlesi ve yüksekliğine göre potansiyel enerji
5. **Hidrostatik Basınç Deneyi** - Sıvının yoğunluğu ve derinliğine göre basınç hesaplama
6. **Arşimet Kaldırma Kuvveti Deneyi** - Sıvının yoğunluğu ve cismin batan hacmine göre kaldırma kuvveti
7. **Basit Sarkaç Periyodu Deneyi** - Sarkacın ip uzunluğuna göre salınım periyodu
8. **Sabit İp Gerilmesi Deneyi** - Sabit duran bir cismin ipte oluşturduğu gerilme kuvveti
9. **Asansör Deneyi** - Asansörün ivmesine bağlı olarak cismin görünür ağırlığı

## 🪐 Desteklenen Gök Cisimleri

- Merkür
- Venüs
- Dünya
- Ay
- Mars
- Jüpiter
- Satürn
- Uranüs
- Neptün

## 🚀 Kullanım

### Derleme

Programı derlemek için:

```bash
gcc main.c -o uzay_simulasyonu -lm
```

### Çalıştırma

```bash
./uzay_simulasyonu
```

### Program Akışı

1. Program başladığında isminizi girmeniz istenir
2. Deney menüsü ekrana yazdırılır
3. Yapmak istediğiniz deneyin numarasını seçin (1-9)
4. Deney için gerekli değerleri girin
5. Sonuçlar tüm gök cisimleri için hesaplanır ve gösterilir
6. Programı sonlandırmak için `-1` tuşlayın

## 💻 Teknik Detaylar

- **Programlama Dili:** C
- **Derleyici:** GCC
- **Kütüphaneler:** stdio.h, stdlib.h, math.h
- **Özellikler:** 
  - Pointer aritmetiği kullanımı
  - Modüler programlama
  - Negatif değer kontrolü (ternary operatör ile)
  - 9 farklı gök cismi için hesaplama

## 📝 Notlar

- Negatif değerler otomatik olarak pozitife çevrilir
- Program çalışırken istediğiniz kadar deney yapabilirsiniz
- Her deney sonucu tüm gök cisimleri için ayrı ayrı gösterilir

---

*Bu proje Algoritmalar ve Programlama dersi kapsamında geliştirilmiştir.*
