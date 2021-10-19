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
	Node* tmp = new Node;
	if (*head) 	(*head)->next = tmp;	
	tmp->previouse = *head;
	tmp->student = newName;
	*head = tmp;
}


void insert(Node** head, int idx, string newName)
{
	for (int i = 1; i < idx; i++)
	{
		*head = (*head)->next;
	}
	Node* tmp = new Node;
	
	Node* p= (*head)->previouse;
	tmp->student = newName;
	tmp->next = *head;
	tmp->previouse = (*head)->previouse;
	(*head)->previouse = tmp;
	if (p) p->next = tmp;	
	*head = tmp;	
}


void del(Node** head, int idx)
{
	for (int i = 1; i < idx; i++)
	{
		*head = (*head)->next;
	}
	Node* tmp = new Node;
	Node* nextNode, * prevNode;
	nextNode = (*head)->next;
	prevNode = (*head)->previouse;
	tmp = *head;	
	if (nextNode)
	{
		nextNode->previouse = prevNode;
		*head = (*head)->next;
	}
	if (prevNode)
	{
		prevNode->next = nextNode;
		*head = (*head)->previouse;
	}
	
	delete tmp;	
}


Node* get(Node* head, int idx)
{
	for (int i = 1; i < idx; i++)
	{
		head = head->next;
	}
	return head;
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


void reposition(Node** head)
{
	Node* t=*head;
	while (*head)
	{		
			t = *head;
			*head = (*head)->previouse;			
	}
	*head = t;
}


int main()
{
	Node* head = nullptr;
	vector<string> group = { "Jack", "Bob","Rick","Clark","Grigoriy" };
	for (int i = 0; i <= group.size() - 1; i++)
	{
		creatList(&head, group[i]);
	}	
	reposition(&head);
	gPrint(head);
	
	insert(&head, 5, "Alex");	
	reposition(&head);
	gPrint(head);

	Node* getName = get(head, 3);
	cout << getName->student << "\n\n";
	
	del(&head, 3);	
	reposition(&head);
	gPrint(head);
	
	return 0;
}