Ось невеликий приклад обробки даних на C++, включаючи роботу з текстовими файлами, масивами та строками.

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Функція для розділення строки на слова
vector<string> split(const string &text, char sep) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

// Функція для виводу вектора
void print_vector(const vector<string> &v) {
    for (const string &str : v) {
        cout << str << endl;
    }
}

int main() {
    // Відкриття файлу для читання
    ifstream file("data.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    // Зчитування даних з файлу
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    // Закривання файлу
    file.close();

    // Обробка даних
    vector<string> words;
    for (const string &line : lines) {
        vector<string> line_words = split(line, ' ');
        words.insert(words.end(), line_words.begin(), line_words.end());
    }

    // Сортування слів
    sort(words.begin(), words.end());

    // Виведення результатів
    print_vector(words);

    return 0;
}
```

Цей код використовує стандартні бібліотеки C++ для читання текстового файлу, розбиває кожен рядок на слова, зберігає всі слова в векторі, сортує слова в алфавітному порядку та виводить на екран.