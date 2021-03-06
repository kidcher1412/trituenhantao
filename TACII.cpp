#include<bits/stdc++.h>
#define MAXN 25
typedef long long int ll;

using namespace std;
enum facing {
	LEFT , RIGHT , UP , DOWN , STAY
};

int puzzle[MAXN][MAXN],taget[MAXN][MAXN] , posX , posY , cost,n;

class node{
	public :
		int arr[MAXN][MAXN],end_arr[MAXN][MAXN] , x , y , f;
		string way;
		facing canFace;
		
		node(int a[MAXN][MAXN],int b[MAXN][MAXN] , string way , facing canFace , int x , int y , int f){
			this->f = f;
			this->way = way;
			this->canFace = canFace;
			this->x = x;
			this->y = y;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					arr[i][j] = a[i][j];
					end_arr[i][j] = b[i][j];
				}
			}
		}
		
		bool canMoveLeft(){
			return canFace != LEFT && y > 0 && cost > herStic();
		}
		bool canMoveRight(){
			return canFace != RIGHT && y < 2 && cost > herStic();
		}
		bool canMoveUp(){
			return canFace != UP && x > 0 && cost > herStic();
		}
		bool canMoveDown(){
			return canFace != DOWN && x < 2 && cost > herStic();
		}
		
		int herStic(){
			int sum = 0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(arr[i][j]!=end_arr[i][j]) sum++;
				}
			}
			return sum + f;
		}
		
		void moveLeft(){
			swap(arr[x][y] , arr[x][y-1]);
			y--;
			canFace = RIGHT;
			way += "l";
			f++;
		}
		void moveRight(){
			swap(arr[x][y] , arr[x][y+1]);
			y++;
			canFace = LEFT;
			way += "r";
			f++;
		}
		void moveUp(){
			swap(arr[x][y] , arr[x-1][y]);
			x--;
			canFace = DOWN;
			way += "u";
			f++;
		}
		void moveDown(){
			swap(arr[x][y] , arr[x+1][y]);
			x++;
			canFace = UP;
			way += "d";
			f++;
		}
		
bool checkFinish(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
				if(arr[i][j] != end_arr[i][j])
					return false;
		}
	
}
return true;
}
};

void moveLeft(){
	swap(puzzle[posX][posY] , puzzle[posX][posY-1]);
	posY--;
}
void moveRight(){
	swap(puzzle[posX][posY] , puzzle[posX][posY+1]);
	posY++;
}
void moveUp(){
	swap(puzzle[posX][posY] , puzzle[posX-1][posY]);
	posX--;
}
void moveDown(){
	swap(puzzle[posX][posY] , puzzle[posX+1][posY]);
	posX++;
}

void initPuzzle(){
	cout<<"nhap chi so n cho puzzle va taget: "; 
	cin>>n;
	cout << "Nhap cac gia tri cho puzzle : ";
	 for (int i = 0; i < n; i++)
	 for (int j = 0; j < n; j++)
	 	cin>>puzzle[i][j];


	cout << "Nhap cac gia tri cho taget : ";
	 for (int i = 0; i < n; i++)
	 for (int j = 0; j < n; j++)
	 	cin>>taget[i][j];	
	cout << "Nhap chi phi toi da cua thuat toan = ";
	cin >> cost; 
	
//	fstream inp("TACII.inp");
//	inp>>cost;
//	for (int i = 0; i < 3; i++)
//	for (int j = 0; j < 3; j++)
//		inp>>puzzle[i][j];
//	inp.close();
	bool checked = true;
	int sum = 0;
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			sum += puzzle[i][j];
			if(puzzle[i][j] > 8) {
				checked = false;
				break;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(puzzle[i][j] == 0){
				posX = i;
				posY = j;
				return;
			}
		}
	}
}
int soH(int puzzle[MAXN][MAXN]){
			int sum = 0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
				if(puzzle[i][j] != taget[i][j])
					sum++;
				}
			}
			return sum;
		}
void prin(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}
		
