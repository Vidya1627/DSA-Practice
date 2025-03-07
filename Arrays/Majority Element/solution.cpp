#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums) {
    int size = nums.size();
    map<int, int> frequency_map;
    for (int i = 0; i < size; i++) {
        frequency_map[nums[i]]++;
        if (frequency_map[nums[i]] > (size / 2)) {
            return nums[i];
        }
    }
    return 0;
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3}; // Example input
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
