#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

//???????G,n????????
void input_grammer(string *G) { 
    int i = 0; //????
    char ch = 'y';
    while (ch == 'y') {
        cin >> G[i++];
        cout << "?????????(y/n)\n";
        cin >> ch;
    }
}

//?????G??????????????P??????????????????U??u??
void preprocess(string *G, string *P, string &U, string &u, int &n, int &t, int &k) {
    int i, j, r, temp; //????
    char C;            //????????��?????????
    int flag;          //???????
    n = t = k = 0;
    for (i = 0; i < 50; i++)
        P[i] = "          ";        //??????????????????????P[i][j]=a???????????????P[i].append(1,a)
    U = u = "                    "; //???????????????????????U[i]=a???????????U.append(1,a)
    for (n = 0; !G[n].empty(); n++) {
        U[n] = G[n][0];
    } //???????????n???????????
    for (i = 0; i < n; i++) {
        for (j = 4; j < G[i].length(); j++) {
            if (U.find(G[i][j]) == string::npos && u.find(G[i][j]) == string::npos)
                if (G[i][j] != '|' && G[i][j] != '^')
                    //if(G[i][j]!='('&&G[i][j]!=')'&&G[i][j]!='|'&&G[i][j]!='^')
                    u[t++] = G[i][j];
        }
    } //?????????t?????????
    for (i = 0; i < n; i++) {
        flag = 0;
        r = 4;
        for (j = 4; j < G[i].length(); j++) {
            P[k][0] = U[i];
            P[k][1] = ':';
            P[k][2] = ':';
            P[k][3] = '=';
            /* if(G[i][j]=='(')
          {    j++;flag=1;
               for(temp=j;G[i][temp]!=')';temp++);
               C=G[i][temp+1];
               //C???????????????????C????????????????????????
           }
          if(G[i][j]==')') {j++;flag=0;}
        */
            if (G[i][j] == '|') {
                //if(flag==1) P[k][r++]=C;
                k++;
                j++;
                P[k][0] = U[i];
                P[k][1] = ':';
                P[k][2] = ':';
                P[k][3] = '=';
                r = 4;
                P[k][r++] = G[i][j];
            }
            else {
                P[k][r++] = G[i][j];
            }
        }
        k++;
    } //??��????????P??k??????????
}

//???????G1??????????????????G2?????????????��????????????
int eliminate_1(string *G, string *P, string U, string *GG) {
    string arfa, beta;     //????????A::=A??|???��???????????????��???????arfa??beta
    int i, j, temp, m = 0; //????
    int flag = 0;          //flag=1????????????
    int flagg = 0;         //flagg=1????????????????
    char C = 'A';          //???????????????????????????A????????????????????????????��??????
    for (i = 0; i < 20 && U[i] != ' '; i++) {
        flagg = 0;
        arfa = beta = "";
        for (j = 0; j < 100 && P[j][0] != ' '; j++) {
            if (P[j][0] == U[i]) {
                //?????j??????
                if (P[j][4] == U[i]) {
                    flagg = 1;
                    for (temp = 5; P[j][temp] != ' '; temp++)
                        arfa.append(1, P[j][temp]);
                    if (P[j + 1][4] == U[i])
                        arfa.append("|"); //???????????????????
                }
                else {
                    for (temp = 4; P[j][temp] != ' '; temp++)
                        beta.append(1, P[j][temp]);
                    if (P[j + 1][0] == U[i] && P[j + 1][4] != U[i])
                        beta.append("|");
                }
            }
        }
        //?????????????????????��
        if (flagg == 0) {
            GG[m] = G[i];
            m++;
        }
        else {
            flag = 1; //???????????
            GG[m].append(1, U[i]);
            GG[m].append("::=");
            if (beta.find('|') != string::npos)
                GG[m].append("(" + beta + ")");
            else
                GG[m].append(beta);
            while (U.find(C) != string::npos) {
                C++;
            }
            GG[m].append(1, C);
            m++;
            GG[m].append(1, C);
            GG[m].append("::=");
            if (arfa.find('|') != string::npos)
                GG[m].append("(" + arfa + ")");
            else
                GG[m].append(arfa);
            GG[m].append(1, C);
            GG[m].append("|^");
            m++;
            C++;
        } //A::=A??|???��??A::=??A????A??=??A'|???
    }
    return flag;
}

int *ifempty(string *P, string U, int k, int n) {
    int *empty = new int[n]; //???????????????????
    int i, j, r;
    for (r = 0; r < n; r++)
        empty[r] = 0; //??????��??????????????????
    int flag = 1;     //1???empty?????????
    int step = 100;   //????????????????????????
    while (step--) {
        for (i = 0; i < k; i++) {
            r = U.find(P[i][0]);
            if (P[i][4] == '^')
                empty[r] = 1; //??????????
            else {
                for (j = 4; P[i][j] != ' '; j++) {
                    if (U.find(P[i][j]) != string::npos) {
                        if (empty[U.find(P[i][j])] == 0)
                            break;
                    }
                    else
                        break;
                }
                if (P[i][j] == ' ')
                    empty[r] = 1; //?????????
                else
                    flag = 0;
            }
        }
    }
    return empty;
}

