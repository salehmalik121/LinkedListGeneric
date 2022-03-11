#include <iostream>
using namespace std;
struct  node
{
	int data;
	node* next;
	node(int n , node* nodePtr) :data(n) , next(nodePtr) {};
};
node* createNode(int data, node* next) {
	node* nGeneral = new node(data, next);
	return nGeneral;
}
void display(node* head);
node* RandomPositionEnter(node*, int);
node* RandomPostionDelete(node*, int);
int main() {
	node* head = NULL;
	node* n = new node(10, NULL);
	for (int i = 9; i>= 1; i--) {
	  n = createNode(i, n);
	  if (i == 1) {
		  head = n;
	  }
	}
	head = RandomPostionDelete(head, 6);
	display(head);
}
void display(node* head) {
	node* temp = head;
	while (temp!=NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}
node* RandomPositionEnter(node* head , int pos) {
	int data;
	cout << "Enter data: ";
	cin >> data;
	node* temp = head;
	node* tempP = temp;
	for (int i = 1; i <= pos; i++) {
		if (temp == NULL) {
			cout << "postion doesnot exist";
			return head;
		}
		else if (pos == i) {
			if (pos != 1 && temp->next!=NULL) {
				
				node* n = createNode(data, temp);
				tempP->next = n;
				
			}
			else if(pos == 1) {
				

				node* start = createNode(data, head);
				head = start;
				
			}
			else if (temp->next == NULL) {
				cout << "Working 3";

				node* endNode = createNode(data, NULL);
				temp->next = endNode;
				

			}
			return head;
		}
		tempP = temp;
		temp = temp->next;
	}
}
node* RandomPostionDelete(node* head, int pos) {
	node* temp = head;
	node* tempP = head;
	for (int i = 1; i <= pos; i++) {
		if (temp == NULL) {
			cout << "Position doesnot exist";
			break;
		}
		else if (i == pos) {
			if (pos != 1 && temp->next!=NULL) {
				tempP->next = temp->next;
				free(temp);
			}
			else if (pos == 1) {
				 head = temp->next;
				 free(temp);
			}
			else if (temp->next == NULL)
			{
				tempP->next = NULL;
				free(temp);
			}
			return head;
		}
		tempP = temp;
		temp = temp->next;
	}
}
