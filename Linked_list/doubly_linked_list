
#include <iostream>

using namespace std;

template <class T>
class node
{
public:
    T data;
    node* next;
    node* prev;
    node* head= NULL;
    int count = 1;  
public:
    //change in insertion and deletion 
    void insert_beginning(T x)
    {
        node* temp = new node;  
        node* temp1 = head;
        if(count>1)
            temp1->prev = temp;
        temp->data = x;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        count++;
    }
    void insert_end(T x)
    {
        node* temp1 = new node;
        temp1->data = x;
        temp1->next = NULL;

        if (head == NULL)
        {
            temp1->next = head;
            temp1->prev = NULL;
            head = temp1;
            count++;
            return;
        }
       
        node* temp2 = head;
        //we can also use while loop tell we hit the temp2->next != null
        for(int i=0;i<count-2;i++)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        temp1->prev = temp2;
        count++;
   
    }
    const void print()const
    {
        node* temp = head;
        if (head ==NULL)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        while (temp!=NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    //print using recursion
    void print_using_recursion(const node* const head)const
    {
        //if head ==null and count==1 because head==null is the base condition 
        if (head == NULL && count==1)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head == NULL)
        {
            return;
        }
        cout << head->data<<endl;
        print_using_recursion(head->next);
    }
//just call first then cout (draw the recursion tree and remember call stack is astack idiot)
    void reverse_print_using_recursion(const node*const head)const
    {
        if (head == NULL && count == 1)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head == NULL)
        {
            return; 
        }
        
        reverse_print_using_recursion(head->next);
        cout << head->data << endl;
    }

    /* check if not out of range 
     1- if index == 1 make the next of the new node  = head ,and the head = the new node

     2- if not create new node and put the head because we will traverse using the head 
     and we dont want to change it 

     3-start loop from 0 to index -2, because we need to stop at the node that we want to insert
     the index to ,i.e we want to insert at posistion 3 ,so we need to stop at position 2
     take the next of position and make the new node hold it and make the node at position 2 
     hold the address of the new node, first -1 is two stop and the position it self scince 
     the loop start from 0 , second -1 beacuse we have the head node 

     4- then we increament the counter ,counter is usfule when we use the insert to end fucntion 
     to know how many nodes we need to travers, we need to traverse using pointer tell we hit
     the previous of last node ,and take its next address that it point to ,that will be the
     address of last node and make that point to the new node 
     
    */
void insert_At(T x, size_t position)
{
    if (position > count)
    {
        cout << "index out of range" << endl;
        return;
    }

    node* temp1 = new node;
    node* first = head;
    temp1->data = x;
    temp1->next = NULL;
    if (position == 1)
    {
        first->prev = temp1;
        temp1->next = head;
        temp1->prev = NULL;
        head = temp1;
        count++;
        return;
    }
    if (position == count)
    {
        insert_end(x);
        return;
    }
    node* temp2 = head;
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->prev = temp2;
    temp2->next->prev = temp1;
    temp1->next = temp2->next;
    temp2->next = temp1;
    count++;
}
size_t size()
{
    return count - 1;
}
/* get a paper and graph this shit

* deletion logic:

* 1- if we delete node that have a node before it, we need to go to the node before
* that node and get the next of it which will be the node we want to delete and put
* that in temp2(temp2 will point to the node we want to delete because the loop will get
* us to the previous node and the next of the prevoius node is the node we want to delete)
* then we get the next of that and put it in the temp1,then delete the old node
*
* 2-special case if we want to delete first element so we need to sit the head to
* what in the hell that element next point to
*/

// العلم جميل ,ارسم 
void delet_At(int position)
{
    node* temp1 = head;
    if (position == 1 && count >2)
    {
        head = temp1->next;
        temp1->next->prev = NULL;
        delete temp1;
        count--;
        return;
    }
    //only one node in the linked list
    if (position == 1)
    {
        delete temp1;
        head = NULL;
        return;
    }
    for (int i = 0; i < position - 2; i++)
        temp1 = temp1->next;
    //temp 1 point to n-1 node the node that before the node we want to delete
    node* temp2 = temp1->next; //nth node
    //adjust the prev of the node after the node we delete to the previous node of the node
    //we delet
    temp2->next->prev = temp1;
    temp1->next = temp2->next; //n+1 node
    count--;
    delete temp2;
}

void delet()
{
    node* temp = head;
    if (count ==2)
    {
        node* temp1 = temp->next;
        delete temp1;
        head = NULL;
        count--;
        return;

    }
    //go to the node before last node -3 because count start with 1 
    for (int i = 0; i < count - 3; i++)
    {
        temp = temp->next;
    }
    //and then create new node that point to the last node
    //and then put the node before last node to null and delete last node
    node* temp1 = temp->next;
    temp->next = NULL;
    count--;
    delete temp1;
}
/*create  three pointers pointer that point to te current node and previous whose
* initially null ,then next will hold the next node from current then current next
will be the previous ,then we update the prvious to current ,then we make the current
point to the same node next point to , the current hold the current node that will get
change, the next hold the next node because once we change the current node we will lose
the access to the next node ,and previous hold the node that its address ,next will
point to
*/
void reverse_using_iteration()
{
    node* current, * prev, * next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void reverse_print()
{
    node* temp = head;
    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    //going to last node
    while (temp->next != NULL)
        temp = temp->next;

    //traversing backword
    while (temp != NULL)
    {
        cout << temp->data<< endl;
        temp = temp->prev;
    }
}
void reverse_using_recursion(node* temp)
{
    if (temp->next == NULL)
    {
        head = temp;
        return;
    }
    reverse_using_recursion(temp->next);
    // or instead of this two lines we can sat temp->next->next=temp
    // node* q = temp->next;
    // q->next = temp;
    temp->next->next = temp;
    temp->next = NULL;
}
node* get_head()
{
    return head;
}

~node() {
   
    while (head != NULL)
        delet();
    delete head;
}

};



