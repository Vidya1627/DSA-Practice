#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    int size = nums.size();
    map<int, int> frequency_map;

    for (auto ele : nums) {
        frequency_map[ele]++;
    }

    for (auto ele : frequency_map) {
        if (ele.second > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 1};

    if (containsDuplicate(nums)) {
        cout << "Contains duplicate" << endl;
    } else {
        cout << "No duplicates" << endl;
    }

    return 0;
}
