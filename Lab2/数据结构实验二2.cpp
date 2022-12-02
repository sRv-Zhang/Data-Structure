// 数据结构实验二2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct node
{
    node* next;
    int val;
    node() : next(0) {}
};
node* Insert(node* head, int data)
{
    node* p = head;
    node* new_node = new node;
    new_node->val = data;
    if (p->val > data)
    {
        new_node->val = head->val;
        new_node->next = head->next;
        head->next = new_node;
        head->val = data;
    }
    else
    {
        node* q = head->next;
        while (q && data > q->val){
            p = q;
            q = q->next;
        }
        new_node->next = q;
        p->next = new_node;
    }
    return head;
}
node* Delete(node* head) 
{
	node* p, * temp = head;
	if (!head->next)
		return head;
	head->next = Delete(head->next);
	p = head->next;
	while (p)
    {
		if (head->val == p->val)
        {
			temp->next = p->next;
			free(p);
			p = temp->next;
		}
		else 
        {
			p = p->next;
			temp = temp->next;
		}
	}
	return head;
}

void Output(node* head)
{
    if (!head)
        cout << "No member";
    else
    for (node* i = head; i; i = i->next)
    {
        if (i->next)
        {
            cout << i->val << " <- ";
        }
        else
            cout << i->val;
    }
}
void Divide(node* head)
{
    node* head2, * head3;
    head2 = new node;
    head3 = new node;
    for (node* i = head; i; i = i->next)
    {
        if (i->val % 2 ==0) 
        {
            Insert(head3, i->val);
        }
        else
        {
            Insert(head2, i->val);
        }
    }
    cout << endl;
    cout << "B : ";
    Output(head2->next);
    cout << endl << "C : ";
    Output(head3->next);
    return;
}
int main()
{
    int n;
    cin >> n;
    node* head = new node;
    head->val = n;
    node* p = head;
    while (cin >> n)
    {
        node* q = new node;
        q->val = n;
        p->next = q;
        p = p->next;
    }
    cout << "A : ";
    Output(head);
	Delete(head);
	cout << endl << "A': ";
	Output(head);
	Divide(head);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
