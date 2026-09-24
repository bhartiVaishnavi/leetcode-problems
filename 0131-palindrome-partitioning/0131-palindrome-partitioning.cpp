class Solution {
public:
    bool isPalindrome(string& temp){
        int i = 0, j = temp.size() - 1;
        while( i< j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void substring(int i, int n, string& s, vector<string>& ds, vector<vector<string>>& ans){
        if(i == n){
            ans.push_back(ds);
            return;
        }

        string temp;

        for(int j = i; j<n; j++){
            temp += s[j];
            if(isPalindrome(temp)){
                ds.push_back(temp);
                substring(j+1, n, s, ds, ans);
                ds.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> ds;
        vector<vector<string>> ans;

        substring(0, n, s, ds, ans);
        return ans;
    }
};