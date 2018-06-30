#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		if (n == 0)
			return 0;
		stack<int> sk;
		int res = 0;
		int tmp = 0;

		for (int i = 0; i<n; i++)
		{
			if (s[i] == '(')
				sk.push(i);
			else
			{
				if (!sk.empty())
				{
					if (s[sk.top()] == '(')
						sk.pop();
					else
						sk.push(i);
				}
				else
				{
					sk.push(i);
				}
			}
		}

		if (sk.empty())
			return n;
		else
		{
			int a = n;
			while (!sk.empty())
			{
				tmp = sk.top();
				sk.pop();
				res = max(res, a - tmp - 1);
				a = tmp;
			}

			res = max(res, a);
		}

		return res;
	}
};

void main()
{
	Solution s;
	s.longestValidParentheses("()((()");
}
