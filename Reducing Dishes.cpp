class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater <int> ());
        int ans = 0;
        int total = 0;
        for (int i=0; i<satisfaction.size(); i++) {
            if (total + ans + satisfaction[i] > total) {
                ans = ans + satisfaction[i];
                total = total + ans;
            } 
        }
        return total;
    }
};