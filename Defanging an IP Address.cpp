class Solution {
public:
    string defangIPaddr(string address) {
        string st;
        for(int i=0; i<address.length(); i++) {
            if(address[i] == '.') {
                st = st + "[.]";
            } else {
                st = st + address[i];
            }
        }
        return st;
    }
};