string *FIRST_X(string *P, string U, string u, int *empty, int k, int n) {
    int i, j, r, s, tmp;
    string *first = new string[n];
    char a;
    int step = 100; //??????????
    while (step--) {
        // cout<<"step"<<100-step<<endl;
        for (i = 0; i < k; i++) {
            //cout<<P[i]<<endl;
            r = U.find(P[i][0]);
            if (P[i][4] == '^' && first[r].find('^') == string::npos) {
                first[r].append(1, '^'); //???????????????
            }
            else {
                for (j = 4; P[i][j] != ' '; j++) {
                    a = P[i][j];
                    //??????????????????
                    if (u.find(a) != string::npos && first[r].find(a) == string::npos) {
                        first[r].append(1, a);
                        break; //?????????
                    }
                    //???????????????????,????X????=Y1Y2...Yk
                    if (U.find(P[i][j]) != string::npos) {
                        s = U.find(P[i][j]);
                        //cout<<P[i][j]<<":\n";
                        for (tmp = 0; first[s][tmp] != '\0'; tmp++) {
                            a = first[s][tmp];
                            if (a != '^' && first[r].find(a) == string::npos) //??FIRST[Y1]?��????????
                                first[r].append(1, a);
                        }
                    }
                    if (!empty[s])
                        break; //??Y1????????????????
                }
                if (P[i][j] == ' ')
                    if (first[r].find('^') == string::npos)
                        first[r].append(1, '^'); //??Y1??Y2...Yk?????????????????????
            }
        }
    }
    return first;
}

//??????s=X1X2...Xn??FIRST??
string FIRST(string U, string u, string *first, string s) {
    int i, j, r;
    char a;
    string fir;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == '^')
            fir.append(1, '^');
        if (u.find(s[i]) != string::npos && fir.find(s[i]) == string::npos) {
            fir.append(1, s[i]);
            break;
        }                                 //X1????????????????????
        //X1???????
        if (U.find(s[i]) != string::npos) {
            r = U.find(s[i]);
            for (j = 0; first[r][j] != '\0'; j++) {
                a = first[r][j];
                if (a != '^' && fir.find(a) == string::npos) //??FIRST(X1)?��?????????
                    fir.append(1, a);
            }
            if (first[r].find('^') == string::npos)
                break; //??X1?????????????????
        }
        if (i == s.length())                    //??X1-Xk???????????
            if (fir.find(s[i]) == string::npos) //fir?��?��????????
                fir.append(1, '^');
    }
    return fir;
}

//???????????P????G??????????????
string **create_table(string *P, string U, string u, int n, int t, int k, string *first) {
    int i, j, p, q;
    string arfa; //??????????
    string fir, follow;
    string FOLLOW[5] = {")#", ")#", "+)#", "+)#", "+*)#"};
    string **table = new string *[n];
    for (i = 0; i < n; i++)
        table[i] = new string[t + 1];
    for (i = 0; i < n; i++)
        for (j = 0; j < t + 1; j++)
            table[i][j] = "          "; //table?��??????????????       ?????error
    for (i = 0; i < k; i++) {
        arfa = P[i];
        arfa.erase(0, 4); //????????????��E::=E+T,??arfa="E+T"
        fir = FIRST(U, u, first, arfa);
        for (j = 0; j < t; j++) {
            p = U.find(P[i][0]);
            if (fir.find(u[j]) != string::npos) {
                q = j;
                table[p][q] = P[i];
            } //??first?????��?????????????????
        }
        if (fir.find('^') != string::npos) {
            follow = FOLLOW[p]; //?????????follow()
            for (j = 0; j < t; j++) {
                if ((q = follow.find(u[j])) != string::npos)
                {
                    q = j;
                    table[p][q] = P[i];
                } //??follow?????��?????????????????
            }
            table[p][t] = P[i]; //??#????????????????
        }
    }
    return table;
}

