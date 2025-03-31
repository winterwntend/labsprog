#include <iostream>
#include <string>
using namespace std;

// Структура элемента списка
struct Item {
    string name;
    int value_int;
    double value_double;
    Item* next;

    Item(string n, int vi, double vd) : name(n), value_int(vi), value_double(vd), next(nullptr) {}
};

// Глобальная переменная — голова списка
Item* head = nullptr;

// Добавление в начало списка
void addToFront(string name, int vi, double vd) {
    Item* newItem = new Item(name, vi, vd);
    newItem->next = head;
    head = newItem;
}

// Добавление в конец списка
void addToEnd(string name, int vi, double vd) {
    Item* newItem = new Item(name, vi, vd);
    if (!head) {
        head = newItem;
        return;
    }
    Item* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newItem;
}

// Вставка после элемента с заданным именем
void insertAfter(string targetName, string name, int vi, double vd) {
    Item* current = head;
    while (current) {
        if (current->name == targetName) {
            Item* newItem = new Item(name, vi, vd);
            newItem->next = current->next;
            current->next = newItem;
            return;
        }
        current = current->next;
    }
    cout << "Элемент '" << targetName << "' не найден!" << endl;
}

// Вставка перед элементом с заданным именем
void insertBefore(string targetName, string name, int vi, double vd) {
    if (!head) return;

    if (head->name == targetName) {
        addToFront(name, vi, vd);
        return;
    }

    Item* prev = head;
    Item* current = head->next;
    while (current) {
        if (current->name == targetName) {
            Item* newItem = new Item(name, vi, vd);
            newItem->next = current;
            prev->next = newItem;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Элемент '" << targetName << "' не найден!" << endl;
}

// Удаление элемента по имени
void deleteByName(string name) {
    if (!head) return;

    if (head->name == name) {
        Item* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Item* prev = head;
    Item* current = head->next;
    while (current) {
        if (current->name == name) {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Элемент '" << name << "' не найден!" << endl;
}

// Вывод списка
void printList() {
    Item* current = head;
    while (current) {
        cout << "Имя: " << current->name 
             << ", int: " << current->value_int 
             << ", double: " << current->value_double << endl;
        current = current->next;
    }
    cout << "--- Конец списка ---" << endl;
}

// Основная функция
int main() {
    // Тестируем функции
    addToFront("First", 10, 3.14);
    addToEnd("Last", 20, 6.28);
    insertAfter("First", "Middle", 15, 4.56);
    insertBefore("Last", "BeforeLast", 18, 5.67);
    
    cout << "Список после добавления элементов:" << endl;
    printList();

    deleteByName("Middle");
    cout << "Список после удаления 'Middle':" << endl;
    printList();

    return 0;
}
