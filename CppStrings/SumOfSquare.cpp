//Given a string of lowercase alphabets and a number k, 
//the task is to print the minimum value of the string after removal of ‘k’ characters.
//The value of a string is defined as the sum of squares of the count of each distinct character.
//For example consider the string “saideep”, 
//here frequencies of characters are s - 1, a - 1, i - 1, e - 2, d - 1, p - 1 
//and value of the string is 1 ^ 2 + 1 ^ 2 + 1 ^ 2 + 1 ^ 2 + 1 ^ 2 + 2 ^ 2 = 9.

//A Better Solution used to Priority Queue which has to the highest element on top.

//Finally Count Sum of square of each element and return it.

#include <iostream>
#include <queue>

using namespace std;

#define MAX_CHAR 26

int minStringValue(string str, int k)
{
	int l = str.length();

	if (k >= l)
		return 0;

	int result = 0;
	int freq[MAX_CHAR] = { 0 };
	//Count frequency of each character and Store into temp array.
	for (int i = 0; i < l; i++)
	{
		freq[str[i] - 'a']++;
	}

	//Initialize empty priority queue.
	priority_queue<int> p;
	for (int i = 0; i < MAX_CHAR; i++)
	{
		p.push(freq[i]);
	}

	//Remove K characters which have highest frequency from queue.
	while (k--)
	{
		// Get the value of to priority ele.
		int temp = p.top();
		// remove top priority element from pq.
		p.pop();
		// decrease the ele by 1.
		temp = temp - 1;
		// push the ele : it will rearrange the pq and brings back the top priority ele on top.
		p.push(temp);
	}

	while (!p.empty())
	{
		int temp = p.top();
		result += (temp * temp);
		p.pop();
	}

	return result;

}

int main()
{
	string str = "abbccc";
	 int k = 3;
	cout << minStringValue(str, k)<<endl;
	system("pause");
	return 0;

}