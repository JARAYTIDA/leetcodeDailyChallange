class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1 || n == 2) return n;
        int mx = INT_MIN;
        
        for(int i = 0; i<n; i++){
            map<double,int> mp;
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                else{
                    if(points[j][0] == points[i][0]) mp[INT_MAX]++;
                    else{
                        double x1 = points[i][0];
                        double y1 = points[i][1];
                        double x2 = points[j][0];
                        double y2 = points[j][1];
                        double a = (y2-y1)/(x2-x1);
                        mp[a]++;
                    }
                }
            }
            
            for(auto k:mp)
                mx = max(mx, k.second+1);
        }
        
        return mx;
    }
};