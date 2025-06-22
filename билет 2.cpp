//Задание 1.
//1.Даны вещественные числа x и y. Определить принадлежит ли точка с координатами (х,у) заштрихованной области по х от -2 до 2 по у от -3 до 2 треугольник. 
#include <iostream>
#include <cmath>
using namespace std;
bool isPointInTriangle(double x, double y) {
    double x1 = -2, y1 = -3;
    double x2 = 2, y2 = -3;
    double x3 = 0, y3 = 2;
    double d1 = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
    double d2 = (x - x2) * (y3 - y2) - (y - y2) * (x3 - x2);
    double d3 = (x - x3) * (y1 - y3) - (y - y3) * (x1 - x3);
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}
bool isPointInShadedArea(double x, double y) {
    return (x >= -2 && x <= 2) && (y >= -3 && y <= 2);
}
int main() {
    double x, y;
    cout << "Введите координаты точки (x, y): ";
    cin >> x >> y;
    if (isPointInShadedArea(x, y) && isPointInTriangle(x, y)) {
        cout << "Точка (" << x << ", " << y << ") принадлежит заштрихованной области." << endl;
    } else {
        cout << "Точка (" << x << ", " << y << ") не принадлежит заштрихованной области." << endl;
    }
    return 0;
}
//2. Задана окружность с центром в точке О(х0,у0) и радиусом r0. Определить пересекается ли заданная окружность с осью абсцисс, если пересекается найти точки пересечения. 
#include <iostream>
#include <cmath>
using namespace std;
void findIntersectionWithXAxis(double x0, double y0, double r0) {
    if (fabs(y0) < r0) {
        double x1 = x0 - sqrt(r0 * r0 - y0 * y0);
        double x2 = x0 + sqrt(r0 * r0 - y0 * y0);
        cout << "Окружность пересекается с осью абсцисс в точках: "
                  << "(" << x1 << ", 0) и (" << x2 << ", 0)" << endl;
    } else if (fabs(y0) == r0) {
        cout << "Окружность касается оси абсцисс в точке: "
                  << "(" << x0 << ", 0)" << endl;
    } else {
        cout << "Окружность не пересекает ось абсцисс." << endl;
    }
}
int main() {
    double x0, y0, r0;
    cout << "Введите координаты центра окружности (x0, y0) и радиус r0: ";
    cin >> x0 >> y0 >> r0;
    findIntersectionWithXAxis(x0, y0, r0);
    return 0;
}
//Задание 2.
//1.Вывести на экран таблицу значений функции y =0.7* x4 - 4.5 * (x2/e) в диапазоне от 5 до10 с шагом1
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    const double e = exp(1);
    cout << fixed << setprecision(4); 
    cout << "  x       y" <<endl;
    for (double x = 5; x <= 10; x += 1) {
        double y = 0.7 * pow(x, 4) - 4.5 * (pow(x, 2) / e);
        cout << setw(4) << x << "  " << y << endl;
    }
    return 0;
}
//2. Вводится последовательность произвольных чисел, 0 — конец последовательности.
//Определить сумму четных элементов последовательности.
#include <iostream>
using namespace std;
int main() {
    int number;
    int sum = 0;
    cout << "Введите числа (0 для завершения):" << endl;
    while (true) {
        cin >> number; 
        if (number == 0) {
            break;
        }
        if (number % 2 == 0) {
            sum += number; 
        }
    }
    cout << "Сумма четных элементов: " << sum << endl;
    return 0;
}
//Задание 3.
//1. В одномерном массиве А(10) вычислить сумму элементов, расположенных после
//максимального. 
#include <iostream>
#include <climits>
using namespace std;
int main() {
    const int size = 10;
    int A[size];
    cout << "Введите 10 элементов массива:\n";
    for (int i = 0; i < size; ++i) {
        cin >> A[i];
    }
    int max_value = INT_MIN;
    int max_index = -1;
    for (int i = 0; i < size; ++i) {
        if (A[i] > max_value) {
            max_value = A[i];
            max_index = i;
        }
    }
    int sum = 0;
    for (int i = max_index + 1; i < size; ++i) {
        sum += A[i];
    }
    cout << "Сумма элементов после максимального: " << sum << endl;
    return 0;
}
//2. В одномерном массиве А(10) вычислить среднее арифметическое элементов,
//расположенных между минимальным и максимальным. 
#include <algorithm>
#include <numeric> 
using namespace std;
int main() {
    const int SIZE = 10;
    int A[SIZE];
    cout << "Введите 10 элементов массива:\n";
    for (int i = 0; i < SIZE; ++i) {
        cin >> A[i];
    }
    auto min_it = min_element(A, A + SIZE);
    auto max_it = max_element(A, A + SIZE);
    int start = min_it - A;
    int end = max_it - A;
    if (start > end) {
        swap(start, end);
    }
    if (end - start <= 1) {
        cout << "Между минимальным и максимальным элементами нет других элементов.\n";
        return 0;
    }
    int sum = 0;
    int count = 0;
    for (int i = start + 1; i < end; ++i) {
        sum += A[i];
        count++;
    }
    double average = static_cast<double>(sum) / count;
    cout << "Среднее арифметическое элементов между min и max: " << average << endl;
    return 0;
}
//Задание 4.
//1. Дана матрица А(4,4). Если первый элемент строки положительный То все элементы
//данной строки переписать в обратном порядке. Построить вектор В из элементов последнего столбца матрицы.
#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
const int SIZE = 4;
int main() {
    int A[SIZE][SIZE];
    vector<int> B; 
    cout << "Введите элементы матрицы 4x4:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        if (A[i][0] > 0) {
            reverse(begin(A[i]), end(A[i]));
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        B.push_back(A[i][SIZE-1]);
    }
    cout << "\nПреобразованная матрица:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nВектор B (последний столбец):\n";
    for (int num : B) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
