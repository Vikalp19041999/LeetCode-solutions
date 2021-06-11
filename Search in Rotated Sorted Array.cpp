class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if(low > high) {
            return -1;
        }
        int middle = (low + high) / 2;
        if(nums[middle] == target) {
            return middle;
        } else if(nums[middle] > target) {
            return binarySearch(nums, low, middle-1, target);
        } else {
            return binarySearch(nums, middle+1, high, target);
        }
    }
    
    int findMiddle(vector<int>& nums, int low, int high) {
        if(high < low) {
            return -1;
        }
        if(high == low) {
            return low;
        }
        int mid = (low + high)/2;
        if(mid < high && nums[mid] > nums[mid+1]) {
            return mid;
        }
        if(mid > low && nums[mid] < nums[mid-1]) {
            return mid-1;
        }
        if(nums[low] >= nums[mid]) {
            return findMiddle(nums, low, mid-1);
        }
        return findMiddle(nums, mid+1, high);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int middle =  findMiddle(nums, low, high);
        if(middle == -1) {
            return binarySearch(nums, low, high, target);
        }
        if(nums[middle] == target) {
            return middle;
        }
        if(nums[0] <= target) {
            return binarySearch(nums, 0, middle, target);
        }
        return binarySearch(nums, middle+1, high, target);
    }
};