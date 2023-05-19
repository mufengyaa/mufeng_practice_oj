#define _CRT_SECURE_NO_WARNINGS

#include<vector>
#include <algorithm> 
#include<iostream>
using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return {};
        }
        vector<vector<int> > arr;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return arr;
            }
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < n && left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    arr.push_back({ nums[i], nums[left++], nums[right--] });
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return arr;
    }
};