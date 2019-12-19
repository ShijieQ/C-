#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
void input_grammer(string *G)//输入文法G,n个非终结符
{
    int i=0;//计数
    char ch='y';
    while(ch=='y'){
        cin>>G[i++];
        cout<<"继续输入?(y/n)\n";
        cin>>ch;
    }
}
void preprocess(string *G,string *P,string &U,string &u,int &n,int &t,int &k)//将文法G预处理产生式集合P，非终结符、终结符集合U、u，
{
    int i,j,r,temp;//计数
    char C;//记录规则中（）后的符号
    int flag;//检测到（）
    n=t=k=0;
    for( i=0;i<50;i++)  P[i]="          ";//字符串如果不初始化，在使用P[i][j]=a时将不能改变，可以用P[i].append(1,a)
    U=u="                    ";//字符串如果不初始化，无法使用U[i]=a赋值，可以用U.append(1,a)
    for(n=0;!G[n].empty();n++)
    { U[n]=G[n][0];
    }//非终结符集合，n为非终结符个数
    for(i=0;i<n;i++)
    {
        for(j=4;j<G[i].length();j++)
        {
            if(U.find(G[i][j])==string::npos&&u.find(G[i][j])==string::npos)
                 if(G[i][j]!='|'&&G[i][j]!='^')
                //if(G[i][j]!='('&&G[i][j]!=')'&&G[i][j]!='|'&&G[i][j]!='^')
                    u[t++]=G[i][j];
        }
    }//终结符集合，t为终结符个数
    for(i=0;i<n;i++)
    {
        flag=0;r=4;
        for(j=4;j<G[i].length();j++)
        {
          P[k][0]=U[i];P[k][1]=':';P[k][2]=':';P[k][3]='=';
        /* if(G[i][j]=='(')
          {    j++;flag=1;
               for(temp=j;G[i][temp]!=')';temp++);
               C=G[i][temp+1];
               //C记录（）后跟的字符，将C添加到（）中所有字符串后面
           }
          if(G[i][j]==')') {j++;flag=0;}
        */
          if(G[i][j]=='|')
          {
           //if(flag==1) P[k][r++]=C;
            k++;j++;
            P[k][0]=U[i];P[k][1]=':';P[k][2]=':';P[k][3]='=';
            r=4;
            P[k][r++]=G[i][j];
          }
          else
          {
           P[k][r++]=G[i][j];
          }
        }
        k++;
    }//获得产生式集合P，k为产生式个数
}
int eliminate_1(string *G,string *P,string U,string *GG)
//消除文法G1中所有直接左递归得到文法G2，要能够消除含有多个左递归的情况）
{
string arfa,beta;//所有形如A::=Aα|β中的α、β连接起来形成的字符串arfa、beta
int i,j,temp,m=0;//计数
int flag=0;//flag=1表示文法有左递归
int flagg=0;//flagg=1表示某条规则有左递归
char C='A';//由于消除左递归新增的非终结符，从A开始增加，只要不在原来问法的非终结符中即可加入
for(i=0;i<20&&U[i]!=' ';i++)
{   flagg=0;
    arfa=beta="";
    for(j=0;j<100&&P[j][0]!=' ';j++)
    {
        if(P[j][0]==U[i])
        {
            if(P[j][4]==U[i])//产生式j有左递归
            {
                flagg=1;
                for(temp=5;P[j][temp]!=' ';temp++) arfa.append(1,P[j][temp]);
                if(P[j+1][4]==U[i]) arfa.append("|");//不止一个产生式含有左递归
            }
            else
            {
                for(temp=4;P[j][temp]!=' ';temp++) beta.append(1,P[j][temp]);
                if(P[j+1][0]==U[i]&&P[j+1][4]!=U[i]) beta.append("|");
            }
        }
    }
    if(flagg==0)//对于不含左递归的文法规则不重写
     {GG[m]=G[i]; m++;}
    else
    {
    flag=1;//文法存在左递归
    GG[m].append(1,U[i]);GG[m].append("::=");
    if(beta.find('|')!=string::npos) GG[m].append("("+beta+")");
    else GG[m].append(beta);
    while(U.find(C)!=string::npos){C++;}
    GG[m].append(1,C);
    m++;
    GG[m].append(1,C);GG[m].append("::=");
    if(arfa.find('|')!=string::npos) GG[m].append("("+arfa+")");
    else GG[m].append(arfa);
    GG[m].append(1,C);GG[m].append("|^");
    m++;
    C++;
   }//A::=Aα|β改写成A::=βA‘，A’=αA'|β，
}
return flag;
}
int* ifempty(string* P,string U,int k,int n)
{
   int* empty=new int [n];//指示非终结符能否推导到空串
   int i,j,r;
   for(r=0;r<n;r++) empty[r]=0;//默认所有非终结符都不能推导到空
   int flag=1;//1表示empty数组有修改
   int step=100;//假设一条规则最大推导步数为步
   while(step--)
   {
   for(i=0;i<k;i++)
   {
       r=U.find(P[i][0]);
       if(P[i][4]=='^') empty[r]=1;//直接推导到空
       else
       {
           for(j=4;P[i][j]!=' ';j++)
           {
               if(U.find(P[i][j])!=string::npos)
                  {
                      if(empty[U.find(P[i][j])]==0) break;
                  }
               else  break;
           }
           if(P[i][j]==' ') empty[r]=1;//多步推导到空
           else flag=0;
       }
   }
   }
   return empty;
}
string* FIRST_X(string* P,string U,string u,int* empty,int k,int n)
{
    int i,j,r,s,tmp;
    string* first=new string[n];
    char a;
    int step=100;//最大推导步数
    while(step--){
   // cout<<"step"<<100-step<<endl;
    for(i=0;i<k;i++)
    {
        //cout<<P[i]<<endl;
        r=U.find(P[i][0]);
        if(P[i][4]=='^'&&first[r].find('^')==string::npos)  first[r].append(1,'^');//规则右部首符号为空
        else
        {
            for(j=4;P[i][j]!=' ';j++)
            {
                a=P[i][j];
                if(u.find(a)!=string::npos&&first[r].find(a)==string::npos)//规则右部首符号是终结符
                {
                    first[r].append(1,a);
                    break;//添加并结束
                }

                if(U.find(P[i][j])!=string::npos)//规则右部首符号是非终结符,形如X：：=Y1Y2...Yk
                {
                    s=U.find(P[i][j]);
                    //cout<<P[i][j]<<":\n";
                    for(tmp=0;first[s][tmp]!='\0';tmp++)
                    {
                        a=first[s][tmp];
                        if(a!='^'&&first[r].find(a)==string::npos)//将FIRST[Y1]中的非空符加入
                            first[r].append(1,a);
                    }
                }
                if(!empty[s]) break;//若Y1不能推导到空，结束
            }
            if(P[i][j]==' ')
               if(first[r].find('^')==string::npos)
                     first[r].append(1,'^');//若Y1、Y2...Yk都能推导到空，则加入空符号
        }
    }
}
    return first;
}
string FIRST(string U,string u,string* first,string s)//求符号串s=X1X2...Xn的FIRST集
{
    int i,j,r;
    char a;
    string  fir;
    for(i=0;i<s.length();i++)
    {
          if(s[i]=='^') fir.append(1,'^');
        if(u.find(s[i])!=string::npos&&fir.find(s[i])==string::npos){ fir.append(1,s[i]);break;}//X1是终结符，添加并结束循环
        if(U.find(s[i])!=string::npos)//X1是非终结符
        {
            r=U.find(s[i]);
            for(j=0;first[r][j]!='\0';j++)
            {
                a=first[r][j];
                if(a!='^'&&fir.find(a)==string::npos)//将FIRST(X1)中的非空符号加入
                    fir.append(1,a);
            }
            if(first[r].find('^')==string::npos) break;//若X1不可推导到空，循环停止
        }
        if(i==s.length())//若X1-Xk都可推导到空
           if(fir.find(s[i])==string::npos)  //fir中还未加入空符号
                   fir.append(1,'^');
    }
    return fir;
}
string** create_table(string *P,string U,string u,int n,int t,int k,string* first)//构造分析表，P为文法G的产生式构成的集合
{
    int i,j,p,q;
    string arfa;//记录规则右部
    string fir,follow;
    string FOLLOW[5]={")#",")#","+)#","+)#","+*)#"};
    string **table=new string*[n];
    for(i=0;i<n;i++) table[i]=new string[t+1];
    for(i=0;i<n;i++)
      for(j=0;j<t+1;j++)
             table[i][j]="          ";//table存储分析表的元素，“       ”表示error
    for(i=0;i<k;i++)
   {
      arfa=P[i];
      arfa.erase(0,4);//删除前个字符，如：E::=E+T,则arfa="E+T"
      fir=FIRST(U,u,first,arfa);
      for(j=0;j<t;j++)
      {
           p=U.find(P[i][0]);
          if(fir.find(u[j])!=string::npos)
          {
             q=j;
             table[p][q]=P[i];
          }//对first（）中的每一终结符置相应的规则
      }
      if(fir.find('^')!=string::npos)
      {
          follow=FOLLOW[p];//对规则左部求follow()
          for(j=0;j<t;j++)
          {
           if((q=follow.find(u[j]))!=string::npos)
          {
              q=j;
             table[p][q]=P[i];
          }//对follow（）中的每一终结符置相应的规则
          }
          table[p][t]=P[i];//对#所在元素置相应规则
      }
   }
    return table;
  }
  void analyse(string **table,string U,string u,int t,string s)//分析符号串s
  {
      string stack;//分析栈
      string ss=s;//记录原符号串
      char x;//栈顶符号
      char a;//下一个要输入的字符
      int flag=0;//匹配成功标志
      int i=0,j=0,step=1;//符号栈计数、输入串计数、步骤数
      int p,q,r;
      string temp;
      for(i=0;!s[i];i++)
      {
          if(u.find(s[i])==string::npos)//出现非法的符号
             cout<<s<<"不是该文法的句子\n";
             return;
      }
      s.append(1,'#');
      stack.append(1,'#');//’#’进入分析栈
      stack.append(1,U[0]);i++;//文法开始符进入分析栈
      a=s[0];
      //cout<<stack<<endl;
      cout<<"步骤     分析栈         余留输入串        所用产生式\n";
      while(!flag)
      {
         // cout<<"步骤     分析栈           余留输入串        所用产生式\n"
          cout<<step<<"         "<<stack<<"               "<<s<<"                 ";
          x=stack[i];stack.erase(i,1);i--;//取栈顶符号x,并从栈顶退出
          //cout<<x<<endl;
          if(u.find(x)!=string::npos)//x是终结符的情况
          {
              if(x==a)
              {
               s.erase(0,1);a=s[0];//栈顶符号与当前输入符号匹配，则输入下一个符号
               cout<<"    \n";//未使用产生式，输出空
              }
              else
              {
                cout<<"error\n";
                cout<<ss<<"不是该文法的句子\n";
                break;
              }
          }
          if(x=='#')
          {
              if(a=='#')  {flag=1;cout<<"成功\n";}//栈顶和余留输入串都为#，匹配成功
              else
              {
                cout<<"error\n";
                cout<<ss<<"不是该文法的句子\n";
                break;
              }
          }
          if(U.find(x)!=string::npos)//x是非终结符的情况
          {
              p=U.find(x);
              q=u.find(a);
              if(a=='#') q=t;
              temp=table[p][q];
              cout<<temp<<endl;//输出使用的产生式
              if(temp[0]!=' ')//分析表中对应项不为error
              {
                  r=9;
                  while(temp[r]==' ') r--;
                  while(r>3)
                  {
                      if(temp[r]!='^')
                      {
                         stack.append(1,temp[r]);//将X::=x1x2...的规则右部各符号压栈
                         i++;
                      }
                       r--;
                  }
              }
              else
              {
                cout<<"error\n";
                cout<<ss<<"不是该文法的句子\n";
                break;
              }
          }
       step++;
      }
      if(flag)  cout<<endl<<ss<<"是该文法的句子\n";
  }
