#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    string word;
    ifstream text2("Tolstoy.txt");
    ofstream text("59495692.txt");
    vector<string> words;

    if (text2.is_open())
    {
        while (text2 >> word)
        {
            words.push_back(word);
            text << word << "\n";
        }
    }

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
        });

    for (int i = 0; i < 5 && i < words.size(); i++)
    {
        cout << words[i] << " ";
    }
}
