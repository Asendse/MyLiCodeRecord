#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

/*(402)�Ƶ�Kλ����

//vectorʵ�ֵ���ջ
string removeKdigits(string num, int k) {
	if (k >= num.size())
		return "0";
	vector<char> vec;

	for (int i = 0; i < num.size(); i++)
	{
		while (!vec.empty() && num[i] < vec.back() && k>0)
		{
			vec.pop_back();
			--k;
		}
		//ȥ��ǰ��0
		if (vec.empty() && num[i] == '0')
			continue;
		vec.push_back(num[i]);
	}
	while (!vec.empty()&&k>0)
	{
		vec.pop_back();
		--k;
	}
	string res;
	for (char tem : vec)
	{
		res += tem;
	}
	return res == "" ? "0" : res;
}

//stringʵ��ջ
string removeKdigits(string num, int k)
{
	if (num.size() <= k)
		return "";

	string res;
	for (int i = 0; i < num.size(); ++i)
	{
		while (!res.empty()&&num[i]<res.back()&&k>0)
		{
			res.pop_back();
			--k;
		}
		if (res.empty() && num[i] == '0')
			continue;
		res.push_back(num[i]);
	}

	while (!res.empty()&&k>0)
	{
		res.pop_back();
		--k;
	}

	return res == "" ? "0" : res;
}
*/

/*(316)ȥ���ظ���ĸ

string removeDuplicateLetters(string s) {
	stack<char> stk;
	map<char, int> m;
	set<char> _set;

	for (size_t i = 0;i < s.size();++i)
	{
		m[s[i]] = i;
	}

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (_set.count(s[i]) == 1)
			continue;
		while (!stk.empty()&&s[i]<stk.top())
		{
			char c = stk.top();
			if (m[c] > i)
			{
				stk.pop();
				_set.erase(c);
			}
			else
			{
				break;
			}

		}
		stk.push(s[i]);
		_set.insert(s[i]);
	}

	string res;
	while (!stk.empty())
	{
		res.insert(res.begin(), stk.top());
		stk.pop();
	}

	return res;
}
*/

