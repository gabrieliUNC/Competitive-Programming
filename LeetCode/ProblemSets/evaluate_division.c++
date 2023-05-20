#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(string s, string d, map<string, vector<pair<string, double>>> m, map<string, int> &v, double &ans, double tmp){
            if(v.count(s))return;
            if(s==d){ans=tmp; return;}
            v[s] = 1;
            for(auto x : m[s]){
                dfs(x.first, d, m, v, ans, tmp*x.second);
            }
            return;
        }



    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {


        map<string, vector<pair<string, double>>> m;
        for(int i=0; i<equations.size(); ++i){
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        vector<double> res;
        for(int i=0; i<queries.size(); ++i){
            string s = queries[i][0];
            string d = queries[i][1];
            map<string, int>v;
            double ans = -1.0;
            double tmp = 1.0;

            if(m.count(s))dfs(s, d, m, v, ans, tmp);
            res.push_back(ans);
            
        }
        return res;
    }
};