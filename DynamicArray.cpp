#include<bits/stdc++.h>
using namespace std;
int current = 0;
int c = 0;
template <typename type>
class vect
{
	type *p, *t;
	int capacity = 5;
	int current;
	int listcount = 0;
	typedef struct node
	{
    	type *address;
    	struct node *next;
	} linkedlist;
	linkedlist *start = NULL;
	linkedlist *newnode;
	linkedlist *last = NULL;
	linkedlist *temp = NULL;
 
public:
	void create()
	{
    	p = new type[capacity];
    	if (p == NULL)
        	return;
    	current = 0;
    	newnode = (linkedlist *)malloc(sizeof(linkedlist));
    	newnode->address = p;
    	newnode->next = NULL;
    	listcount++;
    	if (start == NULL)
    	{
 
        	start = newnode;
        	last = newnode;
    	}
    	else
    	{
       last->next = newnode;
        	last = newnode;
    	}
	}
	void push(type a)
	{
    	if ((current == 0 && listcount == 0) || current == capacity)
    	{
        	create();
        	current = 0;
    	}
    	p[current] = a;
    	current++;
    	c++;
	}
 
	type get(int idx)
	{
    	if (c > 0)
    	{
        	if (listcount == 1 && idx < c)
            	return p[idx];
        	int q = idx / capacity;
        	int r = idx % capacity;
        	temp = start;
        	if (q < listcount)
        	{
            	for (int i = 1; i < q; i++)
                	temp = temp->next;
            	t = temp->address;
            	if (r == 0)
                	return t[capacity - 1];
        	}
        	return t[r];
    	}
	}
	type peak()
	{
    	if (c != 0)
        	return start->address[0];
    	else
        	cout << "Vector is Empty\n";
	}
	int empty()
	{
    	if (c == 0)
        	return 1;
    	return 0;
	}
	void clear()
	{                                                                 
    	temp = start;                                                   
    	for (int i = 0; i < listcount; i++)
    	{
        	free(temp->address);
        	temp = temp->next;
    	}
    	c = 0;
    	current = 0;
    	listcount = 0;
    	start = last = NULL;
	}
 
	void pop()
	{
    	if (c > 0)
    	{
        	if (current == 0)
        	{
            	if (c == 1)
            	{
                	temp = start;
                	start = last = NULL;
                	start->next = NULL;
                	c = 0;
  	              listcount = 0;
                	current = 0;
                	free(temp->address);
            	}
            	else
            	{
                	temp = start;
                	while (temp->next->next != NULL)
                	{                                                     
                    	temp = temp->next;
                	}
                	last = temp;
                    free(temp->next->address);
                	last->next = NULL;
                	c--;
                	listcount--;
                	current = capacity;
            	}
        	}
        	else
        	{
            	c--;
            	current--;
        	}
    	}
    	else
   	     cout << "Vector is Empty\n";
	}
 
	int size()
	{
    	return c;
	}
 
	int getcapacity()
	{
    	return listcount * capacity;
	}
	void printall()
	{
    	if (c > 0)
    	{
        	temp = start;
        	while (temp->next != NULL)
        	{
            	for (int i = 0; i < capacity; i++)                     
                	cout << temp->address[i] << " ";
            	temp = temp->next;
        	}
        	for (int i = 0; i < current - 1; i++)
            	cout << temp->address[i] << " ";
        	cout << "\n";
    	}
    	else
        	cout << "Vector is Empty\n";
	}
};
 
int main()
{
	vect<int> v;
 
	return 0;
}
}
