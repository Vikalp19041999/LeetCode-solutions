class Solution {
public:
    bool isValidSerialization(string preorder) {
        int vacancy = 1; 
        for(int i=0; i<preorder.length(); i++){
            if(preorder[i] == ',') {
                continue;
            } 
            vacancy--;
            if(vacancy < 0) {
                return false;
            }            
            if(preorder[i] != '#') { 
                while(i<preorder.length() && isdigit(preorder[i])) {
                    i++;
                }
                i--;
                vacancy = vacancy + 2;       
            }      
        }
        if(vacancy != 0) {
            return false;
        }
        return true;
    }
};