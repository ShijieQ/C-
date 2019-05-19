#include<map>
#include<cmath>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

const int maxn = 1e5+10;
std::map<char, int> pin, pout;
std::map<char, bool> value;
std::string element;
std::string s, Postfix;
std::vector<std::string> DNF;
std::vector<std::string> CNF;
std::string _DNF;
std::string _CNF;
std::vector<std::string> NumDNF;
std::vector<std::string> NumCNF;

void init() {
	pout['#'] = 0;pin['#'] = 0;
	pout['('] = 12;pin['('] = 1;
	pout[')'] = 1;pin[')'] = 12;
	pout['!'] = 10;pin['!'] = 11;
	pout['&'] = 8;pin['&'] = 9;
	pout['|'] = 6;pin['|'] = 7;
	pout['>'] = 4;pin['>'] = 5;
	pout['<'] = 2;pin['<'] = 3;

}

void InfixToPostFix() {
	std::stack<char> cal;
	cal.push('#');
	int len = s.length();
	std::string ans;
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i]) || isalpha(s[i])) {
			ans = ans + s[i];
			value[s[i]] = false;
			if(element.find(s[i]) == -1){
				element = element + s[i];
			}
		}	
		else if (s[i] == ')') {
			char y = cal.top();
			cal.pop();
			while (y != '(' && !cal.empty()) {
				ans = ans + y;
				y = cal.top();
				cal.pop();
			}
		}
		else {
			char y = cal.top();
			cal.pop();
			while (pout[s[i]] <= pin[y]) {
				ans = ans + y;
				y = cal.top();
				cal.pop();
			}
			cal.push(y);
			cal.push(s[i]);
		}
	}
	while (!cal.empty()) {
		char y = cal.top();
		cal.pop();
		if(y != '#')
			ans = ans + y;
	}
	Postfix = ans;
}

int Calculate() {
	bool flag = true;
	std::stack<bool> a;
	int i = 0;
	while (flag && i < Postfix.length()) {
		switch (Postfix[i]) {
		case '!':
			bool temaa;
			if (a.empty()) {
				flag = false;
				break;
			}
			else {
				temaa = a.top();
				a.pop();
			}
			a.push(!temaa);
			break;
		case '&':
		case '|':
		case '>':
		case '<':
			bool tema, temb;
			if (a.empty()) {
				flag = false;
			}
			else {
				tema = a.top();
				a.pop();
			}
			if (a.empty()) {
				flag = false;
			}
			else {
				temb = a.top();
				a.pop();
			}
			if (!flag) {
				break;
			}
			switch (Postfix[i])
			{
			case '&':
				a.push(tema&&temb);
				break;
			case '|':
				a.push(tema||temb);
				break;
			case '>':
				a.push(!tema||temb);
				break;
			case '<':
				a.push((tema&&temb)||(!tema&&!temb));
				break;
			}
			break;
		default:
			a.push(value[Postfix[i]]);
			break;
		}
		i++;
	}
	if (!flag) {
		return -1;
	}
	if (a.size() != 1) {
		return -1;
	}
	return a.top();
}

int cas = 0;
void Calculate_ans(int k) {
	//std::cout<< ++cas<<std::endl;
	if(k == element.length()){
		int tem = Calculate();
		if(tem == -1)
			return ;
		if(tem){
			std::string D;
			std::string NumD;
			if(!value[element[0]]){
				D = D + "!";
			}
			D = D + element[0];
			for(int i = 1; i < element.length(); i++){
				D = D + "&";
				if(!value[element[i]]){
					D = D + "!";
				}
				D = D + element[i];
			}
			for(int i = 0; i < element.length(); i++){
				char tem = value[element[i]] == true ? 'T':'F';
				NumD = NumD + tem + " ";
			}
			NumD = NumD + "T";
			DNF.push_back(D);
			NumDNF.push_back(NumD);
		}
		else{
			std::string C;
			std::string NumC;
			if(value[element[0]]){
				C = C + "!";
			}
			C = C + element[0];
			for(int i = 1; i < element.length(); i++){
				C = C + "|";
				if(value[element[i]]){
					C = C + "!";
				}
				C = C + element[i];
			}
			for(int i = 0; i < element.length(); i++){
				char tem = value[element[i]] == true ? 'T':'F';
				NumC = NumC + tem + " ";
			}
			NumC = NumC + "F";
			CNF.push_back(C);
			NumCNF.push_back(NumC);
		}
		return ;
	}
	value[element[k]] = 0;
	Calculate_ans(k+1);
	value[element[k]] = 1;
	Calculate_ans(k+1);
}

void PrintAns(){
	Calculate_ans(0);
	if (DNF.empty() && CNF.empty()) {
		std::cout << "ERROR" << std::endl;
		_DNF = "ERROR";
		_CNF = "ERROR";
		return;
	}
	_DNF = _DNF + "(";
	_DNF = _DNF + DNF[0];
	_DNF = _DNF + ")";
	for (int i = 1; i < DNF.size(); i++) {
		_DNF = _DNF + "|";
		_DNF = _DNF + "(";
		_DNF = _DNF + DNF[i];
		_DNF = _DNF + ")";
	}
	_CNF = _CNF + "(";
	_CNF = _CNF + CNF[0];
	_CNF = _CNF + ")";
	for (int i = 1; i < CNF.size(); i++) {
		_CNF = _CNF + "&";
		_CNF = _CNF + "(";
		_CNF = _CNF + CNF[i];
		_CNF = _CNF + ")";
	}
}

std::string returnDNF(){
	return _DNF;
}

std::string returnCNF(){
	return _CNF;
}

void PrintNum(){
	for(int i = 0; i < element.length(); i++){
		std::cout<<element[i]<<" ";
	}
	std::cout<<s<<std::endl;
	for(int i = 0; i < NumDNF.size(); i++){
		std::cout<<NumDNF[i]<<std::endl;
	}
	for(int i = 0; i < NumCNF.size(); i++){
		std::cout<<NumCNF[i]<<std::endl;
	}
}

int main(){
	init();
	std::cin>>s;
	InfixToPostFix();
	PrintAns();
	std::cout<<returnDNF()<<std::endl<<returnCNF()<<std::endl;
	PrintNum();
	return 0;
}