#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);  // Позволяет вводить строку с пробелами

    Solution sol;
    int result = sol.lengthOfLongestSubstring(input);

    cout << "Длина самой длинной подстроки без повторяющихся символов: " << result << endl;

    return 0;
}