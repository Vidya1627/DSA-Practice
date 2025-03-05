#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> product_prefix(size, 0);
    vector<int> product_sufix(size, 0);
    vector<int> result(size, 0);

    // Compute prefix product
    product_prefix[0] = 1;
    for (int i = 1; i < size; i++) {
        product_prefix[i] = product_prefix[i - 1] * nums[i - 1];
    }

    // Compute suffix product
    product_sufix[size - 1] = 1;
    for (int i = size - 2; i >= 0; i--) {
        product_sufix[i] = product_sufix[i + 1] * nums[i + 1];
    }

    // Compute result
    for (int i = 0; i < size; i++) {
        result[i] = product_prefix[i] * product_sufix[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> output = productExceptSelf(nums);

    cout << "Output: ";
    for (int num : output) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
