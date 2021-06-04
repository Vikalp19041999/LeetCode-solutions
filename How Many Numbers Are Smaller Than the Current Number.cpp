class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
		int max, c;
		for(int i = 0; i < nums.size(); i++){
			max = nums[i];
			c = 0;
			for(int j = 0; j < nums.size(); j++){
				if(nums[j] < max and j != i){
					c++;
				}                   
			}
			res.push_back(c);
		}
		return res;
    }
};