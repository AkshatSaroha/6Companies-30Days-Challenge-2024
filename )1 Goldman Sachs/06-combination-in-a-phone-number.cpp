class Solution {
public:
    void helper(string digits, vector<string>&buttons, vector<string>&result, string &temp, int index){
        if(index == digits.size()){
            result.push_back(temp);
            return;
        }
        //
        string value = buttons[digits[index] - '0'];
        for(int i=0; i<value.size(); i++){
            temp.push_back(value[i]);
            helper(digits, buttons, result, temp, index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> buttons = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        vector<string> result;
        string temp;
        helper(digits, buttons, result, temp, 0);
        return result;
    }
};