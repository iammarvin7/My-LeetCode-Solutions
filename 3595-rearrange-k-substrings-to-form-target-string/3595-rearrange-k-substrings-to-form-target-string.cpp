class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> freq;
        int n = s.size();
        int l = n/k;
        // int i = 0;
        // while(i < n){
        //     string str = t.substr(i,l);
        //     t_freq[str]++;
        //     i+=l;
        // }

        // i = 0;
        // while(i < n){
        //     string str = s.substr(i,l);
        //     if(!(t_freq[str])){
        //         return false;
        //     }
        //     else t_freq[str]--;
        //     i += l;
        // }
        // return true;

        for(int i = 0; i < n; i+=l) freq[t.substr(i, l)]++;
        for(int i = 0; i < n; i+=l) freq[s.substr(i, l)]--;

        for(auto& [k, v] : freq) if(v) return false;

        return true;

    }
};