// Ferhat Yiğit Aydın
// 04.07.2025

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

std::string DeleteSpace(std::string str)
{
    std::string newStr;
    for (int i = 0; str[i] != '\0' ; i++){
        if (str[i] != ' ')
            newStr += str[i];
    }
    return newStr;
}

int StartAlgorithm(std::string str)
{
    int l = str.length();
    int lower = floor(sqrt(l)); // alt taban Y EKS
    int upper = ceil(sqrt(l));  // üst taban X EKS 
    int m = 0, n = 0;

    // m * n >= l olacak ilk uygun kombinasyonu buluyoruz.
    for (int i = lower; i <= upper; ++i) {
        for (int j = i; j <= upper; ++j) {
            if (i * j >= l) {
                m = i;
                n = j;
                break;
            }
        }
        if (m && n) break;
    }
    if ((m * n) < l){
        std::cout << "Hata Var!" << std::endl;
        return 1;
    }
    else
    {
        int index = 0;
        for (int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                std::cout << str[index];
                index++;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

int main()
{
    std::string fileName;
    std::cout << "Dosya adini giriniz: ";
    std::cin >> fileName;
    std::ifstream file(fileName);

    if (!file.is_open()) {
    std::cerr << "Dosya açilamadi!" << std::endl;
    return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string str = buffer.str();
    std::string newStr = DeleteSpace(str);
    if (StartAlgorithm(newStr)){
        file.close();
        return 1;
    }
    else{
        file.close();
        return 0;
    }
}