//Задание 1.1
#include <iostream>
using namespace std;

int main() {
    double x, y;
    cout << "Введите координаты точки (x y): ";
    cin >> x >> y;

    bool in_rectangle = (x >= -2 && x <= 2) && (y >= -3 && y <= 2);
    
    bool below_left_side = (y <= (5.0 / 2) * x + 2);
    bool below_right_side = (y <= -(5.0 / 2) * x + 2);

    if (in_rectangle && below_left_side && below_right_side) {
        cout << "Точка принадлежит заштрихованной области." << endl;
    } else {
        cout << "Точка не принадлежит заштрихованной области." << endl;
    }

    return 0;
}

//Задание 1.2
#include <iostream>
#include <string>
using namespace std;

int main() {
    int D;
    cout << "Введите число месяца (1-31): ";
    cin >> D;

    if (D < 1 || D > 31) {
        cout << "Ошибка: число должно быть от 1 до 31" << endl;
        return 1;
    }

    string days[] = {"Понедельник", "Вторник", "Среда", 
                    "Четверг", "Пятница", "Суббота", "Воскресенье"};
    
    int dayOfWeek = (D - 1) % 7; 
    
    cout << "День недели: " << days[dayOfWeek] << endl;

    return 0;
}

//Задание 2.1
2.1
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, h;
    
    cout << "Введите начальное значение a: ";
    cin >> a;
    cout << "Введите конечное значение b: ";
    cin >> b;
    cout << "Введите шаг h: ";
    cin >> h;
    
    if (h <= 0) {
        cout << "Ошибка: шаг должен быть положительным числом!";
        return 1;
    }
    if (a > b) {
        cout << "Ошибка: начальное значение должно быть меньше конечного!";
        return 1;
    }
    
    cout << "\n  x\t\t  y\n";
    cout << "-----------------------\n";
    
    cout << fixed << setprecision(4);
    for (double x = a; x <= b; x += h) {
        double denominator = 1.16 * x * x + 2;
        if (fabs(denominator) < 1e-10) {  
            cout << x << "\tне определено (деление на 0)\n";
        }
        else {
            double y = (3.8 * x * x * x - 1) / denominator;
            cout << x << "\t" << y << "\n";
        }
    }
    
    return 0;
}

//Задание 2.2

#include <iostream>
using namespace std;

int main() {
    int num, max = 0;
    
    cout << "Введите последовательность чисел (0 для завершения):\n";
    
    while (true) {
        cin >> num;
        if (num == 0) break;
        if (num > max) max = num;
    }
    
    cout << "Наибольшее число: " << max;
    
    return 0;
}

//Задание 3.1
#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int A[N];

    cout << "Введите 10 элементов массива (сначала положительные, затем отрицательные):\n";
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int first_neg = 0;
    while(first_neg < N && A[first_neg] > 0) {
        first_neg++;
    }

    int product = 1;
    for(int i = 0; i < first_neg; i++) {
        product *= A[i];
    }

    int sum = 0;
    for(int i = first_neg; i < N; i++) {
        sum += A[i];
    }
    
    cout << "Произведение положительных: " << product << endl;
    cout << "Сумма отрицательных: " << sum << endl;
    
    return 0;
}

//Задание 3.2
3.2
#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    double A[N], sum = 0;
    int min_index = 0;

    cout << "Введите 10 элементов массива:\n";
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];  
        if(A[i] < A[min_index]) {
            min_index = i; 
        }
    }

    double average = sum / N;

    cout << "Индекс минимального элемента: " << min_index << endl;
    cout << "Среднее арифметическое: " << average << endl;

    return 0;
}
//Задание №4 (1 часть)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int n = 10;
    int A[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
        }
    }

    cout << "Матрица A:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> B;
    for(int i = 0; i < n; i++) {
        B.push_back(A[i][n-1-i]);
    }

    cout << "\nВектор B:\n";
    for(int num : B) {
        cout << num << " ";
    }

    auto [min_it, max_it] = minmax_element(B.begin(), B.end());
    swap(*min_it, *max_it);

    cout << "\n\nВектор B после замены:\n";
    for(int num : B) {
        cout << num << " ";
    }

    return 0;
}
//Задание №4 (2 часть)

#include <iostream>

using namespace std;

int main() {
    const int n = 6;
    int A[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
        }
    }

    bool symmetric = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(A[i][j] != A[j][i]) {
                symmetric = false;
                break;
            }
        }
        if(!symmetric) break;
    }

    if(symmetric) {
        for(int i = 0; i < n; i++) {
            A[i][i] = 0;
        }
        cout << "Матрица симметрична. Диагональ заменена нулями:\n";
    } else {
        cout << "Матрица не симметрична:\n";
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//Задание №5

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int marks[3];
    double average;
};

bool cmpName(const Student &a, const Student &b) {
    return a.name < b.name;
}

bool cmpAvg(const Student &a, const Student &b) {
    return a.average > b.average;
}

bool cmpMark(const Student &a, const Student &b, int subject) {
    return a.marks[subject] > b.marks[subject];
}

int main() {
    ifstream in("students.txt");
    ofstream out("sorted_students.txt");
    vector<Student> students;
    string line;

    while(getline(in, line)) {
        Student s;
        istringstream iss(line);
        iss >> s.name >> s.marks[0] >> s.marks[1] >> s.marks[2];
        s.average = (s.marks[0] + s.marks[1] + s.marks[2]) / 3.0;
        students.push_back(s);
    }

    cout << "Сортировать по (1-имя, 2-средний, 3-предмет): ";
    int choice;
    cin >> choice;

    if(choice == 1) {
        sort(students.begin(), students.end(), cmpName);
    } else if(choice == 2) {
        sort(students.begin(), students.end(), cmpAvg);
    } else if(choice == 3) {
        cout << "Номер предмета (1-3): ";
        int subject;
        cin >> subject;
        sort(students.begin(), students.end(), 
            [subject](const Student &a, const Student &b) {
                return cmpMark(a, b, subject-1);
            });
    }

    for(const auto &s : students) {
        out << s.name << " " << s.marks[0] << " " 
            << s.marks[1] << " " << s.marks[2] << endl;
    }

    cout << "Список сохранен в sorted_students.txt\n";

    return 0;
}
