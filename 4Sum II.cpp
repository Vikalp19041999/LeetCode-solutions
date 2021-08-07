class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        int count = 0;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                hash[nums1[i] + nums2[j]]++;
            }
        }
        for(int i=0; i<nums3.size(); i++) {
            for(int j=0; j<nums4.size(); j++) {
                count = count + hash[-(nums3[i] + nums4[j])];
            }
        }
        return count;
    }
};