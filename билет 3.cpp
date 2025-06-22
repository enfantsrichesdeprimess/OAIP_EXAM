//Задание 1.
//1. Даны вещественные числа х и у. Определить, принадлежит ли точка с координатами (х,у) заштрихованной области по х от -3 до 5 и по у от -1 до 4.
#include <iostream>
using namespace std;
int main() {
    double x, y;
    cout << "Введите координату x: ";
    cin >> x;
    cout << "Введите координату y: ";
    cin >> y;
    if (x >= -3 && x <= 5 && y >= -1 && y <= 4) {
        cout << "Точка (" << x << ", " << y << ") принадлежит заштрихованной области";
    } else {
        cout << "Точка (" << x << ", " << y << ") НЕ принадлежит заштрихованной области";
    }
    return 0;
}
//2. Задан круг с центром в точке О(х0,у0), радиусом r0 и точка А(х1,у1). определить находится ли точка внутри круга.
#include <iostream>
#include <cmath> 
using namespace std;
int main() {
    double x0, y0, r0; 
    double x1, y1;
    cout << "Введите координаты центра круга (x0 y0): ";
    cin >> x0 >> y0;
    cout << "Введите радиус круга: ";
    cin >> r0;
    cout << "Введите координаты точки (x1 y1): ";
    cin >> x1 >> y1;
    double distance = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
    if (distance <= r0) {
        cout << "Точка (" << x1 << ", " << y1 << ") находится внутри круга";
    } else {
        cout << "Точка (" << x1 << ", " << y1 << ") находится вне круга";
    }
    return 0;
}
//Задание 2.
//1.-
//2. Вводится последовательность произвольных чисел, 0 — конец последовательности.
//Определить сумму отрицательных элементов последовательности.
#include <iostream>
using namespace std;
int main() {
    double number;
    double sum = 0.0;
    cout << "Вводите последовательность чисел (0 для завершения):\n";
    while (true) {
        cin >> number;
        if (number == 0) {
            break;
        }
        if (number < 0) {
            sum += number; 
        }
    }
    cout << "Сумма отрицательных элементов: " << sum << endl;
    return 0;
}
//Задание 3.
//1. В одномерном массиве А (10) выполнить преобразования таким образом, чтобы в
//начале располагались все положительные элементы, затем все отрицательные. (Элементы,
//равные нулю, считать положительными).
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b) {
    return (a >= 0) > (b >= 0);
}
int main() {
    const int SIZE = 10;
    int A[SIZE];
    cout << "Введите 10 элементов массива:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> A[i];
    }
    sort(A, A + SIZE, compare);
    cout << "Преобразованный массив:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
//2. В одномерном массиве А(10) вычислить сумму элементов массива, отличающихся от
//максимального на 1
#include <iostream>
#include <cmath> 
using namespace std;
int main() {
    const int SIZE = 10;
    int A[SIZE];
    cout << "Введите 10 элементов массива:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> A[i];
    }
    int max = A[0];
    for (int i = 1; i < SIZE; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        if (abs(A[i] - max) == 1) {
            sum += A[i];
        }
    }
    cout << "Максимальный элемент: " << max << endl;
    cout << "Сумма элементов, отличающихся от максимального на 1: " << sum << endl;
    return 0;
}
//Задание 4.
//1. Дана матрица А(5,5). Найти 10 максимальных элементов и переписать их в другой
//массив в обратном порядке.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int ROWS = 5;
const int COLS = 5;
const int RESULT_SIZE = 10;
int main() {
    int A[ROWS][COLS];
    vector<int> allElements;
    cout << "Введите элементы матрицы 5x5:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> A[i][j];
            allElements.push_back(A[i][j]);
        }
    }
    sort(allElements.begin(), allElements.end(), greater<int>());
    int result[RESULT_SIZE];
    int elementsToCopy = min(RESULT_SIZE, (int)allElements.size());
    for (int i = 0; i < elementsToCopy; ++i) {
        result[i] = allElements[elementsToCopy - 1 - i];
    }
    cout << "\n10 максимальных элементов в обратном порядке:\n";
    for (int i = 0; i < elementsToCopy; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
//2. Дано: Х(М), Y(М). Вектор, имеющий наибольшее количество одинаковых компонент
//преобразовать по правилу: все компоненты <0 возвести в квадрат.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int countMaxDuplicates(const vector<int>& vec) {
    unordered_map<int, int> freq;
    for (int num : vec) {
        freq[num]++;
    }
    int max_count = 0;
    for (const auto& pair : freq) {
        if (pair.second > max_count) {
            max_count = pair.second;
        }
    }
    return max_count;
}
void transformVector(vector<int>& vec) {
    for (int& num : vec) {
        if (num < 0) {
            num = num * num;
        }
    }
}
int main() {
    int M;
    cout << "Введите размер векторов: ";
    cin >> M;
    vector<int> X(M), Y(M);
    cout << "Введите элементы вектора X:\n";
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
    }
    cout << "Введите элементы вектора Y:\n";
    for (int i = 0; i < M; ++i) {
        cin >> Y[i];
    }
    int x_max = countMaxDuplicates(X);
    int y_max = countMaxDuplicates(Y);
    vector<int>* target = nullptr;
    if (x_max > y_max) {
        target = &X;
        cout << "Вектор X имеет больше повторений (" << x_max << ")\n";
    } else if (y_max > x_max) {
        target = &Y;
        cout << "Вектор Y имеет больше повторений (" << y_max << ")\n";
    } else {
        target = &X; // если одинаково, выбираем X
        cout << "Оба вектора имеют одинаковое количество повторений (" << x_max << ")\n";
    }
    cout << "Исходный вектор: ";
    for (int num : *target) {
        cout << num << " ";
    }
    cout << endl;
    transformVector(*target);
    cout << "Преобразованный вектор: ";
    for (int num : *target) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
