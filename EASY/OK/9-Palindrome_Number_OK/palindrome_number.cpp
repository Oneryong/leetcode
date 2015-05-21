/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/11 18:01:02
* >File Name: palindrome_number.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * //Some hints:
 * //Could negative integers be palindromes? (ie, -1)
 * //
 * //If you are thinking of converting the integer to string, note the restriction of using extra space.
 * //
 * //You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 * //
 * //There is a more generic way of solving this problem.
 */

bool isPalindrome(int x)
{
	if(x < 0)
	{
		cout << "the negative integers no palindrome..." << endl;
		return false;
	}
	int base1 = 1;
	int base2 = 10;
	while((x / base1) > 9)
	{
		base1 = base1 * 10;
	}
	
	while(((x / base1) % 10) == ((x % base2) / (base2 / 10)))
	{
		if((base1 / base2) <= 10)
			return true;
		base1 = base1 / 10;
		base2 = base2 * 10;
	}

	return false;
}

int main()
{
/*
Input:	1000021
Output:	true
Expected: false
*/
	//int a = 121;
	//int a = 1;
	//int a = 0;
	//int a = -1;
	//int a = 123;
	//int a = 1213453121;
	int a = 1000021;
	bool result;
	cout << "a = " << a << endl;
	result = isPalindrome(a);
	cout << "result = " << result << endl;
	return 0;
}
