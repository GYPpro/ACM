#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
// bitset<1110> die[500100];
map<int,int> die[500100];
char word[100];
int tree[500100][26];

int idx = 0; // 定义全局变量防止爆栈，同时全局变量自动初始化为0

int num(char s)
{
    if (s >= 'a' && s <= 'z')
        return s - 'a';
}

void insert(char *s, int n)
{
    int root = 0, i = 0, pos; // 不用每次都把索引值初始化为零
    for (; i < strlen(s); i++)
    {
        pos = num(s[i]);
        if (tree[root][pos] == 0)    // 如果在当前节点的子节点中，索引为 pos 的节点未被使用。
            tree[root][pos] = ++idx; // 为当前节点的子节点中，索引为 pos 的节点分配一个新的索引值 idx，并将其赋值给相应位置。
        root = tree[root][pos];      // 更新当前节点为新添加的子节点。idx的值一直叠加
    }
    die[root][n] = 1; // 每个单词的最后节点不同
}

int find(char *s, int n)
{
    int root = 0, i = 0, pos;
    for (; i < strlen(s); i++)
    {
        pos = num(s[i]);
        if (tree[root][pos] == 0)
            return 0;
        root = tree[root][pos]; // 最后的节点
    }
    for (i = 0; i < n; i++)
    {
        if (die[root].find(i)->second == 1)
            cout << i + 1 << " ";
    }
    printf("\n");
}

int main()
{
    int n, i, l, j, k, m;
    cin >> n;
    for (i = 0; i < n; i++) // 插入
    {
        cin >> l;
        for (j = 0; j < l; j++)
        {
            cin >> word;
            insert(word, i);
        }
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> word;
        find(word, n);
    }
} // 这个是我写的代码，一直re，看起来是数组越界了？