#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

/*（131）分割回文串

vector<vector<string>> res;

bool Judge(string str)
{
	if (str.size() == 1)
		return true;
	int start = 0, end = str.size() - 1;
	while (start<end)
	{
		if (str[start] == str[end])
		{
			start++;
			end--;
		}
		else
		{
			return false;
		}
	}

	return true;
}

void Helper(string str, vector<string>& vec)
{
	for (int i = 0; i < str.size(); i++)
	{
		string tem = str.substr(0, i + 1);
		if (Judge(tem))
		{
			vec.push_back(tem);
			if (i == str.size() - 1)
				res.push_back(vec);
			else
				Helper(str.substr(i + 1, str.size() - i), vec);
			vec.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<string> vec;
	Helper(s, vec);

	return res;
}

*/

/*（5）最长回文串
//动态规划
string longestPalindrome(string s) {

	vector<vector<bool>> dp(s.size());
	for (int i = 0;i < s.size();i++)
		dp[i].resize(s.size(), false);

	int len = 0;
	int start = 0, end = 0;
	for (int i = s.size() - 1;i >= 0;--i)
	{
		for (int j = i;j < s.size();++j)
		{
			if (j - i < 3)
			{
				dp[i][j] = s[i] == s[j] ? true : false;
			}
			else
			{
				dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]) ? true : false;
			}
			if (dp[i][j])
			{
				if ((j - i + 1) > len)
				{
					len = j - i + 1;
					start = i;
					end = j;
				}
			}
		}
	}

	return s.substr(start, end - start + 1);
}

//中心扩散法
string Helper(string s, int left, int right)
{
	while (left>=0&&right<s.size())
	{
		if (s[left] == s[right])
		{
			--left;
			++right;
		}
		else
		{
			break;
		}
	}

	return s.substr(left + 1, right - left - 1);
}

string longestPalindrome1(string s)
{
	if (s.size() < 2)
		return s;
	string res = "";

	for (int i = 0; i < s.size()-1; i++)
	{
		string oddStr = Helper(s, i, i);
		string evenStr = Helper(s, i, i + 1);
		int maxLen = oddStr.size() > evenStr.size() ? oddStr.size() : evenStr.size();
		if (maxLen > res.size())
		{
			res = oddStr.size() > evenStr.size() ? oddStr : evenStr;
		}
	}
	return res;
}
*/

/*(214)最短回文串

string shortestPalindrome(string s)
{
	if (s.size() < 2)
		return s;
	vector<int> next = Next(s);
	int len = s.size();

	int i = s.size()-1,j = 0;
	while (i >= 0 && j < len)
	{
		if (j == -1 || s[i] == s[j])
		{
			--i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	string pre;
	if (j != -1)
		pre = s.substr(j, s.size() - j);
	else
		pre = s.substr(1, s.size() - 1);

	reverse(pre.begin(), pre.end());

	return pre + s;
}
*/