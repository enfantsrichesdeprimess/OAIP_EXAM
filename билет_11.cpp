//Задание 1.1
#include <iostream>
using namespace std;

int main() {
    double x, y;
    cout << "Введите координаты точки (x y): ";
    cin >> x >> y;

    if (x >= -1.0 && x <= 3.0 && y >= -2.0 && y <= 4.0) {
        cout << "Точка (" << x << ", " << y << ") принадлежит заданной области";
    } else {
        cout << "Точка (" << x << ", " << y << ") НЕ принадлежит заданной области";
    }

    return 0;
}

//Задание 1.2
1.2
#include <iostream>
using namespace std;

int main() {
    double x, y;
    cout << "Введите координаты точки (x y): ";
    cin >> x >> y;

    if (x >= -3.0 && x <= 5.0 && y >= -1.0 && y <= 4.0) {
        cout << "Принадлежит";
    } else {
        cout << "Не принадлежит";
    }

    return 0;
}

//Задание 2.1
2.1

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "x y" << endl; 
    
    for(int x = 5; x <= 10; x++) {
        double y = 0.7 * pow(x, 4) - 4.5 * (pow(x, 2) / exp(1));
        cout << x << " " << y << endl;
    }
    
    return 0;
}

//Задание 2.2
2.2 
#include <iostream>
using namespace std;

int main() {
    int n, min = 0, max = 0;
    bool hasNumbers = false;
    
    while (cin >> n && n != 0) {
        if (!hasNumbers) {
            min = max = n;
            hasNumbers = true;
        } else {
            if (n < min) min = n;
            if (n > max) max = n;
        }
    }

    if (hasNumbers) {
        cout << (double)min / max;
    }
    
    return 0;
}

//Задание 3.1
3.1
#include <iostream>
using namespace std;

int main() {
    int A[10];
    int min_val, min_index;
    
    for(int i = 0; i < 10; i++) {
        cin >> A[i];
        if(i == 0 || A[i] < min_val) {
            min_val = A[i];
            min_index = i;
        }
    }
    
    if(min_index > 0) {
        double sum = 0;
        for(int i = 0; i < min_index; i++) {
            sum += A[i];
        }
        cout << sum / min_index;
    } else {
        cout << "Нет элементов до минимального";
    }
    
    return 0;
}

//Задание 3.2
#include <iostream>
using namespace std;

int main() {
    int A[10];
    int min_val, max_val;
    int min_idx = 0, max_idx = 0;

    for(int i = 0; i < 10; i++) {
        cin >> A[i];
        if(i == 0  A[i] < min_val) {
            min_val = A[i];
            min_idx = i;
        }
        if(i == 0  A[i] > max_val) {
            max_val = A[i];
            max_idx = i;
        }
    }

    int sum = 0;
    int start = min(min_idx, max_idx);
    int end = max(min_idx, max_idx);
    
    for(int i = start + 1; i < end; i++) {
        sum += A[i];
    }

    cout << sum;
    return 0;
}

//Задание 4.1
#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    int A[N][N], B[N];
  
    cout << "Введите элементы матрицы 4x4:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i][0] > 0) {
  
            for(int j = 0; j < N/2; j++) {
                swap(A[i][j], A[i][N-1-j]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        B[i] = A[i][N-1];
    }

    cout << "\nПреобразованная матрица:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nВектор B (последний столбец):\n";
    for(int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }

    return 0;
}

//Задание 4.2
4.2
#include <iostream>
using namespace std;

const int N = 6;

int main() {
    int A[N][N];
    bool symmetric = true;

    cout << "Введите матрицу 6x6:\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(A[i][j] != A[j][i]) {
                symmetric = false;
                break;
            }
        }
        if(!symmetric) break;
    }

    if(symmetric) {
        for(int i = 0; i < N; i++) {
            A[i][i] = 0;
        }
        cout << "Матрица симметрична. Преобразованная матрица:\n";
    } else {
        cout << "Матрица не симметрична.\n";
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
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

void loadFromFile() {
    ifstream file("shops.txt");
    if (!file) return;
    
    Shop s;
    while (file >> s.name >> s.city >> s.year >> s.profit) {
        shops.push_back(s);
    }
    file.close();
}

void saveToFile() {
    ofstream file("shops.txt");
    for (const auto& s : shops) {
        file << s.name << " " << s.city << " " << s.year << " " << s.profit << endl;
    }
    file.close();
}

void addShop() {
    Shop s;
    cout << "Введите данные магазина:\n";
    cout << "Название: "; cin >> s.name;
    cout << "Город: "; cin >> s.city;
    cout << "Год: "; cin >> s.year;
    cout << "Прибыль: "; cin >> s.profit;
    shops.push_back(s);
}

void sortShops() {
    cout << "Сортировать по:\n1. Названию\n2. Прибыли\n3. Году\nВыбор: ";
    int choice; cin >> choice;
    
    if (choice == 1) sort(shops.begin(), shops.end(), 
        [](const Shop& a, const Shop& b) { return a.name < b.name; });
    else if (choice == 2) sort(shops.begin(), shops.end(), 
        [](const Shop& a, const Shop& b) { return a.profit < b.profit; });
    else if (choice == 3) sort(shops.begin(), shops.end(), 
        [](const Shop& a, const Shop& b) { return a.year < b.year; });
}

void showByCity() {
    string city;
    cout << "Введите город: "; cin >> city;
    
    for (const auto& s : shops) {
        if (s.city == city) {
            cout << s.name << " " << s.city << " " << s.year << " " << s.profit << endl;
        }
    }
}

int main() {
    loadFromFile();
    
    while (true) {
        cout << "\nМеню:\n1. Добавить\n2. Сортировать\n3. Поиск по городу\n4. Выход\nВыбор: ";
        int choice; cin >> choice;
        
        if (choice == 1) addShop();
        else if (choice == 2) sortShops();
        else if (choice == 3) showByCity();
        else if (choice == 4) break;
    }
    
    saveToFile();
    return 0;
}
