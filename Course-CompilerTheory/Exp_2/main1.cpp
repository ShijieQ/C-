#include<bits/stdc++.h>

using namespace std;
string *grammar;  //文法G
string *grammarSet;  //产生式集合
string Vn, Vt;                 //文法非终结符集合、终结符集合
int numOfVn, numOfVt, numOfG;     //非终结符、终结符个数,产生式数
string *grammarAfter; //消除左递归后的新文法
string *grammarSetAfter; //新文法的产生式集合PP
string VnAfter, VtAfter; //新文法的非终结符集合、终结符集合
int numOfVnAfter, numOfVtAfter, numOfGAfter;      //消除左递归后的非终结符、终结符个数、产生式数
string **table;              //分析表

void init() {
    grammar = new string[50];
    grammarSet = new string[50];
    grammarAfter = new string[50];
    grammarSetAfter = new string[50];
}

void read() {
    int num;
    cout<<"Please input the number of grammar:";
    cin>>num;
    for (int i = 0; i < num; i++) {
        cin>>grammar[i];
    }
}

void preWork() {
    char C;
    int flag;
    numOfVn = numOfVt = numOfG = 0;
    for (int i = 0; i < 50; i++)
        grammarSet[i] = "          ";
    Vn = Vt = "                    ";
    for (numOfVn = 0; !grammar[numOfVn].empty(); numOfVn++) {
        Vn[numOfVn] = grammar[numOfVn][0];
    }
    for (int i = 0; i < numOfVn; i++) {
        for (int j = 4; j < grammar[i].length(); j++) {
            if (Vn.find(grammar[i][j]) == string::npos && Vt.find(grammar[i][j]) == string::npos)
                if (grammar[i][j] != '|' && grammar[i][j] != '^')
                    Vt[numOfVt++] = grammar[i][j];
        }
    }
    for (int i = 0; i < numOfVn; i++, numOfG++) {
        flag = 0;
        int r = 4;
        for (int j = 4; j < grammar[i].length(); j++) {
            grammarSet[numOfG][0] = Vn[i];
            grammarSet[numOfG][1] = ':';
            grammarSet[numOfG][2] = ':';
            grammarSet[numOfG][3] = '=';
            if (grammar[i][j] == '|') {
                numOfG++; j++;
                grammarSet[numOfG][0] = Vn[i];
                grammarSet[numOfG][1] = ':';
                grammarSet[numOfG][2] = ':';
                grammarSet[numOfG][3] = '=';
                r = 4;
                grammarSet[numOfG][r++] = grammar[i][j];
            }
            else {
                grammarSet[numOfG][r++] = grammar[i][j];
            }
        }
    }
}

void anotherPreWork() {
    char C;
    int flag;
    numOfVnAfter = numOfVtAfter = numOfGAfter = 0;
    for (int i = 0; i < 50; i++)
        grammarSetAfter[i] = "          ";
    VnAfter = VtAfter = "                    ";
    for (numOfVnAfter = 0; !grammarAfter[numOfVnAfter].empty(); numOfVnAfter++) {
        VnAfter[numOfVnAfter] = grammarAfter[numOfVnAfter][0];
    }
    for (int i = 0; i < numOfVnAfter; i++) {
        for (int j = 4; j < grammarAfter[i].length(); j++) {
            if (VnAfter.find(grammarAfter[i][j]) == string::npos && VtAfter.find(grammarAfter[i][j]) == string::npos)
                if (grammarAfter[i][j] != '|' && grammarAfter[i][j] != '^')
                    VtAfter[numOfVtAfter++] = grammarAfter[i][j];
        }
    }
    for (int i = 0; i < numOfVnAfter; i++, numOfGAfter++) {
        flag = 0;
        int r = 4;
        for (int j = 4; j < grammarAfter[i].length(); j++) {
            grammarSetAfter[numOfGAfter][0] = VnAfter[i];
            grammarSetAfter[numOfGAfter][1] = ':';
            grammarSetAfter[numOfGAfter][2] = ':';
            grammarSetAfter[numOfGAfter][3] = '=';
            if (grammarAfter[i][j] == '|') {
                numOfGAfter++; j++;
                grammarSetAfter[numOfGAfter][0] = VnAfter[i];
                grammarSetAfter[numOfGAfter][1] = ':';
                grammarSetAfter[numOfGAfter][2] = ':';
                grammarSetAfter[numOfGAfter][3] = '=';
                r = 4;
                grammarSetAfter[numOfGAfter][r++] = grammarAfter[i][j];
            }
            else {
                grammarSetAfter[numOfGAfter][r++] = grammarAfter[i][j];
            }
        }
    }
}

