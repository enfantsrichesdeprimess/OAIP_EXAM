//Задание №1 (1 часть)

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a;
    cout << "Введите число a: ";
    cin >> a;
    
    double y;
    if(a < 0) {
        y = a*a + 1;
    } else if(a >= 0 && a <= 1) {
        y = 2*a;
    } else {
        y = sqrt(a);
    }
    
    cout << "f(a) = " << y << endl;
    
    return 0;
}
//Задание №1 (2 часть)

#include <iostream>

using namespace std;

int main() {
    double a, b, k, m;
    cout << "Введите a, b для первой прямой: ";
    cin >> a >> b;
    cout << "Введите k, m для второй прямой: ";
    cin >> k >> m;
    
    if(a == k) {
        if(b == m) {
            cout << "Прямые совпадают" << endl;
        } else {
            cout << "Прямые параллельны" << endl;
        }
    } else {
        double x = (m - b)/(a - k);
        double y = a*x + b;
        cout << "Точка пересечения: (" << x << ", " << y << ")" << endl;
    }
    
    return 0;
}
//Задание №2 (1 часть)

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, h;
    cout << "Введите a, b, h: ";
    cin >> a >> b >> h;
    
    cout << "x\t\ty" << endl;
    for(double x = a; x <= b; x += h) {
        double y = (3.8*pow(x,3) - 1)/(1.16*pow(x,2) + 2);
        cout << fixed << setprecision(2) << x << "\t\t" << y << endl;
    }
    
    return 0;
}
//Задание №2 (2 часть)

#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Введите N: ";
    cin >> N;
    
    int product = 1;
    for(int i = 3; i <= N; i += 3) {
        product *= i;
    }
    
    cout << "Произведение: " << product << endl;
    
    return 0;
}
//Задание №3 (1 часть)

#include <iostream>

using namespace std;

int main() {
    int A[10] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    
    int max_idx = 0;
    for(int i = 1; i < 10; i++) {
        if(A[i] > A[max_idx]) {
            max_idx = i;
        }
    }
    
    int sum = 0;
    for(int i = max_idx + 1; i < 10; i++) {
        sum += A[i];
    }
    
    cout << "Сумма после максимального: " << sum << endl;
    
    return 0;
}
Задание №3 (2 часть)
cpp
#include <iostream>

using namespace std;

int main() {
    int A[10] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    
    int max_val = A[0];
    for(int i = 1; i < 10; i++) {
        if(A[i] > max_val) {
            max_val = A[i];
        }
    }
    
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        if(abs(A[i] - max_val) == 1) {
            sum += A[i];
        }
    }
    
    cout << "Сумма отличающихся на 1: " << sum << endl;
    
    return 0;
}
//Задание №4 (1 часть)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int n = 4;
    int A[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = rand() % 20 - 10;
        }
    }
    
    cout << "Исходная матрица:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < n; i++) {
        if(A[i][0] > 0) {
            reverse(A[i], A[i] + n);
        }
    }
    
    cout << "\nПреобразованная матрица:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<int> B;
    for(int i = 0; i < n; i++) {
        B.push_back(A[i][n-1]);
    }
    
    cout << "\nВектор B: ";
    for(int num : B) {
        cout << num << " ";
    }
    
    return 0;
}
//Задание №4 (2 часть)

#include <iostream>
#include <climits>

using namespace std;

int main() {
    const int n = 10;
    int A[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
        }
    }
    
    int max_val = INT_MIN;
    int max_row = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] > max_val) {
                max_val = A[i][j];
                max_row = i;
            }
        }
    }
    
    int min_val = INT_MAX;
    for(int j = 0; j < n; j++) {
        if(A[max_row][j] < min_val) {
            min_val = A[max_row][j];
        }
    }
    
    for(int j = 0; j < n; j++) {
        A[max_row][j] *= min_val;
    }
    
    cout << "Результат:" << endl;
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
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> splitWords(const string& text) {
    vector<string> words;
    string word;
    for(char c : text) {
        if(c == ' ') {
            if(!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if(!word.empty()) words.push_back(word);
    return words;
}

void printLongestWords(const vector<string>& words) {
    int max_len = 0;
    for(const auto& word : words) {
        if(word.length() > max_len) {
            max_len = word.length();
        }
    }
    
    cout << "Самые длинные слова: ";
    for(const auto& word : words) {
        if(word.length() == max_len) {
            cout << word << " ";
        }
    }
    cout << endl;
}

void removeMiddleLetter(vector<string>& words) {
    for(auto& word : words) {
        if(word.length() % 2 == 1) {
            int mid = word.length() / 2;
            word.erase(mid, 1);
        }
    }
}

bool isPalindrome(const string& word) {
    int n = word.length();
    for(int i = 0; i < n/2; i++) {
        if(word[i] != word[n-i-1]) {
            return false;
        }
    }
    return true;
}

void checkPalindromes(const vector<string>& words) {
    cout << "Симметричные слова: ";
    for(const auto& word : words) {
        if(isPalindrome(word)) {
            cout << word << " ";
        }
    }
    cout << endl;
}

void moveFirstToEnd(vector<string>& words, int index) {
    if(index >= 0 && index < words.size()) {
        string& word = words[index];
        if(!word.empty()) {
            char first = word[0];
            word.erase(0, 1);
            word += first;
        }
    }
}

int countWordsEndingWith(const vector<string>& words, char letter) {
    int count = 0;
    for(const auto& word : words) {
        if(!word.empty() && word.back() == letter) {
            count++;
        }
    }
    return count;
}

int main() {
    string text = "level radar hello world programming abba test";
    vector<string> words = splitWords(text);
    
    printLongestWords(words);
    
    removeMiddleLetter(words);
    cout << "После удаления средней буквы: ";
    for(const auto& word : words) cout << word << " ";
    cout << endl;
    
    checkPalindromes(words);
    
    cout << "Введите номер слова для переноса буквы (1-" << words.size() << "): ";
    int index;
    cin >> index;
    moveFirstToEnd(words, index-1);
    cout << "После переноса буквы: ";
    for(const auto& word : words) cout << word << " ";
    cout << endl;
    
    cout << "Введите букву для поиска: ";
    char letter;
    cin >> letter;
    int count = countWordsEndingWith(words, letter);
    cout << "Количество слов, оканчивающихся на '" << letter << "': " << count << endl;
    
    return 0;
}