//?????????s
void analyse(string **table, string U, string u, int t, string s) {
    string stack;               //?????
    string ss = s;              //?????????
    char x;                     //???????
    char a;                     //??????????????
    int flag = 0;               //????????
    int i = 0, j = 0, step = 1; //???????????????????????????
    int p, q, r;
    string temp;
    for (i = 0; !s[i]; i++) {
        if (u.find(s[i]) == string::npos) //???????????
            cout << s << "?????????????\n";
        return;
    }
    s.append(1, '#');
    stack.append(1, '#'); //??#??????????
    stack.append(1, U[0]);
    i++; //????????????????
    a = s[0];
    //cout<<stack<<endl;
    cout << "????     ?????         ????????        ???��????\n";
    while (!flag) {
        // cout<<"????     ?????           ????????        ???��????\n"
        cout << step << "         " << stack << "               " << s << "                 ";
        x = stack[i];
        stack.erase(i, 1);
        i--; //????????x,??????????
        //cout<<x<<endl;
        //x???????????
        if (u.find(x) != string::npos) {
            if (x == a) {
                s.erase(0, 1);
                a = s[0];         //???????????????????????????????????
                cout << "    \n"; //��??��???????????
            }
            else {
                cout << "error\n";
                cout << ss << "?????????????\n";
                break;
            }
        }
        if (x == '#') {
            if (a == '#') {
                flag = 1;
                cout << "???\n";
            } //????????????????#???????
            else {
                cout << "error\n";
                cout << ss << "?????????????\n";
                break;
            }
        }
        //x????????????
        if (U.find(x) != string::npos) {
            p = U.find(x);
            q = u.find(a);
            if (a == '#')
                q = t;
            temp = table[p][q];
            cout << temp << endl; //???????????
            //???????��?????error
            if (temp[0] != ' ') {
                r = 9;
                while (temp[r] == ' ')
                    r--;
                while (r > 3) {
                    if (temp[r] != '^') {
                        stack.append(1, temp[r]); //??X::=x1x2...????????????????
                        i++;
                    }
                    r--;
                }
            }
            else {
                cout << "error\n";
                cout << ss << "can'.'t\n";
                break;
            }
        }
        step++;
    }
    if (flag)
        cout << endl
             << ss << "can \n";
}

int main() {
    int i, j;
    string *G = new string[50];  //???G
    string *P = new string[50];  //?????????P
    string U, u;                 //???G??????????U??????????u
    int n, t, k;                 //????????????????,???????
    string *GG = new string[50]; //?????????????GG
    string *PP = new string[50]; //???GG??????????PP
    string UU, uu;               //???GG??????????U??????????u
    int nn, tt, kk;              //?????????????????????????,???????
    string **table;              //??????
    cout << "                         LL(1)!\n\n\n";
    cout << "\n";
    input_grammer(G);
    preprocess(G, P, U, u, n, t, k);
    cout << "\nhas" << n << "Vn\n";
    for (i = 0; i < n; i++)
        cout << U[i];
    cout << endl;
    cout << "has" << t << "Vt\n";
    for (i = 0; i < t; i++)
        cout << u[i];
    cout << "\n\n                          Left\n\n";
    if (eliminate_1(G, P, U, GG)) {
        preprocess(GG, PP, UU, uu, nn, tt, kk);
        cout << "has Left\n\nAfter remove Left:\n\n";
        for (i = 0; i < nn; i++)
            cout << GG[i] << endl;
        cout << endl;
        cout << "has " << nn << " Vn\n";
        for (i = 0; i < nn; i++)
            cout << UU[i];
        cout << endl;
        cout << "has " << tt << " Vt\n";
        for (i = 0; i < tt; i++)
            cout << uu[i];
        cout << endl;
        //cout<<"???????"<<kk<<"?????????\n";
        //for(i=0;i<kk;i++)  cout<<PP[i]<<endl;
    }
    else {
        cout << "not left\n";
        GG = G;
        PP = P;
        UU = U;
        uu = u;
        nn = n;
        tt = t;
        kk = k;
    }
    cout << "                       get FIRST\n\n";
    int *empty = ifempty(PP, UU, kk, nn);
    string *first = FIRST_X(PP, UU, uu, empty, kk, nn);
    string FOLLOW[5] = {")#", ")#", "+)#", "+)#", "+*)#"};
    for (i = 0; i < nn; i++)
        cout << "FIRST(" << UU[i] << "):   " << first[i] << endl;
    cout << "                      get FOLLOW\n\n";
    for (i = 0; i < nn; i++)
        cout << "FOLLOW(" << UU[i] << "):   " << FOLLOW[i] << endl;
    cout << "\n\n                          table\n\n";
    table = create_table(PP, UU, uu, nn, tt, kk, first);
    cout << "     ";
    for (i = 0; i < tt; i++)
        cout << "   " << uu[i] << "      ";
    cout << "#        " << endl;
    for (i = 0; i < nn; i++) {
        cout << UU[i] << "    ";
        for (j = 0; j < t + 1; j++)
            cout << table[i][j];
        cout << endl;
    }
    cout << "\n\n                         Analyse\n\n";
    string s;
    cout << input string \n";
    cin >> s;
    analyse(table, UU, uu, tt, s);
    return 0;
}