int remove() {
    string arfa, beta;
    int m = 0;
    int hasLeftRecursion = 0, hasLeftRecursionInRuler = 0;
    char C = 'A';
    for (int i = 0; i < 20 && Vn[i] != ' '; i++) {
        hasLeftRecursionInRuler = 0;
        arfa = beta = "";
        for (int j = 0; j < 100 && grammarSet[j][0] != ' '; j++) {
            if (grammarSet[j][0] == Vn[i]) {
                if (grammarSet[j][4] == Vn[i]) {
                    hasLeftRecursionInRuler = 1;
                    for (int temp = 5; grammarSet[j][temp] != ' '; temp++)
                        arfa.append(1, grammarSet[j][temp]);
                    if (grammarSet[j + 1][4] == Vn[i])
                        arfa.append("|");
                }
                else {
                    for (int temp = 4; grammarSet[j][temp] != ' '; temp++)
                        beta.append(1, grammarSet[j][temp]);
                    if (grammarSet[j + 1][0] == Vn[i] && grammarSet[j + 1][4] != Vn[i])
                        beta.append("|");
                }
            }
        }
        if (hasLeftRecursionInRuler == 0) {
            grammarAfter[m] = grammar[i];
            m++;
        }
        else {
            hasLeftRecursion = 1;
            grammarAfter[m].append(1, Vn[i]);
            grammarAfter[m].append("::=");
            if (beta.find('|') != string::npos)
                grammarAfter[m].append("(" + beta + ")");
            else
                grammarAfter[m].append(beta);
            while (Vn.find(C) != string::npos) {
                C++;
            }
            grammarAfter[m].append(1, C);
            m++;
            grammarAfter[m].append(1, C);
            grammarAfter[m].append("::=");
            if (arfa.find('|') != string::npos)
                grammarAfter[m].append("(" + arfa + ")");
            else
                grammarAfter[m].append(arfa);
            grammarAfter[m].append(1, C);
            grammarAfter[m].append("|^");
            m++, C++;
        } //A::=Aα|β改写成A::=βA‘，A’=αA'|β，
    }
    return hasLeftRecursion;
}

int *ifempty() {
    int *empty = new int[numOfVnAfter];
    for (int r = 0; r < numOfVnAfter; r++)
        empty[r] = 0;
    int flag = 1;
    int maxDeduction = 100;
    while (maxDeduction--) {
        for (int i = 0; i < numOfGAfter; i++) {
            int r = Vn.find(grammarSetAfter[i][0]);
            if (grammarSetAfter[i][4] == '^')
                empty[r] = 1;
            else {
                int j;
                for (j = 4; grammarSetAfter[i][j] != ' '; j++) {
                    if (VnAfter.find(grammarSetAfter[i][j]) != string::npos) {
                        if (empty[VnAfter.find(grammarSetAfter[i][j])] == 0)
                            break;
                    }
                    else
                        break;
                }
                if (grammarSetAfter[i][j] == ' ')
                    empty[r] = 1;
                else
                    flag = 0;
            }
        }
    }
    return empty;
}

