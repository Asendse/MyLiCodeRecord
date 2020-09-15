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

/*(392)判断子序列
//双指针
bool isSubsequence(string s, string t)
{
	if (s.size() > t.size())
		return false;
	int ps = 0, pt = 0;

	while (pt<t.size())
	{
		if (s[ps] == t[pt])
		{
			++ps;
			++pt;
		}
		else
		{
			++pt;
		}
		if (ps == s.size())
			return true;
	}

	return false;
}
//动态规划
bool isSubsequence1(string s, string t)
{
	vector<vector<int>> dp(t.size() + 1);
	for (int i = 0; i < dp.size(); i++)
	{
		dp[i].resize(26, -1);
	}

	for (int i = t.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < 26; j++)
		{
			if ((t[i] - 'a') == j)
				dp[i][j] = i;
			else
				dp[i][j] = dp[i + 1][j];
		}
	}

	for (int i = 0; i < dp.size(); i++)
	{
		for (int j = 0; j < dp[i].size(); j++)
		{
			cout << dp[i][j];
		}
		cout << endl;
	}

	int ps = 0, pt = 0;
	while (ps!=s.size())
	{
		int index = dp[pt][s[ps] - 'a'];
		if (index != -1)
		{
			ps++;
			pt = index + 1;
		}
		else
			return false;
	}

	return true;
}
*/

#pragma region 滑动窗口

/*(3)无重复字符的最长子串

int lengthOfLongestSubstring(string s) {
	int i = 0, j = 0;
	int len = 0;
	map<char, int> mp;

	while (j < s.size())
	{
		if (mp.count(s[j]) == 0)
		{
			mp[s[j]] = j;
		}
		else
		{
			if (i < mp[s[j]])
			{
				len = (j - i) > len ? (j - i) : len;
				i = mp[s[j]] + 1;
			}
			mp[s[j]] = j;

		}
		++j;
	}
	len = (j - i) > len ? (j - i) : len;

	return len;
}
*/

/*(76)最小覆盖子串

bool CheckMap(map<char, int>& mapT, map<char, int>& mapS)
{
	for (const auto& p : mapT)
	{
		if (mapS[p.first] != p.second)
			return false;
	}

	return true;
}

string minWindow(string s, string t) {
	map<char, int> mapS, mapT;

	for (char c : t)
	{
		++mapT[c];
	}

	int l = 0, r = 0;
	int len = INT_MAX, resL = -1;

	while (r<s.size())
	{
		if (mapT.find(s[r]) != mapT.end())
		{
			mapS[s[r]]++;
		}

		while (CheckMap(mapT, mapS) && l <= r)
		{
			if (len > (r - l + 1))
			{
				len = (r - l + 1);
				resL = l;
			}

			if (mapT.find(s[l]) != mapT.end())
			{
				mapS[s[l]]--;
			}
			++l;
		}
		++r;
	}

	return (resL == -1) ? string() : s.substr(resL, len);
}
*/

/*(209)长度最小的子数组
//滑动窗口
int minSubArrayLen(int s, vector<int>& nums) {
	int num = 0;
	int l = 0, r = 0;
	int len = INT_MAX;

	while (r < nums.size())
	{
		if (num < s)
		{
			num += nums[r];
		}

		while (num >= s && l <= r)
		{
			if ((r - l + 1) < len)
			{
				len = (r - l + 1);
			}

			num -= nums[l];
			++l;
		}
		++r;
	}

	return len == INT_MAX ? 0 : len;
}

//前缀和+二分查找
int minSubArrayLen2(int s, vector<int>& nums)
{
	vector<int> sums(nums.size() + 1,0);
	for (size_t i = 1; i < sums.size(); i++)
	{
		sums[i] = sums[i - 1] + nums[i - 1];
	}

	int len = INT_MAX;

	for (int i = 0; i < sums.size(); i++)
	{
		int target = s + sums[i];
		auto bound = lower_bound(sums.begin(), sums.end(), target);
		if (bound != sums.end())
		{
			len = min(len, (int)(bound - sums.begin()) - i + 1);
		}
	}

	return len;
}
*/

/*(239)滑动窗口最大值

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	deque<int> que;

	if (k == 1)
		return nums;

	//初始化滑动窗口（双端队列）
	for (int i = 0; i < k; i++)
	{
		while (!que.empty()&&nums[i]>=nums[que.back()])
		{
			que.pop_back();
		}

		que.push_back(i);
	}
	res.push_back(nums[que.front()]);

	//移动滑动窗口（双端队列）
	for (int i = k; i < nums.size(); i++)
	{
		if (!que.empty() && (i - k) == que.front())
		{
			que.pop_front();
		}

		while (!que.empty() && nums[i] >= nums[que.back()])
		{
			que.pop_back();
		}

		que.push_back(i);

		res.push_back(nums[que.front()]);
	}

	return res;
}
*/

#pragma endregion
