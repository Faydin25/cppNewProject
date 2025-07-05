# Ferhat Yiğit Aydın
# 05.07.2025

#Hedef Konum Mesafesi

Bu proje, döngüsel bir alanda (örneğin yuvarlak bir harita üzerinde) rastgele ama mantıklı bir şekilde noktalar arasında gezinmeyi sağlayan bir algoritma içerir.

Amaç
- 0–20 arasında tanımlı noktalardan rastgele bir seçim yapılır.
- Seçilen noktanın daha önce ziyaret edilmemiş olması gerekir.
- Aynı zamanda, bir önceki adımdan en az 5 birim uzaklıkta olmalıdır.
- Alan döngüseldir: 20'den sonra tekrar 0 gelir, yani 0 ve 20 birbirine komşudur.

Önemli Noktalar

1. Rastgelelik
cpp
std::srand(static_cast<unsigned int>(std::time(nullptr)));

Projenin en hassas kısmı burasıydı. İlk başta mesafe sadece fark ile hesaplandı:
int diff = std::abs(a - b);

Ama bu yöntem yuvarlak bir düzende hatalı sonuç verir.

Örneğin:

0 ile 20'nin farkı |0 - 20| = 20 olurdu. Aslında aralarındaki gerçek mesafe sadece 1 birimdir!

Bunu düzeltmek için şu yöntem benimsendi:
int diff = std::abs(item.first - LastStep);
int circularDistance = std::min(diff, TotalPoints - diff);

EXTRA BİLGİ:
Bu proje eğer C dilinde yazılsaydı ve veri yapısı olarak linked list (bağlı liste) kullanılsaydı, döngüsel yapı doğrudan liste mantığına gömülebilirdi.
Her düğüm bir sonraki düğüme bağlı olurdu ve son düğüm tekrar başa bağlanarak doğal bir circular list oluşturulabilirdi.

Programı çalıştırmak için extra Makefile yazıldı. "make" Yazarak kodu derleyebilirsiniz.(Ubuntu ile Make Çalıştırdım.)