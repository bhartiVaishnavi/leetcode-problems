class Solution {
public:
    void findcombo(int ind, int k, vector<int>& ds, int n, vector<vector<int>>& ans){
        if( ds.size() == k && n == 0){
            ans.push_back(ds);
            return ;
        }
        for(int i = ind; i< 9; i++){
            
            if(i + 1 > n) {
                break;
            }
            ds.push_back(i + 1);
            findcombo(i + 1, k, ds, n - (i + 1), ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombo(0, k, ds, n, ans);
        return ans;
    }
};