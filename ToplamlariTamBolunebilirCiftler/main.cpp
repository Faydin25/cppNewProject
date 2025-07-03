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

int CheckInput(int CountNumber, size_t PozNumber)
{
    if(2 > CountNumber || 1000 < CountNumber){
        std::cout << "Dizinin uzunlugu 2 ile 1000 arasinda olmali!" << std::endl;
        return 0;
    }
    if (1 > PozNumber || 100 < PozNumber){
        std::cout << "Pozitif tam sayinin araliği 1 ile 100 arasinda olmalidir!" << std::endl;
        return 0;
    }
    return 1;
}

int mod(int a, int b) {
    return ((a % b) + b) % b;
}
//************************* */
void FindExactlyDivisibleAndPush(int CountNumber, std::vector<int>& Numbers, size_t NumberForMode) {
    std::vector<std::pair<int, int>> Couples;

    for (int i = 0; i < CountNumber; ++i) {
        for (int j = i + 1; j < CountNumber; ++j) {
            int sum = Numbers[i] + Numbers[j];
            if (mod(sum, NumberForMode) == 0) {
                Couples.push_back(std::make_pair(i, j));
            }
        }
    }

    for (const auto& c : Couples) {
        int sum = Numbers[c.first] + Numbers[c.second];
        std::cout << "(" << c.first << ", " << c.second << ") -> ("
                  << Numbers[c.first] << ", " << Numbers[c.second] << ")"
                  << ", toplam: " << sum
                  << ", mod " << NumberForMode << ": " << mod(sum, NumberForMode)
                  << std::endl;
    }
}


void StartAlgorithm(int CountNumber, size_t NumberForMode){
    int index = 0;
    std::vector<int> Numbers(CountNumber);
    while (index < CountNumber)
        Numbers[index++] = RandomValue();
    std::cout << "Random Sayilar:" << std::endl;
    for (int i = 0; i < index; i++)
        std::cout << Numbers[i] << std::endl;
    std::cout << "------------" << std::endl;
    FindExactlyDivisibleAndPush(CountNumber, Numbers, NumberForMode);
}

int main()
{
    int CountNumber;
    size_t PozNumber;
    while(true)
    {
        std::cout << "Dizinin Uzunlugunu Girin: ";
        std::cin >> CountNumber;
        std::cout << "Pozitif Tam Sayi Girin: ";
        std::cin >> PozNumber;
        if (!CheckInput(CountNumber, PozNumber))
            std::cout << "Hatali input! Tekrar Deneyin." << std::endl;
        else
            break ;
    }
    StartAlgorithm(CountNumber,PozNumber);
    return 0;
}