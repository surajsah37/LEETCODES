class Solution {
public:
    string frequencySort(string s) {
     int freq[128]={0};
     for(char c:s){
        freq[c]++;
     }
     //sort using the comparator
     sort(s.begin(),s.end() ,[&](char a,char b){
        if(freq[a]!=freq[b]) 
        return freq[a]>freq[b];
        return a<b;
     });
     return s;
    }
};









   /*
        unordered_map<char, int> freq; // To store frequency of each character

    // Step 1: Count the frequency
    for (char c : s) {
        freq[c]++;
    }
    // Step 2: Create buckets where index = frequency
    int n = s.size();
    vector<vector<char>> buckets(n + 1); // size n+1 because frequency can be up to n

    for (auto it : freq) {
        buckets[it.second].push_back(it.first); // Put character in its frequency bucket
    }
    // Step 3: Build the final string from high frequency to low
    string result = "";
    for (int i = n; i >= 1; i--) { // from highest possible frequency to lowest
        for (char c : buckets[i]) { // iterate all characters with this frequency
            result.append(i, c); // add character 'i' times
        }
    }
    return result;
    */