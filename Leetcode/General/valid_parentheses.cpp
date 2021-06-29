/*
Problem link: https://leetcode.com/problems/valid-parentheses
Valid Parentheses check
*/

class Solution {
private:
    unordered_map <char, char> mappings;
public:
    bool isValid(string s) {
        mappings.insert(make_pair(')', '('));
        mappings.insert(make_pair('}', '{'));
        mappings.insert(make_pair(']', '['));
        
        stack<char> table;
        for (int i=0; i<s.size(); ++i) {
            char c = s.at(i);
            if (mappings.find(c) != mappings.end()) {  // if c is a closing bracket
                
                char top_ele = table.empty() ? '#' : table.top();
                table.pop();
                
                if (top_ele != mappings[c])
                    return false;
            }
            else
                table.push(c); 
        }
        return table.empty();
    }
};