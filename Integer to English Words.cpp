class Solution {
public:
    vector<string> below20 {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> below100 {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string solve(int n){
        if(n < 20){
            return below20[n];
        } else if(n < 100){
            string tens = below100[n/10];
            string ones = below20[n%10];
            return tens + (ones.empty()?"":" ") + ones;
        } else if(n < 1000) {
            string hundred = solve(n/100) + " Hundred";
            string tens = solve(n%100);
            return hundred + (tens.empty()?"":" ") + tens;
        } else if(n < 1000000){
            string thousand = solve(n/1000) + " Thousand";
            string hundred = solve(n%1000);
            return thousand + (hundred.empty()?"":" ") + hundred;
        } else if(n < 1000000000){
            string million = solve(n/1000000) + " Million";
            string thousand = solve(n%1000000);
            return million + (thousand.empty()?"":" ") + thousand;
        } else {
            string billion = solve(n/1000000000) + " Billion";
            string million = solve(n%1000000000);
            return billion + (million.empty()?"":" ") + million;
        }
    }
    
    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }
        return solve(num);
    }
};