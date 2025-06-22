//Задание 1. 
//1.Даны вещественные числа x и y. Определить принадлежит ли точка с координатами (х,у) заштрихованной области по х от -1 до 3 по у от -2 до 4.
#include <iostream>
using namespace std;
int main() {
    double x, y;
    cout << "Введите координаты x и y: ";
    cin >> x >> y;
    if (x >= -1 && x <= 3 && y >= -2 && y <= 4) {
        cout << "Точка принадлежит заштрихованной области." << endl;
    } else {
        cout << "Точка не принадлежит заштрихованной области." << endl;
    }
    return 0;
}
//2. Определить пересекает ли линия y=ax+b ось абсцисс. Если пересекает, найти точку пересечения.
#include <iostream>
using namespace std;
int main() {
    double a, b;
    cout << "Введите коэффициенты a и b: ";
    cin >> a >> b;
    if (a != 0) {
        double x_intersection = -b / a;
        cout << "Линия пересекает ось абсцисс в точке: (" << x_intersection << ", 0)" << endl;
    } else {
        if (b == 0) {
            cout << "Линия совпадает с осью абсцисс." << endl;
        } else {
            cout << "Линия не пересекает ось абсцисс." << endl;
        }
    }
    return 0;
}
//Задание 2.
//1.Вывести на экран таблицу значений функции: y = 3.8 *x3 - 1/1.16 * x2 + 2 в диапазоне от a до b с шагом h. Значение a, b и h вводятся с клавиатуры. 
#include <iostream>
#include <iomanip>
using namespace std;
double calculateFunction(double x) {
    return (3.8 * x * x * x - 1) / (1.16 * x * x + 2);
}
int main() {
    double a, b, h;
    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;
    cout << "Введите значение h: ";
    cin >> h;
    cout << fixed << setprecision(2);
    cout << " x\t\t y\n";
    for (double x = a; x <= b; x += h) {
        double y = calculateFunction(x);
        cout << x << "\t " << y << "\n";
    }
    return 0;
}
//2. Вводится последовательность из N целых чисел. Определить количество одинаково рядом стоящих чисел. 
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cout << "Введите количество целых чисел (N): ";
    cin >> N;
    if (N <= 0) {
        cout << "Количество чисел должно быть больше 0." << endl;
        return 1;
    }
    vector<int> numbers(N);
    cout << "Введите " << N << " целых чисел:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    int count = 0;
    for (int i = 1; i < N; ++i) {
        if (numbers[i] == numbers[i - 1]) {
            count++;
        }
    }
    cout << "Количество одинаково рядом стоящих чисел: " << count << endl;
    return 0;
}
//Задание 3.
//1. В одномерном массиве А(10) вычислить произведение элементов расположенных
//после максимального.
#include <iostream>
using namespace std;
int main() {
    const int size = 10;
    int A[size];
    cout << "Введите 10 целых чисел:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> A[i];
    }
    int maxElementIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (A[i] > A[maxElementIndex]) {
            maxElementIndex = i;
        }
    }
    long long product = 1;
    bool hasElementsAfterMax = false; 
    for (int i = maxElementIndex + 1; i < size; ++i) {
        product *= A[i];
        hasElementsAfterMax = true;
    }
    if (hasElementsAfterMax) {
        cout << "Произведение элементов после максимального: " << product << endl;
    } else {
        cout << "Нет элементов после максимального." << std::endl;
    }
    return 0;
}
//2. В одномерном массиве А(10) вычислить сумму элементов, расположенных между
//минимальным и максимальным.
#include <iostream>
#include <limits>
using namespace std;
int main() {
    const int size = 10;
    int A[size];
    cout << "Введите 10 целых чисел:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> A[i];
    }
    int minElementIndex = 0;
    int maxElementIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (A[i] < A[minElementIndex]) {
            minElementIndex = i;
        }
        if (A[i] > A[maxElementIndex]) {
            maxElementIndex = i;
        }
    }
    int startIndex = min(minElementIndex, maxElementIndex);
    int endIndex = max(minElementIndex, maxElementIndex);
    int sum = 0;
    for (int i = startIndex + 1; i < endIndex; ++i) {
        sum += A[i];
    }
    cout << "Сумма элементов между минимальным и максимальным: " << sum <<endl;
    return 0;
}
//Задание 4.
//1. Дана матрица А(10,10). Построить вектор В из элементов побочной диагонали. В
//новом векторе поменять местами минимальный и максимальный элементы. 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    const int size = 10;
    int A[size][size];
    cout << "Введите 100 целых чисел для матрицы 10x10:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> A[i][j];
        }
    }
    vector<int> B(size);
    for (int i = 0; i < size; ++i) {
        B[i] = A[i][size - 1 - i];
    }
    auto minMaxItr = minmax_element(B.begin(), B.end());
    int minIndex = distance(B.begin(), minMaxItr.first);
    int maxIndex = distance(B.begin(), minMaxItr.second);
    swap(B[minIndex], B[maxIndex]);
    cout << "Вектор B (элементы побочной диагонали после замены):" << endl;
    for (const int& element : B) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
