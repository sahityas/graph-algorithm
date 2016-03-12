#include<iostream>
#include <limits>
using namespace std;
struct vertex{
	int dist;
	bool known;
	int parent;};
class graph{
	vertex v[100];
	int a[100][100];
	int n,noe;
	
	public:
		void input(){
			int i,p,q,r,j;
			cout<<"Enter number of vertices : ";
			cin>>n;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i==j)
						a[i][j]=0;
					else
						a[i][j]=INT_MAX;}}
			cout<<"Enter the number of edges : ";
			cin>>noe;
			cout<<"Enter the edges connected along with weights"<<endl;
			for(i=0;i<noe;i++){
				cin>>p>>q>>r;
				a[--p][--q]=r;}
			for(i=0;i<n;i++){
				v[i].dist=INT_MAX;
				v[i].known=false;
				v[i].parent=0;}}
		int findmin(int a[100][100]){
			int i,minimum;
			for(i=0;i<n;i++){
				if(v[i].known==false)
					minimum=i;}
			for(i=0;i<n;i++){
				if(v[i].dist<v[minimum].dist && v[i].known==false)
					minimum=i;}
			return minimum;}
		void displayv(){
			int i;
			for(i=0;i<n;i++){
				cout<<i+1<<"\t"<<v[i].dist<<"\t"<<v[i].parent<<endl;}}
		void displaya(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(a[i][j]==INT_MAX)
						cout<<"INF\t";
					else
						cout<<a[i][j]<<"\t";}
				cout<<endl;}}
		void dijkstra(int ver){
			int i,minimum,flag=0;
			v[--ver].dist=0;
			v[ver].known=true; flag++;
			for(i=0;i<n;i++){
				if(a[ver][i]!=INT_MAX && a[ver][i]!=0){
					v[i].dist=a[ver][i];
					v[i].parent=ver+1;}}
			while(flag<n){
				minimum=findmin(a);
				v[minimum].known=true; flag++;
				for(i=0;i<n;i++){
					if(a[minimum][i]!=INT_MAX && a[minimum][i]!=0){
						if(!v[i].known){
							if(v[minimum].dist+a[minimum][i]<v[i].dist){
								v[i].dist=v[minimum].dist+a[minimum][i];
								v[i].parent=minimum+1;}}}}}}
		
		void display(){
			int i;
			cout<<"SHORTEST PATHS FROM SOURCE"<<endl;
			for(i=1;i<n;i++)
				cout<<"Vertex :"<<i+1<<"\tDistance : "<<v[i].dist<<"\tParent : "<<v[i].parent<<endl;}
		void displaypath(int source,int v1,int v2){
			int i,temp,path[100],j=0;
			cout<<"Shortest path between vertex "<<v1<<" and "<<v2<<" is "<<source<<" ";
			i=v2-1;
			while(temp!=source){
				temp=v[i].parent;
				if(temp!=source){path[j]=temp;j++;}
				i=v[i].parent-1;}
			j--;
			while(j>=0){
				cout<<path[j]<<" ";
				j--;}
			cout<<v2<<endl;}};

int main(){
	int ch=1,ver,v1,v2;
	graph g;
	cout<<"1.INPUT GRAPH\n2.DISPLAY ADJACENCY MATRIX\n3.PERFORM DIJKSTRA\n4.DISPLAY RESULT\n";
	cout<<"5.DISPLAY THE PATH BETWEEN TWO VERTICES\n6.EXIT"<<endl;
	while(ch!=6){
		cout<<"\nENTER CHOICE : ";
		cin>>ch;
		if(ch==1) {g.input();}
		if(ch==2){ cout<<"ADJACENCY MATRIX"<<endl;g.displaya();}
		if(ch==3){
			cout<<"Enter the source vertex : ";
			cin>>ver;
			g.dijkstra(ver);}
		if(ch==4) g.display();
		if(ch==5){
			cout<<"Enter vertex 1 : ";
			cin>>v1;
			cout<<"Enter vertex 2 : ";
			cin>>v2;
			g.displaypath(ver,v1,v2);}}
	return 0;}
