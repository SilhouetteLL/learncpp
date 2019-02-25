// 451. Sort Characters By Frequency
// https://leetcode-cn.com/problems/sort-characters-by-frequency/
/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:
输入:
"tree"
输出:
"eert"
解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

示例 2:
输入:
"cccaaa"
输出:
"cccaaa"
解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。

示例 3:
输入:
"Aabb"
输出:
"bbAa"
解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。

*/
#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) 
{
    string res = "";                // 根据频率从高到低排序的结果字符串
    unordered_map<char, int> table; // 记录每一个字符的频率
    vector<pair<char, int>> freq;   // 将table中每一个元素存入vector 便于排序

    // 读取并且存储每一个字符的频率到table中
    for(char alpha : s)             
    {
        table[alpha]++;
    }

    // 将table中的每一个元素加入到vector中
    for(pair<char, int> item : table)          
    {
        freq.push_back(item);
    }

    // 匿名函数自定义排序方式(<) 按照频率从高到低排序
    sort(freq.begin(), freq.end(), 
    [](pair<char, int> a, pair<char, int> b) 
    {
        return a.second > b.second;
    }
    );

    // 表中的每一个元素 键值为字符(添加到结果字符串),映射值为频率(添加的字符个数) 
    // 使用append函数 依次添加到结果字符串中
    for(pair<char, int> item : freq)           
    {
        res.append(item.second, item.first);
    }
    return res;
}

//输入的字符串("xxx")转换为string对象(内容为xxx)
string stringToString(string input) 
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        string s = stringToString(line);
        
        string ret = frequencySort(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}