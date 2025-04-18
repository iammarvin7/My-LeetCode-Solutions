class Solution {

public:
    string countAndSay(int n) {
        string RLE = "1";


        for(int x = 2; x <= n; ++x){
            string ans;
            int count = 1;
            char cur = RLE[0];
            for(int i = 1; i < RLE.size(); ++i){
                if(RLE[i]==cur){
                    count++;
                }
                else{
                    ans += (to_string(count) + cur);
                    cur = RLE[i];
                    count = 1;
                }
            }
            ans += (to_string(count) + cur);
            RLE = ans;

        }
        return RLE;
    }
};