class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> t_freq;
        int n = s.size();
        int l = n/k;
        int i = 0;
        while(i < n){
            string str = t.substr(i,l);
            t_freq[str]++;
            i+=l;
        }

        i = 0;
        while(i < n){
            string str = s.substr(i,l);
            if(!(t_freq[str])){
                return false;
            }
            else t_freq[str]--;
            i += l;
        }
        return true;
    }
};