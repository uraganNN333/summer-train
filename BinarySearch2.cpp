#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Генерация случайного вектора
vector<int> generateArray(int size) {
    srand(time(0)); // Инициализация генератора

    vector<int> arr(size);
    for (int& num : arr) {
        num = rand() % (size * 2 + 1);  // случайные числа от 0 до size*2
    }

    sort(arr.begin(), arr.end());                 // Сортировка
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); // Удаление дубликатов

    return arr;
}

// Поиск минимального отсутствующего элемента
int findMissingNumber(const vector<int>& arr) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    vector<int> arr = generateArray(size);

    cout << "Сгенерированный массив:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    int missing = findMissingNumber(arr);
    cout << "Наименьшее отсутствующее число: " << missing << "\n";

    return 0;
}