string *FIRST_X(int *empty) {
    string *first = new string[numOfVnAfter];
    int maxDeduction = 100;
    while (maxDeduction--) {
        for (int i = 0; i < numOfGAfter; i++) {
            int r = Vn.find(grammarSetAfter[i][0]);
            if (grammarSetAfter[i][4] == '^' && first[r].find('^') == string::npos) {
                first[r].append(1, '^');
            }
            else {
                int j;
                for (j = 4; grammarSetAfter[i][j] != ' '; j++) {
                    char a = grammarSetAfter[i][j];
                    int s;
                    if (VtAfter.find(a) != string::npos && first[r].find(a) == string::npos) {
                        first[r].append(1, a);
                        break;
                    }
                    if (VnAfter.find(grammarSetAfter[i][j]) != string::npos) {
                        s = VnAfter.find(grammarSetAfter[i][j]);
                        for (int tmp = 0; first[s][tmp] != '\0'; tmp++) {
                            a = first[s][tmp];
                            if (a != '^' && first[r].find(a) == string::npos)
                                first[r].append(1, a);
                        }
                    }
                    if (!empty[s])
                        break;
                }
                if (grammarSetAfter[i][j] == ' ')
                    if (first[r].find('^') == string::npos)
                        first[r].append(1, '^');
            }
        }
    }
    return first;
}

string getFIRST(string *first, string s) {
    string fir;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '^')
            fir.append(1, '^');
        if (Vt.find(s[i]) != string::npos && fir.find(s[i]) == string::npos) {
            fir.append(1, s[i]);
            break;
        }
        if (Vn.find(s[i]) != string::npos) {
            int r = Vn.find(s[i]);
            for (int j = 0; first[r][j] != '\0'; j++) {
                char a = first[r][j];
                if (a != '^' && fir.find(a) == string::npos)
                    fir.append(1, a);
            }
            if (first[r].find('^') == string::npos)
                break;
        }
        if (i == s.length())
            if (fir.find(s[i]) == string::npos)
                fir.append(1, '^');
    }
    return fir;
}

string **getTable(string *first) {
    int p, q;
    string FOLLOW[5] = {")#", ")#", "+)#", "+)#", "+*)#"};
    string **table = new string *[numOfVnAfter];
    for (int i = 0; i < numOfVnAfter; i++)
        table[i] = new string[numOfVtAfter + 1];
    for (int i = 0; i < numOfVnAfter; i++)
        for (int j = 0; j < numOfVtAfter + 1; j++)
            table[i][j] = "          ";
    for (int i = 0; i < numOfGAfter; i++) {
        string arfa = grammarSetAfter[i];
        arfa.erase(0, 4);
        string fir = getFIRST(first, arfa);
        for (int j = 0; j < numOfVtAfter; j++) {
            p = VnAfter.find(grammarSetAfter[i][0]);
            if (fir.find(VtAfter[j]) != string::npos) {
                q = j;
                table[p][q] = grammarSetAfter[i];
            }
        }
        if (fir.find('^') != string::npos) {
            string follow = FOLLOW[p];
            for (int j = 0; j < numOfVtAfter; j++) {
                if ((q = follow.find(VtAfter[j])) != string::npos) {
                    q = j;
                    table[p][q] = grammarSetAfter[i];
                }
            }
            table[p][numOfVtAfter] = grammarSetAfter[i];
        }
    }
    return table;
}

