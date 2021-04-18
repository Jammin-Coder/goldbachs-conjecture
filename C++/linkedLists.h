#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class List
{
private:
	typedef struct Node
	{
		int data;
		struct Node* next;
		struct Node* prev;
	} node;

	// Private methods
	node* m_listNode()
	{
		node* head = NULL;
		head = (node*)malloc(sizeof(node));

		head->data = 0; // This just initializes the list the first time, so it's ignored.
		head->next = NULL;
		head->prev = NULL;

		return head;
	}
	
	void m_removeNode(node* target)
	{	
		node* nextNode = target->next;
		node* prevNode = target->prev;
		
		if(prevNode != NULL && nextNode != NULL)
		{
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}
        m_size--;
		free(target);

	}

    void copyNode(node* dest, node* src)
    {
        dest->next = src->next;
        dest->prev = src->prev;
        dest->data = src->data;
    }

	// Private variables.
	node* m_head = m_listNode();
	node* m_first = m_head; // Sets the first list node to the current state of m_head
	node* m_last = m_head;
	node* m_lastRemovedNode = m_listNode();
	int m_lastRemovedIndex;

public:
	int m_size = 0;
	// prints list
	void print()
	{
		m_head = m_first;
		// The list function initializes the list
		// with 0, so when the list is printed, we skip the first one.
		if(m_size != 0)
		{
			if(m_head->next != NULL)
			{
				m_head = m_first->next;
			}
			while(m_head != NULL)
			{
				printf("%d, ", m_head->data);
				m_head = m_head->next;
			}
		} else
		{
			printf("[-] Nothing in list.\n");
			exit(0);
		}
		printf("\n");
	}

	int remel(int index)
	{
		int maxIndex = m_size - 1;

		// Index out of range
		if(index > maxIndex)
		{
			cout << "[ERROR]: Index out of range!\n";
			exit(1);
		}

        m_head = m_first->next;
        // Start at the beginning of the list and iterate over the items until reaching the desired index.
		for(int i = 0; i <= index; i++)
		{
			if (i == index && m_head != NULL)
			{
				int data = m_head->data;
                copyNode(m_lastRemovedNode, m_head);
				m_removeNode(m_head);
			    return data;
			}
			m_head = m_head->next;
		}

		cout << "[ERROR]: Something went wrong while removing element from index " << index << endl;
		cout << "Make sure list is not empty, and index is not out of range.\n";
		exit(1);
	}

    void slice(int startIndex, int endIndex)
    {
        int maxIndex = m_size - 1;

		// Index out of range
		if(startIndex > maxIndex)
		{
			cout << "[ERROR]: Index out of range!\n";
			cout << "Max index is " << maxIndex << " but you chose " << startIndex << " for slice start.\n";
			exit(1);
		}
        if(endIndex > maxIndex)
        {
            cout << "[ERROR]: Index out of range!\n";
			cout << "Max index is " << maxIndex << " but you chose " << endIndex << " for slice end.\n";
			exit(1);
        }
		remel(startIndex);

		for(int i = startIndex + 1; i <= endIndex; i++)
		{
		        node* target = m_lastRemovedNode->next;
		        copyNode(m_lastRemovedNode, target);
		        m_removeNode(target);

		}

    }

	int index(int index)
	{
		int maxIndex = m_size - 1;
		m_head = m_first;
		if (index > maxIndex)
		{
			cout << "[ERROR] No element at index " << index << "!!!\n";
			cout << "The length of the list you are accessing is only " << m_size << endl;
			exit(1);
		}
		if(m_head->next != NULL)
		{
			m_head = m_head->next;
		}
		for(int i = 0; i <= index; i++)
		{
			if(i == index)
			{
				return m_head->data;
			}
			m_head = m_head->next;
		}
		exit(1);
	}
	
	// appends to list
	void append(int value)
	{
		node* nextNode = m_listNode();
		m_last->next = nextNode;
		nextNode->prev = m_last;
		nextNode->data = value;
		m_last = nextNode;

		m_size++;
	}

	int size()
	{
		return m_size;
	}
};


