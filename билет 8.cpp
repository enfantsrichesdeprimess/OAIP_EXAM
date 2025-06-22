//Задание №1.1 (1 балл)
//Определить принадлежность точки области


#include <iostream>
using namespace std;

int main() {
    float x, y;
    cin >> x >> y;
    
    if(x >= -1 && x <= 3 && y >= -2 && y <= 4) {
        cout << "Точка принадлежит области";
    } else {
        cout << "Точка не принадлежит области";
    }
    
    return 0;
}
//Задание №1.2 (1 балл)
//Определить принадлежность точки области


#include <iostream>
using namespace std;

int main() {
    float x, y;
    cin >> x >> y;
    
    if((x >= -2 && x <= 2 && y >= -3 && y <= 3) || (y >= x-1 && y <= -x+1)) {
        cout << "Точка принадлежит области";
    } else {
        cout << "Точка не принадлежит области";
    }
    
    return 0;
}
//Задание №2.1 (2 балла)
//Найти наибольшее число в последовательности


#include <iostream>
using namespace std;

int main() {
    int num, max = 0;
    
    do {
        cin >> num;
        if(num != 0 && num > max) {
            max = num;
        }
    } while(num != 0);
    
    cout << "Наибольшее число: " << max;
    
    return 0;
}
//Задание №2.2 (2 балла)
//Найти отношение min к max


#include <iostream>
using namespace std;

int main() {
    int num, min = 0, max = 0;
    bool first = true;
    
    do {
        cin >> num;
        if(num != 0) {
            if(first) {
                min = num;
                max = num;
                first = false;
            } else {
                if(num < min) min = num;
                if(num > max) max = num;
            }
        }
    } while(num != 0);
    
    cout << "Отношение min/max: " << (float)min/max;
    
    return 0;
}
//Задание №3.1 (3 балла)
//Сортировка положительных и отрицательных


#include <iostream>
using namespace std;

int main() {
    int A[10] = {3, -2, 0, 5, -1, 4, -3, 2, -4, 1};
    int B[10];
    int k = 0;
    
    for(int i = 0; i < 10; i++) {
        if(A[i] >= 0) {
            B[k++] = A[i];
        }
    }
    for(int i = 0; i < 10; i++) {
        if(A[i] < 0) {
            B[k++] = A[i];
        }
    }
    
    for(int i = 0; i < 10; i++) {
        cout << B[i] << " ";
    }
    
    return 0;
}
//Задание №3.2 (3 балла)
//Сумма между min и max


#include <iostream>
using namespace std;

int main() {
    int A[10] = {3, 7, 2, 8, 5, 1, 9, 4, 6, 0};
    int min = 0, max = 0;
    
    for(int i = 1; i < 10; i++) {
        if(A[i] < A[min]) min = i;
        if(A[i] > A[max]) max = i;
    }
    
    int start = min < max ? min : max;
    int end = min > max ? min : max;
    int sum = 0;
    
    for(int i = start+1; i < end; i++) {
        sum += A[i];
    }
    
    cout << "Сумма между min и max: " << sum;
    
    return 0;
}
//Задание №4.1 (4 балла)
//10 максимальных элементов матрицы


#include <iostream>
using namespace std;

int main() {
    int A[5][5] = {
        {3, 7, 2, 8, 5},
        {1, 9, 4, 6, 0},
        {11,15,12,16,13},
        {17,21,18,22,19},
        {23,27,24,28,25}
    };
    int B[10];
    int k = 0;
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            B[k++] = A[i][j];
        }
    }
    
    for(int i = 0; i < 25; i++) {
        for(int j = i+1; j < 25; j++) {
            if(B[i] < B[j]) {
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }
    
    cout << "10 максимальных: ";
    for(int i = 0; i < 10; i++) {
        cout << B[i] << " ";
    }
    
    return 0;
}
//Задание №4.2 (4 балла)
//Проверка симметричности матрицы


#include <iostream>
using namespace std;

int main() {
    int A[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {2, 1, 0, 0, 0, 0},
        {3, 0, 1, 0, 0, 0},
        {4, 0, 0, 1, 0, 0},
        {5, 0, 0, 0, 1, 0},
        {6, 0, 0, 0, 0, 1}
    };
    bool sim = true;
    
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < i; j++) {
            if(A[i][j] != A[j][i]) {
                sim = false;
            }
        }
    }
    
    if(sim) {
        for(int i = 0; i < 6; i++) {
            A[i][i] = 0;
        }
        cout << "Матрица симметрична. Диагональ обнулена.";
    } else {
        cout << "Матрица не симметрична.";
    }
    
    return 0;
}
//Задание №5 (5 баллов)
//Обработка текста


#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "level radar hello world program exam";
    string words[10];
    int cnt = 0;
    string word = "";
    
    for(char c : text) {
        if(c == ' ') {
            words[cnt++] = word;
            word = "";
        } else {
            word += c;
        }
    }
    words[cnt++] = word;
    
    // 1. Слова минимальной длины
    int min_len = words[0].length();
    for(int i = 1; i < cnt; i++) {
        if(words[i].length() < min_len) {
            min_len = words[i].length();
        }
    }
    cout << "1. Самые короткие слова: ";
    for(int i = 0; i < cnt; i++) {
        if(words[i].length() == min_len) {
            cout << words[i] << " ";
        }
    }
    cout << endl;
    
    // 2. Удалить первую букву в четных словах
    for(int i = 0; i < cnt; i++) {
        if(words[i].length() % 2 == 0) {
            words[i].erase(0, 1);
        }
    }
    cout << "2. После удаления: ";
    for(int i = 0; i < cnt; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    // 3. Поиск симметричных слов
    cout << "3. Симметричные слова: ";
    for(int i = 0; i < cnt; i++) {
        bool sim = true;
        string w = words[i];
        for(int j = 0; j < w.length()/2; j++) {
            if(w[j] != w[w.length()-1-j]) {
                sim = false;
                break;
            }
        }
        if(sim) {
            cout << w << " ";
        }
    }
    cout << endl;
    
    // 4. Удалить самые короткие слова
    int new_cnt = 0;
    for(int i = 0; i < cnt; i++) {
        if(words[i].length() != min_len) {
            words[new_cnt++] = words[i];
        }
    }
    cout << "4. После удаления коротких: ";
    for(int i = 0; i < new_cnt; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    // 5. Слова на заданную букву
    char letter = 'p';
    int kol = 0;
    for(int i = 0; i < new_cnt; i++) {
        if(!words[i].empty() && words[i][0] == letter) {
            kol++;
        }
    }
    cout << "5. Слов на букву '" << letter << "': " << kol;
    
    return 0;
}