void analyse(string s) {
    string stack;
    string sBefore = s;
    char top, next;
    int flag = 0;
    int i = 0, j = 0, step = 1; //符号栈计数、输入串计数、步骤数
    
    for (i = 0; !s[i]; i++) {
        if (VtAfter.find(s[i]) == string::npos)
            cout<<s<<" can't match.\n";
        return;
    }
    
    s.append(1, '#');
    stack.append(1, '#');
    stack.append(1, Vn[0]);
    i++;
    next = s[0];
      cout<<"step     AnalyseStack       Input             Used\n";
    while (!flag) {
        cout << step << "         " << stack << "               " << s << "                 ";
        top = stack[i];
        stack.erase(i, 1);
        i--;
        if (VtAfter.find(top) != string::npos) {
            if (top == next) {
                s.erase(0, 1);
                next = s[0];
                cout<<"    "<<endl;
            }
            else {
                cout<<"error"<<endl;
                cout << sBefore << " can't match.\n";
                break;
            }
        }
        if (top == '#') {
            if (next == '#') {
                flag = 1;
                cout << "Success.\n";
            }
            else {
                cout << "error\n";
                cout << sBefore << " can't match.\n";
                break;
            }
        }
        if (VnAfter.find(top) != string::npos) {
            int p = VnAfter.find(top), q = VtAfter.find(next);
            if (next == '#')
                q = numOfVtAfter;
            string temp = table[p][q];
            cout << temp << endl;
            if (temp[0] != ' ') {
                int r = 9;
                while (temp[r] == ' ')
                    r--;
                while (r > 3) {
                    if (temp[r] != '^') {
                        stack.append(1, temp[r]);
                        i++;
                    }
                    r--;
                }
            }
            else {
                cout << "error\n";
                cout << sBefore << " can't match.\n";
                break;
            }
        }
        step++;
    }
    if (flag)
        cout<<endl<< sBefore<<" can match.\n";
}

int main() {
    init();
    int i, j;
    cout<<"Input eg. E::=E+T|T\n";
    read();
    preWork();
    cout<<"\n\nVn :";
    for (i = 0; i < numOfVn; i++)
        cout << Vn[i];
    cout << endl;
    cout<<"\n\nVt :";
    for (i = 0; i < numOfVt; i++)
        cout << Vt[i];
    cout << "\n\n                          左递归检测与消除\n\n";
    if (remove()) {
        anotherPreWork();
        cout<<"It has Left recursion.\n\nAfter dealing:\n\n";
        for (i = 0; i < numOfVnAfter; i++)
            cout << grammarAfter[i] << endl;
        cout << endl;
        cout<<"\n\nVn :";
        for (i = 0; i < numOfVnAfter; i++)
            cout << VnAfter[i];
        cout << endl;
        cout<<"\n\nVt :";
        for (i = 0; i < numOfVtAfter; i++)
            cout << VtAfter[i];
        cout << endl;
    }
    else {
        cout<<"It doesn't have Left recursion.\n";
        grammarAfter = grammar;
        grammarSetAfter = grammarSet;
        VnAfter = Vn;
        VtAfter = Vt;
        numOfVnAfter = numOfVn;
        numOfVtAfter = numOfVt;
        numOfGAfter = numOfG;
    }
    cout<<"\n\nFirst Set:"<<endl;
    int *empty = ifempty();
    string *first = FIRST_X(empty);
    string FOLLOW[5] = {")#", ")#", "+)#", "+)#", "+*)#"};
    for (i = 0; i < numOfVnAfter; i++)
        cout << "FIRST(" << VnAfter[i] << "):   " << first[i] << endl;
    cout<<"\n\nFollow Set:"<<endl;
    for (i = 0; i < numOfVnAfter; i++)
        cout << "FOLLOW(" << VnAfter[i] << "):   " << FOLLOW[i] << endl;
    cout << "\n\n                          构造文法分析表\n\n";
    table = getTable(first);
    cout << "     ";
    for (i = 0; i < numOfVtAfter; i++)
        cout << "   " << VtAfter[i] << "      ";
    cout << "#        " << endl;
    for (i = 0; i < numOfVnAfter; i++) {
        cout << VnAfter[i] << "    ";
        for (j = 0; j < numOfVt + 1; j++)
            cout << table[i][j];
        cout << endl;
    }
    cout<<"\n\n                          Analyse table\n\n";
    string s;
    cout<<"\n\nPlease input string:";
    cin >> s;
    cout<<endl;
    analyse(s);
    return 0;
}