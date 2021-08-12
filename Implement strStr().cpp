class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0){
			return 0;
		}
		int j = 0;
		for(int i=0; i<haystack.length(); i++){
			if(haystack[i] == needle[j]) {
				j++;
			} else{
				i = i-j;
				j = 0;
			}
			if(j == needle.length()) {
				return i-j+1 ;
			}
		}
		return -1;
    }
};