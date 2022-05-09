class Solution {
public:
string value_to_string(int value)
{
    string str;
    switch(value)
    { 
        case 2: str = "abc";
                break; 
        case 3: str = "def";
                break; 
        case 4: str = "ghi";
                break;
        case 5: str = "jkl";
                break;
        case 6: str = "mno";
                break; 
        case 7: str = "pqrs";
                break;   
        case 8: str = "tuv";
                break;
        case 9: str = "wxyz";
                break;  
    }
    return str;
}

void print_Keypad_string(vector<string>& res, string str,int i,string curr)
{
    if(str.length() == curr.length())
    {
        res.push_back(curr);
        return;
    }
    int digit = str[i] - '0';
    string keypad = value_to_string(digit);
    for(int j = 0; j < keypad.length(); j++)
    {
        print_Keypad_string(res,str,i+1,curr+keypad[j]);
    }
}
    vector<string> letterCombinations(string digits) {
       vector<string> ans;
        if(digits.length() == 0)
        {
            return ans;
        }
        print_Keypad_string(ans,digits,0,"");
        return ans;
    }
};