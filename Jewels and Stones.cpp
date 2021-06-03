class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map <char,int> hashmap;
        int count=0;
        for(char i : jewels) hashmap[i]++;
        for(char i : stones) count += hashmap[i];
        return count;
    }
};