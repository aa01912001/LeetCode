class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret = 0, aCount = 0, bCount = 0;
        priority_queue <int, vector<int>, greater<int> > aDiff; // store the difference of costs for those people in city "a" 
        priority_queue <int, vector<int>, greater<int> > bDiff; // store the difference of costs for those people in city "b" 
        for(int i=0; i<costs.size(); i++) { 
            if(costs[i][0] < costs[i][1]) {
                aCount++;
                ret += costs[i][0];
                aDiff.push(costs[i][1] - costs[i][0]);
            } else {
                bCount++;
                ret += costs[i][1];
                bDiff.push(costs[i][0] - costs[i][1]);
            }
        }

        while(aCount > costs.size()/2) { // transfer someone who has minimum difference of costs to city b
            ret += aDiff.top();
            aDiff.pop();
            aCount--;
        }
        
        while(bCount > costs.size()/2) { // transfer someone who has minimum difference of costs to city a
            ret += bDiff.top();
            bDiff.pop();
            bCount--;
        }
        
        return ret;
    }
};