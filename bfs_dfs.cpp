 //AIM : DEPTH FIRST TRAVERSAL OF THE GRAPH 

#include<stack>
#include<iostream>

using namespace std;

int main()
{
    int n,v; int a[10][10];
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    int visited[n];
    cout<<"Enter adjacency matrix: \n";
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Adjacency matrix: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    stack <int> s;
    cout<<"Enter starting vertex"<<endl;
    cin>>v;
    s.push(v);
    cout<<"The traversed sequence is :"<<endl;

    while(!s.empty())
    {
        v=s.top();
        s.pop();
        if(visited[v] == 0)
        {
            visited[v]=1;
        for(int w=0; w<n; w++)
        {
            if(a[v][w] == 1 && visited[w] == 0)
            {
              s.push(w);
            }

        }
        }
        cout<< v << " "<<endl;

    }

}


  // TO IMPLEMENT BREADTH FIRST SEARCH ON A GRAPH

#include<queue>
#include<iostream>

using namespace std;

int main()
{
    int n,v; int a[10][10];
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    int visited[n];
    cout<<"Enter adjacency matrix: \n";
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Adjacency matrix: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter starting vertex"<<endl;
    cin>>v;
    visited[v]=1;
    queue <int> q;
    q.push(v);
    cout<<"The traversed sequence is :"<<endl;

    while(!q.empty())
    {
        v=q.front();
        q.pop();
        for(int w=0; w<n; w++)
        {
            if(a[v][w] == 1 && visited[w] == 0)
            {
              visited[w]=1;
              q.push(w);
            }

        }
        cout<< v << " "<<endl;

    }

} 
