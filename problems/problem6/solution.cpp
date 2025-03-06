#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int current_sum = nums[0];
    int max_sum = nums[0];

    for (int i = 1; i < size; i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl; // Output: 6

    nums = {5, 4, -1, 7, 8};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl; // Output: 23

    nums = {-1, -2, -3, -4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl; // Output: -1

    return 0;
}
