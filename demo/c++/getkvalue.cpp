#include<iostream>
#include<stack>

using namespace std;

struct linkNode
{
int data;
linkNode *next;
};

void addNode(linkNode **head , int data)
{
   linkNode* newNode=new linkNode;
   newNode->data=data;
   newNode->next=NULL;

   if(*head ==NULL)
   {
	*head=newNode;
   }
   else
   {
     	linkNode *tempNode=*head;

	while((tempNode->next) !=NULL)
		tempNode=(tempNode->next);
	(tempNode->next)=newNode;
   }

}

void findDeleteNode(linkNode* *head,int data)
{
    if((head==NULL)||(*head==NULL))
    	return ;

    linkNode *deleteNode=NULL;
    if((*head)->data==data)
    {
	deleteNode=*head;
	(*head)=(*head)->next;
    }  
    else
    {
	linkNode* tempNode=*head;
	while(tempNode->next!=NULL && tempNode->next->data!=data)
		tempNode=tempNode->next;

	if((tempNode->next !=NULL && tempNode->next->data ==data))
	{
		deleteNode = tempNode->next;
		tempNode->next=tempNode->next->next;
	}
	
	if(deleteNode != NULL)
	{
		delete deleteNode;
		deleteNode=NULL;
	}
    }
}

void printInvStack(linkNode *head)
{
   stack<linkNode *>nodes;
   linkNode * tempNode =head;
   
   while(tempNode != NULL)
   {
	nodes.push(tempNode);
	tempNode=tempNode->next;
   }

   while(!nodes.empty())
   {
	tempNode=nodes.top();
	cout<<tempNode->data<<" ";
   }
   //cout<<endl;

}

void printInvRecur(linkNode *head)
{
   if(head!=NULL)
   {
	if((head->next)!=NULL)
		printInvRecur(head->next);
	cout<<(head->data)<<" ";
   }
//   cout<<endl;
}

void printlinkNode(linkNode *head)
{
if(head==NULL)
	return;
cout<<head->data<<" ";
while(head->next!=NULL)
{
	cout<<head->next->data<<" ";
	head->next=head->next->next;
}

cout<<endl;
}

linkNode *Reverselist(linkNode* head)
{
linkNode *p1,*p2,*p3;
p1=NULL;
p2=head;
p3=head->next;

while(p2!=NULL)
{
p2->next=p1;
p1=p2;
p2=p3;
if(p3!=NULL)
{
p3=p3->next;
}
}

return  p1;
}

linkNode* getkvalue(linkNode *head, int k)
{
if(0==k||NULL==head)
	return NULL;
linkNode *slow=head;
linkNode *fast=head;

for(int i=0;i<k-1;i++)
{
	fast=fast->next;
	if(fast==NULL)
		return NULL;
	//fast=fast->next;
}

while(fast->next!=NULL)
{
slow=slow->next;
fast=fast->next;
}
cout<<slow->data;
return slow;
}


int main()
{
linkNode *head;

//head->data=3;
//head->next=NULL;
addNode( &head,3);
addNode( &head,5);
addNode( &head,8);
//printInvRecur(head);
//printlinkNode(head);

#if 0
findDeleteNode(&head,5);
printInvRecur(head);
cout<<endl;
head=Reverselist(head);
printlinkNode(head);
//printInvStack(head);
#endif
cout<<endl;
head=getkvalue(head,4);
cout<<head->data;

//cout<<endl;
//printlinkNode(head);
return 0;
}

