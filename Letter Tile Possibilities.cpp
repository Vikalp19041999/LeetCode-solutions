class Solution {
public:
    set<string> result;
    map<int, int> flag;
    string s;
    
    int numTilePossibilities(string tiles) {
        backtrack(tiles);
        return result.size();
    }
    
    void backtrack(string tiles) {
        for(int i=0; i<tiles.size(); i++) {
            if(flag[i] != 1) {
                s.push_back(tiles[i]);
                flag[i] = 1;
                result.insert(s);
                backtrack(tiles);
                flag[i] = 0;
                s.pop_back();
            }
        }
    }
};
