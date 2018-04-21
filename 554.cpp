#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> dic;

int main() {
	int inter2 = 0, inter=0, l,comp,i;
	string str;
	while (getline(cin, str), str[0] != '#'){
		dic.insert(str);
	}
	getline(cin, str);
	string b;
	for (int k = 0; k < 27; k++){
		string x = str;
		for (int j = 0; j < x.length(); j++){
			if (isalpha(x[j])){//lettre?
				int inter=x[j]-'A'+1;
				if ((inter+k)%27){
					x[j]=(inter+k)%27+'A'-1;
				}
				else{
					x[j]=' ';
				}
			}
			else{
				int inter2=0;
				if ((k)%27){
					x[j]=(k)%27 + 'A' -1;
				}
				else{
					x[j]=' ';
				}
			}
		}
		inter2 = 0;
		for (int i = 0; i < x.length(); i += l+1){
			for (l = 1; i+l < x.length() && x[i+l] != ' '; l++){
				if (dic.find(x.substr(i, l)) != dic.end()){
					inter2++;
				}
			}
		}
		if (inter2 > inter){
			inter = inter2;
			b = x;
		}
	}
	comp = 0;
	string s = "";
	for (i = 0; i < b.length(); i += l+1){
		for (l = 1; i+l < b.length() && b[i+l] != ' '; l++);
		if (comp + l + s.length() > 60){
			cout << '\n';
			s = "";
			comp = 0;
		}
		comp += l + s.length();
		cout << s << b.substr(i, l);
		s = " ";
	}
	cout << '\n';
}