bool checkFinish(){
	int sum=0;
for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
				if(puzzle[i][j] == taget[i][j])
					sum=sum+1;
}}
	if(sum<n*n) return true;
	return false;
}
int checkFinish1(){
	int sum=0;
for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
				if(puzzle[i][j] == taget[i][j])
					sum=sum+1;
}}
	return sum;
}
// 2 8 3 1 6 4 7 0 5
// 1 2 3 8 0 4 7 6 5
int main(){
	int step = 0 ;
	bool check = checkFinish();
	initPuzzle();
//	const clock_t begin_time = clock();
	string way = "";
	node nd(puzzle,taget , "" , STAY , posX , posY , 0);
	vector<node> vt;
	vt.push_back(nd);
	int coster=0;
	cout << "Trang thai ban dau : " << endl;
	cout<<"g= "<<coster<<endl;
	cout<<"h ="<<soH(puzzle)<<endl;
	cout<<"f= "<<coster+soH(puzzle)<<endl;
	prin();
	cout<<"===================================="<<endl;
	cout << endl;
	while(!check && vt.size() != 0){
		vector<node> open;
			int i = vt.size()-1;
			if(vt.at(i).checkFinish()){
				way = vt.at(i).way;
				check = true;
				break;
			}else{
				if(vt.at(i).canMoveUp()){
					node nd = vt.at(i);
					nd.moveUp();
					open.push_back(nd);
				}
				if(vt.at(i).canMoveDown()){
					node nd = vt.at(i);
					nd.moveDown();
					open.push_back(nd);
				}
				if(vt.at(i).canMoveRight()){
					node nd = vt.at(i);
					nd.moveRight();
					open.push_back(nd);
				}
				if(vt.at(i).canMoveLeft()){
					node nd = vt.at(i);
					nd.moveLeft();
					open.push_back(nd);
				}
			}
			vt.pop_back();
			
		for(int i=0;i<open.size();i++){
			for(int j=i+1;j<open.size();j++){
				if(open.at(i).herStic() <= open.at(j).herStic()){
					swap(open.at(i) , open.at(j));
				}
			}
			
		}
		for(int i=0;i<open.size();i++){
			if(open.at(i).herStic() == open.at(open.size()-1).herStic())
			vt.push_back(open.at(i));
			
		}
	}
	if(!check){
		cout << "Thuat toan that bai , khong tim duoc dich";
		return 0;
	}
	coster++;
	for(int i=0;i<way.length();i++,coster++){
		if(way[i] == 'l'){
			moveLeft();
			cout<<"STEP "<<i+1<<"-------------------------------------------"<<endl;
			cout << "di chuyen sang trai" << endl;
			cout<<"g= "<<coster<<endl;
			cout<<"h ="<<soH(puzzle)<<endl;
			cout<<"f= "<<coster+soH(puzzle)<<endl<<endl;
			prin();
		}else if(way[i] == 'r'){
			moveRight();
			cout<<"STEP "<<i+1<<"-------------------------------------------"<<endl;
			cout << "di chuyen sang phai" << endl;
			cout<<"g= "<<coster<<endl;
			cout<<"h ="<<soH(puzzle)<<endl;
			cout<<"f= "<<coster+soH(puzzle)<<endl<<endl;
			prin();
		}else if(way[i] == 'u'){
			moveUp();
			cout<<"STEP "<<i+1<<"-------------------------------------------"<<endl;
			cout << "di chuyen len tren" << endl;
			cout<<"g= "<<coster<<endl;
			cout<<"h ="<<soH(puzzle)<<endl;
			cout<<"f= "<<coster+soH(puzzle)<<endl<<endl;
			prin();
		}else if(way[i] == 'd'){
			moveDown();
			cout<<"STEP "<<i+1<<"-------------------------------------------"<<endl;
			cout << "di chuyen xuong duoi" << endl;
			cout<<"g= "<<coster<<endl;
			cout<<"h ="<<soH(puzzle)<<endl;
			cout<<"f= "<<coster+soH(puzzle)<<endl<<endl;
			prin();
		}
	}
	cout << "tim cach giai TACII da hoan thanh!!!" << endl;
system("pause");
return 0;
}
