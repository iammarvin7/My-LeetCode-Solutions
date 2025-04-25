class Solution {

    char mirror(char ch){
        return 'z' - (ch - 'a');
    }

public:
    long long calculateScore(string s) {
        long long score = 0;
        int n = s.size();
        unordered_map<char, stack<int>> past;

        for(int i = 0; i < n; ++i){
            char ch = s[i];
            char m = mirror(ch);

            auto it = past.find(m);
            if(it != past.end() and !it->second.empty()){
                int v = it->second.top();
                it->second.pop();
                score = score + (i - v);
            }
            else {
                past[ch].push(i);
            };
        }
        return score;

    }
};

// class Solution {

//     char mirror(char ch){
//         return 'z' - (ch - 'a');
//     }

// public:
//     long long calculateScore(string s) {
//         long long score = 0;
//         int n = s.size();
//         vector<vector<int>> vec(26, vector<int>());

//         for(int i = 0; i < n; ++i){
//             char ch = s[i];
//             char m = mirror(ch); 

//             if(vec[m-'a'].size() == 0){
//                 vec[ch-'a'].push_back(i);
//             }
//             else{
//                 int v = vec[m-'a'].back();
//                 score += (i - v);
//                 vec[m-'a'].pop_back();
//             }   
//         }
//         return score;

//     }
// };