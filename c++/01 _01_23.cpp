class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> stoc;
        unordered_map<char,string> ctos;
        
        int idx = 0;
        int n = pattern.length();
        int m = s.length();
        int i = 0;
        for(i = 0; i<n; i++){
            string str;
            
            while(idx < m && s[idx] != ' '){
                str.push_back(s[idx]);
                idx++;
            }
            idx++;
            auto it1 = ctos.find(pattern[i]);
            auto it2 = stoc.find(str);
            
            if(it1 != ctos.end() && it2 != stoc.end()){
                if(it1->first != it2->second || it1->second != it2->first)
                    return false;
            }
            
            else if(it1 != ctos.end() && it2 == stoc.end() || it1 == ctos.end() && it2 != stoc.end() )
                return false;
            
            else{
                ctos[pattern[i]] = str;
                stoc[str] = pattern[i];
            }
            
        }
        cout<<i<<"-"<<n<<"  "<<idx-1<<"-"<<s.length();
        
        return (i == n && idx-1 == s.length());
    }
};