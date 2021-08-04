class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) {
            return tasks.size();
        }
        int freq[26] = {0};
        for(char c: tasks) {
            freq[c - 'A']++;
        }
        sort(freq, freq+26);
        int max_freq = freq[25] - 1;
        int idle = max_freq * n;  
        for(int i=24; i>=0; i--) {
            idle = idle - min(freq[i], max_freq);
        }
        if(idle > 0) {
            return tasks.size() + idle;
        }
        return tasks.size();
    }
};