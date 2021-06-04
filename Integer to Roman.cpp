class Solution {
public:
    string intToRoman(int num) {
        string str = "";
        while(num >= 1000) {
            str = str + 'M';
            num = num - 1000;
        } if(num >= 900) {
            str = str + "CM";
            num = num - 900;
        }
        
        while(num >= 500) {
            str = str + 'D';
            num = num - 500;
        } if(num >= 400) {       
            str = str + "CD";
            num = num - 400;
        }
        
        while(num >= 100) {
            str = str + 'C';
            num = num - 100;
        } if(num >=90) {
            str = str + "XC";
            num = num - 90;
        }
        
        while(num >= 50) {
            str = str + 'L';
            num = num - 50;
        } if (num >= 40) {
            str = str + "XL";
            num = num - 40;
        }
        
        while(num >= 10) {
            str = str + 'X';
            num = num - 10;
        } if(num >= 9) {
            str = str + "IX";
            num = num - 9;
        }
        
        while(num >= 5) {
            str = str + 'V';
            num = num - 5;
        } if(num >= 4) {
            str = str + "IV";
            num = num - 4;
        }
        
        while(num >= 1) {
            str = str + 'I';
            num = num - 1;
        }
        return str;
    }
};