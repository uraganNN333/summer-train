#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
            }
        }
        return {};
    }
};

int main() {
    // Пример входных данных
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Индексы: " << result[0] << " и " << result[1] << endl;
    }
    else {
        cout << "Пара не найдена." << endl;
    }

    return 0;
}
