class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int sum = 0;
        int array = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i]==0?-1:1;
            if(sum==0) {
                if(array < i+1) {
                    array = i+1;
                }
            } else if(mymap.find(sum)!=mymap.end()) {
                if(array < i-mymap[sum]) {
                    array = i-mymap[sum];
                }
            } else {
                mymap[sum] = i;
            }
        }
        return array;
    }
};