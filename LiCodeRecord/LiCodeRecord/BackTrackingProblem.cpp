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

/*（79）单词搜索
int fx[4] = { 0,0,-1,1 };
int fy[4] = { -1,1,0,0 };

bool Helper(vector<vector<char>>& board, string word, int k,vector<int> vec)
{
	if (k == word.size())
		return true;

		for (int j = 0; j < 4; j++)
		{
			int x = vec[0] + fx[j];
			int y = vec[1] + fy[j];

			if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size())
			{
				if (board[y][x] == word[k])
				{
					board[y][x] = '!';
					if (Helper(board, word, k + 1, vector<int>{x, y}))
						return true;
					board[y][x] = word[k];
				}
			}
		}
		return false;
}

bool exist(vector<vector<char>>& board, string word) {

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == word[0])
			{
				board[i][j] = '!';
				if (Helper(board, word, 1, vector<int>{j, i}))
					return true;
				board[i][j] = word[0];
			}
		}
	}
	return false;
}
*/

/*（212）单词搜索 II

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

int fx[4] = { 0,0,-1,1 };
int fy[4] = { -1,1,0,0 };
vector<string> res;
Trie* trie;

void Helper(vector<vector<char>>& board, string word,int X,int Y)
{
	if (trie->search(word))
		res.push_back(word);

	for (int j = 0; j < 4; j++)
	{
		int x = X + fx[j];
		int y = Y + fy[j];
		if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size())
		{
			if (board[y][x] == '!')
				continue;
			string str = word + board[y][x];
			if (trie->startsWith(str))
			{
				char tem = board[y][x];
				board[y][x] = '!';
				Helper(board, str, x, y);
				board[y][x] = tem;
			}
		}
	}
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	//创建前缀树
    trie = new Trie();
	for (int i = 0; i < words.size(); i++)
	{
		trie->insert(words[i]);
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			//判断当前字母是否在前缀树中
			string str;
			str += board[i][j];
			if (trie->startsWith(str))
			{
				char tem = board[i][j];
				board[i][j] = '!';
				Helper(board, str, j, i);
				board[i][j] = tem;
			}
		}
	}

	return res;
}
*/

/*(491)递增子序列

vector<vector<int>> res;
vector<int> arr;
void Helper(vector<int>& nums,int cur,int last)
{
	if (cur == nums.size())
	{
		if (arr.size() > 1)
			res.push_back(arr);
		return;
	}

	if (nums[cur] >= last)
	{
		arr.push_back(nums[cur]);
		Helper(nums, cur + 1, nums[cur]);
		arr.pop_back();
	}
	if (nums[cur] != last)
	{
		Helper(nums, cur + 1, last);
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
	if (nums.size() < 2)
		return res;
	Helper(nums, 0, INT_MIN);
	return res;
}
*/

