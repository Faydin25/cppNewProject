# Ferhat Yiğit Aydın
# 04.07.2025

# Metin Şifreleme Algoritması

Bu program, verilen bir metni boşluklardan arındırıp satır-sütun matrisine dönüştürerek şifreli bir görünüm sunar.

1. Dosyadan metin okunur.
2. Boşluklar silinir.
3. Metin uzunluğu `l` alınır.
4. `m` ve `n` için: `⌊√l⌋ ≤ m ≤ n ≤ ⌈√l⌉` şartını sağlayan ilk `m * n ≥ l` kombinasyonu bulunur.
5. Metin, `m × n` boyutlu matrise satır satır yazdırılır.


Giriş:  
`Iyi gunler Ali`

Çıkış:
Iyig
unle
rAli

- Başta `m * n < l` hatası yaşandı, dinamik hesaplamayla çözüldü.
- Son satır eksik çıkıyordu, index kontrolü ile düzeltildi.
- Gerekirse Türkçe karakter dönüştürme eklenebilir. Türkçe karakterler bastırılırken ascii değerlerinden dolayı karmaşa yaşanabiliyor.

Programı çalıştırmak için extra Makefile yazıldı. "make" Yazarak kodu derleyebilirsiniz.(Ubuntu ile Make çalıştırdım.)