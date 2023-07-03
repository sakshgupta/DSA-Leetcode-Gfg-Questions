class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;

        bool flag = false;
        char temp1 = NULL, temp2 = NULL;

        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size();
        }

        for(int i=0; i<s.length(); i++){
            if(flag == true and (s[i] != goal[i])) return false;
            if(temp1 == NULL and s[i] != goal[i]) {
                temp1 = s[i];
                temp2 = goal[i];
            }
            else if((s[i] == temp1) and s[i] != goal[i]){
                return false;
            }
            else if(((s[i] == temp2) and (goal[i] == temp1)) and s[i] != goal[i]){
                flag = true;
            }
        }

        return flag;
    }
};