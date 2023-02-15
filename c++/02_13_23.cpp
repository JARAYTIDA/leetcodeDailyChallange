class Solution {
public:
    int countOdds(int low, int high) {
        int n = high - low;
        if((n)%2 == 1) return n/2 +1;
        else{
            if(high%2 == 1)
                return n/2+1;
            else return n/2;
        }
    }
};