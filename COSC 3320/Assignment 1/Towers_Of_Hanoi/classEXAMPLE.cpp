#include <iostream>
using namespace std;
#include <string>

class Hanoi  {
public:
	void move(string from, string to);
    void h2(int n, string s, string a, string b, string d);
    void h3(int n, string s, string a, string b, string d);
};



void Hanoi::move(string from, string to)
{
	cout << "Move disk from " << from << " to " << to << endl;
}

void Hanoi::h2(int n, string s, string a, string b, string d){
    if(n==1){
        move(s,a);
        move(a,b);
    }
    if(n>=2){
        h3(n-1,s,a,b,d);
        move(s,a);
        move(a,b);
        h3(n-1,d,s,a,b);
    }
}

void Hanoi::h3(int n, string s, string a, string b, string d){//sTOd
if (n==1){
    move(s,a);
    move(a,b);
    move(b,d);
}
if(n>=2){
    //move n-1 to d
    h3(n-1,s,a,b,d);
    //move n to b
    move(s,a);
    move(a,b);
    //move n-1 to s
    h2(n-1,d,s,a,b);
    //move n from b to d
    move(b,d);
    //move n-1 from s to d
    h2(n-1,a,b,d,s);
}
}




int main(){




int n = 2;
string s="Start";
string a="A";
string b="B";
string d="Destination";
	Hanoi object;
	object.h3(n,s,a,b,d);
}






