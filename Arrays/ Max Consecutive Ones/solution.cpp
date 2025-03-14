#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int length = 0;
    int count = 0;
    for(int num: nums) {
        if(num == 1) {
            length++;
        } else {
            length = 0;
        }
        count = max(count, length);
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = findMaxConsecutiveOnes(nums);
    cout << "Max consecutive ones: " << result << endl;
    return 0;
}
