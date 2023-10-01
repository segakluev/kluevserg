#include <iostream>


using namespace std;
int main() {
	int chislo;
	cout << "1.Add pipe" << endl;
	cout << "2.Add KS" << endl;
	cout << "3.View all objects" << endl;
	cout << "4.Edit pipe" << endl;
	cout << "5.Edit KS" << endl;
	cout << "6.Save" << endl;
	cout << "7.Load" << endl;
	cout << "0.Exit" << endl;
	cout << "Enter number:"<<endl;
	cin >> chislo;
	switch (chislo)
		{
		case 0: return 3;break;
		//case 1: truba();break;
		}
	return 0;
}

