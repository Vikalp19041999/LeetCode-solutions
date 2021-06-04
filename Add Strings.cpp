class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string str = "";
        if(num1.length() > num2.length()) {
            swap(num1, num2);
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0; i<(num1.length()); i++) {
            int sum = ((num1[i] - '0') + (num2[i] - '0') + carry);
            str.push_back((sum % 10) + '0');
            carry = sum/10;
        }
        for(int i=num1.length(); i<num2.length(); i++) {
            int sum = ((num2[i] - '0') + carry);
            str.push_back((sum % 10) + '0');
            carry = sum/10;
        }
        if(carry) {
            str.push_back(carry + '0');
        }
        reverse(str.begin(), str.end());
        return str;
    }
};