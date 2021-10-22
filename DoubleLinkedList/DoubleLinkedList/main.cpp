#include <iostream>
#include<string>
#include<vector>
using namespace std;


struct Node
{
	string student;
	Node* next = nullptr;
	Node* previouse = nullptr;	
};

void creatList(Node** head, string newName) 
{
	Node* tHead = *head;
	Node* tmp = new Node;
	tmp->student = newName;
	if ((*head)==nullptr)
	{		
		*head = tmp;
		return;
	}
	while (tHead->next != nullptr) tHead = tHead->next;
	tHead->next = tmp;
	tmp->previouse = tHead;	
}


void insert(Node** head, int idx, string newName)
{	
	Node* tHead = *head;
	Node* tmp = new Node;
	tmp->student = newName;
	if (idx == 0 )
	{
		if ((*head)== nullptr)
		{
			*head = tmp;
			return;
		}
		tmp->next = *head;
		(*head)->previouse = tmp;
		(*head) = (*head)->previouse;
		return;
	}	
	for (int i = 0; i < idx; i++)
	{
		if (tHead->next == nullptr)
		{
			tmp->previouse = tHead;
			tHead->next = tmp;
			return;
		}
		tHead = tHead->next;		
	}
	tmp->next = tHead;
	tmp->previouse = tHead->previouse;
	tHead->previouse->next = tmp;
	tHead->previouse = tmp;	
}


void del(Node** head, int idx)
{
	Node* tHead = *head;	
	Node* tmp = new Node;
	if (idx == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		(*head)->previouse = nullptr;
		delete tmp;
		return;
	}
	for (int i = 0; i < idx-1; i++)
	{	
		tHead = tHead->next;
	}
	tmp = tHead->next;
	tHead->next = tmp->next;
	if (tmp->next) tmp->next->previouse = tHead;
	delete tmp;	
}


Node* get(Node** head, int idx)
{
	Node* tHead = *head;
	for (int i = 0; i < idx; i++)
	{
		tHead = tHead->next;
		if (tHead == nullptr) return nullptr;
	}
	return tHead;
}


void gPrint(Node* head)
{
	while (head)
	{
		cout <<head->student << endl;
		head = head->next;
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
	
	insert(&head, 1, "Alex");		
	gPrint(head);	
	
	Node* getName = get(&head, 0);
	if (getName == nullptr) cout << "Inccorect index\n\n";
	else cout << getName->student << "\n\n";
	
	del(&head, 0);		
	gPrint(head);
	
	return 0;
}
