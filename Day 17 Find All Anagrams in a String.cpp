class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> sf(26,0), pf(26,0) , ans;
        if(p.size()>s.size())
            return ans;
        for(int i=0;i<p.size();i++)
        {
            sf[s[i]-'a']++;
            pf[p[i]-'a']++;
        }
        if(sf==pf)
            ans.push_back(0);
        for(int i=p.size();i<s.size();i++)
        {
            sf[s[i]-'a']++;
            sf[s[i-p.size()]-'a']--;
            if(sf==pf)
                ans.push_back(i-(p.size()-1));
        }
        return ans;
    }
};
