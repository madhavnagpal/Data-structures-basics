// I am Nothing , You Are Nothing
// Jai Shree Krishna

//bubble sort

#include<bits/stdc++.h>
using namespace std;
#define int long long
void letsStart();


class node
{
public:
  int data;
  node* next;
  node(int d)
  {
    data = d;
    next = NULL;
  }
};

void insertAtEnd(node* &head,int data)
{
  node* n = new node(data);
  if(head==NULL)
  {
    head = n;
    return;
  }
  node* temp = head;
  while(temp->next!=NULL)
    temp = temp->next;
  temp->next = n;
  return;
}

void Print(node* head)
{
  if(head==NULL)
    return;
  cout<<"Linked List is : ";
  while(head)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
}

node* bubbleSort(node* head,int len)
{
  if(head==NULL || head->next==NULL)
    return head;

  for(int i=0;i<len-1;i++)
  {
    node *curr=head,*prev=NULL,*n=head->next;
    node *m=head ,*mPrev=NULL,*mN=head->next;

    //each iteration find max

    for(int j=0;j<len-1-i;j++)
    {

      if(m->data < curr->data)
      {
          m =curr;
          mPrev = prev;
          mN = n;
      }
      prev = curr;
      curr = n;
      n=curr->next;
    }
    // found max now reposi
    // swap prev and m
    if(prev == m){
      //no swap
      continue;
    }
    // swap req
    node* prevN = prev->next;
    //find prevPrev
    node* prevPrev = head;
    while(prevPrev->next != prev)
      prevPrev = prevPrev -> next;

    //swapping prev and m
    if(m == head)
    {
      if(m->next = prev)
      {
        head = prev;
        m->next = prevN;
        head->next = m;
      }else
      {
         head = prev;
         m->next = prevN;
         head->next = mN;
         prevPrev->next = m;
      }
    }else
    {
      if(m->next = prev)
      {
        mPrev->next = prev;
        m->next = prev->next;
        prev->next = m;
      }else
      {
       prevPrev->next = m;
       m->next = prev->next;
       prev->next = mN;
       mPrev->next = prev;
      }

    }//ladder off

  }//loop off

}

int32_t main()
{

  node* head = NULL;
  int n,data;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>data;
    insertAtEnd(head,data);
  }
  Print(head);
  head = bubbleSort(head,n);
  Print(head);

  return 0;
}

void letsStart()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}
