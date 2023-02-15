class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1 = 0, cnt2 = 0;
        
        for(auto i:s){
            if(i == '0'){
                cnt1++;
                cnt1 = min(cnt1, cnt2);
            }
            else cnt2++;
        }
        return cnt1;
    }
};