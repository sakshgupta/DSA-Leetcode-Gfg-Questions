class Solution {
public:
    bool solve(string s, unordered_set<string> &mp, unordered_map<string, bool> &dp){
        if(s.length()==0){
            return true;
        }

        if(dp.find(s)!=dp.end()) return dp[s];

        // leethub
        for(int i=0;i<s.length();i++){
            // i = 4
            // temp = leet
            string r=s.substr(0,i+1);
            if(mp.count(r)){
                if(solve(s.substr(i+1),mp, dp)) // hub
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // idea: is to put the word dict in a unordered_set then at each point in the string partition it and check if the substring is present in the set or not if yes then call for right substring and if false then continue
        unordered_set<string> mp(wordDict.begin(), wordDict.end());

        unordered_map<string, bool> dp;
        return solve(s, mp, dp);
    }
};