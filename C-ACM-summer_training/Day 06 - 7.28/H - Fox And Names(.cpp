#include<bits/stdc++.h>
using namespace std;
#define mx 100020
vector<int>G[mx];
vector<string> lol;
int ar[34];
int u,v,vis[mx],flag=0;
stack<int> mula;
void dfs(int src)
{
/*	for(int i = 0; i <= 25; i++)
		cout<<vis[i]<<" ";
	cout<<endl;*/
    vis[src]=1;
    for(int i=0;i<G[src].size();i++)
    {
        int x=G[src][i];
        if(vis[x] == 1)
        {
            flag = 1;
            return;
        }
        else if(vis[x] == 0)
        { 
            dfs(x);
        } 
    }
    mula.push(src);
    vis[src]=2;
    return;
}
int main()
{
    int test,j=test;
    scanf("%d\n",&test);
    j=test;
    int leflag = 0;
    //puts("");
    while(test--)
    {
        string str;
        getline(cin,str);
        lol.push_back(str);
        //cout<<str<<endl;
    }
    for(int i=0;i<j-1;i++)
    {
        
        string str1 = lol[i];
        string str2 = lol[i+1];
        //cout<<str1<<" "<<str2<<endl;

        int cnt=0;

        for(int j=0;j<min(str1.length(),str2.length());j++)
        {
            if(str1[j] == str2[j])cnt++;
            if(str1[j] != str2[j])
            {
                int p = str1[j]-'a';
                int q = str2[j]-'a';
                //cout<<p<<" "<<q<<endl;
                G[p].push_back(q);
                break;
            }
            if(str1.length() > str2.length() && cnt == str2.length())
            {
                leflag = 1;
            }
        }
    }
    //for(int i=0;i<26;i++)
      //  sort(G[i].begin(),G[i].end(),greater<int>());
    for(int i=25;i>=0;i--)
    {
        if(!vis[i])
            dfs(i);
        if(flag == 1 || leflag == 1)
        {
            printf("Impossible");
            return 0;
        }    
    }
    
    while(!mula.empty())
    {
        printf("%c",(mula.top()+'a'));
        mula.pop();
    }
    puts("");

}

