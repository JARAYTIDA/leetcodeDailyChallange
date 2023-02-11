class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int cnt = 0;
        int i = 0;
        int n = points.size();
        int shoot_at = 0;
        
        while(i<n){
            cnt++;
            shoot_at = points[i][0];
            pair<int,int> range = {points[i][0], points[i][1]};
            i++;
            while(i<n && range.first <= points[i][0] && points[i][0] <= range.second){
                if(points[i][1] <= range.second)
                    range = {points[i][0], points[i][1]};
                
                else range.first = points[i][0];
                i++;
            }
            
        }
        
        return cnt;
    }
};