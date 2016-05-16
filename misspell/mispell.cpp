#include <iostream>
#include <string>
using namespace std;

class missSpell
{
public:
	int order;
	string missStr;
};
string RemovemissSpel(missSpell input)
{
	int length = input.missStr.length();
	int j = 0;
	string result = "";
	for (int i = 0; i<length; i++)
	{
		if (i + 1 == input.order)
			continue;
		result += input.missStr[i];
		j++;
	}//»õ¹öÀüÀ» À§ÇÑ ÁÖ¼®
	return result;
}
int main()
{
	int count = 0;
	missSpell *practice;
	//cout<<"Input the number of datasets (1<=N<=1000) : ";
	cin >> count;
	while (!(count >= 1 && count <= 1000))
	{
		count = 0;
		//  cout<<"Please input the number higher than or equal to 1 lower than or equal to 1000."<<endl;
		cout << endl;
		// cout<<"Input the number of datasets (1<=N<=1000) : "<<endl;
		cin >> count;
	}
	practice = new missSpell[count];
	for (int i = 0; i<count; i++)
	{
		cin >> practice[i].order;
		cin >> practice[i].missStr;
		while (practice[i].order > practice[i].missStr.length() || practice[i].order < 1)
		{
			practice[i].order = 0;
			practice[i].missStr = "";
			// cout<<"Cotradictory Input"<<endl;
			// cout<<"Please type another input"<<endl;
			cin >> practice[i].order;
			cin >> practice[i].missStr;
		}
	}
	// this is the place main misspelling have to be  accessed
	string temp;
	for (int i = 0; i<count; i++)
	{
		temp = RemovemissSpel(practice[i]);
		practice[i].missStr = temp;
	}
	cout << endl;
	for (int i = 0; i<count; i++)
	{
		cout << i + 1 << " " << practice[i].missStr << endl;
	}

	return 0;
}
