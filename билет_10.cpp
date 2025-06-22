//Задание 1.1
#include <iostream>
using namespace std;

int main() {
    double x, y;
    cout << "Введите координату x: ";
    cin >> x;
    cout << "Введите координату y: ";
    cin >> y;

    bool is_in_rectangle = (x >= -3.0) && (x <= 5.0) && (y >= -1.0) && (y <= 4.0);

    if (is_in_rectangle) {
        cout << "Точка (" << x << ", " << y << ") принадлежит прямоугольной области" << endl;
    } else {
        cout << "Точка (" << x << ", " << y << ") НЕ принадлежит прямоугольной области" << endl;
    }

    return 0;
}

//Задание 1.2
#include <iostream>
#include <cmath>
using namespace std;

double calculate_f(double x) {
    if (x < -2.0) {
        return 0.5 * x + 3.0;  
    }
    else if (x >= -2.0 && x <= 2.0) {
        return -x * x + 4.0;
    }
    else {
        return x - 2.0;
    }
}

int main() {
    double a;
    cout << "Введите вещественное число a: ";
    cin >> a;
    
    double result = calculate_f(a);
    cout << "f(" << a << ") = " << result << endl;
    
    return 0;
}

//Задание 2.1
2.1
#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    cout << "X\tY" << endl; 
    
    for (int x = 5; x <= 10; x++) {
        double y = 0.7 * pow(x, 4) - 4.5 * (pow(x, 2) / exp(1));
        cout << x << "\t" << y << endl; 
    }

    return 0;
}

//Задание 2.2
2.2

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;

    long long product = 1;  
    
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) {   
            product *= i;  
        }
    }

    cout << "Произведение натуральных чисел, кратных 3 и не превышающих " 
         << N << ": " << product << endl;

    return 0;
}

//Задание 3.1
3.1
#include <iostream>
using namespace std;

int main() {
    int A[10], max_i = 0, sum = 0;

    for (int i = 0; i < 10; i++) {
        cin >> A[i];
        if (A[i] > A[max_i]) max_i = i;
    }

    for (int i = max_i + 1; i < 10; i++) 
        sum += A[i];

    cout << sum;
    return 0;
}

//Задание 3.2
#include <iostream>
using namespace std;

int main() {
    int a[10], min_i = 0, s = 0;

    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        if (a[i] < a[min_i]) min_i = i;
    }

    for (int i = 0; i < min_i; i++)
        s += a[i];

    cout << (min_i ? (double)s/min_i : 0);
}

//Задание 4.1
4.1
#include <iostream>
using namespace std;

int main() {
    int a[4][4], v[4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];

    for (int i = 0; i < 4; i++) {
        if (a[i][0] > 0) {  
            for (int j = 0; j < 2; j++) {  
                int t = a[i][j];
                a[i][j] = a[i][3-j];
                a[i][3-j] = t;
            }
        }
        v[i] = a[i][3]; 
    }

    for (int i = 0; i < 4; i++)
        cout << v[i] << " ";

    return 0;
}

//Задание 4.2
4.2
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m;
    int* x = new int[m];
    for(int i = 0; i < m; i++) cin >> x[i];

    cin >> n;
    int* y = new int[n];
    for(int i = 0; i < n; i++) cin >> y[i];

    int uniq_x = 0, uniq_y = 0;
    for(int i = 0; i < m; i++) {
        bool is_uniq = true;
        for(int j = 0; j < i; j++) {
            if(x[i] == x[j]) { is_uniq = false; break; }
        }
        if(is_uniq) uniq_x++;
    }

    for(int i = 0; i < n; i++) {
        bool is_uniq = true;
        for(int j = 0; j < i; j++) {
            if(y[i] == y[j]) { is_uniq = false; break; }
        }
        if(is_uniq) uniq_y++;
    }

    int* vec = (uniq_x > uniq_y) ? x : y;
    int size = (uniq_x > uniq_y) ? m : n;

    for(int i = 0; i < size; i++) {
        if(vec[i] % 2 == 0) vec[i] /= 2;
    }

    for(int i = 0; i < size; i++) cout << vec[i] << " ";

    delete[] x;
    delete[] y;
    return 0;
}

//Задание 5
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> split(const string& s) {
    vector<string> words;
    string word;
    for(char c : s) {
        if(c == ' ') {
            if(!word.empty()) words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    if(!word.empty()) words.push_back(word);
    return words;
}

bool areEqual(const vector<string>& words, int i, int j) {
    return i < words.size() && j < words.size() && words[i] == words[j];
}

void processOddLengthWords(vector<string>& words) {
    for(string& word : words) {
        if(word.length() % 2 != 0 && !word.empty()) {
            word.pop_back();
        }
    }
}

bool isSymmetric(const string& word) {
    int n = word.length();
    for(int i = 0; i < n/2; i++) {
        if(word[i] != word[n-1-i]) return false;
    }
    return true;
}

void removeLongestWords(vector<string>& words) {
    if(words.empty()) return;
    
    int max_len = 0;
    for(const string& word : words) {
        if(word.length() > max_len) max_len = word.length();
    }
    
    words.erase(remove_if(words.begin(), words.end(), 
        [max_len](const string& w) { return w.length() == max_len; }), 
        words.end());
}

int countSameStartEnd(const vector<string>& words) {
    int count = 0;
    for(const string& word : words) {
        if(!word.empty() && word[0] == word.back()) count++;
    }
    return count;
}

int main() {
    string text;
    cout << "Введите текст: ";
    getline(cin, text);
    
    vector<string> words = split(text);

    int i, j;
    cout << "Введите номера двух слов для сравнения (начиная с 1): ";
    cin >> i >> j;
    cout << "Слова " << (areEqual(words, i-1, j-1) ? "" : "не ") << "равны\n";

    processOddLengthWords(words);
    cout << "Текст после обработки: ";
    for(const string& word : words) cout << word << " ";
    cout << endl;

    int k;
    cout << "Введите номер слова для проверки на симметричность: ";
    cin >> k;
    if(k-1 < words.size()) {
        cout << "Слово " << (isSymmetric(words[k-1]) ? "" : "не ") << "симметрично\n";
    }

    removeLongestWords(words);
    cout << "Текст после удаления длинных слов: ";
    for(const string& word : words) cout << word << " ";
    cout << endl;

    cout << "Количество слов с одинаковыми первой и последней буквой: " 
         << countSameStartEnd(words) << endl;
    
    return 0;
}
