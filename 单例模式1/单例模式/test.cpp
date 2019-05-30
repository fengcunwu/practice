#include "Head.hpp"

using namespace std;

int main()
{
	CSingleton* s1 = CSingleton::GetInstance();
	s1->p();
	cout << s1 << endl;
	CSingleton* s2 = CSingleton::GetInstance();
	s2->p();
	cout << s2 << endl;
	system("pause");
	return 0;
}