#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int nums_size = nums.size();
    map<int, int> sum_map;
    vector<int> result;
    
    for(int i = 0; i < nums_size; i++) {
        int current_num = nums[i];
        int num = target - current_num;
        auto it = sum_map.find(num);
        
        if(it != sum_map.end()) {
            result.push_back(it->second);
            result.push_back(i);
            return result;
        }
        
        sum_map[nums[i]] = i;
    }
    
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);
    
    cout << "indices: [" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
