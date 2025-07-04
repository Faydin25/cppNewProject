# Ferhat Yiğit Aydın
# 02.07.2025

# MetinDuzenle

Bu program, verilen bir metin dosyası üzerinde çeşitli düzenleme işlemleri yapar. Kullanıcıdan alınan komutlara göre metni işler ve çıktıyı ekrana veya dosyaya yazar.

## Dikkat Edilmesi Gerekenler

UNDO Komutu:
Programda yapılan değişikliklerin geri alınabilmesi için UNDO komutu desteklenmektedir. UNDO işleminin doğru çalışabilmesi için, yapılan her düzenleme bir yığın (stack) yapısında saklanır ve kullanıcı UNDO komutunu verdiğinde son yapılan işlem geri alınır. Bu sayede güvenli ve kontrollü bir şekilde metin üzerinde geri alma işlemleri gerçekleştirilebilir.

Programı çalıştırmak için extra Makefile yazıldı. "make" Yazarak kodu derleyebilirsiniz.