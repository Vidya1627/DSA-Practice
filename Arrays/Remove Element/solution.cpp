#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int nums_size = nums.size();
    int i = 0;
    int j = nums_size - 1;
    
    while (i < nums_size && j > -1 && i <= j) {
        while (j > 0 && nums[j] == val) {
            j--;
        }
        if (i <= j && nums[i] == val) {
            swap(nums[i], nums[j]);
            j--;
        }
        while (i < nums_size && nums[i] != val) {
            i++;
        }
    }
    
    return i; 
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int newLength = removeElement(nums, val);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
