# Dutch National Flag Algorithm (Sort an array of 0s, 1s and 2s)
### [Problem Link](https://leetcode.com/problems/sort-colors/)

## Approach (Iterative) : 
* there are 3 pointers, low, mid and high
* low and mid are initialized to 0 and high to n-1
* mid is used to traverse the array
* if arr[mid] == 0, swap(arr[low], arr[mid]) and increment low and mid
* if arr[mid] == 1, increment mid
* if arr[mid] == 2, swap(arr[mid], arr[high]) and decrement high

## Intuition :
* all the elements before low are 0
* all the elements after high are 2
* all the elements between low and mid are 1
* inshort 
    * 0 to low-1 are 0's
    * low to mid-1 are 1's
    * high+1 to n-1 are 2's
    * mid to high are unsorted elements


## Code : 
```cpp
// 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low,mid,high;
        low = mid = 0;
        high = nums.size()-1;
        
        while(mid <= high){
            if(0==nums[mid]){
                swap(nums[low],nums[mid]);
                mid ++;
                low ++;
            }else if(1 == nums[mid]){
                mid ++;
            }else{
                swap(nums[mid],nums[high]);
                high --;
            }
        }
    }
};
```

#### Time Complexity : O(n) // n is the size of the array
#### Space Complexity : O(1)

---

# Related Problems

<h3>
<details>
<summary>LeetCode</summary>

> ### 1. Problem: 75. Sort Colors ( [Try It](https://leetcode.com/problems/sort-colors/) )

</details>
</h3>


<h3>
<details>
<summary>GFG</summary>

> ### 1. Sort an array of 0s, 1s and 2s ( [Try It](https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1) )

</details>
</h3>