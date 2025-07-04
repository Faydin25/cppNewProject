# Ferhat Yiğit Aydın
# 03.07.2025

# ToplamlariTamBolunebilirCiftler

Bu program, kullanıcıdan dizi uzunluğu ve bir pozitif tam sayı (k) alır. Rastgele tamsayılarla bir dizi oluşturur. Dizideki toplamı k'ya tam bölünebilen indis çiftlerini ekrana yazdırır.

## Dikkat Edilmesi Gerekenler

C++'da Mod Alma:
C++ dilinde `%` operatörü negatif sayılar için matematiksel mod değil, kalan (remainder) döndürür. Bu nedenle negatif sayılarla çalışırken beklenmedik sonuçlar alınabilir. Matematiksel olarak doğru mod almak için şu yöntem kullanılmalıdır:

```cpp
int mod(int a, int b) {
    return ((a % b) + b) % b;
}
```
Bu fonksiyon, hem pozitif hem negatif sayılar için doğru mod değerini verir. 

Programı çalıştırmak için extra Makefile yazıldı. "make" Yazarak kodu derleyebilirsiniz.