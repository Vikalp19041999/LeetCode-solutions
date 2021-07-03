class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int n=nums.size();
        for(i=n-1; i>0; i--){
            if(nums[i] > nums[i-1]) {
                break;
            }
        }
        int j=i-1;
        int index=j;
        for(int i=n-1; j!=-1 && i>j; i--){
            if(nums[i] > nums[j]){
                index = i;
                break;
            }
        }
        if(j!=-1)
        swap(nums[j], nums[index]);
        reverse(nums.begin()+j+1, nums.end());
    }
};