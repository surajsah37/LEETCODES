class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char task:tasks){
            freq[task-'A']++;
        }
            int maxfreq=*max_element(freq.begin(),freq.end());
            int maxcount=count(freq.begin(),freq.end(),maxfreq);

             int partcount = maxfreq - 1;
        int partLength = n + 1;
        int emptySlots = partcount * partLength + maxcount;
        
         return max((int)tasks.size(), emptySlots);
        }
};