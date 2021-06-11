class Solution {
public:
    int helperfunc(vector<int>& nums, int target, int left, int right) {
    if(left > right) {
        return -1;
    }
    int middle = (left + right) / 2;
    if(nums[middle] == target) {
        return middle;
    } else if(nums[middle] > target) {
        return helperfunc(nums, target, left, middle-1);
    } else {
        return helperfunc(nums, target, middle+1, right);
    }
}
    
    int search(vector<int>& nums, int target) {
        return helperfunc(nums, target, 0, nums.size()-1);
    }
};