#  Maximum Sub array (using Kadane's Algorithm)
### [Problem Link](https://leetcode.com/problems/maximum-subarray/)

## Approach (Iterative) : 
* one thing to note is that if all the elements are negative then the maximum sum will be the maximum element in the array.
* we will keep track of the maximum sum till now and the current sum.
* if the current sum is negative then we will make it 0.
* if the current sum is greater than the maximum sum till now then we will update the maximum sum.


## Code : 
```cpp
// nums : given array
// maxi : maximum sum till now
// sum : current sum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > maxi) maxi = sum;
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
```

#### Time Complexity : O(n) // n is the size of the array
#### Space Complexity : O(1)

---

## How to print the subarray with maximum sum?
* we will keep track of the starting and ending index of the subarray with maximum sum.
* we will update the starting and ending index whenever we update the maximum sum.
* we will print the subarray from the starting index to the ending index.

```cpp
// nums : given array
// maxi : maximum sum till now
// sum : current sum
// ansStart : starting index of the subarray with maximum sum
// ansEnd : ending index of the subarray with maximum sum

class Solution {
public:
    void printSubarray(vector<int>& nums,int start,int end){
        while(start<=end){
            cout<<nums[start]<<" ";
            start++;
        }
        cout<<endl;
    }
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int ansStart = -1,ansEnd = -1,start = -1;
        for(int i=0;i<nums.size();i++){
            if(0 == sum) start = i;
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;  
                ansStart = start;
                ansEnd = i;
            } 
            if(sum < 0) sum = 0;
        }
        printSubarray(nums,ansStart,ansEnd);
        return maxi;
    }
};
```

---

# Related Problems

<h3>
<details>
<summary>LeetCode</summary>

> ### 1. Problem: 53. Maximum Subarray ( [Try It](https://leetcode.com/problems/maximum-subarray/) )

</details>
</h3>

<!-- 
<h3>
<details>
<summary>GFG</summary>

> ### 1. Name ( [Try It]() )

</details>
</h3> -->