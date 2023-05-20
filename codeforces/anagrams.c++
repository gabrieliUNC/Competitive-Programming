class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(string anagram: strs){
            string temp = anagram;
            sort(temp.begin(), temp.end());
            m[temp].push_back(anagram);
        }
        vector<vector<string>> ans;
        for(pair<string, vector<string>> e: m){
            ans.push_back(e.second);
        }
        return ans;
    }
};