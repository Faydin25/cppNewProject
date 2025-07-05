// Ferhat Yiğit Aydın
// 05.07.2025

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath> // abs, min için

const int totalPoints = 21; // 0–20 dahil
int lastStep = 100;

void SelectRandomAddress(std::vector<std::pair<int, int>> &Address)
{
    std::vector<int> SuitableIndexes;
    for (size_t i = 0; i < Address.size(); i++) {
        const auto& item = Address[i];
        if (item.second != 1) {
            if (lastStep == 100) {
                SuitableIndexes.push_back(i); // ilk adım için mesafe önemsiz
            } else {
                int diff = std::abs(item.first - lastStep);
                int circularDistance = std::min(diff, totalPoints - diff);
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
        lastStep = Address[selectedIndex].first;
    } else {
        std::cout << "Suitable bos!" << std::endl;
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));//Randomluğun bozulmaması için!

    std::vector<std::pair<int, int>> Address;
    for (int i = 0; i < totalPoints; ++i){
        Address.push_back({i, 0});
    }
    
    for(int i = 0; i < 10; ++i){
        SelectRandomAddress(Address);
    }

    return 0;
}
