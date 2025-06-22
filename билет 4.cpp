//Задание 1.
//1. Написать программу решения квадратного уравнения аx2 + bx + с = 0. Исходные
//данные: вещественные числа а, b и С — коэффициенты квадратного уравнения. 
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c;
    cout << "Введите коэффициенты a, b и c квадратного уравнения (ax^2 + bx + c = 0): ";
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Уравнение имеет бесконечно много решений (любое x)." << endl;
            } else {
                cout << "Уравнение не имеет решений." << endl;
            }
        } else {
            double x = -c / b;
            cout << "Уравнение линейное. Решение: x = " << x << endl;
        }
    } else {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Уравнение имеет два действительных корня: x1 = " << x1 << ", x2 = " << x2 << endl;
        } else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "Уравнение имеет один действительный корень: x = " << x << endl;
        } else {
            cout << "Уравнение не имеет действительных корней (комплексные корни)." << endl;
        }
    }
    return 0;
}
//2. Определить, пересекаются ли линии У = ах + b, У = kx + m. Если пересекаются,
//найти точку пересечения. 
#include <iostream>
using namespace std;
int main() {
    double a, b, k, m;
    cout << "Введите коэффициенты первой прямой (y = ax + b): ";
    cin >> a >> b;
    cout << "Введите коэффициенты второй прямой (y = kx + m): ";
    cin >> k >> m;
    if (a == k) {
        if (b == m) {
            cout << "Прямые совпадают (бесконечно много точек пересечения)." << endl;
        } else {
            cout << "Прямые параллельны и не пересекаются." << endl;
        }
    } else {
        double x = (m - b) / (a - k);
        double y = a * x + b;
        cout << "Прямые пересекаются в точке: (" << x << ", " << y << ")" << endl;
    }
    return 0;
}
//Задание 2.
//1.
//2. Вводится последовательность произвольных чисел, 0 - конец последовательности.
//Определить отношение минимального и максимального элементов друг к другу.
#include <iostream>
#include <limits>
using namespace std;
int main() {
    double num;
    double min_val = numeric_limits<double>::max(); 
    double max_val = numeric_limits<double>::min();
    cout << "Введите последовательность чисел (0 для завершения):\n";
    while (true) {
        cin >> num;
        if (num == 0) break; 
        if (num < min_val) min_val = num; 
        if (num > max_val) max_val = num; 
    }
    if (min_val == numeric_limits<double>::max() || max_val == numeric_limits<double>::min()) {
        cout << "Последовательность пуста или содержит только 0.\n";
    } else {
        cout << "Минимальный элемент: " << min_val << "\n";
        cout << "Максимальный элемент: " << max_val << "\n";
        if (max_val != 0) {
            double ratio_min_max = min_val / max_val;
            cout << "Отношение min/max: " << ratio_min_max << "\n";
        } else {
            cout << "Максимальный элемент равен 0, деление невозможно.\n";
        }
        if (min_val != 0) {
            double ratio_max_min = max_val / min_val;
            cout << "Отношение max/min: " << ratio_max_min << "\n";
        } else {
            cout << "Минимальный элемент равен 0, деление невозможно.\n";
        }
    }
    return 0;
}
//Задание 3
//1. В одномерном массиве А(10) вычислить среднее арифметическое элементов,
//расположенных до минимального элемента.
#include <iostream>
using namespace std;
int main() {
    const int SIZE = 10;
    double A[SIZE];
    int min_index = 0;
    cout << "Введите 10 элементов массива:\n";
    for (int i = 0; i < SIZE; ++i) {
        cin >> A[i];
        if (A[i] < A[min_index]) min_index = i; 
    }
    if (min_index == 0) {
        cout << "Минимальный элемент первый, элементов до него нет.\n";
    } else {
        double sum = 0;
        for (int i = 0; i < min_index; ++i) {
            sum += A[i];
        }
        double average = sum / min_index;
        cout << "Среднее арифметическое до минимального: " << average << "\n";
    }
    return 0;
}
//2. В одномерном массиве А(10) вычислить сумму элементов массива, отличающихся от
//максимального на 1. 
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const int SIZE = 10;
    double A[SIZE];
    double max_val;
    cout << "Введите 10 элементов массива:\n";
    for (int i = 0; i < SIZE; ++i) {
        cin >> A[i];
        if (i == 0 || A[i] > max_val) max_val = A[i]; 
    }
    double sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (abs(A[i] - max_val) == 1) { 
            sum += A[i];
        }
    }
    cout << "Максимальный элемент: " << max_val << "\n";
    cout << "Сумма элементов, отличающихся от максимума на 1: " << sum << "\n";
    return 0;
}
//Задание 4.
//1. Дана матрица А (6,6). Определить является ли она симметричной относительно
//главной диагонали. Если да, то все элементы этой диагонали заменить нулями. 
#include <iostream>
using namespace std;
const int SIZE = 6;
bool isSymmetric(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}
void replaceDiagonalWithZeros(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        matrix[i][i] = 0;
    }
}
int main() {
    int A[SIZE][SIZE];
    cout << "Введите матрицу 6x6:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> A[i][j];
        }
    }
    if (isSymmetric(A)) {
        cout << "Матрица симметрична относительно главной диагонали.\n";
        replaceDiagonalWithZeros(A);
        cout << "Матрица после замены диагонали нулями:\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Матрица не симметрична.\n";
    }
    return 0;
}
//2. Дано: Х(М), Y(М). Вектор, имеющий наибольшее количество различных компонент
//преобразовать по правилу: ко всем нечетным компонентам прибавить 1. 
#include <iostream>
#include <unordered_set>
using namespace std;
const int M = 5; 
int countUniqueElements(double arr[], int size) {
    unordered_set<double> unique_elements(arr, arr + size);
    return unique_elements.size();
}
void transformVector(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(arr[i]) % 2 != 0) { 
            arr[i] += 1;
        }
    }
}
int main() {
    double X[M], Y[M];
    cout << "Введите элементы вектора X(" << M << "):\n";
    for (int i = 0; i < M; ++i) cin >> X[i];
    cout << "Введите элементы вектора Y(" << M << "):\n";
    for (int i = 0; i < M; ++i) cin >> Y[i];
    int unique_X = countUniqueElements(X, M);
    int unique_Y = countUniqueElements(Y, M);
    if (unique_X > unique_Y) {
        cout << "Вектор X имеет больше уникальных элементов.\n";
        transformVector(X, M);
        cout << "Преобразованный вектор X:\n";
        for (int i = 0; i < M; ++i) cout << X[i] << " ";
    } else if (unique_Y > unique_X) {
        cout << "Вектор Y имеет больше уникальных элементов.\n";
        transformVector(Y, M);
        cout << "Преобразованный вектор Y:\n";
        for (int i = 0; i < M; ++i) cout << Y[i] << " ";
    } else {
        cout << "Оба вектора имеют одинаковое количество уникальных элементов.\n";
    }
    return 0;
}
//Задание 5.
//Дан символьный массив, образованный из слов, разделенных пробелами. С использованием процедур и функций:
//1.Проверить на равенство два указанных слова;
//2. Удалить из слов, имеющих нечетную длину последнюю букву;
//3.Проверить указанное слово на симметричность;
//4. Удалить из текста слова максимальной длины;
//5.Определить сколько слов в тексте, начинаются и заканчиваются на одну и ту же
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> splitText(const string& text) {
    vector<string> words;
    string word;
    for (char ch : text) {
        if (ch == ' ') {
            if (!word.empty()) {
                words.resize(words.size() + 1);
                words.back() = word;
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        words.resize(words.size() + 1);
        words.back() = word;
    }
    return words;
}
bool areWordsEqual(const string& word1, const string& word2) {
    return word1 == word2;
}
void removeLastLetterInOddWords(vector<string>& words) {
    for (string& word : words) {
        if (word.length() % 2 != 0 && !word.empty()) {
            word.resize(word.length() - 1);
        }
    }
}
bool isPalindrome(const string& word) {
    int left = 0, right = word.length() - 1;
    while (left < right) {
        if (word[left] != word[right]) return false;
        left++;
        right--;
    }
    return true;
}
void removeLongestWords(vector<string>& words) {
    if (words.empty()) return;
    size_t max_len = 0;
    for (const string& word : words) {
        if (word.length() > max_len) max_len = word.length();
    }
    words.erase(remove_if(words.begin(), words.end(), 
        [max_len](const string& word) { return word.length() == max_len; }), words.end());
}
int countSameStartEndWords(const vector<string>& words) {
    int count = 0;
    for (const string& word : words) {
        if (!word.empty() && word.front() == word.back()) {
            count++;
        }
    }
    return count;
}
int main() {
    string text;
    cout << "Введите текст (слова через пробел):\n";
    getline(cin, text);
    vector<string> words = splitText(text);
    if (words.size() >= 2) {
        cout << "Слова '" << words[0] << "' и '" << words[1] << "' "
             << (areWordsEqual(words[0], words[1]) ? "равны." : "не равны.") << "\n";
    }
    removeLastLetterInOddWords(words);
    cout << "Текст после удаления последней буквы в нечётных словах:\n";
    for (const string& word : words) cout << word << " ";
    cout << "\n";
    if (!words.empty()) {
        cout << "Слово '" << words[0] << "' "
             << (isPalindrome(words[0]) ? "симметрично." : "не симметрично.") << "\n";
    }
    removeLongestWords(words);
    cout << "Текст после удаления самых длинных слов:\n";
    for (const string& word : words) cout << word << " ";
    cout << "\n";
    cout << "Количество слов, начинающихся и заканчивающихся на одну букву: "
         << countSameStartEndWords(words) << "\n";
    return 0;
}
