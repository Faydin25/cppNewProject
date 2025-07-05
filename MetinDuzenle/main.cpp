//Ferhat Yiğit Aydın
//02.07.2025

#include <iostream>
#include <string>
#include <fstream>
#include <stack>

std::string Append(std::string wordToAdd, std::string str) {
    for (char c : WordToAdd) {
        str += c;
    }
    
    return str;
}

std::string Delete(std::string str, int index) {
    if (index == 0) {
        return str;
    }
    if (index > (int)str.length()) {
        index = str.length(); // kontrol!!
    }
    str.erase(str.end() - index, str.end());
    return str;
}

void Print(std::string str, int index) {
    for (int i = 0; i < index; i++) {
        std::cout << str[i];
    }
    std::cout << std::endl;
}

void Save(std::string str) {
    std::ofstream file("metin.txt");
    file << str;
    file.close();
}

int main() {
    std::string str;
    std::stack<std::string> history;
    std::string input;

    std::cout << "Metin duzenleyiciye hosgeldiniz!" << std::endl;
    std::cout << "Metin duzenleme islemleri icin asagidaki komutlari kullanabilirsiniz:" << std::endl;
    std::cout << "Append <kelime> - Metinin sonuna kelimeyi ekle" << std::endl;
    std::cout << "Delete <sayi> - Metinden son sayi kadar karakteri sil" << std::endl;
    std::cout << "Print <sayi> - Metinden ilk sayi kadar karakteri yazdir" << std::endl;
    std::cout << "Save - Metni dosyaya kaydet" << std::endl;
    std::cout << "Undo - Son islemi geri al" << std::endl;

    while (true) {
        std::cout << "Komut Girin ";
        std::cin >> input;
        std::string command = input.substr(0, input.find(" "));

        if (command == "Append") {
            std::string word;
            std::cin >> word;
            str = Append(word, str);
            history.push(str);
        }
        else if (command == "Delete") {
            int index;
            std::cin >> index;
            history.push(str);
            str = Delete(str, index);
        }
        else if (command == "Print") {
            int index;
            std::cin >> index;
            Print(str, index);
        }
        else if (command == "Save") {
            Save(str);
        }
        else if (command == "Undo") {
            if (!history.empty()) {
                str = history.top();
                history.pop();
            }
            else
                std::cout << "Ilk Komut 'Undo' Olamaz!" << std::endl;
        }
        else
            std::cout << "Gecersiz komut!" << std::endl;
    }
    return 0;
}





