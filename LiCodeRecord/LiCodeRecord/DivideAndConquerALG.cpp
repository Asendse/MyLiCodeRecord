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

/*(321)拼接最大数

//nums中取n个数保持最大
vector<int> Helper(vector<int>& nums, int n)
{
	vector<int> res;
	int k = nums.size() - n;
	for (int i = 0; i < nums.size(); i++)
	{
		while (!res.empty() && nums[i] > res.back() && k > 0)
		{
			res.pop_back();
			--k;
		}
		res.push_back(nums[i]);
	}

	res.resize(n);

	return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
	vector<int> res;

	for (int i = 0; i <= k; i++)
	{
		if (nums1.size() < i || nums2.size() < (k - i))
			continue;

		//分别取nums1和nums2的最大值（分）
		vector<int> vec1 = Helper(nums1, i);
		vector<int> vec2 = Helper(nums2, k - i);

		//合并nums1和nums2最大数（合）
		vector<int> tem;
		auto it1 = vec1.begin(), it2 = vec2.begin();
		while (it1!=vec1.end() || it2!=vec2.end())
		{
			tem.push_back(lexicographical_compare(it1, vec1.end(), it2, vec2.end()) ? *it2++ : *it1++);
		}
		res = lexicographical_compare(res.begin(), res.end(), tem.begin(), tem.end()) ? tem : res;
	}

	return res;
}
*/

/*(53)最大子序和

struct Status
{
	int lmax;
	int rmax;
	int max;
	int sum;
	Status(int l, int r, int m, int s)
		:lmax(l), rmax(r), max(m), sum(s) {}
};

int max3(int a, int b, int c)
{
	return a > (b > c ? b : c) ? a : (b > c ? b : c);
}

Status Helper(vector<int>& nums, int l, int r)
{
	if (l == r) return Status(nums[l], nums[l], nums[l], nums[l]);
	int mid = (l + r) / 2;
	Status left = Helper(nums, l, mid);
	Status right = Helper(nums, mid + 1, r);

	Status res(0,0,0,0);
	res.lmax = left.lmax > (left.sum + right.lmax) ? left.lmax : (left.sum + right.lmax);
	res.rmax = right.rmax > (right.sum + left.rmax) ? right.rmax : (right.sum + left.rmax);
	res.max = max3(left.max, right.max, left.rmax + right.lmax);
	res.sum = left.sum + right.sum;

	return res;
}

int maxSubArray(vector<int>& nums)
{
	Status res = Helper(nums, 0, nums.size() - 1);
	return res.max;
}
*/

/*（215）数组中的第K个最大元素


//归并排序
vector<int> Helper(vector<int>& nums, int star, int end)
{
	if (star == end)
		return vector<int>{nums[star]};

	int mid = (star + end) / 2;
	vector<int> left = Helper(nums, star, mid);
	vector<int> right = Helper(nums, mid + 1, end);

	vector<int> res;
	int index1 = 0, index2 = 0;
	while (index1<left.size()&&index2<right.size())
	{
		if (left[index1] > right[index2])
		{
			res.push_back(right[index2]);
			index2++;
		}
		else
		{
			res.push_back(left[index1]);
			index1++;
		}
	}
	while (index1<left.size())
	{
		res.push_back(left[index1]);
		index1++;
	}
	while (index2<right.size())
	{
		res.push_back(right[index2]);
		index2++;
	}

	return res;
}

int findKthLargest(vector<int>& nums, int k) {
	if (nums.empty())
		return 0;

	vector<int> res = Helper(nums, 0, nums.size() - 1);

	return res[nums.size() - k];
}

//快速选择（快速排序）
int Partition(vector<int>& nums, int star, int end)
{
	int pivot = nums[star];
	int left = star;
	int right = end;
	int tem;

	while (left!=right)
	{
		while (left<right && nums[right]>pivot)
		{
			right--;
		}
		while (left<right && nums[left]<=pivot)
		{
			left++;
		}
		if (left < right)
		{
			tem = nums[left];
			nums[left] = nums[right];
			nums[right] = tem;
		}
	}
	tem = nums[left];
	nums[left] = nums[star];
	nums[star] = tem;

	return left;
}

int findKthLargest(vector<int>& nums, int k)
{
	int star = 0, end = nums.size() - 1;
	int target = nums.size() - k;

	while (star<=end)
	{
		int index = Partition(nums, star, end);
		if (index == target)
		{
			return nums[target];
		}
		else if (index < target)
		{
			star = index + 1;
		}
		else if (index > target)
		{
			end = index - 1;
		}
	}

	return 0;
}
*/




