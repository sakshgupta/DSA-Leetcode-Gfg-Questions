class Solution {
private:
    string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void f(int i, string digits, string str, vector<string> &res){
        if(i == digits.length()){
            res.push_back(str);
            return;
        }

        // looping over the arr[2] to get "abc"
        for(int j = 0; j < arr[((int) digits[i])-48].length(); j++){
            f(i+1, digits, str+arr[((int) digits[i])-48][j], res);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // idea: is to check for each character the strings assigned then just use recursion to add the strings letter to the string and if idx == digits.length then append it to the answer vector
        vector<string> res;
        if(digits.length() == 0) return res;
        f(0, digits, "", res);
        return res;
    }
};