int main()
{
    int i,j;
    string *G=new string[50];//文法G
    string *P=new string[50];//产生式集合P
    string U,u;//文法G非终结符集合U，终结符集合u
    int n,t,k;//非终结符、终结符个数,产生式数
    string *GG=new string[50];//消除左递归后的文法GG
    string *PP=new string[50];//文法GG的产生式集合PP
    string UU,uu;//文法GG非终结符集合U，终结符集合u
    int nn,tt,kk;//消除左递归后的非终结符、终结符个数,产生式数
    string** table;//分析表
    cout<<"                         欢迎使用LL(1)语法分析器!\n\n\n";
    cout<<"请输入文法（同一左部的规则在同一行输入，例如：E::=E+T|T；用^表示空串）\n";
    input_grammer(G);
    preprocess(G,P,U,u,n,t,k);
    cout<<"\n该文法有"<<n<<"个非终结符：\n";
    for(i=0;i<n;i++)  cout<<U[i];
    cout<<endl;
    cout<<"该文法有"<<t<<"个终结符：\n";
    for(i=0;i<t;i++)  cout<<u[i];
    cout<<"\n\n                          左递归检测与消除\n\n";
    if(eliminate_1(G,P,U,GG))
    {
      preprocess(GG,PP,UU,uu,nn,tt,kk);
      cout<<"该文法存在左递归！\n\n消除左递归后的文法:\n\n";
      for(i=0;i<nn;i++)  cout<<GG[i]<<endl;
      cout<<endl;
      cout<<"新文法有"<<nn<<"个非终结符：\n";
      for(i=0;i<nn;i++)  cout<<UU[i];
      cout<<endl;
      cout<<"新文法有"<<tt<<"个终结符：\n";
      for(i=0;i<tt;i++)  cout<<uu[i];
      cout<<endl;
      //cout<<"新文法有"<<kk<<"个产生式：\n";
      //for(i=0;i<kk;i++)  cout<<PP[i]<<endl;
    }
    else
    {cout<<"该文法不存在左递归\n";
    GG=G;PP=P;UU=U;uu=u;nn=n;tt=t;kk=k;
    }
      cout<<"                       求解FIRST集\n\n";
      int *empty=ifempty(PP,UU,kk,nn);
      string* first=FIRST_X(PP,UU,uu,empty,kk,nn);
      string FOLLOW[5]={")#",")#","+)#","+)#","+*)#"};
      for(i=0;i<nn;i++)
           cout<<"FIRST("<<UU[i]<<"):   "<<first[i]<<endl;
     cout<<"                       求解FOLLOW集\n\n";
     for(i=0;i<nn;i++)
           cout<<"FOLLOW("<<UU[i]<<"):   "<<FOLLOW[i]<<endl;
    cout<<"\n\n                          构造文法分析表\n\n";
    table=create_table(PP,UU,uu,nn,tt,kk,first);
      cout<<"     ";
      for(i=0;i<tt;i++) cout<<"   "<<uu[i]<<"      ";
      cout<<"#        "<<endl;
      for( i=0;i<nn;i++)
      {
          cout<<UU[i]<<"    ";
          for(j=0;j<t+1;j++)
              cout<<table[i][j];
          cout<<endl;
      }
      cout<<"\n\n                         分析符号串\n\n";
      string s;
      cout<<"请输入要分析的符号串\n";
      cin>>s;
      analyse(table,UU,uu,tt,s);
return 0;
}