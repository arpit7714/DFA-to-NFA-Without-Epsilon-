#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
#define length 20

vector<int> finalsatesnfa;


class nfastates{
public:	
	int transition[length][length];
	nfastates(){
		
		for(int i=0;i<length;i++){
			for(int j=0;j<length;j++){
				transition[i][j]=-1;
			}
		}
	}	
};
string converttostring(vector<int> vec){
	//cout<<vect<<"\n";
	ostringstream oss;
	sort(vec.begin(),vec.end());

  if (!vec.empty())
  {
    	copy(vec.begin(), vec.end()-1,
    	ostream_iterator<int>(oss, ","));
    	oss << vec.back();
  }
  string st=oss.str();
  int flag=0;
  for(int i=0;i<vec.size();i++){
  		if (find(finalsatesnfa.begin(), finalsatesnfa.end(), vec[i]) != finalsatesnfa.end()){
  			flag=1;
  		}
	}
	if (flag==1) {
		st+="f";
	}	
	//cout<<ct<<" ";
	//cout<<st;
	return st;
}

int main(){
	int n,m,x,no,y,z,y1,fint;
	unordered_map<string,int>map1;
	ifstream in("nfa.txt");
	in>>n>>m;
	//cout<<n<<" "<<m<<"\n";
	//nfastates numstates[n];
	nfastates obj[n];
	in>>fint;
	for(int i=0;i<fint;i++){
		in>>x;
		finalsatesnfa.push_back(x);
		//cout<<x<<" ";
	}
	in>>no;
	//cout<<"\n";
	while(no--){
		in>>x>>y>>z;       //x is previous state y is the symbol and z is the number of states that x can visit
		for(int i=0;i<z;i++){
			in >> y1;
			//cout<<y1<<" ";
			obj[x].transition[y-1][i]=y1;
		}//cout<<"\n";
	}
	in.close();
	//--------------------------------------------------------------------------------------------------------------
	string ft[length][m+1];
	queue<vector<int>> qq;

	map1["0"]=1;

	int flag1=0;
	if (find(finalsatesnfa.begin(), finalsatesnfa.end(), 0) != finalsatesnfa.end()){
		ft[0][0]="0f";
	}
	else{
		ft[0][0]="0";
	}
	for(int i=0;i<m;i++){
		int j=0;
		vector<int> arr;
		while(obj[0].transition[i][j]!=-1){
			arr.push_back(obj[0].transition[i][j]);
			j++;
		}
		if (arr.size()!=0){
			string s=converttostring(arr);
			//cout<<" "<<s<<"\n";
			if (map1.find(s)==map1.end()){
				//cout<<"map2 runned\n";
				map1[s]=1;
				qq.push(arr);
			}
			//cout<<s<<"\n";
			ft[0][i+1]=s;
		}
		else{
			ft[0][i+1]="-1";
			flag1=1;

		}
		arr.clear();
	}
	int id=0;
	
	unordered_map<int ,int>map2;
	
	while(!qq.empty()){
		vector <int> arr=qq.front();
		//cout<<"\nvalue "<<converttostring(arr)<<"\n";
		qq.pop();
		id++;
		ft[id][0]=converttostring(arr);
		for(int i=0;i<m;i++){
			vector <int> arr1;
			for(int j=0;j<arr.size();j++){
				int k=0;
				while(obj[arr[j]].transition[i][k]!=-1){
						int res=obj[arr[j]].transition[i][k];
						if(map2.find(res)==map2.end()){
							map2[res]=1;
							arr1.push_back(res);
						}
					k++;
				}
			}
			map2.clear();
			if (arr1.size()!=0){
					//cout<<"\n"<<id<<" "<<converttostring(arr1)<<"\n";
					ft[id][i+1]=converttostring(arr1);
					string str=converttostring(arr1);
					if (map1.find(str)==map1.end()){
						map1[str]=1;
						qq.push(arr1);
					}
			}
			else{
			 		ft[id][i+1]="-1";
			 		flag1=1;
			} 
			arr1.clear();
		}
		arr.clear();
	}
	if (flag1==1){
		ft[++id][0]="-1";
		ft[id][1]="-1";
		ft[id][2]="-1";
	}
	//cout<<"\n"<<id<<"\n";
	cout<<"DFA for the corresponding NFA\n";
	for(int i=0;i<=id;i++){
		for(int j=0;j<3;j++){
			cout<<ft[i][j]<<"  ";
		}cout<<"\n";
	}
	ofstream out("dfa.txt");
	for(int i=0;i<=id;i++){
		for(int j=0;j<3;j++){
			out<< ft[i][j] <<"     ";
		}out<<"\n";
	}
	out.close();
}