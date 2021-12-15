class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        int arr[s.length()][s.length()];
        string res(1, s[0]);
        memset(arr, -1, sizeof(arr[0][0]) * s.length() *s.length());
        for(int i = 0; i < s.length(); i++)
            arr[i][i] = 1;
        for(int subLen = 2; subLen <= s.length(); subLen++)
        {
            for(int j = 0; j <= s.length() - subLen; j++)
            {
                string sub = s.substr(j, subLen);
                if(sub[0] == sub[subLen - 1] && (arr[j+1][j+subLen-2] || arr[j+1][j+subLen-2] == -1))
                {
                    arr[j][j+subLen-1] = 1;
                    if(subLen > res.length())
                        res = sub;
                } else { arr[j][j+subLen-1] = 0;}
            }
        }
        
        return res;
    }
};