#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class Dictionary 
{
map<string, string> words; 

public:
    void addWord(const string& word, const string& definition) 
    {
        words[word] = definition;
        cout << "Слово \"" << word << "\" добавлено в словарь.\n";
    }

    void removeWord(const string& word) 
    {
        auto it = words.find(word);
        if (it != words.end()) 
        {
            words.erase(it);
            cout << "Слово \"" << word << "\" удалено из словаря.\n";
        }
        else 
        {
            cout << "Слово \"" << word << "\" не найдено в словаре.\n";
        }
    }

    void searchWord(const string& word) 
    {
        auto it = words.find(word);
        if (it != words.end()) 
        {
            cout << "Значение слова \"" << word << "\": " << it->second << "\n";
        }
        else {
            cout << "Слово \"" << word << "\" не найдено в словаре.\n";
        }
    }

    void editWord(const string& word, const string& newDefinition) 
    {
        auto it = words.find(word);
        if (it != words.end()) 
        {
            it->second = newDefinition;
            cout << "Значение слова \"" << word << "\" изменено.\n";
        }
        else 
        {
            cout << "Слово \"" << word << "\" не найдено в словаре.\n";
        }
    }

    void saveToFile(const string& filename) 
    {
        ofstream file("dictionary1.txt");
        if (file.is_open()) 
        {
            for (const auto& pair : words) 
            {
                file << pair.first << ":" << pair.second << "\n";
            }
            cout << "Словарь сохранен в файл \"" << filename << "\".\n";
        }
        else 
        {
            cout << "Не удалось открыть файл \"" << filename << "\" для записи.\n";
        }
    }

    void loadFromFile(const string& filename) 
    {
        ifstream file("dictionary1.txt");
        if (file.is_open()) 
        {
            words.clear(); 
            string line;
            while (getline(file, line)) 
            {
                size_t pos = line.find(':');
                if (pos != string::npos) 
                {
                    string word = line.substr(0, pos);
                    string definition = line.substr(pos + 1);
                    words[word] = definition;
                }
            }
            cout << "Словарь загружен из файла \"" << "dictionary1.txt" << "\".\n";
        }
        else 
        {
            cout << "Не удалось открыть файл \"" << "dictionary1.txt" << "\" для чтения.\n";
        }
    }
};

int main() 
{

    system("chcp 1251");

    Dictionary dictionary;

    dictionary.addWord("apple", "a fruit");
    dictionary.addWord("book", "a collection of pages");
    dictionary.addWord("computer", "an electronic device");
    dictionary.searchWord("apple");
    dictionary.editWord("apple", "a round fruit");
    dictionary.searchWord("apple");
    dictionary.removeWord("book");
    dictionary.searchWord("book");

    dictionary.saveToFile("dictionary.txt");
    dictionary.loadFromFile("dictionary.txt");

    return 0;
}
