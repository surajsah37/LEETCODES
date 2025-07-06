class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Step 1: Convert each number to a string
    vector<string> strNums;
    for (int num : nums) {
        strNums.push_back(to_string(num));
    }
    // Step 2: Sort using custom comparator (lambda function)
    sort(strNums.begin(), strNums.end(), [](string &a, string &b) {
        return a + b > b + a;
    });
    // Step 3: Edge case: if the largest number is "0", return "0"
    if (strNums[0] == "0") {
        return "0";
    }
    // Step 4: Join the sorted strings
    string result;
    for (string &s : strNums) {
        result += s;
    }
    return result;
    }
};