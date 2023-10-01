#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int x;
	do
	{
		cout << "Type number" << endl;
		cin >> x;
		if (x==0 and !cin.fail()){
			break;
		}
		if (cin.fail())
		{
			cout << "error, not number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} 
	while (x==0);
	cout << "Hello word" << endl;
	return 0;
}

