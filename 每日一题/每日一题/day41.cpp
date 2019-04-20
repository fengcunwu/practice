#include"Head.hpp"

int atoi(string c)
{
	int len = c.length();
	int res = 0;
	int i = 0;
	for (i = 0; i<len; i++){
		res = res * 10 + (c[i] - '0');
	}
	return res;
}

//Å£¿ÍÍø-----emacs¼ÆËãÆ÷
void retResult()
{
	int n;
	string c;
	string sign = "+-*/";
	while (cin >> n){
		stack<int> ss;
		int a, b;
		while (n--){
			cin >> c;
			if (sign.find(c) == string::npos){
				ss.push(atoi(c));
				continue;
			}
			else{
				a = ss.top();
				ss.pop();
				b = ss.top();
				ss.pop();
				if (c == "+")
					ss.push(a + b);
				else if (c == "-")
					ss.push(b - a);
				else if (c == "*")
					ss.push(a*b);
				else
					ss.push(b / a);
			}
		}
		int res = ss.top();
		ss.pop();
		cout << res << endl;
	}
}