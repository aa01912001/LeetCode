class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long int ret = 0;
        vector<int> count(101, 0);
        for(int i=0; i<arr.size(); i++) {
            count[arr[i]]++;
        }
        
        for(int i=0; i<=100; i++) {
            for(int j=i; j<=100; j++) {
                for(int k=j; k<=100; k++) {
                    if((i+j+k) == target) {
                        unordered_map<int, int> hmap;
                        hmap[i]++;
                        hmap[j]++;
                        hmap[k]++;
                        long long int tmp = 1;
                        for(auto p : hmap) {
                            int c = p.second;
                            long long int t = 1;
                            int d = 1;
                            while(c > 0) {
                                t *= count[p.first]--;
                                d *= c;
                                c--;
                            }
                            count[p.first] += p.second;
                            tmp *= t/d;    
                        }
                        ret += tmp;
                    }
                }
            }
        }
        
        return ret % 1000000007;
    }
    
};