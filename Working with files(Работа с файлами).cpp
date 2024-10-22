#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Phone {
    std::string manufacturer;
    std::string model;
    double weight;
    double price;
};

std::vector<Phone> getPhones() {
    return {
        {"Samsung", "GalaxyS21", 169, 79999},
        {"Apple", "iPhone12", 162, 99999},
        {"Xiaomi", "Mi11", 196, 74999},
        {"Samsung", "GalaxyA52", 189, 29999},
        {"Apple", "iPhoneSE", 148, 39999}
    };
}

void processPhones(const std::vector<Phone>& phones, const std::string& targetManufacturer) {
    double totalCost = 0.0;
    int count = 0;
    double minWeight = std::numeric_limits<double>::max();
    Phone lightestPhone;

    double minPrice = std::numeric_limits<double>::max();
    double maxPrice = std::numeric_limits<double>::min();
    Phone cheapestPhone;
    Phone mostExpensivePhone;

    for (const auto& phone : phones) {
        if (phone.manufacturer == targetManufacturer) {
            totalCost += phone.price;
            count++;

            if (phone.weight < minWeight) {
                minWeight = phone.weight;
                lightestPhone = phone;
            }
        }

        if (phone.price < minPrice) {
            minPrice = phone.price;
            cheapestPhone = phone;
        }

        if (phone.price > maxPrice) {
            maxPrice = phone.price;
            mostExpensivePhone = phone;
        }
    }

    if (count > 0) {
        std::cout << "Средняя стоимость телефонов фирмы " << targetManufacturer << ": "
            << (totalCost / count) << std::endl;
        std::cout << "Самый легкий телефон фирмы " << targetManufacturer << ": "
            << lightestPhone.model << " с весом " << lightestPhone.weight << " г." << std::endl;
    }
    else {
        std::cout << "Телефоны фирмы " << targetManufacturer << " не найдены." << std::endl;
    }

    std::cout << "Самый дешевый телефон: " << cheapestPhone.model << " от "
        << cheapestPhone.manufacturer << " за " << cheapestPhone.price << " руб." << std::endl;

    std::cout << "Самый дорогой телефон: " << mostExpensivePhone.model << " от "
        << mostExpensivePhone.manufacturer << " за " << mostExpensivePhone.price << " руб." << std::endl;
}

int main() {
    std::vector<Phone> phones = getPhones();

    std::string targetManufacturer;
    std::cout << "Введите название фирмы: ";
    std::cin >> targetManufacturer;

    processPhones(phones, targetManufacturer);

    return 0;
}

