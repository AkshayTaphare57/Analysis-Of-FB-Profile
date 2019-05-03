
#include<iostream>
#include<stdlib.h>
#include<cstring>
#define MAX 20
#define TRUE 1
#define FALSE 0
using namespace std;
class FB
{
	typedef struct node1
	{
		int vertex;
		int comments;
		char bd[20];
		struct node1 *next;
	}node;
	node *head[MAX];
	struct friendlist
	{
		int no_of_friends;
		int comments;
		char bd[20];
	}friends[MAX];
	int visited[MAX];
	int Q[MAX], front, rear;
	public:

	FB()
	{
		int V1;
		for(V1=0;V1<MAX;V1++)
			visited[V1] = FALSE;
		front = rear = -1;
		for(V1=0;V1<MAX;V1++)
			head[V1] = NULL;
	}

	void create();
	void bfs(int);
};

void FB::create()
{
	int V1, V2, c;
	char ans = 'y';
	node *New;
	node *first;
	cout<<endl<<"Enter Friend's number starting from 0"<<endl;
	do
	{
		cout<<"\nEnter the friends to be linked:\n"<<endl;
		cin>>V1>>V2;
		if(V1>=MAX || V2>=MAX)
			cout<<"Wrong vertex value"<<endl;
		else
		{
			New = new node;		//create node V1 to V2
			if(New==NULL)
				cout<<"Insufficient memory"<<endl;
			New -> vertex = V2;
			New -> next = NULL;
			first = head[V1];
			if(first==NULL)
				head[V1] = New;
			else
			{
				while(first->next!=NULL)
				{
					first = first -> next;
				}
				first -> next = New;
			}

			New = new node;		//create node V2 to V1
			if(New==NULL)
				cout<<"Insufficient memory"<<endl;
			New -> vertex = V1;
			New -> next = NULL;
			first = head[V2];
			if(first==NULL)
				head[V2] = New;
			else
			{
				while(first->next!=NULL)
				{
					first = first -> next;
				}
				first -> next = New;
			}
			cout<<"Enter number of comments for "<<V1<<" : "<<endl;
			cin>>c;
			head[V1] ->comments = c;

			cout<<"Enter birthdate for "<<V1<<" : "<<endl;
			cin>>head[V1]->bd;

			cout<<"Enter number of comments for "<<V2<<" : "<<endl;
			cin>>c;
			head[V2] ->comments = c;

			cout<<"Enter birthdate for "<<V2<<" : "<<endl;
			cin>>head[V2]->bd;
		}
	cout<<"Do you want more people included in the network?(y/n)"<<endl;
	cin>>ans;
	}while(ans=='y' || ans=='Y');
}

void FB::bfs(int V1)
{
	int i, no_of_friends, n, max_friends, friend_node, ch;
	int max_comments, min_comments;
	char ans = 'y';
	char month[3];
	char extractmonth[MAX][3];
	node *first;
	Q[++rear] = V1;
	while(front!=rear)
	{
		i = Q[++front];
		if(visited[i]==FALSE)
		{
			visited[i] = TRUE;
		}

		first = head[i];
		friends[i].comments = head[i] -> comments;
		strcpy(friends[i].bd , head[i]->bd);
		no_of_friends = 0;
		while(first!=NULL)
		{
			if(visited[first->vertex]==FALSE)
			{
				Q[++rear] = first -> vertex;
			}

			first = first -> next;
			no_of_friends++;
		}
		 friends[i].no_of_friends = no_of_friends;
	}
	n = i; //number of nodes
	cout<<"\nUser's Node\tNumber of friends\tNumber of Comments\tBirthdate"<<endl;
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<endl<<i<<"\t\t\t"<<friends[i].no_of_friends<<"\t\t\t"<<friends[i].comments<<"\t\t\t"<<friends[i].bd<<endl;
	}
	cout<<endl;
	do
	{
		cout<<"HOME"<<endl;
		cout<<"1-Who is the most popular? (maximum friends)"<<endl;
		cout<<"2-Who has posted the maximum comments?"<<endl;
		cout<<"3-Who is the silent one(minimum comments)?"<<endl;
		cout<<"4-Enter the month to display birthdays"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				friend_node = 0;
				max_friends = friends[0].no_of_friends;
				for(i=0;i<=n;i++)
				{
					if(max_friends < friends[i].no_of_friends)
					{
						max_friends = friends[i].no_of_friends;
						friend_node = i;
					}
				}
				cout<<"The node "<<friend_node<<" is having the maximum number of friends, that is "<<max_friends<<endl;
				break;

			case 2:
				friend_node = 0;
				max_comments = friends[0].comments;
				for(i=0;i<=n;i++)
				{
					if(max_comments < friends[i].comments)
					{
						max_comments = friends[i].comments;
						friend_node = i;
					}
				}
				cout<<"The node "<<friend_node<<" is having the maximum number of comments, that is "<<max_comments<<endl;
				break;

			case 3:
				friend_node = 0;
				min_comments = friends[0].comments;
				for(i=0;i<=n;i++)
				{
					if(min_comments > friends[i].comments)
					{
						min_comments = friends[i].comments;
						friend_node = i;
					}
				}
				cout<<"The node "<<friend_node<<" is having the minimum number of comments, that is "<<min_comments<<endl;
				break;

			case 4:
				cout<<"Enter month"<<endl;
				cin>>month;
				for(int j=0;j<MAX;j++)
				{
					extractmonth[j][0] = friends[j].bd[3];
					extractmonth[j][1] = friends[j].bd[4];
					extractmonth[j][2] = '\0';
				}
				cout<<"Users having their birthday in this month";
				for(i=0;i<=n;i++)
				{
					if(strcmp(month,extractmonth[i])==0)
					{
						cout<<"User "<<i<<endl;
					}
				}
				break;
		}
	}while(ch<5);
}

int main()
{
	int V1;
	FB g;
	FB();
	g.create();
	cout<<"Enter the person from which you want to travel"<<endl;
	cin>>V1;
	if(V1>=MAX)
		cout<<"Invalid vertex";
	else
	{
		cout<<"Breadth first search is "<<endl;
		g.bfs(V1);
		return 0;
	}

}



























