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

/*(19)删除链表的倒数第N个节点

//一次遍历 双指针法
ListNode* removeNthFromEnd(ListNode* head, int n) {

	ListNode* p1 = head;
	ListNode* p2 = head;

	for (int i = 0; i < n; i++)
	{
		if (p2)
			p2 = p2->next;
	}
	if (p2 == nullptr)
		return head->next;

	while (true)
	{
		if (!p2->next)
			break;
		p1 = p1->next;
		p2 = p2->next;
	}

	p1->next = p1->next->next;

	return head;
}
*/

/*（23）合并K个升序链表

//合并两个链表
ListNode* mergeTwoList(ListNode* a, ListNode* b)
{
	if (a == nullptr) return b;
	if (b == nullptr) return a;

	ListNode head(0);
	ListNode* tail = &head;
	ListNode* ptr1 = a, * ptr2 = b;

	while (ptr1&&ptr2)
	{
		if (ptr1->val < ptr2->val)
		{
			tail->next = ptr1;
			ptr1 = ptr1->next;
		}
		else
		{
			tail->next = ptr2;
			ptr2 = ptr2->next;
		}
		tail = tail->next;
	}
	tail->next = ptr1 ? ptr1 : ptr2;

	return head.next;
}
//归并
ListNode* Helper(vector<ListNode*>& lists, int l, int r)
{
	if (l == r) return lists[l];
	int mid = (l + r) / 2;
	ListNode* left = Helper(lists, l, mid);
	ListNode* right = Helper(lists, mid + 1, r);

	return mergeTwoList(left, right);
}
//归并法
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	return Helper(lists, 0, lists.size() - 1);
}

struct Status
{
	int val;
	ListNode* node;
	bool operator<(const Status& rhs) const
	{
		return val > rhs.val;
	}
};

priority_queue<Status> prior_que;
//优先队列法
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	for (auto node : lists)
	{
		if (node)
			prior_que.push({ node->val,node });
	}

	ListNode head(0);
	ListNode* tail = &head;

	while (!prior_que.empty())
	{
		auto p = prior_que.top();
		prior_que.pop();

		tail->next = p.node;
		tail = tail->next;
		if (p.node->next)
			prior_que.push({ p.node->next->val,p.node->next });
	}

	return head.next;
}
*/

/*环形链表

//(141)环形链表
bool hasCycle(ListNode* head) {
	ListNode* p1 = head;
	ListNode* p2 = head;

	while (p1&&p2)
	{
		p1 = p1->next;
		if (p2->next)
			p2 = p2->next->next;
		else
			return false;

		if (p1 == p2)
			return true;
	}

	return false;
}

//(142)环形链表 II
ListNode* detectCycle(ListNode* head) {
	ListNode* p1 = head, * p2 = head;

	while (p1 && p2)
	{
		//慢指针
		p1 = p1->next;
		//快指针
		if (p2->next)
			p2 = p2->next->next;
		else
			return nullptr;

		if (p1 == p2)
		{
			p2 = head;
			while (p1!=p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}

	}

	return nullptr;
}
*/

/*(147)对链表进行插入排序

ListNode* insertionSortList(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode* res = new ListNode(0);
	res->next = head;
	ListNode* pre = head;
	ListNode* node = head->next;

	while (node)
	{
		if (node->val < pre->val)
		{
			ListNode* tem = res;
			while (node->val > tem->next->val)
			{
				tem = tem->next;
			}
			pre->next = node->next;
			node->next = tem->next;
			tem->next = node;
			node = pre->next;
		}
		else
		{
			pre = pre->next;
			node = node->next;
		}
	}


	return res->next;
}
*/

/*(148)排序链表

//递归法
ListNode* Helper(ListNode* head)
{
	if (!head||!head->next)
		return head;

	ListNode* slow = head;
	ListNode* fast = head;

	//快慢指针找中点
	while (fast)
	{
		slow = slow->next;
		if (fast->next)
			fast = fast->next->next;
		else
			break;
	}

	ListNode* left = Helper(head);
	ListNode* right = Helper(slow->next);
	//分割
	slow->next = nullptr;

	//合并
	ListNode node(0);
	ListNode* p = &node;
	while (left && right)
	{
		if (left->val < right->val)
		{
			p->next = left;
			left = left->next;
		}
		else
		{
			p->next = right;
			right = right->next;
		}
		p = p->next;
	}
	p->next = left ? left : right;

	return node.next;
}

//分割
ListNode* cut(ListNode* head, int n)
{
	ListNode* p = head;
	while (p&&--n)
	{
		p = p->next;
	}

	if (p == nullptr)
		return p;

	ListNode* node = p->next;
	p->next = nullptr;
	return node;
}

//合并
ListNode* merge(ListNode* left, ListNode* right)
{
	ListNode node(0);
	ListNode* p = &node;
	while (left && right)
	{
		if (left->val < right->val)
		{
			p->next = left;
			left = left->next;
		}
		else
		{
			p->next = right;
			right = right->next;
		}
		p = p->next;
	}
	p->next = left ? left : right;

	return node.next;
}

//迭代法
ListNode* sortList(ListNode* head) {
	ListNode dummyHead(0);
	dummyHead.next = head;

	int length = 0;
	ListNode* p = head;
	while (p)
	{
		++length;
		p = p->next;
	}

	for (int size = 1; size < length; size <<= 1)
	{
		ListNode* cur = dummyHead.next;
		ListNode* tail = &dummyHead;

		while (cur)
		{
			ListNode* left = cur;
			ListNode* right = cut(left, size);
			cur = cut(right, size);

			tail->next = merge(left, right);
			while (tail->next)
			{
				tail = tail->next;
			}
		}
	}

	return dummyHead.next;
}

*/

/*(160)相交链表

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	ListNode* pa = headA;
	ListNode* pb = headB;

	int a = 0,b=0;
	while (pa||pb)
	{
		if (pa)
			pa = pa->next;
		else
			b++;

		if (pb)
			pb = pb->next;
		else
			a++;
	}

	pa = headA;
	pb = headB;
	while (a||b)
	{
		if (a)
		{
			--a;
			pa = pa->next;
		}
		if (b)
		{
			--b;
			pb = pb->next;
		}
	}

	while (pa&&pb&&pa!=pb)
	{
		pa = pa->next;
		pb = pb->next;
	}

	return pa;
}
*/