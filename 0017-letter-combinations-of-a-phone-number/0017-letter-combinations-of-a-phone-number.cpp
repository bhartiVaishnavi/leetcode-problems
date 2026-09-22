class Solution {
public:
    void solve(int ind, string& digits, vector<string>& mp, string& ds, vector<string>& ans){
        if(ind == digits.size()){
            ans.push_back(ds);
            return;
        }
        string letter = mp[digits[ind] - '0'];
        for(int i = 0; i < letter.size(); i++){
            ds.push_back(letter[i]);
            solve(ind + 1, digits, mp, ds, ans);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans;
        string ds;

        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(0, digits, mp, ds, ans);

        return ans;
    }
};