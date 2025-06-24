class Solution {
public:
    unordered_map<int, int> mp;  // maps stone value → index
    unordered_map<int, unordered_map<int, bool>> dp;  // memo: index → jump → result

    bool solve(vector<int>& stones, int curr_idx, int last_jump, int n) {
        if (curr_idx == n - 1) return true;

        // Check memoized result
        if (dp[curr_idx].count(last_jump)) return dp[curr_idx][last_jump];

        for (int jump = last_jump - 1; jump <= last_jump + 1; ++jump) {
            if (jump > 0) {
                int next_pos = stones[curr_idx] + jump;
                if (mp.count(next_pos)) {
                    int next_idx = mp[next_pos];
                    if (solve(stones, next_idx, jump, n)) {
                        return dp[curr_idx][last_jump] = true;
                    }
                }
            }
        }

        return dp[curr_idx][last_jump] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        for (int i = 0; i < n; ++i) {
            mp[stones[i]] = i;
        }

        return solve(stones, 1, 1, n);  // ✅ start from index 1 with jump 1
    }
};

/*   RECURSIVE CALL ONY
class Solution {
public:
unordered_map<int, int>mp;
int solve(vector<int>& stones,int curr_stone_idx,int prevjump,int n){
    if(curr_stone_idx == n-1){
        return true;
    }
    bool result=false;
    for(int nextjump=prevjump-1;nextjump<=prevjump+1;nextjump++){
        if(nextjump>0){
            int next_stone=stones[curr_stone_idx]+nextjump;
            if(mp.find(next_stone)!=mp.end()){
                result=result || solve(stones,mp[next_stone],nextjump,n);
            }   } }
    return result;
}
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=-1) return false;
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solve(stones, 0 ,0, n);
    }};
    */