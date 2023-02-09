#include<iostream>
using namespace std;

class NODE
{
    int data;
    NODE*next;
    public:
    NODE(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    void insertF(NODE* &head,int x);
    void insertL(NODE* &head,int x);
    void insertR(NODE* &head,int x,int pos);
    void display(NODE* &head);
    int size(NODE* &head);
    int deleteF(NODE* &head);
    int deleteL(NODE* &head);
    int deleteR(NODE* &head,int pos);

};
void NODE::insertF(NODE* &head,int x)
{
    NODE* temp=new NODE(x);
    if(head==NULL)
    {
        head=temp;
    }
   else
   {
    temp->next=head;
    head=temp;
   }
}
void NODE::insertL(NODE* &head,int x)
{
     NODE* temp=new NODE(x);
     NODE* p;
     if(head==NULL)
     {
        head=temp;
     }
     else
     {
        for(p=head;p->next!=NULL;p=p->next);
      p->next=temp;
     }
}
void NODE::insertR(NODE* &head,int x,int pos)
{
    NODE* temp=new NODE(x);
    NODE* p;
    int i;
    int l=size(head);

        if(pos==1)
        insertF(head,x);
        else if(pos==l+1)
        insertL(head,x);
        else if(pos<0||pos>l+1)
         cout<<"invalid position";
        else
            {
                for(p=head,i=1;i<(pos-1);i++,p=p->next);
           temp->next=p->next;
           p->next=temp;
            }
         
    


}
void NODE::display(NODE* &head)
{
    NODE* p;
    if(head==NULL)
    {
        cout<<"list is empty";
    }
    else
   {
     for(p=head;p!=NULL;p=p->next)
     cout<<p->data<<" ";
   }

}
int NODE::size(NODE* &head)
{
    NODE* p;
    int i=0;
    if(head==NULL)
    {
        cout<<"list is empty";

    }
    else
    {
        for(p=head;p!=NULL;i++,p=p->next);
       return i;
    }

}
int NODE::deleteF(NODE* &head)
{
    int x;
    NODE*p;
    p=head;
    head=p->next;
    x=p->data;
    delete p;
    return x;

}
int NODE::deleteL(NODE* &head)
{
    int x;
    NODE*p,*t;
    for(p=head;p->next!=NULL;t=p,p=p->next);
    x=p->data;
    t->next=NULL;
    delete p;
    return x;
   
}

int NODE::deleteR(NODE* &head,int pos)
{
   int x,i;
   NODE*p,*t;
   int l=size(head);
   if(pos==1)
    deleteF(head);
   else if(pos==l)
     deleteL(head);
   else if(pos<0||pos>l)
     cout<<"invalid position";
   else 
     {
        for(p=head,i=1;i<(pos-1);i++,p=p->next);
        t=p->next;
        x=t->data;
        p->next=t->next;
        
     }  
     return x;  
}

int main()
{
    NODE* node=new NODE(10);
    int ch,x,pos,k;
    NODE *head=NULL;
    cout<<"\n1.insert first\n2.insert last\n3.insert random\n4.display\n5.delete first\n6.delete last\n7.delete random\n8.size\n9.exit"<<endl;
    do
    {
        cout<<"enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
              cout<<"enter the value you have to insert:";
              cin>>x;
              node->insertF(head,x);
              break;
            case 2:
               cout<<"enter the value you have to insert:";
               cin>>x;
               node->insertL(head,x);
               break;
            case 3:
               cout<<"enter the value you have to insert:";
               cin>>x;
               cout<<"enter the position at which you have to insert:";
               cin>>pos;
               node->insertR(head,x,pos);
               break;
            case 4:
                 node->display(head);
                 break;
            case 5:
                  k=node->deleteF(head);
                  cout<<"deleted element is:"<<k<<endl;
                  break;
            case 6:
                k=node->deleteL(head);
                cout<<"deleted element is:"<<k<<endl;
                break;
            case 7:
                cout<<"enter the position from which you have to delete:";
                cin>>pos;
                k=node->deleteR(head,pos);
                cout<<"deleted element is:"<<k<<endl;
                break;
            case 8:
                k=node->size(head);
                cout<<"size of list is:"<<k<<endl;
                break;                  
            case 9:
                 cout<<"exit";
                 break;


        }

    }while(ch!=9);
    
    
    return 0;
}