//Given two numbers as strings.The numbers may be very large
//(may not fit in long long int),
//the task is to find sum of these two numbers.

#include <iostream>
#include <string>
using namespace std;


string findSum(string str1, string str2)
{

	// ensure m to be laways greater than n
	// so that str1 is always greater than str2
	if (str1.length() < str2.length())
		swap(str1, str2);

	int len1 = str1.length();
	int len2 = str2.length();

	int diff = len1 - len2;
	int carry = 0;
	string ans = "";

	for (int i = len2-1; i>=0; i--)
	{
		int ds = (str2[i] - '0') + (str1[i + diff]) - '0' + carry;
		ans.push_back(ds % 10 + '0');
		carry = ds / 10;
	}

	// For rest of the numbers keep adding carry
	// as basic mathematics.

	for (int i = len1-len2; i>0; i--)
	{
		int ds = (str1[i - 1] - '0') + carry;
		ans.push_back(ds % 10 + '0');
		carry = ds / 10;
	}

	if (carry > 0)
		ans.push_back(carry + '0');

	reverse(ans.begin(), ans.end());

	return ans;
}

int main()
{
	string str1 = "12";
	string str2 = "198111";
	cout<<findSum(str1, str2)<<endl;
	system("pause");
	return 0;

}

