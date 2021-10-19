#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	string student;
	Node* next = nullptr;
	Node* previouse = nullptr;
	int counter = 1;
};

void creatList(Node** head, string newName)
{
	Node* tmp = new Node;
	if (*head) {
		(*head)->next = tmp;
		tmp->counter = (*head)->counter + 1;
	}
	tmp->previouse = *head;
	tmp->student = newName;
	*head = tmp;
}

void insert(Node* head, int idx, string newName)
{
	while (head)
	{
		if (idx > head->counter)
		{
			cout << "You entered wrong index";
			return;
		}
		else if (head->counter == idx)
		{
			Node* tmp = new Node;

			tmp->counter = idx;
			tmp->student = newName;
			tmp->next = head;
			tmp->previouse = head->previouse;
			head->previouse = tmp;
			head->counter++;
			head = tmp;
			head = head->previouse;
			if (head) head->next = tmp;
			return;
		}
		else
		{
			head->counter++;
			head = head->previouse;
		}
	}
}
void del(Node* head, int idx)
{
	while (head)
	{
		if (idx == head->counter)
		{
			Node* tmp = new Node;
			Node* n, * p;
			n = head->next;
			p = head->previouse;
			tmp = head;
			n->previouse = p;
			p->next = n;
			delete tmp;
			return;
		}
		else
		{
			head->counter--;
			head = head->previouse;
		}
	}
}
Node* get(Node* head, int idx)
{
	while (head) {
		if (head->counter == idx) return head;
		else head = head->previouse;
	}
}

void gPrint(Node* head)
{
	while (head)
	{
		cout << head->counter << " - " << head->student << endl;
		head = head->previouse;
	}
	cout << '\n';
}

int main()
{
	Node* head = nullptr;
	vector<string> group = { "Jack", "Bob","Rick","Clark","Grigoriy" };
	for (int i = 0; i <= group.size() - 1; i++)
	{
		creatList(&head, group[i]);
	}

	gPrint(head);
	insert(head, 4, "Alex");
	gPrint(head);

	Node* p = get(head, 3);
	cout << p->student << "\n\n";

	del(head, 2);
	gPrint(head);
	return 0;
}