#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
    int size = nums.size();
    int min_product = nums[0];
    int max_product = nums[0];
    int result = nums[0];

    for(int i = 1; i < size; i++) {
        if(nums[i] < 0) {
            swap(min_product, max_product);
        }

        max_product = max(nums[i], max_product * nums[i]);
        min_product = min(nums[i], min_product * nums[i]);
        result = max(max_product, result);
    }

    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << maxProduct(nums) << endl; // Output: 6

    nums = {-2, 0, -1};
    cout << "Maximum Product Subarray: " << maxProduct(nums) << endl; // Output: 0

    nums = {1, -2, -3, 4};
    cout << "Maximum Product Subarray: " << maxProduct(nums) << endl; // Output: 12

    return 0;
}
