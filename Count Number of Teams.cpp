class Solution {
public:
    int numTeams(vector<int>& rating) {
        int result = 0;
        for(int i=1; i<rating.size()-1; i++) {
            int leftSmall = 0; 
            int leftLarge = 0;
            int rightSmall = 0;
            int rightLarge = 0;
            for(int j=0; j<i ;j++) {
                if(rating[j] < rating[i]) {
                    leftSmall++;
                }
                if(rating[j] > rating[i]) {
                    leftLarge++;
                }
            }
            for(int j=i+1; j<rating.size(); j++){
                if(rating[j] < rating[i]){
                    rightSmall++;
                }
                if(rating[j] > rating[i]){
                    rightLarge++;
                }
            }
            result += leftSmall * rightLarge + leftLarge * rightSmall;
        }
        return result;
    }
};