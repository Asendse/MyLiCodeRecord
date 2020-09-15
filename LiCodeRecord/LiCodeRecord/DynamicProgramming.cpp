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


/*(53)最大子序和

int maxSubArray(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int max = nums[0];
	int cur = nums[0];

	for (int i = 1;i < nums.size();++i)
	{
		if ((cur + nums[i]) > nums[i])
		{
			cur += nums[i];
		}
		else
		{
			cur = nums[i];
		}
		max = max > cur ? max : cur;
	}

	return max;
}

*/

