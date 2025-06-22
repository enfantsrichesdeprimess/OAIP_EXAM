//Задание 1.1 - Частично неверно
#include <iostream>
using namespace std;

int main() {
    double a;
    cout << "Введите число a: ";
    cin >> a;

    double y = 2 * a + 3; // Пример: y = 2a + 3
    cout << "f(a) = " << y << endl;

    return 0;
}

// Задание 1.2
#include <iostream>
using namespace std;

int main() {
    double a, b, k, m;
    cout << "Введите a, b для первой прямой (y = ax + b): ";
    cin >> a >> b;
    cout << "Введите k, m для второй прямой (y = kx + m): ";
    cin >> k >> m;

    if (a == k) {
        cout << "Прямые параллельны или совпадают." << endl;
    } else {
        double x = (m - b) / (a - k);
        double y = a * x + b;
        cout << "Точка пересечения: (" << x << ", " << y << ")" << endl;
    }

    return 0;
}

// Задание 2.1 - Частично неверно
#include <iostream>
using namespace std;

int main() {
    double x, P = 0;
    cout << "Введите x: ";
    cin >> x;

    for (int i = 0; i <= 3; i++) {
        P += pow(x, i) / (i + 1);
    }

    cout << "P = " << P << endl;
    return 0;
}

//Задание 2.2
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
    int max = A[0], maxPos = 0;
    long long product = 1;

    for (int i = 1; i < 10; i++) {
        if (A[i] > max) {
            max = A[i];
            maxPos = i;
        }
    }

    for (int i = maxPos + 1; i < 10; i++) {
        product *= A[i];
    }

    cout << "Произведение: " << product << endl;
    return 0;
}

//Задание 3.2
#include <iostream>
using namespace std;

int main() {
    int A[10] = {5, 8, 3, 8, 9, 2, 9, 4, 7, 6};
    int min = A[0], max = A[0], minPos = 0, maxPos = 0;
    double sum = 0, count = 0;

    for (int i = 1; i < 10; i++) {
        if (A[i] < min) { min = A[i]; minPos = i; }
        if (A[i] > max) { max = A[i]; maxPos = i; }
    }

    int start = min(minPos, maxPos);
    int end = max(minPos, maxPos);

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
    int A[10][10]; // Заполните матрицу - она незваполнена
    int B[10];

    for (int i = 0; i < 10; i++) {
        B[i] = A[i][9 - i];
    }

    int min = B[0], max = B[0], minPos = 0, maxPos = 0;
    for (int i = 1; i < 10; i++) {
        if (B[i] < min) { min = B[i]; minPos = i; }
        if (B[i] > max) { max = B[i]; maxPos = i; }
    }

    swap(B[minPos], B[maxPos]);

    for (int i = 0; i < 10; i++) {
        cout << B[i] << " ";
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
        if (num % 2 != 0) num += 1;
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

struct Student {
    string name;
    int grades[3];
    double avg;
};

vector<Student> students;

void loadFromFile(const string& filename) {
    ifstream file(filename);
    Student s;
    while (file >> s.name >> s.grades[0] >> s.grades[1] >> s.grades[2]) {
        s.avg = (s.grades[0] + s.grades[1] + s.grades[2]) / 3.0;
        students.push_back(s);
    }
    file.close();
}

void saveToFile(const string& filename) {
    ofstream file(filename);
    for (const Student& s : students) {
        file << s.name << " " << s.grades[0] << " " << s.grades[1] << " " << s.grades[2] << endl;
    }
    file.close();
}

int main() {
    loadFromFile("students.txt");

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.avg > b.avg;
    });

    saveToFile("sorted_students.txt");
    return 0;
}
