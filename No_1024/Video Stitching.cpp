class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(101, INT_MAX);
        sort(clips.begin(), clips.end());
        if(clips[0][0] > 0) return -1;
        dp[0] = 0;
        for(int i=0; i<clips.size(); i++) { // for each clip
            int s = clips[i][0];
            int e = clips[i][1];
            if(dp[s] == INT_MAX) return -1;
            for(int j=s; j<=e; j++) { // from clips[i][0] to clips[i][1]
                dp[j] = min(dp[j], dp[s]+1);
            }
            if(e >= time) break;
        }
        
        return dp[time] == INT_MAX ? -1 : dp[time];
    }
};