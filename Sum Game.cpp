class Solution {
public:
    bool sumGame(string num) {
       int n = num.size();
        int aq = 0; 
        int bq = 0;
        int a = 0; 
        int b = 0;
        for(int i=0; i<n; i++) {
            if(i < n/2) {
                if(num[i] == '?') {
                    aq++;
                } else {
                    a += (num[i]-'0');
                }
            } else {
                if(num[i] == '?') {
                    bq++;
                } else{
                    b += (num[i]-'0');
                }
            }
        }
        int ans = a+(aq/2)*9-b-(bq/2)*9;
        return ans!=0; 
    }
};