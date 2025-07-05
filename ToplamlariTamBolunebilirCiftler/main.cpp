//Ferhat Yiğit Aydın
//03.07.2025

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <random>
#include <utility>

int RandomValue() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(-1000, 1000);
    return distrib(gen);
}

int CheckInput(int countNumber, size_t posNumber)
{
    if(2 > countNumber || 1000 < countNumber){
        std::cout << "Dizinin uzunlugu 2 ile 1000 arasinda olmali!" << std::endl;
        return 0;
    }
    if (1 > posNumber || 100 < posNumber){
        std::cout << "Pozitif tam sayinin araliği 1 ile 100 arasinda olmalidir!" << std::endl;
        return 0;
    }
    return 1;
}

int mod(int a, int b) {
    return ((a % b) + b) % b;
}

void FindExactlyDivisibleAndPush(int countNumber, std::vector<int>& Numbers, size_t NumberForMod) {
    std::vector<std::pair<int, int>> Couples;

    for (int i = 0; i < countNumber; ++i) {
        for (int j = i + 1; j < countNumber; ++j) {
            int sum = Numbers[i] + Numbers[j];
            if (mod(sum, NumberForMod) == 0) {
                Couples.push_back(std::make_pair(i, j));
            }
        }
    }

    for (const auto& c : Couples) {
        std::cout << "(" << c.first << ", " << c.second << ")" << std::endl;
    }
}


void StartAlgorithm(int countNumber, size_t NumberForMod){
    int index = 0;
    std::vector<int> Numbers(countNumber);
    while (index < countNumber)
        Numbers[index++] = RandomValue();
    
    for (int i = 0; i < index; i++){
        std::cout << i + 1 <<  ". sayi: " << Numbers[i] << std::endl;;
    }
    FindExactlyDivisibleAndPush(countNumber, Numbers, NumberForMod);
}

int main()
{
    int countNumber;
    size_t posNumber;
    while(true)
    {
        std::cout << "Dizinin Uzunlugunu Girin: ";
        std::cin >> countNumber;
        std::cout << "Pozitif Tam Sayi Girin: ";
        std::cin >> posNumber;
        if (!CheckInput(countNumber, posNumber))
            std::cout << "Hatali input! Tekrar Deneyin." << std::endl;
        else
            break ;
    }
    StartAlgorithm(countNumber,posNumber);
    return 0;
}