/*
 * Given a non-negative number represented as an array of digits, plus one to the number.

 * The digits are stored such that the most significant digit is at the head of the list.
 */
#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
	int tag = 1;
	int count = 0;
	vector<int>::size_type i = digits.size() - 1;

	while(tag)
	{
		if(digits[i] == 9)
		{
			digits[i] = 0;
			count++;
			i--;
			tag = 1;
		}
		else
		{
			digits[i] += tag;
			tag = 0;
		}
		if(count == digits.size())
		{
			digits.push_back(0);
			digits[0] = 1;
			tag = 0;
		}
	}
	return digits;
}

int main()
{
	vector<int> digits(10, 9);
	for(vector<int>::iterator iter = digits.begin(); iter < digits.end(); iter++)
	{
		cout<<*iter;
	}
	cout<<endl;
	plusOne(digits);
	for(vector<int>::iterator iter = digits.begin(); iter < digits.end(); iter++)
	{
		cout<<*iter;
	}
	cout<<endl;
	return 0;
}
