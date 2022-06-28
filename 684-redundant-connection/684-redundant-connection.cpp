class Solution {
public:
    vector<int>par;
    int find(int a){
        if(par[a]==a){
            return a;
        }
        return par[a] = find(par[a]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        par[b] = par[a];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // sz.resize(n+1,1);
        par.resize(n+1);
        for(int i = 0;i<=n;i++)par[i] = i;
        
        for(auto &it:edges){
            if(find(it[0])!=find(it[1])){
                Union(it[0],it[1]);
            }
            else{
                return it;
            }
        }
        return {};
        
    }
    
};