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

/*(20)有效的括号

bool isValid(string s) {
	if (s.length() == 0)
		return true;

	stack<char> stk;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			stk.push(s[i]);
			continue;
		}
		if (stk.empty())
			return false;
		char str = stk.top();
		stk.pop();
		if (s[i] == ')')
		{
			if (str != '(')
				return false;
		}
		if (s[i] == ']')
		{
			if (str != '[')
				return false;
		}
		if (s[i] == '}')
		{
			if (str != '{')
				return false;
		}
	}
	if (!stk.empty())
		return false;

	return true;
}
*/

/*(150)逆波兰表达式求值

int evalRPN(vector<string>& tokens) {
	stack<int> stk;
	int num;

	for (size_t i = 0; i < tokens.size(); ++i)
	{
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
		{
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			if (tokens[i] == "+")
				stk.push(b + a);
			if (tokens[i] == "-")
				stk.push(b - a);
			if (tokens[i] == "*")
				stk.push(b * a);
			if (tokens[i] == "/")
				stk.push(b / a);
		}
		else
		{
			stringstream str(tokens[i]);
			str >> num;
			stk.push(num);
		}
	}

	return stk.top();
}
*/

/*(84)柱状图中最大的矩形

//单调栈
int largestRectangleArea(vector<int>& heights) {
	int res = 0;
	stack<int> stk;

	for (size_t i = 0; i < heights.size(); ++i)
	{
		while (!stk.empty()&&heights[i]<heights[stk.top()])
		{
			int height = heights[stk.top()];
			stk.pop();
			int width = i;
			if (!stk.empty())
				res = res > (height * (width - stk.top() - 1)) ? res : height * (width - stk.top() - 1);
			else
				res = res > height* width ? res : height * width;
		}
		stk.push(i);
	}

	while (!stk.empty())
	{
		int height = heights[stk.top()];
		stk.pop();
		int width = heights.size();
		if (!stk.empty())
			res = res > (height * (width - stk.top() - 1)) ? res : height * (width - stk.top() - 1);
		else
			res = res > height* width ? res : height * width;
	}

	return res;
}
//单调栈+哨兵
int largestRectangleArea2(vector<int>& heights) {
	//加入哨兵
	heights.insert(heights.begin(), 0);
	heights.push_back(0);
	
	int res = 0;
	stack<int> stk;

	for (size_t i = 0; i < heights.size(); ++i)
	{
		while (!stk.empty() && heights[i] < heights[stk.top()])
		{
			int height = heights[stk.top()];
			stk.pop();
			int width = i;
			if (!stk.empty())
				res = res > (height * (width - stk.top() - 1)) ? res : height * (width - stk.top() - 1);
			else
				res = res > height* width ? res : height * width;
		}
		stk.push(i);
	}

	return res;
}
*/

/*下一个更大元素

//(496)下一个更大元素 I
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	stack<int> stk;
	map<int, int> m;
	vector<int> res;

	for (int i = 0;i < nums2.size();++i)
	{
		while (!stk.empty()&&nums2[i]>stk.top())
		{
			int tem = stk.top();
			stk.pop();
			
			m[tem] = nums2[i];
		}
		stk.push(nums2[i]);
	}

	while (!stk.empty())
	{
		int tem = stk.top();
		stk.pop();

		m[tem] = -1;
	}

	for (int i = 0; i < nums1.size(); ++i)
	{
		res.push_back(m[nums1[i]]);
	}

	return res;
}

//(503)下一个更大元素 II
vector<int> nextGreaterElements(vector<int>& nums) {
	if (nums.size() == 0)
		return vector<int>();
	vector<int> res(nums.size(), -1);
	stack<int> stk;

	int index = 0;
	while (true)
	{
		while (!stk.empty()&&nums[index]>nums[stk.top()])
		{
			int tem = stk.top();
			stk.pop();

			res[tem] = nums[index];
		}
		if (!stk.empty() && index == stk.top())
			break;
		if (stk.size() > nums.size())
			break;
		stk.push(index);
		index = ++index % nums.size();
	}

	return res;
}

*/

/*(739)每日温度
vector<int> dailyTemperatures(vector<int>& T) {
	if (T.size() == 0)
		return vector<int>();
	stack<int> stk;
	vector<int> res(T.size(), 0);

	for (size_t i = 0; i < T.size(); i++)
	{
		while (!stk.empty()&&T[i]>T[stk.top()])
		{
			int index = stk.top();
			stk.pop();

			res[index] = i - index;
		}
		stk.push(i);
	}

	return res;
}
*/




