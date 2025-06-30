class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill : bills) {
            if(bill == 5) {
                five++; // no change needed
            } else if(bill == 10) {
                if(five == 0) return false; // can't give $5 change
                five--;  // give $5 as change
                ten++;   // take $10
            } else { // bill == 20
                if(ten > 0 && five > 0) {
                    ten--; // give $10
                    five--; // give $5
                } else if(five >= 3) {
                    five -= 3; // give three $5
                } else {
                    return false; // can't give change
                }
            }
        }
        return true;
    }
};
