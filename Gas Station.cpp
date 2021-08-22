class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int surplus = 0;
        int total_surplus = 0;
        int starting = 0;
        for(int i=0; i<gas.size(); i++) {
            total_surplus = total_surplus + gas[i] - cost[i];
            surplus = surplus + gas[i] - cost[i];
            if(surplus < 0) {
                surplus = 0;
                starting = i+1;
            }
        }
        if(total_surplus < 0) {
            return -1;
        }
        return starting;
    }
};