class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        bool table[n][n];
        memset(table, 0, sizeof(table));
        
        for(int i=0; i<n; ++i) 
            table[i][i] = true;
        int max_length = 1, start = 0;
        
        for(int i=0; i<n-1; ++i) {
            if(s[i] == s[i+1]) {
                table[i][i+1] = true; 
                start = i;
                max_length = 2;
            }
        }
        
        for (int j=2; j<n; ++j) {
            for (int i=0; i<j-1; ++i) {
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    if (j-i+1 > max_length){
                        max_length = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        string ans = s.substr(start, max_length);
        return ans;
                
        
    }
};