class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int n = a.length();
        int m = b.length();
        
        if(n == 0) return to_string(m);
        if(m == 0) return to_string(n);
        
        string ans = "";
        int i = 0;
        int j = 0;
        int carry = 0;
        while(i<n&& j<m){
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            
            i++;
            j++;
            if(sum > 1){
                carry = 1;
                if(sum == 2)
                    sum = 0;
                else sum = 1;
            }
            else carry = 0;
            
            ans += to_string(sum);
        }
        
        while(i<n){
            int sum = (a[i] - '0') + carry;
            
            i++;
            // j++;
            if(sum > 1){
                carry = 1;
                if(sum == 2)
                    sum = 0;
                else sum = 1;
            }
            else carry = 0;
            
            ans += to_string(sum);
        }
        
        while(j<m){
            int sum = (b[j] - '0') + carry;
            
            // i++;
            j++;
            if(sum > 1){
                carry = 1;
                if(sum == 2)
                    sum = 0;
                else sum = 1;
            }
            else carry = 0;
            
            ans += to_string(sum);
        }
        
        if(carry > 0)
            ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};