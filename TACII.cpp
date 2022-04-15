#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

enum facing {
	LEFT , RIGHT , UP , DOWN , STAY
};

int puzzle[3][3] , posX , posY , cost;

class node{
	public :
		int arr[3][3] , x , y , f;
		string way;
		facing canFace;
		
		node(int a[3][3] , string way , facing canFace , int x , int y , int f){
			this->f = f;
			this->way = way;
			this->canFace = canFace;
			this->x = x;
			this->y = y;
			for(int i=0;i<=2;i++){
				for(int j=0;j<=2;j++){
					arr[i][j] = a[i][j];
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
				if(arr[0][0] != 1) sum++;
				if(arr[0][1] != 2) sum++;
				if(arr[0][2] != 3) sum++;
				if(arr[1][0] != 8) sum++;
				if(arr[1][2] != 4) sum++;
				if(arr[2][0] != 7) sum++;
				if(arr[2][1] != 6) sum++;
				if(arr[2][2] != 5) sum++;
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
				for(int i=0;i<=2;i++){
					if(arr[0][i] != i+1 || arr[2][i] != 7-i) return false;;
				}
				return arr[1][0] != 8 || arr[1][2] != 4 ? false : true;
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
/*	cout << "Nhap cac gia tri cho puzzle : ";
	cin >> puzzle[0][0] >> puzzle[0][1] >> puzzle[0][2];
	cin >> puzzle[1][0] >> puzzle[1][1] >> puzzle[1][2];
	cin >> puzzle[2][0] >> puzzle[2][1] >> puzzle[2][2];
	cout << "Nhap chi phi toi da cua thuat toan = ";
	cin >> cost; */
	fstream inp("TACII.inp");
	inp>>cost;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		inp>>puzzle[i][j];
	inp.close();
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
	if(sum != 36 || checked == false){
		cout << "Nhap sai du lieu vui long nhap lai" << endl;
		return initPuzzle();
	}
	
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			if(puzzle[i][j] == 0){
				posX = i;
				posY = j;
				return;
			}
		}
	}
}
		int soH(int puzzle[3][3]){
			int sum = 0;

				if(puzzle[0][0] != 1) sum=sum+1;
				if(puzzle[0][1] != 2) sum=sum+1;
				if(puzzle[0][2] != 3) sum=sum+1;
				if(puzzle[1][0] != 8) sum=sum+1;
				if(puzzle[1][2] != 4) sum=sum+1;
				if(puzzle[2][0] != 7) sum=sum+1;
				if(puzzle[2][1] != 6) sum=sum+1;
				if(puzzle[2][2] != 5) sum=sum+1;
			return sum;
		}
void prin(){
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}
}
		
bool checkFinish(){
	int counter1 = 0, counter2 = 0;
	for(int i=0;i<=2;i++){
		if(puzzle[0][i] == i+1) counter1++;
	}
	
	for(int i=0;i<=2;i++){
		if(puzzle[2][i] == 7-i) counter1++;
	}
	if(puzzle[1][0] == 8){
		counter1++;
	} 
	if(puzzle[1][2] == 4) {
		counter1++;
	}
	if(counter1 == 8) return true;
		
	for(int i=0;i<=2;i++){
		if(puzzle[0][i] == i) counter2++;
		if(puzzle[1][i] == i+3) counter2++;
		if(puzzle[2][i] == i+6) counter2++;
	}
	if(counter2 == 8) return true;
	return false;
}
// 2 8 3 1 6 4 7 0 5
int main(){
	int step = 0 ;
	ll numOfNode = 0;
	bool check = checkFinish();
	initPuzzle();
	const clock_t begin_time = clock();
	string way = "";
	node nd(puzzle , "" , STAY , posX , posY , 0);
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
		numOfNode++;
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
return 0;
}