//Задание 5.
//Дан символьный массив, образованный из слов, разделенных пробелами. С использованием процедур и функций выполнить:
//Выдать на печать слова минимальной длины;
//Вставить перед вторым словом новое СЛОВО;
//Упорядочить слова текста по алфавиту
//Удалить из каждого слова заданную букву;
//Указать сколько раз встречается каждое слово в тексте.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <sstream>
using namespace std;
vector<string> splitString(const string& str) {
    vector<string> words;
    istringstream iss(str);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
    return words;
}
vector<string> findMinLengthWords(const vector<string>& words) {
    if (words.empty()) return {};
    auto min_len = min_element(words.begin(), words.end(),
        [](const string& a, const string& b) { return a.length() < b.length(); })->length();
    vector<string> result;
    copy_if(words.begin(), words.end(), back_inserter(result),
        [min_len](const string& word) { return word.length() == min_len; });
    return result;
}
void insertBeforeSecondWord(vector<string>& words, const string& newWord) {
    if (words.size() >= 2) {
        words.insert(words.begin() + 1, newWord);
    } else {
        words.resize(words.size() + 1);
        words.back() = newWord;
    }
}
void sortWordsAlphabetically(vector<string>& words) {
    sort(words.begin(), words.end());
}
void removeLetterFromWords(vector<string>& words, char letter) {
    for_each(words.begin(), words.end(),
        [letter](string& word) {
            word.erase(remove(word.begin(), word.end(), letter), word.end());
        });
}
map<string, int> countWordFrequency(const vector<string>& words) {
    map<string, int> frequency;
    for_each(words.begin(), words.end(),
        [&frequency](const string& word) { frequency[word]++; });
    return frequency;
}
int main() {
    string input;
    cout << "Введите текст: ";
    getline(cin, input);
    vector<string> words = splitString(input);
    vector<string> minWords = findMinLengthWords(words);
    cout << "\n1. Слова минимальной длины: ";
    copy(minWords.begin(), minWords.end(), ostream_iterator<string>(cout, " "));
    string newWord;
    cout << "\n\n2. Введите слово для вставки: ";
    cin >> newWord;
    insertBeforeSecondWord(words, newWord);
    cout << "Текст после вставки: ";
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    sortWordsAlphabetically(words);
    cout << "\n\n3. Текст после сортировки: ";
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    char letter;
    cout << "\n\n4. Введите букву для удаления: ";
    cin >> letter;
    removeLetterFromWords(words, letter);
    cout << "Текст после удаления буквы '" << letter << "': ";
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    map<string, int> wordCount = countWordFrequency(words);
    cout << "\n\n5. Частота слов в тексте:\n";
    for_each(wordCount.begin(), wordCount.end(),
        [](const pair<string, int>& p) {
            cout << p.first << ": " << p.second << " раз(а)\n";
        });
    return 0;
}
