﻿/*------------------------------------------------------------------|
给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
第一项是数字 1

描述前一项，这个数是 1 即 “一个 1 ”，记作 11

描述前一项，这个数是 11 即 “两个 1 ” ，记作 21

描述前一项，这个数是 21 即 “一个 2 一个 1 ” ，记作 1211

描述前一项，这个数是 1211 即 “一个 1 一个 2 两个 1 ” ，记作 111221

 

示例 1:

输入: 1
输出: "1"
解释：这是一个基本样例。
示例 2:

输入: 4
输出: "1211"
解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 = 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	递归方法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了86.29%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了60.91%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_map>

using namespace std;

string countAndSay(int n) 
{
	if (n == 1)
	{
		return "1";
	}
	
	string iter = countAndSay(n - 1),res = "";

	int cnt = 1;

	for (int i = 0; i < iter.length(); i++)
	{
		if (iter[i] == iter[i + 1])
		{
			cnt++;
		}
		else
		{
			res.push_back('0' + cnt);
			res.push_back(iter[i]);
			/*res += to_string(cnt) + iter[i];*/									/*	迭代的时候就可以发现+= 和=+的内存占用差别了，养成使用+=的习惯	*/
			cnt = 1;															/*	使用=+的内存占用为50几M	*/
		}
	}
	return res;
}

int main()
{
	int n = 5;
	cout << countAndSay(n) << endl;
}