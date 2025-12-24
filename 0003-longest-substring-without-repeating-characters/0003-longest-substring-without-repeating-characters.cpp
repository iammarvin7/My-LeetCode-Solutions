class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = i, len = 0, cur = 0;
        unordered_set<char> st;

        while(j < s.size()){
            char ch = s[j];

            if(!st.count(ch)){
                st.insert(ch);
                cur = j-i+1;   
            }
            else{

                while(st.count(ch)){
                    st.erase(s[i]);
                    i++;
                }
                st.insert(ch);
                cur = j-i+1;
            }
            len = max(cur, len);
            j++;

        }
        return max(cur, len);
    }
};
