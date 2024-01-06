#include<iostream>
using namespace std;

class DoublyLinkedList;
class DNode
{
	int data;
	DNode* next, * prev;
	friend class DoublyLinkedList;
};

class DoublyLinkedList
{
	DNode* head;
public:
	DoublyLinkedList()
	{
		head = nullptr;
	}

	~DoublyLinkedList()
	{
		DNode* current = head;
		DNode* next;
		while (current != nullptr) 
		{
			next = current->next;
			delete current;
			current = next;
		}
	}

	bool insertAtStart(int val)
	{
		DNode* temp = new DNode;
		temp->data = val;
		temp->prev = nullptr;

		if (head != nullptr)
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}

		else {
			temp->next = nullptr;
			head = temp;
		}
		 	
		return true;
	}

	bool insertAtEnd(int val)
	{
		DNode* temp = new DNode;
		temp->data = val;
		temp->next = nullptr;

		if (head == nullptr) 
		{
			temp->prev = nullptr;
			head = temp;
			return 1;
		}

		else {
			DNode* current = head;
			while (current->next != nullptr)
				current = current->next;

			current->next = temp;
			temp->prev = current;
		}
		return 1;
	}

	bool sortedInsert(int val)   //if list has 1, 2, 4 and 3 is the new value to insert then you have to insert the node having value 3 before node having value 4
	{
		DNode* temp = new DNode;
		temp->data = val;

		if (head->data >= val || head == nullptr)     //for first node 
		{
			temp->next = head;
			temp->prev = nullptr;

			if (head != nullptr)
				head->prev = temp;
			head = temp;
			return true;
		}

		DNode* current = head;
		while (current->next->data < val && current->next != nullptr)
			current = current->next;

		temp->next = current->next;
		if (current->next != nullptr) 
			current->next->prev = temp;

		current->next = temp;
		temp->prev = current;

		return true;
	}

	bool deleteFromStart()
	{
		if (head == nullptr)
			return false;

		DNode* current = head;
		head = head->next;
		if (head != nullptr)
			head->prev = nullptr;
		delete current;
		return true;
	}

	bool deleteFromEnd()
	{
		if (head == nullptr)
			return false;

		if (head->next == nullptr) 
		{
			delete head;
			head = nullptr;
			return true;
		}

		DNode* current = head;
		while (current->next != nullptr)
			current = current->next;

		current->prev->next = nullptr;
		delete current;
		return true;
	}

	DNode* Search(int val)   //if value found then this function returns the address of that node otherwise it will return 0
	{
		DNode* current = head;
		while (current != nullptr) 
		{
			if (current->data == val)
				return current;
			current = current->next;
		}
		return 0;
	}

	bool deleteSpecificValue(int valToDelete)
	{
		DNode* DeleteNode = Search(valToDelete);
		if (DeleteNode == 0)
			return false;

		if (DeleteNode->prev == nullptr)
			head = DeleteNode->next;
			
		else
			DeleteNode->prev->next = DeleteNode->next;		

		if (DeleteNode->next != nullptr)
			DeleteNode->next->prev = DeleteNode->prev;

		delete DeleteNode;
		return true;
	}

	void display()
	{
		DNode* current = head;
		if (current == nullptr)
			cout << "List is empty" << endl;
		else {
			while (current != nullptr)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
	}
};

int main()
{
	DoublyLinkedList LinkedList;

	LinkedList.insertAtStart(6);
	LinkedList.insertAtStart(4);
	LinkedList.insertAtStart(3);
	LinkedList.insertAtStart(2);
	LinkedList.insertAtStart(1);

	LinkedList.insertAtEnd(7);
	LinkedList.insertAtEnd(8);
	LinkedList.insertAtEnd(9);
	LinkedList.insertAtEnd(10);

	cout << "Linked List:" << endl;
	LinkedList.display();
	cout << endl;


	cout << "After sorted insert the list becomes:" << endl;
	LinkedList.sortedInsert(5);
	LinkedList.display();
	cout << endl;


	cout << "After Deleting a value from end:" << endl;
	LinkedList.deleteFromEnd();
	LinkedList.display();
	cout << endl;


	cout << "After Deleting a value from start:" << endl;
	LinkedList.deleteFromStart();
	LinkedList.display();
	cout << endl;


	cout << "Deleting a specific value:" << endl;
	LinkedList.deleteSpecificValue(4);
	LinkedList.deleteSpecificValue(6);
	LinkedList.display();
	cout << endl;
	

	bool search = LinkedList.Search(3);
	if (search == 0)
	{
		cout << "Value not found" << endl;
	}
	else
		cout << "The address of the searched value is " << LinkedList.Search(3) << endl;
	
	cout << endl;
	system("Pause");
	return 0;
}