class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].length();
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                string A = strs[j];
                string B = strs[j+1];
                int a = A[i];
                int b = B[i];
                if(b<a){
                    ans++;
                    break;
                }
            }
        }
        return ans;
        
    }
};