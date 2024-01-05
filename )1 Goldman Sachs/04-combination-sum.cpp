class Solution {
public:
    void helper(int k, int n, vector<int>&temp, vector<vector<int>>&ans, int indx, int sum){
        if(sum == n && k == 0){
            ans.push_back(temp);
            return;
        }
        if(sum > n) return;

        for(int i=indx; i<=9; i++){
            if(i > n) return;
            temp.push_back(i);
            helper(k-1, n, temp, ans, i+1, sum+i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(k, n, temp, ans, 1, 0);
        return ans;
    }
};