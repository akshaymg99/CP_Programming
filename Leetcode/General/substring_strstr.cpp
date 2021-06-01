Problem link: https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1161/
Substring matching in a string (needle in a haystack)

class Solution {
public:
    int check(int i, string haystack, string needle) {
        int j = 0;
        while (j < needle.length()) {
            if (haystack[i+j] != needle[j])
                return -1; 
            j++;
        }
        return 1;
    }
    
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        
        if (needle == "") return 0;
        
        int flag = 0;
        char c = needle[0];
        for(int i=0; i<haystack.length() - needle.length() +1; ++i) {
            if (haystack[i] == c) {
                flag = check(i, haystack, needle);
                if (flag == 1) 
                    return i;
            }
        }
        return -1;
    }
};