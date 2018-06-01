#include "Board.h"
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
static int file_num=0;


const int Board:: size() const {return this->num;}

Board::Board( const Board& b){
    num = b.num;
    Character** temp = new Character*[num];
    for(int i = 0 ; i < num ; i++)
        temp[i] = new Character[num];

    for(int i=0;i<this->num;i++){
        for(int j=0; j<this->num;j++){
            temp[i][j]=b.board[i][j];
        }
    }
    this->board=temp;
}

Board::~Board()
{
    for(int i = 0 ; i < num ; i++)
        delete board[i];
    delete board;
}

ostream& operator << (ostream& os, const Board& c){
    for(int i=0 ; i<c.num ; i++){
        for(int j=0 ; j<c.num ; j++){
            os<<c.board[i][j];
        }
            os<<endl;
    }
    return os;
}

 Character& Board::operator [](Coordinate p) const{
    if(p.x<num && p.y<num){
        return board[p.x][p.y];
    }
    else
        throw IllegalCoordinateException(p);
}

void Board::operator = (char c) const {
    if(c=='.'){
        Character temp(c);
        for(int i=0; i<this->num; i++){
            for(int j=0; j<this->num; j++){
                this->board[i][j]=temp;
            }
        }
      //  return (*this);
    }

    else
        throw IllegalCharException(c);
}

 Board& Board::operator = (const Board& b){
    this->num=b.num;
     Character** temp = new Character*[num];
    for(int i = 0 ; i < num ; i++)
        temp[i] = new Character[num];

    for(int i = 0;i<this->num;i++){
        for(int j = 0; j<this->num;j++){
            temp[i][j]=b.board[i][j];
        }
    }
    this->board=temp;
    return (*this);
}

 istream& operator >> (istream& in,  Board& c){
  string line;
  getline(in,line);
  int num= line.length();
   Board d{num};
  for(int i=0;i<num;i++){
    d[{0,i}]=line.at(i);
  }
  for(int i=1; i<num; i++){
    getline(in,line);
    for(int j=0; j<num; j++){
      d[{i,j}]=line.at(j);
    }
  }
  c=d;
return in;
}

string Board::draw(int n){
    file_num++;
    string name="12345"+to_string(file_num)+".ppm";
    ofstream imageFile(name, ios::out | ios::binary);
    imageFile << "P6" << endl <<n<<" " <<n<< endl << 255 << endl;
    if(this->num==0){
        this->num=1;
    }
    RGB image[n*n];
    	int size=(n)/num;
      	for (int j = 0; j < n; ++j)  {  // row
        		for (int i = 0; i < n; ++i) { // column
    			image[n*j+i].red = (255);
    			image[n*j+i].blue = (255);
    			image[n*j+i].green = (255);
        }
      }

    for(int i=size; i<n; i = i+size ){
      for(int j=0; j<n;j++){
        image[i*n+j].red = 0;
        image[i*n+j].green =0;
        image[i*n+j].blue =0;
        image[j*n+i].red = 0;
        image[j*n+i].green =0;
        image[j*n+i].blue =0;

      }

    }
    int i=0;
      for (int k = 0; k < num; k++)  {  // row
          for (int l = 0; l < num; l++) { // colum
            if(this->board[k][l]=='X'){
              drowX(image,n,size,k,l);
              cout << "drew  x " <<i << '\n';
            }
            else if(this->board[k][l]=='O'){
              drowO(image,n,size,k,l);
              cout << "drew O " << i<<'\n';


            }
            i+=size;
          }

      }

  imageFile.write(reinterpret_cast<char*>(&image), 3*n*n);
  imageFile.close();

  return name;
}

void Board::drowX (RGB image[], int n, int size, int i, int j){
    int counter=0;
  for(int count=i*n+j; count<(size*n)+i*n+j;count+=n){
      image[count+counter].red=0;
      image[count+counter].green=0;
      image[count+counter].blue=0;
      image[(size*n)+i*n+j-count-counter].red=0;
      image[(size*n)+i*n+j-count-counter].green=0;
      image[(size*n)+i*n+j-count-counter].blue=0;
      counter++;
  }
}

void Board::drowO (RGB image[], int n, int size, int k, int l){
  int rad=(size-size/10)/2;
  int col=l*size;
  int row=k*size;
  int cen_x=(col+col+size)/2;
  int cen_y=(row+row+size)/2;
  Coordinate center {cen_x, cen_y};
  for (int k = row; k < row+size; k++)  {
        for (int l =col; l < col+size;l++) {
            Coordinate temp {k,l};
            if ( distance(temp,center,rad) ){
              image[n*k+l].red = 0;
              image[n*k+l].blue = 0;
              image[n*k+l].green = 0;
            }
    }
  }
}
bool Board:: distance(Coordinate a, Coordinate b, int rad){
  int x=(a.x-b.x)*(a.x-b.x);
  int y=(a.y-b.y)*(a.y-b.y);
  int dis=pow((y+x),0.5);
  if(dis>rad-1&&dis<rad+1) return 1;
    else  return 0;
  }
//int main(){
	// Board board1{4};  // Initializes a 4x4 board
	// cout << board1 << endl;   /* Shows an empty board:
	// ....
	// ....
	// ....
	// ....
	// */
	// cout << board1[{1,2}] << endl; // .
	// board1[{1,1}]='X';
	// board1[{1,2}]='O';
	// char c = board1[{1,2}];
  //   cout << c << endl; // O
	//  cout << board1 << endl;  /* Shows the following board:
	// // ....
	// // .XO.
	// // ....
	// // ....
	// // */
  //
	// try {
	// 	board1[{3,4}]='O';   // This should raise an exception
	// } catch (const IllegalCoordinateException& ex) {
	// 	cout << "Illegal coordinate: " << ex.theCoordinate() << endl;  // prints "Illegal coordinate: 3,4"
	// }
  //
	// board1 = '.';     // Fill the entire board with "."
	// cout << board1 << endl;  /* Shows an empty board, as above */
	// try {
	// 	board1 = 'a';        // This should raise an exception
	// } catch (const IllegalCharException& ex) {
	// 	cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: a"
	// }
  //
	// try {
	// 	board1[{0,1}] = 'x';  // This should raise an exception
	// } catch (const IllegalCharException& ex) {
	// 	cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: x"
	// }
  //
	// Board board2 = board1;
	// board2[{0,0}] = 'X';
	// cout << board1 << endl;  /* Shows an empty board, as above */
	// cout << board2 << endl;  /* Shows a board with an X at top-left */
  //
	// board1 = board2;
	// board1[{3,3}] = 'O';
	// cout << board2 << endl;  /* Shows a board with an X at top-left */
	// cout << board1 << endl;  /* Shows a board with an X at top-left and O at bottom-right */
  //
	//  cout << "Good bye!" << endl;

//return 0;
//}
