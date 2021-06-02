class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max;
        vector<bool> c;
        max = candies[0];
        for(int i=0; i<candies.size(); i++) {
            if(candies[i] > max) {
                max = candies[i];
            }
        }
        for(int i=0; i<candies.size(); i++) {
            if(candies[i] + extraCandies >= max) {
                c.emplace_back(true);
            } else {
                c.emplace_back(false);
            }
        }
        return c;
    }
};