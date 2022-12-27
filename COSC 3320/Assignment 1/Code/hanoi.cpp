#include <iostream>
using namespace std;


class Hanoi  {
public:
	void move(string from, string to);
    void a1Toa4(int n, string s, string a, string b, string d);
    void twoHop(int n, string s, string a, string b, string d);
    void sTOa1(int n,string s, string d,string a1,string a2, string a3, string a4);
    void a1TOd(int n, string d, string a1, string a2, string a3, string a4);
    void sTOd(int n, string s, string d, string a1, string a2, string a3, string a4);
    void a1TOa4(int n, string a1, string a2, string a3, string a4);
    void oneHop(int n, string a1, string a2, string a3, string a4);

void stooa1(int n, string s, string d, string a1, string a2, string a3, string a4 );


    int count=0;
};

//prints moves
void Hanoi::move(string from, string to)
{
    count++;
     // if(count <=100){
	cout <<count<< ": Move disk from " << from << " to " << to << endl;//}
}

void Hanoi::a1TOa4(int n, string a1, string a2, string a3, string a4){
    if(n==1){
        move(a1,a2);
        move(a2,a3);
        move(a3,a4);
    }
    if(n>=2){
        //move n-1 to a4
        a1TOa4(n-1,a1,a2,a3,a4);

        //move n to a3
        move(a1,a2);
        move(a2,a3);

        //move n-1 to a1
        oneHop(n-1,a1,a2,a3,a4);

        //move n to a4
         move(a3,a4);
        //move n-1 from a1 to a4
        a1TOa4(n-1,a1,a2,a3,a4);
        //twoHop(n-1,a1,a2,a3,a4);
    }
}

//move from a1 to a3
void Hanoi::twoHop(int n, string a1, string a2, string a3, string a4){
    if(n==1){
        move(a1,a2);
        move(a2,a3);
    }
    if(n<=2){
        //move n-1 to 
        a1TOa4(n-1,a1,a2,a3,a4);
        //move(a1,a2);
        //move(a2,a3);
        a1TOa4(n-1,a4,a1,a2,a3);
    }
}
//moves from a4 to a1
void Hanoi::oneHop(int n, string a1, string a2, string a3, string a4){
    if(n==1){
        move(a4,a1);
    }
    if(n>=2){
        //move n-1 from a4 to a2
        twoHop(n-1,a4,a1,a2,a3);
        //move n to a1
        move(a4,a1);
        //move n-1 from a2 to a4
        twoHop(n-1,a2,a3,a4,a1);
        //move n-1 from a4 to a1
        oneHop(n-1,a1,a2,a3,a4);
    }
}

void Hanoi::sTOa1(int n,string s, string d,string a1,string a2, string a3, string a4){
    if(n==1){
        move(s,d);
        move(d,a1);
    }
    if(n>=2){
        //move n-1 from s to a1
        sTOa1(n-1, s, d, a1,a2,a3,a4);
        //move n to d
        move(s,d);
        //move n-1 from a1 to a4
        a1TOa4(n-1,a1,a2,a3,a4);
        //move n to a1
        move(d,a1);
        //move n-1 from a4 to a1
        oneHop(n-1,a1,a2,a3,a4);
    }
}

void Hanoi::a1TOd(int n, string d, string a1, string a2, string a3, string a4){
    if (n==1){
        move(a1,d);
    }
    if(n>=2){
        //move n-1 to a4
        a1TOa4(n-1,a1,a2,a3,a4);
        //move n from a1 to d
        move(a1,d);
        //move n-1 from a4 to a1
        oneHop(n-1,a1,a2,a3,a4);
        //move n-1 from a1 to d
        a1TOd(n-1,d,a1,a2,a3,a4);
    }
}
//actual solving function that is called
void Hanoi::sTOd(int n, string s, string d, string a1, string a2, string a3, string a4){
if (n==1){
    move(s,d);
}
if(n>=2){
    //move n-1 to a1
    sTOa1(n-1, s, d, a1, a2, a3, a4);
    //move n to d
    move(s,d);
    //then moving n-1 from a1 to d move(a1,d)
     a1TOd(n-1,d,a1,a2,a3,a4);
}
}

int main(){

int n=10;

string s="Start";
string a1="A1";
string a2="A2";
string a3="A3";
string a4="A4";
string d="Destination";

	Hanoi object;
    cout<<"\t"<<"Number of disks: "<<n<<endl;
     object.sTOd(n,s,d,a1,a2,a3,a4);
     object.sTOd(n,s,d,a1,a2,a3,a4);

    object.sTOd(n,s,d,a1,a2,a3,a4);

}
//came up with this code myself :-)
