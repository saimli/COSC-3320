#include <iostream>
using namespace std;

void printer(char start, char end){
    cout<<start<<" -> "<<end<<endl;
}

void hanoi(int n, char start, char end, char middle){
    if (n == 1){
        printer(start,end);
        return;
    }
  
        hanoi(n-1,start,middle,end);
        printer(start,end);
        hanoi(n-1,middle,end,start);
   
}


int main(){
 int n=4;
    char start= '1';
    char end='3';
    char middle= '2' ;

 //hanoi(n,start,end,middle);

int vertices = 6;
int edges = 7;


int **graph = new int*[vertices];
for(int i =0; i<vertices; i++){
    graph[i] = new int[vertices];
}

for(int i = 0 ; i<vertices;i++){
for(int j = 0 ; j<vertices;j++)
{
graph[i][j] = 32;
}
}

for(int i = 0 ; i<vertices;i++){
for(int j = 0 ; j<vertices;j++)
{
cout<<graph[i][j]<<" ";
}
cout<<endl;
}



    return 0;

}