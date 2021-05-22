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
        
        for(int k=3; k<=n; ++k) {
            for(int i=0; i< n-k+1; ++i) {
                
                int j = i+k-1;
                if(s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    
                    if(k > max_length) {
                        max_length = k;
                        start = i;
                    }
                }
                
                    
            }
        }
        
        string ans = s.substr(start, max_length);
        return ans;
                
        
    }
};