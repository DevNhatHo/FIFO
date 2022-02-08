#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int size;
    int flag;
    int id;
    Node* next;
    Node* previous;
};


//global declarations
Node* res = NULL;
Node* a = NULL;
Node* b = NULL;
Hole *remLastPosition;
Hole *tempHole;
int allocations=0;
bool noHole=false;
void mergeHole(Node* head);


/* Function to insert a node at 
the beginging of the linked list */
void push(Node** head_ref, int id, int size, int flag)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->id = id;
    new_node->size = size;
    new_node->flag=flag;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

//Function will scan list with Two consecutive flags of "0"(00) and update the list so there will be one open memory i.e. 1 hole(instead of 2 holes)
void mergeHole(Node* head){
     Node *ptr1, *ptr2, *dup;
     ptr1 = head;
     

     while(ptr1 !=NULL &&ptr1->next!=NULL)
     {
        ptr2 =ptr1;

        if(ptr1->flag == 0 && ptr2->next->flag ==0)
        {
            ptr1->size= ptr1->size+ptr2->next->size;
            cout<<"\n"<<"YES\n";
            dup = ptr2->next;
                
                ptr2->next = ptr2->next->next;
                delete(dup);
        }

        
        
            

        ptr1=ptr1->next;
        ptr2=ptr2->next;
        

    }
}

void  FirstFit(Node* a, Node *b)
{
    Node *ptr1, *ptr2;
    ptr1 = a;
    ptr2 = b;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if((ptr1->size >= ptr2->size) &&(ptr1->flag==0) )
        {
            ptr1->id=b->id;
            ptr1->size=b->size;
            ptr1->flag=1;
        }

        ptr1=ptr1->next;

            
        
    }// end of while


   
}


void editsizeDel(Node* head, int id){
    Node* current = head;
    //current->size=size;
    while (current != NULL)
    {
        if (current->id == id){
            current->flag = 0;
             current->id = 0;


        }


        
        current = current->next;
    }
    mergeHole(a);


}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    cout << "ID\t\tsize\t\tFLAG\t\t\n";
    while (node!=NULL)
    {
         

        cout<<node->id<<"\t\t";
        cout<<node->size<<"\t\t";
        cout<<node->flag<<"\n";
        node = node->next;
    }
}



int main()
{
    
   push(&a, rand()%999999, 3,0);
   push(&a, rand()%999999, 5,1);
   push(&a, rand()%999999, 3,1);
   push(&a, rand()%999999, 7,1);
   push(&a, rand()%999999, 10,0);
   push(&a, rand()%999999, 3,1);
   push(&a, rand()%999999, 10,1);
   push(&a, rand()%999999, 4,1);
   push(&a, rand()%999999, 7,0);
   push(&a, rand()%999999, 3,1);
   push(&a, rand()%999999, 9,0);
   push(&a, rand()%999999, 3,1);
   push(&a, rand()%999999, 3,1);
   push(&a, rand()%999999, 5,0);
   push(&a, rand()%999999, 7,1);
   push(&a, rand()%999999, 4,1);
   push(&a, rand()%999999, 6,1);
   push(&a, rand()%999999, 9,0);
   push(&a, rand()%999999, 3,1);
   push(&a, rand()%999999, 10,1);
   push(&a, 2, 4,1);
   push(&a, rand()%999999, 7,0);
   push(&a, rand()%999999, 3,1);
   editsizeDel(a,2);
   printList(a);


   push(&b, rand()%999999, rand() % 10 +3 ,1);
   printList(b);
   FirstFit(a,b);
   printList(a);
   

   
   
   
    



 
    return 0;
}


