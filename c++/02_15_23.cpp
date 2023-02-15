class Solution {

public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        if(k == 0)
            return num;
        
        int n = num.size();
        int j = k;
        int i = n-1;
        int carry = 0;
        vector<int> ans;
        
        while(j>0 && i>=0){
            int sum = num[i] + j%10 + carry;
            carry = sum/10;
            j /= 10;
            i--;
            ans.push_back(sum%10);
        }
        
        while(i>=0){
            int sum = num[i] + carry;
            carry = sum/10;
            i--;
            ans.push_back(sum%10);
        }
        
        while(j>0){
            int sum = j%10 + carry;
            carry = sum/10;
            j /= 10;
            ans.push_back(sum%10);
        }
        
        while(carry > 0){
            ans.push_back(carry);
            carry /= 10;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};