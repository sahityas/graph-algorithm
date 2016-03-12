#include<iostream>
#include <limits>
using namespace std;
class graph{
	int d[100][100];
	int a[100][100];
	int path[100][100];
	int n,noe;
	public:
		void input(){
			int i,p,q,r,j;
			cout<<"Enter number of vertices : ";
			cin>>n;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					path[i][j]=0;
					if(i==j)
						a[i][j]=0;
					else
						a[i][j]=INT_MAX;
				}
			}
			cout<<"Enter the number of edges : ";
			cin>>noe;
			cout<<"Enter the edges connected along with weights"<<endl;
			for(i=0;i<noe;i++){
				cin>>p>>q>>r;
				a[--p][--q]=r;
			}
		}
		void displayd(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
						if(d[i][j]==INT_MAX)
							cout<<"INF\t";
						else
							cout<<d[i][j]<<"\t";
				}
				cout<<endl;		
			}
			
		}
		void displayp(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
						if(path[i][j]==0)
							cout<<"0\t";
						else
							cout<<path[i][j]+1<<"\t";
				}
				cout<<endl;		
			}
			
		}
		
		void displaya(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(a[i][j]==INT_MAX)
						cout<<"INF\t";
					else
						cout<<a[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		
	void floydwarshall(){
			int i,j,k;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					d[i][j]=a[i][j];
				}
			}
			for(k=0;k<n;k++){
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						if(d[i][k]==INT_MAX || d[k][j]==INT_MAX)
							continue;
						if(d[i][k]+d[k][j]<d[i][j]){
							d[i][j]=d[i][k]+d[k][j];
							path[i][j]=k;
						}
					}
				}
				cout<<"DISTANCE MATRIX AFTER ITERATION "<<k+1<<endl;
				displayd();
				cout<<endl;
				cout<<"PATH MATRIX AFTER ITERATION "<<k+1<<endl;
				displayp();
				cout<<endl;
			}
		}
		
		void display(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i==j)
						continue;
					if(d[i][j]==INT_MAX)
						cout<<"No path from "<<i+1<<" to "<<j+1<<endl;
					else if(path[i][j]==0)
						cout<<"Shortest path from "<<i+1<<" to "<<j+1<<" is direct with distance "<<d[i][j]<<endl;
					else
						cout<<"Shortest path from "<<i+1<<" to "<<j+1<<" is through "<<path[i][j]+1<<" with distance "<<d[i][j]<<endl;
				}
			}
		}
		
		void displaypath(int v1,int v2){
			int i,j;
			i=v1-1;
			j=v2-1;
			if(d[i][j]==INT_MAX)
				cout<<"No path from "<<v1<<" to "<<v2<<endl;
			else{
			cout<<"Shortest path from "<<v1<<" to "<<v2<<" is "<<v1<<" ";
			while(path[i][j]!=0){
				if(path[i][j]==0)
					break;
				else{
					cout<<path[i][j]+1<<" ";
					i=path[i][j];
				}
			}
			cout<<v2<<endl;}
		}
		
};

int main(){
	int ch=1,i,j,v1,v2;
	graph g;
	cout<<"1.INPUT GRAPH\n2.DISPLAY ADJACENCY MATRIX\n3.PERFORM FLOYD WARSHALL\n4.DISPLAY RESULT\n";
	cout<<"5.DISPLAY THE PATH BETWEEN TWO VERTICES\n6.EXIT"<<endl;
	while(ch!=6){
		cout<<"\nENTER CHOICE : ";
		cin>>ch;
		if(ch==1) g.input();
		if(ch==2){ cout<<"ADJACENCY MATRIX"<<endl; g.displaya();}
		if(ch==3) g.floydwarshall();
		if(ch==4) g.display();
		if(ch==5){
			cout<<"Enter vertex 1 : ";
			cin>>v1;
			cout<<"Enter vertex 2 : ";
			cin>>v2;
			g.displaypath(v1,v2);
		}
	}
	return 0;
}
	

