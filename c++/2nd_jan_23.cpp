class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() == 1)
            return 1;
        
        int count = 0;
        for( auto i:word )
            if(isupper(i))
                count++;
        
        if((count == 1 && isupper(word[0])) || count == 0 || count == word.length())
            return 1;
        
        else return 0;
        
    }
};