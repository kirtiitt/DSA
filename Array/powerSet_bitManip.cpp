//intuition: if bit is set (we're iterating over a string here), then add to the subset otherwise continue to the next index of the string
//TC: O(2^n* n), SC: O(1)
vector<string> findSet(string S) {
    vector<string> ans;
    int n= S.size();
    for(int i=0; i<(1<<n); i++) {
        string sub= "";
        for(int ind=0; i<n; i++)
            if(i& (1<<ind))
                sub+= string[ind]
        ans.push_back(sub);
    }
    return ans;
}
