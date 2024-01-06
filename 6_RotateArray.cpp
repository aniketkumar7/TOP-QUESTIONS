// Problem:
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        // Calculate the effective rotation amount
        k = k % n;
        if (k < 0)
        {
            k += n; // Adjust negative rotation amount
        }
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution sol;
    sol.rotate(nums, k);
    cout << "Rotated array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    return 0;
}

// # **Approach**

// 1. Calculate the effective rotation amount by taking the remainder of k divided by the size of the array.
// 2. If the effective rotation amount is negative, adjust it to a positive value by adding the size of the array.
// 3. Reverse the entire array, effectively reversing the order of all elements.
// 4. Reverse the first k elements, effectively moving the last k elements to the front.
// 5. Reverse the remaining elements, effectively moving the first n-k elements to the end.
