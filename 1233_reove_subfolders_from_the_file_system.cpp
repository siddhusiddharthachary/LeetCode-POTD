class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        string parent = "";

        vector<string> ans;

        for(const string& f:folder){
            if(parent.empty() || f.find(parent + '/') != 0){
                ans.push_back(f);
                parent = f;
            }
        }
        return ans;
    }
};
