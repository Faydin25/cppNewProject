// Ferhat Yiğit Aydın
// 05.07.2025

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath> // abs, min için

const int TotalPoints = 21; // 0–20 dahil
int LastStep = 100;

void SelectRandomAddress(std::vector<std::pair<int, int>> &Address)
{
    std::vector<int> SuitableIndexes;
    for (size_t i = 0; i < Address.size(); i++) {
        const auto& item = Address[i];
        if (item.second != 1) {
            if (LastStep == 100) {
                SuitableIndexes.push_back(i); // ilk adım için mesafe önemsiz
            } else {
                int diff = std::abs(item.first - LastStep);
                int circularDistance = std::min(diff, TotalPoints - diff);
                if (circularDistance >= 5)
                    SuitableIndexes.push_back(i);
            }
        }
    }

    if (!SuitableIndexes.empty()) {
        int randomIndex = std::rand() % SuitableIndexes.size();
        int selectedIndex = SuitableIndexes[randomIndex];
        std::cout << "Gezilen Nokta: " << Address[selectedIndex].first << std::endl;

        Address[selectedIndex].second = 1;
        LastStep = Address[selectedIndex].first;
    } else {
        std::cout << "Suitable bos!" << std::endl;
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::pair<int, int>> Address;
    for (int i = 0; i < TotalPoints; ++i){
        Address.push_back({i, 0});
    }
    
    for(int i = 0; i < 10; ++i){
        SelectRandomAddress(Address);
    }

    return 0;
}
