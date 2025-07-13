class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isalpha(c)){
                result.push_back(c);
            }else if(c=='*' && !result.empty()){
                result.pop_back();
            }else if(c=='#' && !result.empty()){
                string temp = result;
                result+=temp;
            }else if(c=='%' && !result.empty()){
                string temp = result;
                reverse(temp.begin(), temp.end());
                result = temp;
            }
        }
        return result;
    }
};
