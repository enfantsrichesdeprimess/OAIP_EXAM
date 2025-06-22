//Задание 1.1
#include <iostream>
using namespace std;

int main() {
    int D;
    cout << "Введите число месяца (1-31): ";
    cin >> D;

    string days[] = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    int dayIndex = (D - 1) % 7;

    cout << "День недели: " << days[dayIndex] << endl;
    return 0;
}

//Задание 1.2
// Частично неверное
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a;
    cout << "Введите число a: ";
    cin >> a;

    double y = pow(a, 2); // Пример: y = a²
    cout << "f(a) = " << y << endl;

    return 0;
}

//Задание 2.1
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    for (int i = 10; i < 100; i++) {
        if (i % 2 == 0 && i % 10 != 0) {
            count++;
        }
    }
    cout << "Количество чисел: " << count << endl;
    return 0;
}

// Задание 2.2
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите N: ";
    cin >> N;

    long long product = 1;
    for (int i = 3; i <= N; i += 3) {
        product *= i;
    }
    cout << "Произведение: " << product << endl;

    return 0;
}

//Задание 3.1

#include <iostream>
using namespace std;

int main() {
    int A[10] = {5, 8, 3, 8, 9, 2, 9, 4, 7, 6};
    int max = A[0], sum = 0;

    for (int i = 1; i < 10; i++) {
        if (A[i] > max) max = A[i];
    }

    for (int i = 0; i < 10; i++) {
        if (abs(A[i] - max) == 1) {
            sum += A[i];
        }
    }

    cout << "Сумма: " << sum << endl;
    return 0;
}


//Задание 3.2

#include <iostream>
using namespace std;

int main() {
    int A[10] = {5, 8, 3, 8, 9, 2, 9, 4, 7, 6};
    int min = A[0], max = A[0], minPos = 0, maxPos = 0;

    for (int i = 1; i < 10; i++) {
        if (A[i] < min) { min = A[i]; minPos = i; }
        if (A[i] > max) { max = A[i]; maxPos = i; }
    }

    int start = min(minPos, maxPos);
    int end = max(minPos, maxPos);
    double sum = 0, count = 0;

    for (int i = start + 1; i < end; i++) {
        sum += A[i];
        count++;
    }

    cout << "Среднее: " << (count > 0 ? sum / count : 0) << endl;
    return 0;
}

//Задание 4.1

#include <iostream>
using namespace std;

int main() {
    int A[10][10] = { /* Заполните матрицу */ };
    int max = A[0][0], min = A[0][0], maxRow = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (A[i][j] > max) { max = A[i][j]; maxRow = i; }
            if (A[i][j] < min) min = A[i][j];
        }
    }

    for (int j = 0; j < 10; j++) {
        A[maxRow][j] *= min;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//Задание 4.2

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> X = {5, 10, 15, 20, 10};
    vector<int> Y = {1, 2, 3, 4, 5};

    unordered_set<int> uniqueX(X.begin(), X.end());
    unordered_set<int> uniqueY(Y.begin(), Y.end());

    vector<int>& target = (uniqueX.size() > uniqueY.size()) ? X : Y;

    for (int& num : target) {
        if (num >= 10) num = 1;
    }

    for (int num : target) {
        cout << num << " ";
    }

    return 0;
}

//Задание 5
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shop {
    string name;
    string city;
    int year;
    double profit;
};

vector<Shop> shops;

void addShop() {
    Shop s;
    cout << "Название: "; cin >> s.name;
    cout << "Город: "; cin >> s.city;
    cout << "Год: "; cin >> s.year;
    cout << "Прибыль: "; cin >> s.profit;
    shops.push_back(s);
}

void printByCity(const string& city) {
    for (const Shop& s : shops) {
        if (s.city == city) {
            cout << s.name << ", " << s.year << ", " << s.profit << endl;
        }
    }
}

void saveToFile(const string& filename) {
    ofstream file(filename);
    for (const Shop& s : shops) {
        file << s.name << " " << s.city << " " << s.year << " " << s.profit << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "1. Добавить магазин\n2. Сортировать\n3. Вывести по городу\n4. Сохранить\n0. Выход\n";
        cin >> choice;
        if (choice == 1) addShop();
        else if (choice == 3) {
            string city;
            cout << "Город: ";
            cin >> city;
            printByCity(city);
        }
    } while (choice != 0);

    saveToFile("shops.txt");
    return 0;
}
