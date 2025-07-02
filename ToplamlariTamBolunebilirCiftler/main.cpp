#include <iostream>
#include <string>
#include <fstream>
#include <stack>

void FindExactlyDivisibleCouples()

bool CheckInput(int CountNumber, int PozNumber)
{
    if(2 > CountNumber || 1000 < CountNumber){
        std::cout << "Dizinin uzunluğu 2 ile 1000 arasinda olmali!" << std::endl;
        return 0;
    }
    if (1 > PozNumber || 100 < PozNumber){
        std::cout << "Pozitif tam sayinin araliği 1 ile 100 arasinda olmalidir!" << std::endl;
        return 0;
    }
    return 1;
}

int main()
{
    int CountNumber;
    size_t PozNumber;
    while(1)
    {
        std::cout << "Dizinin Uzunlugunu Girin: ";
        std::cin >> CountNumber;
        std::cout << "Pozitif Tam Sayi Girin: ";
        std::cin >> PozNumber;
        if (!CheckInput(CountNumber, PozNumber))
            break;
        else

    }
    return ;
}