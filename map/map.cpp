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
        cout << "����� \"" << word << "\" ��������� � �������.\n";
    }

    void removeWord(const string& word) 
    {
        auto it = words.find(word);
        if (it != words.end()) 
        {
            words.erase(it);
            cout << "����� \"" << word << "\" ������� �� �������.\n";
        }
        else 
        {
            cout << "����� \"" << word << "\" �� ������� � �������.\n";
        }
    }

    void searchWord(const string& word) 
    {
        auto it = words.find(word);
        if (it != words.end()) 
        {
            cout << "�������� ����� \"" << word << "\": " << it->second << "\n";
        }
        else {
            cout << "����� \"" << word << "\" �� ������� � �������.\n";
        }
    }

    void editWord(const string& word, const string& newDefinition) 
    {
        auto it = words.find(word);
        if (it != words.end()) 
        {
            it->second = newDefinition;
            cout << "�������� ����� \"" << word << "\" ��������.\n";
        }
        else 
        {
            cout << "����� \"" << word << "\" �� ������� � �������.\n";
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
            cout << "������� �������� � ���� \"" << filename << "\".\n";
        }
        else 
        {
            cout << "�� ������� ������� ���� \"" << filename << "\" ��� ������.\n";
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
            cout << "������� �������� �� ����� \"" << "dictionary1.txt" << "\".\n";
        }
        else 
        {
            cout << "�� ������� ������� ���� \"" << "dictionary1.txt" << "\" ��� ������.\n";
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
