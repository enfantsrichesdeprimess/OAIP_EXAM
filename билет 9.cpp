//Билет 9
//1.1
#include <iostream>

using namespace std;

int main() {
    double x, y;

    cout << "Введите координату x: ";
    cin >> x;

    cout << "Введите координату y: ";
    cin >> y;

   
    if (x >= -2.0 && x <= 2.0 && y >= -3.0 && y <= 2.0) {
        cout << "Точка (" << x << "; " << y << ") принадлежит заштрихованной области." << endl;
    } else {
        cout << "Точка (" << x << "; " << y << ") не принадлежит заштрихованной области." << endl;
    }

    return 0;
}

//Задание 1.2
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    
    cout << "a = ";
    cin >> a;
    
    cout << "b = ";
    cin >> b;
    
    cout << "c = ";
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            cout << (c == 0 ? "Любое x" : "Нет решений") << endl;
        } else {
            cout << "x = " << -c / b << endl;
        }
        return 0;
    }

    double D = b * b - 4 * a * c;

    if (D > 0) {
        double sqrtD = sqrt(D);
        cout << "x1 = " << (-b + sqrtD) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrtD) / (2 * a) << endl;
    } else if (D == 0) {
        cout << "x = " << -b / (2 * a) << endl;
    } else {
        double real = -b / (2 * a);
        double imag = sqrt(-D) / (2 * a);
        cout << "x1 = " << real << " + " << imag << "i" << endl;
        cout << "x2 = " << real << " - " << imag << "i" << endl;
    }

    return 0;
}

// Задание 2.1
#include <iostream>

using namespace std;

int main() {
    int number;
    int sum = 0;

    cout << "Введите последовательность целых чисел (0 для завершения):" << endl;
    
    do {
        cin >> number;
        if (number < 0) {
            sum += number;
        }
    } while (number != 0);

    cout << "Сумма отрицательных элементов: " << sum << endl;

    return 0;
}

//Задание 2.2
#include <iostream>

using namespace std;

int main() {
    int prev, curr;
    int count = 0;
    
    cout << "Введите последовательность целых чисел (0 для окончания ввода):" << endl;
    cin >> prev; // Читаем первое число
    
    if (prev == 0) {
        cout << "В последовательности нет пар соседних чисел" << endl;
        return 0;
    }
    
    while (true) {
        cin >> curr;
        if (curr == 0) break; // 0 - признак конца последовательности
        
        if (curr == prev) {
            count++;
        }
        prev = curr;
    }
    
    cout << "Количество пар одинаковых соседних чисел: " << count << endl;
    
    return 0;
}

//Задание 3.1
#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int A[N];

    cout << "Введите 10 элементов массива:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max_index = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[max_index]) {
            max_index = i;
        }
    }

    int product = 1;
    bool elements_exist = false;
    
    for (int i = max_index + 1; i < N; i++) {
        product *= A[i];
        elements_exist = true;
    }

    if (elements_exist) {
        cout << "Произведение элементов после максимального: " << product << endl;
    } else {
        cout << "Максимальный элемент последний, элементов после него нет" << endl;
    }

    return 0;
}

//Задание 3.2
3.2

#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    double A[SIZE];

    cout << "Введите 10 элементов массива:" << endl;
    for(int i = 0; i < SIZE; i++) {
        cin >> A[i];
    }
  
    int min_index = 0;
    for(int i = 1; i < SIZE; i++) {
        if(A[i] < A[min_index]) {
            min_index = i;
        }
    }

    if(min_index == 0) {
        cout << "Минимальный элемент первый, элементов до него нет." << endl;
    } else {
        double sum = 0;
        for(int i = 0; i < min_index; i++) {
            sum += A[i];
        }
        double average = sum / min_index;
        cout << "Среднее арифметическое элементов до минимального: " << average << endl;
    }

    return 0;
}

//Задание 4.1
4.1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;

int main() {
    int A[SIZE][SIZE];
    vector<int> B(SIZE);

    
    cout << "Введите элементы матрицы 10x10:" << endl;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> A[i][j];
        }
    }

  
    for(int i = 0; i < SIZE; i++) {
        B[i] = A[i][SIZE - 1 - i];
    }

    auto min_it = min_element(B.begin(), B.end());
    auto max_it = max_element(B.begin(), B.end());

    if(min_it != B.end() && max_it != B.end()) {
        iter_swap(min_it, max_it);
    }

    cout << "Вектор B после обмена min и max элементов:" << endl;
    for(int num : B) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

//Задание 4.2
#include <iostream>
using namespace std;

const int SIZE = 10;

int main() {
    int A[SIZE][SIZE];
    
    cout << "Введите матрицу 10x10:" << endl;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> A[i][j];
        }
    }

    int max_val = A[0][0];
    int max_row = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(A[i][j] > max_val) {
                max_val = A[i][j];
                max_row = i;
            }
        }
    }

    int min_val = A[0][0];
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(A[i][j] < min_val) {
                min_val = A[i][j];
            }
        }
    }

    for(int j = 0; j < SIZE; j++) {
        A[max_row][j] = min_val;
    }

    cout << "Матрица после замены:" << endl;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//Задание 5
5.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<string> splitWords(const string& text) {
    vector<string> words;
    string word;
    istringstream iss(text);
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

void printMinLengthWords(const vector<string>& words) {
    if (words.empty()) return;
    
    int min_len = words[0].length();
    for (const auto& word : words) {
        if (word.length() < min_len) {
            min_len = word.length();
        }
    }
    
    cout << "Слова минимальной длины (" << min_len << "): ";
    for (const auto& word : words) {
        if (word.length() == min_len) {
            cout << word << " ";
        }
    }
    cout << endl;
}

vector<string> insertWordBeforeSecond(vector<string> words, const string& new_word) {
    if (words.size() >= 2) {
        words.insert(words.begin() + 1, new_word);
    } else {
        cout << "Недостаточно слов для вставки перед вторым словом" << endl;
    }
    return words;
}

void sortWordsAlphabetically(vector<string>& words) {
    sort(words.begin(), words.end());
}

void removeLetterFromWords(vector<string>& words, char letter) {
