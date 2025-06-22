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
