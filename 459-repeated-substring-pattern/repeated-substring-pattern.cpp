class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // idea: is to keep popping ele from the start and appending them at the back and if the strings get equal then we found the substring
        
        string temp = s;
        for(int i=0; i<s.size()-1; i++){
            char ch = temp[0]; // store the first char
            temp.erase(0, 1); // remove the first char
            temp.push_back(ch); // append the popped char

            if(temp == s) return true;
        }
        return false;
    }
};