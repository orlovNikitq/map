#include <iostream>
#include<map>
#include<fstream>
#include<string>
using namespace std;
char menu() {
    cout << "Меню:\n";
    cout << "1. Поиск слова\n";
    cout << "2. Добавить слово\n";
    cout << "3. Удалить слово\n";
    cout << "4. Редактировать слово\n";
    cout << "5. Сохранить в файл\n";
    cout << "6. Считать из файла\n";
    cout << "7. Выйти\n";
    cout << "Выберите действие: ";
    char choice;
    cin >> choice;
    return choice;
}
int main() {
    setlocale(LC_ALL, "rus");
    string filename = "dictionary.txt";
    ifstream in(filename);
    ofstream out(filename);
    int count = 0;
    map<int, string> dictionary;
    map<int, string>buf;
    char choice;

    while (true) {      
        choice = menu();
        if (choice == '1') {
            string word;
            cout << "Введите слово для поиска: ";
            cin >> word;
            bool found = false;
            for (auto& el : dictionary) {
                if (el.second == word) {
                    cout << "Слово найдено: " << el.first << ". " << el.second << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Слово не найдено." << endl;
            }
        }
        else if (choice == '2') {
            string word;
            cout << "Введите слово для добавления: ";
            cin >> word;
            dictionary[++count] = word;
        }
        else if (choice == '3') {
           
            int key;
            cout << "Введите номер слова для удаления: ";
            cin >> key;
            auto it = buf.find(key);
            if (it != buf.end()) {
                buf.erase(it);
                count--; 
            }
            dictionary = buf;
           
        }
        
        else if (choice == '4') {
            string  newWord;
            int key;
            cout << "Введите номер слова для редактирования: ";
            cin >> key;
            cout << "Введите новое слово: ";
            cin >> newWord;
            auto it = buf.find(key);
            if (it != buf.end()) {
                it->second = newWord; 
              
            }
            dictionary = buf;
           
        }
        else if (choice == '5') {
            out.close();
            out.open(filename);
            for (auto& el : dictionary) {
                out << el.first << ". " << el.second << endl;
            }
            buf = dictionary;
            
            dictionary.clear();
            
        }
        else if (choice == '6') {
            string str;
            while (getline(in, str)) {
                cout << str << endl;
            }
        }
        else if (choice == '7') {
            break;
        }
        else {
            cout << "Попробуйте ещё раз." << endl;
        }
    }
}


