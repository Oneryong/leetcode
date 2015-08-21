/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 11:27:47
* >File Name: repeated_DNA_sequences.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <cstring>

using namespace std;

/*
 * All DNA is composed of a series of nucleotides(核苷酸) abbreviated(缩写，使简略) as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter(信，字母，文字)-long sequences (substrings) that occur more than once in a DNA molecule(分子，微粒).
 *
 * For example,
 *
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 */
int getcode(char ch)
{
	if(ch == 'A')
		return 0;
	else if(ch == 'C')
		return 1;
	else if(ch == 'G')
		return 2;
	else if(ch == 'T')
		return 3;
	else
		return -1;
}

vector<string> findRepeatedDnaSequences(string s)
{
	unordered_set<int> judge;
	vector<string> result;
	int len = s.size();
	if(len < 10)
		return result;

	bool hashtable[1024 * 1024];
	memset(hashtable, false, sizeof(hashtable));
	int i;
	int pos = 0;
	string temp;

	for(i = 0; i < 10; ++i)
	{
		pos <<= 2;
		pos |= getcode(s[i]);
	}

	hashtable[pos] = true;

	for(i = 10; i < len; ++i)
	{
		pos <<= 2;
		pos |= getcode(s[i]);
		pos &= 0xfffff;

		if(hashtable[pos] == true)
		{
			temp = s.substr(i - 9, 10);
			if(judge.find(pos) == judge.end())
			{
				judge.insert(pos);
				result.push_back(temp);
			}
		}
		else
			hashtable[pos] = true;
	}

	return result;

}

int main()
{
	return 0;
}
