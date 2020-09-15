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

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*摩尔投票法

//(169)多数元素
int majorityElement2(vector<int>& nums)
{
	int candidate = nums[0];
	int count = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (candidate == nums[i])
			count++;
		else
		{
			if (count == 0)
			{
				candidate = nums[i];
				count++;
			}
			else
			{
				count--;
			}
		}
	}

	return candidate;
}
//(229)求众数 II
vector<int> majorityElement3(vector<int>& nums)
{
	if (nums.size()<2)
		return nums;
	int candidate1 = nums[0], candidate2 = nums[0];
	int count1 = 0, count2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != candidate1)
		{
			candidate2 = nums[i];
			break;
		}
	}
	if (candidate1 == candidate2)
		return vector<int>{candidate1};

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == candidate1)
		{
			count1++;
		}
		else if (nums[i] == candidate2)
		{
			count2++;
		}
		else
		{
			if (count1 == 0)
			{
				candidate1 = nums[i];
				count1++;
			}
			else if (count2 == 0)
			{
				candidate2 = nums[i];
				count2++;
			}
			else
			{
				count1--;
				count2--;
			}
		}
	}

	vector<int> res;
	count1 = 0;
	count2 = 0;
	for (int tem : nums)
	{
		if (tem == candidate1)
			count1++;
		if (tem == candidate2)
			count2++;
	}
	if (count1 > nums.size() / 3)
		res.push_back(candidate1);
	if (count2 > nums.size() / 3)
		res.push_back(candidate2);
	return res;
}
*/

/*字符串匹配算法

//暴力法
int strStr(string haystack, string needle) {
	if (needle.empty())
		return 0;

	for (size_t i = 0; i < haystack.size(); i++)
	{
		if (haystack[i] == needle[0] && haystack.size()-i>=needle.size())
		{
			int index = 0;
			while (haystack[i+index]==needle[index])
			{
				index++;
				if (index == needle.size())
					return i;
			}
		}
	}

	return -1;
}

//Rabin Karp算法
int strStr_RB(string haystack, string needle)
{
	if (needle.empty())
		return 0;
	if (haystack.size() < needle.size())
		return -1;
	int L = needle.size();
	
	int main_hash = 0;
	int needle_hash = 0;
	//求主串哈希值和模式串哈希值
	for (size_t i = 0; i < L; i++)
	{
		main_hash += (haystack[i] - 'a') * pow(26, L - i - 1);
		needle_hash += (needle[i] - 'a') * pow(26, L - i - 1);
	}
	cout << "main_hash:" << main_hash << endl;
	cout << "needle_hash:" << needle_hash << endl;

	//移动计算主串哈希值并与模式串哈希值比较
	for (size_t i = 0; i <= haystack.size()-L; i++)
	{
		//如果相等则返回起始位置
		if (main_hash == needle_hash)
			return i;
		//计算下一个主串哈希值
		main_hash = main_hash * 26 - (haystack[i] - 'a') * pow(26, L) + (haystack[i + L] - 'a');
	}

	return -1;
}

//求next数组
vector<int> Next(string t)
{
	vector<int> next(t.size()+1, 0);
	next[0] = -1;
	int i = 0, j = -1;
	while(i<t.size())
	{
		if (j == -1 || t[i] == t[j])
		{
			++j;
			++i;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}

	return next;
}
//KMP算法
int Kmp(string s,string t)
{
	vector<int> next = Next(t);

	int i = 0, j = 0;
	while (i < s.size() && j < t.size())
	{
		if (j == -1 || s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}

	if (j == t.size())
		return i - j;

	return -1;
}
*/

/*前缀树

class Trie {
public:
	//Initialize your data structure here.
	Trie() {
		isEnd = false;
		memset(next, 0, sizeof(next));
	}

	//Inserts a word into the trie. 
	void insert(string word) {
		Trie* t = this;
		for (char c : word)
		{
			if (t->next[c - 'a'] == nullptr)
				t->next[c - 'a'] = new Trie();
			t = t->next[c - 'a'];
		}
		t->isEnd = true;
	}

	//Returns if the word is in the trie. 
	bool search(string word) {
		Trie* t = this;
		for (char c : word)
		{
			if (t->next[c - 'a'] == nullptr)
				return false;
			t = t->next[c - 'a'];
		}
		return t->isEnd;
	}

	//Returns if there is any word in the trie that starts with the given prefix.
	bool startsWith(string prefix) {
		Trie* t = this;
		for (char c : prefix)
		{
			if (t->next[c - 'a'] == nullptr)
				return false;
			t = t->next[c - 'a'];
		}
		return true;
	}

private:
	bool isEnd;
	Trie* next[26];
};

*/



int main()
{


	return 0;
}
