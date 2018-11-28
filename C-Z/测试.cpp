#include<iostream>  
#include<map>  
#include<vector>  
#include<algorithm>  
using namespace std;  
map<string, int> dict;  
vector<string> words;  
vector<string> ans;  
string getkey(const string & s)  
{ 
    string key = s;
    for(int i = 0; i < (int)key.length(); i++)  
        key[i] = tolower(key[i]); 
    sort(key.begin(), key.end());
    return key;  
} 
int main()  
{  
    string s;  
  
    while(cin >> s) {  
        if(s[0] == '#')  
            break;  
  
        string key = getkey(s);  
  
        if(dict.count(key) == 0)  
            dict[key] = 0;  
        dict[key]++;  
        words.push_back(s);  
    }  
    for(int i=0; i<(int)words.size(); i++)  
        if(dict[getkey(words[i])] == 1)  
            ans.push_back(words[i]);  
    sort(ans.begin(), ans.end());  
    for(int i=0; i<(int)ans.size(); i++)  
        cout << ans[i] << "\n";  
    return 0;  
}  