//2. Дано: X(М), Y(N). Вектор, имеющий наибольшее количество одинаковых компонент
//преобразовать по правилу; все компоненты >10 заменить на 0.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int countMaxDuplicates(const vector<int>& vec) {
    map<int, int> freqMap;
    for (int num : vec) {
        freqMap[num]++;
    }
    int maxCount = 0;
    for (const auto& pair : freqMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
        }
    }
    return maxCount;
}
void transformVector(vector<int>& vec) {
    for (int& num : vec) {
        if (num > 10) {
            num = 0;
        }
    }
}
int main() {
    int M, N;
    cout << "Введите размер вектора X: ";
    cin >> M;
    cout << "Введите размер вектора Y: ";
    cin >> N;
    vector<int> X(M), Y(N);
    cout << "Введите элементы вектора X:\n";
    for (int& x : X) {
        cin >> x;
    }
    cout << "Введите элементы вектора Y:\n";
    for (int& y : Y) {
        cin >> y;
    }
    int xDuplicates = countMaxDuplicates(X);
    int yDuplicates = countMaxDuplicates(Y);
    vector<int>* vecToTransform = nullptr;
    if (xDuplicates > yDuplicates) {
        vecToTransform = &X;
        cout << "Вектор X имеет больше одинаковых элементов (" << xDuplicates << ")\n";
    } else if (yDuplicates > xDuplicates) {
        vecToTransform = &Y;
        cout << "Вектор Y имеет больше одинаковых элементов (" << yDuplicates << ")\n";
    } else {
        cout << "Векторы имеют одинаковое количество повторяющихся элементов (" << xDuplicates << ")\n";
        vecToTransform = &X;
    }
    cout << "\nИсходный вектор X: ";
    for (int x : X) {
        cout << x << " ";
    }
    cout << "\nИсходный вектор Y: ";
    for (int y : Y) {
        cout << y << " ";
    }
    if (vecToTransform != nullptr) {
        vector<int> original = *vecToTransform; 
        transformVector(*vecToTransform);
        cout << "\n\nПреобразованный вектор: ";
        for (int num : *vecToTransform) {
            cout << num << " ";
        }
        cout << "\n(Исходные значения: ";
        for (int num : original) {
            cout << num << " ";
        }
        cout << ")";
    }
    return 0;
}
//Задание 5.
//Дан символьный массив, образованный из слов, разделенных пробелами.С
//использованием процедур и функций выполнить:
//1. Выдать на печать слова минимальной длины;
//2. Удалить из слов, имеющих четную длину первую букву;
//З. Проверить, есть ли в тексте симметричные слова;
//4. Удалить из текста слова минимальной длины;
//5. Определить количество слов в тексте, начинающихся на заданную букву.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> splitString(const string& str) {
    vector<string> words;
    string word;
    for (char ch : str) {
        if (ch == ' ') {
            if (!word.empty()) words.push_back(word);
            word.clear();
        } else {
            word += ch;
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}
vector<string> findMinWords(const vector<string>& words) {
    if (words.empty()) return {};
    size_t min_len = min_element(words.begin(), words.end(), 
        [](const string& a, const string& b) { return a.length() < b.length(); })->length();
    vector<string> result;
    copy_if(words.begin(), words.end(), back_inserter(result),
        [min_len](const string& word) { return word.length() == min_len; });
    return result;
}
void processWords(vector<string>& words) {
    for (string& word : words)
        if (word.length() % 2 == 0 && !word.empty())
            word = word.substr(1);
}
bool hasPalindromes(const vector<string>& words) {
    return any_of(words.begin(), words.end(), 
        [](const string& word) { 
            return word.length() > 1 && equal(word.begin(), word.end(), word.rbegin()); 
        });
}
int countStartingWith(const vector<string>& words, char letter) {
    return count_if(words.begin(), words.end(),
        [letter](const string& word) { 
            return !word.empty() && tolower(word[0]) == tolower(letter); 
        });
}
int main() {
    cout << "Введите строку: ";
    string input;
    getline(cin, input);
    vector<string> words = splitString(input);
    auto min_words = findMinWords(words);
    cout << "\n1. Минимальные слова: ";
    for (const auto& word : min_words) cout << word << " ";
    auto words_copy = words;
    processWords(words_copy);
    cout << "\n\n2. После обработки: ";
    for (const auto& word : words_copy) cout << word << " ";
    cout << "\n\n3. Палиндромы: " << (hasPalindromes(words) ? "есть" : "нет");
    words_copy = words;
    if (!min_words.empty()) {
        words_copy.erase(remove_if(words_copy.begin(), words_copy.end(),
            [len = min_words[0].length()](const string& word) { return word.length() == len; }),
            words_copy.end());
    }
    cout << "\n\n4. После удаления: ";
    for (const auto& word : words_copy) cout << word << " ";
    cout << "\n\n5. Введите букву: ";
    char letter;
    cin >> letter;
    cout << "Найдено: " << countStartingWith(words, letter) << endl;
    return 0;
}