//2. Дано: X(М), Y(N). Вектор, имеющий наибольшее количество различных компонент преобразовать по правилу: все четные компоненты разделить на 2.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> transformVector(const vector<int>& vec) {
    vector<int> transformedVec(vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] % 2 == 0) {
            transformedVec[i] = vec[i] / 2;
        } else {
            transformedVec[i] = vec[i];
        }
    }
    return transformedVec;
}
int countDistinct(const vector<int>& vec) {
    set<int> distinctElements(vec.begin(), vec.end());
    return distinctElements.size();
}
int main() {
    int M, N;
    cout << "Введите размер вектора X: ";
    cin >> M;
    vector<int> X(M);
    cout << "Введите элементы вектора X:" << endl;
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
    }
    cout << "Введите размер вектора Y: ";
    cin >> N;
    vector<int> Y(N);
    cout << "Введите элементы вектора Y:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> Y[i];
    }
    int distinctCountX = countDistinct(X);
    int distinctCountY = countDistinct(Y);
    vector<int> resultVector;
    if (distinctCountX >= distinctCountY) {
        cout << "Вектор X имеет больше или столько же различных компонент, чем Y." << endl;
        resultVector = transformVector(X);
    } else {
        cout << "Вектор Y имеет больше различных компонент." << endl;
        resultVector = transformVector(Y);
    }
    cout << "Преобразованный вектор:" << endl;
    for (int value : resultVector) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
//Задание 5.
//Дан символьный массив, образованный из слов, разделенных пробелами. С использованием
//процедур и функций выполнить:
//1.Выдать на печать слова максимальной длины;
//2.Удалить из слов, имеющих нечетную длину среднюю букву;
//3.Проверить, есть ли в тексте симметричные слова;
//4.Перенести первую букву указанного слова в конец слова;
//Определить количество слов в тексте, оканчивающихся на заданную букву.
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
void printMaxLengthWords(const vector<string>& words) {
    size_t maxLength = 0;
    for (const auto& word : words) {
        if (word.length() > maxLength) {
            maxLength = word.length();
        }
    }
    cout << "Слова максимальной длины:" << endl;
    for (const auto& word : words) {
        if (word.length() == maxLength) {
            cout << word << endl;
        }
    }
}
void removeMiddleLetterFromOddLengthWords(vector<string>& words) {
    for (auto& word : words) {
        if (word.length() % 2 != 0) {
            size_t middleIndex = word.length() / 2;
            word.erase(middleIndex, 1);
        }
    }
}
bool isSymmetric(const string& word) {
    return equal(word.begin(), word.begin() + word.size()/2, word.rbegin());
}
void checkSymmetricWords(const vector<string>& words) {
    cout << "Симметричные слова:" << endl;
    for (const auto& word : words) {
        if (isSymmetric(word)) {
            cout << word << endl;
        }
    }
}
void moveFirstLetterToEnd(string& word) {
    if (!word.empty()) {
        word += word[0];
        word.erase(0, 1);
    }
}
void moveFirstLetterInWord(vector<string>& words, const string& targetWord) {
    for (auto& word : words) {
        if (word == targetWord) {
            moveFirstLetterToEnd(word);
            break;
        }
    }
}
int countWordsEndingWith(const vector<string>& words, char letter) {
    return count_if(words.begin(), words.end(), 
        [letter](const string& word) { 
            return !word.empty() && word.back() == letter; 
        });
}
int main() {
    string input;
    cout << "Введите текст: ";
    getline(cin, input);
    istringstream counter(input);
    const size_t wordCount = distance(istream_iterator<string>(counter), 
                                istream_iterator<string>());
    vector<string> words(wordCount);
    istringstream iss(input);
    for (size_t i = 0; i < wordCount; ++i) {
        iss >> words[i];
    }
    printMaxLengthWords(words);
    removeMiddleLetterFromOddLengthWords(words);
    checkSymmetricWords(words);
    string targetWord;
    cout << "Введите слово, первую букву которого нужно перенести в конец: ";
    cin >> targetWord;
    moveFirstLetterInWord(words, targetWord);
    char endingLetter;
    cout << "Введите букву, на которую должны заканчиваться слова: ";
    cin >> endingLetter;
    int count = countWordsEndingWith(words, endingLetter);
    cout << "Количество слов, оканчивающихся на букву '" << endingLetter << "': " << count << endl;
    cout << "Преобразованные слова:" << endl;
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}
