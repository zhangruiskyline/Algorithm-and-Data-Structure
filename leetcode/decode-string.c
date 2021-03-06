//https://leetcode.com/problems/decode-string/
/*
Given an encoded string, return it's decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class Solution {
public:
    string decodeString(string s) {
        int num = 0;
        string ret = "";
        int index = 0;
        ret = dfs(s,index);
        return ret;
    }
    
    int getnumber(string &s, int& index){
        int num = 0;
        while(index<s.size()){
            if(isdigit(s[index])){
                num = num*10 + s[index]-'0';
                index++;
            }else{
                break;
            }
        }
        return num;
    }
    
    string dfs(string &s, int& index){
        string ret="";
        string cur="";
        int num = 0;
        while(index<s.size()){
            if(isdigit(s[index])){
                num = getnumber(s,index);
            }else if(s[index]=='['){
                index++;
                cur = dfs(s,index);
                for(int i=0;i<num;i++){
                    ret+=cur;
                }
            }else if(s[index]==']'){
                //reach end, return
                index++;
                break;
            }else if(isalpha(s[index])){
                ret+=s[index];
                index++;
            }
        }

        return ret;
    }
};
