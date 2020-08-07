#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	Node *next,*random; 
	Node(int x) 
	{ 
		data = x; 
		next = random = NULL; 
	} 
}; 

void print(Node *start) 
{ 
	Node *ptr = start; 
	while (ptr) 
	{ 
		cout << "Data = " << ptr->data << ", Random = "
			<< ptr->random->data << endl; 
		ptr = ptr->next; 
	} 
} 

Node* clone(Node *head) 
{ 
	Node *curr = head;
    while (curr != NULL) {
        Node *tmp = new Node(curr->data);
        tmp->next = curr->next;
        curr->next = tmp;
        curr = tmp->next;
    }
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    curr = head->next;
    while (curr->next != NULL) {
        curr->next = curr->next->next;
        curr = curr->next;
    }
    return head->next;
} 

int main() 
{ 
	Node* start = new Node(1); 
	start->next = new Node(2); 
	start->next->next = new Node(3); 
	start->next->next->next = new Node(4); 
	start->next->next->next->next = new Node(5); 

	start->random = start->next->next; 

	start->next->random = start; 

	start->next->next->random = 
					start->next->next->next->next; 
	start->next->next->next->random = 
					start->next->next->next->next; 

	start->next->next->next->next->random = 
									start->next; 

	cout << "Original list : \n"; 
	print(start); 

	cout << "\nCloned list : \n"; 
	Node *cloned_list = clone(start); 
	print(cloned_list); 

	return 0; 
} 
