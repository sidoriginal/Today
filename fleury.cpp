#include <algorithm>
#include <iostream>
#include <list>
#include <string.h>
using namespace std;

class Graph{
	int V;
	list <int> *adj;
	public:
		Graph(int a){
			V=a;
			adj=new list<int>[V];
		}
		
		void addedge(int a,int b){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		void deledge(int u,int v){
			list<int>::iterator i=find(adj[u].begin(),adj[u].end(),v);
			*i=-1;
			list<int>::iterator j=find(adj[v].begin(),adj[v].end(),u);
			*j=-1;
		}
			
			int DFS(int u,bool visited[]){
				visited[u]=true;
				 list<int>::iterator i;
				 
				 int count =1;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
    	if(*i!=-1 && visited[*i]!=true){
    		count =count+DFS(*i,visited);
		}
	}
			}
			
			
			bool isvalid(int u,int v){
				int count = 0; 
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        if (*i != -1)
            count++;}
    if (count == 1)
        return true;
        
        bool visited[V];
        
        for(int i=0;i<V;i++){
        	visited[i]=false;
		}
        
        int c1=DFS(u,visited);
        deledge(u,v);
        
         for(int i=0;i<V;i++){
        	visited[i]=false;
		}
        int c2=DFS(u,visited);
        addedge(u,v);
         
        if(c1>c2)
        return false;
        return true;
        
        
			}
			
			
			void euler2(int u){
				list<int>::iterator i;
				for(i=adj[u].begin();i!=adj[u].end();++i){
					int v=*i;
					
					
					if(v!=-1 && isvalid(u,v)){
						cout<<u<<"--"<<v<<endl;
						deledge(u,v);
						euler2(v);
					}
				}
		}
		
		void euler(){
			int u=0;
			for(int i=0;i<V;i++){
				if(adj[i].size()%2!=0){
					u=i;
					break;
				}
			}
			
			euler2(u);	
		
		}
		
	
		
	
};


int main()
{
    // Let us first create and test graphs shown in above
    // figure
    Graph g1(4);
    g1.addedge(0, 1);
    g1.addedge(0, 2);
    g1.addedge(1, 2);
    g1.addedge(2, 3);
    g1.euler();

 
   return 0;}
