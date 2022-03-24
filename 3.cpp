#include<iostream>
#include<string>
using namespace std;
class Boy;
class Girl
{
	string name;
	int age;
public:
	Girl(string N,int A);
	~Girl()
	{
		cout<<"Girl destructing...\n";
	}
	void Print();
	void VisitBoy(Boy & );
};
class Boy
{
	string name;
	int age;
	friend Girl;
public:
	Boy(string N,int A);
	~Boy()
	{
		cout<<"Boy destructing...\n";
	}
	void Print();
	void VisitGirl(Girl & );
};
Girl::Girl(string N,int A)
{
	name=N;
	age=A;
	cout<<"Girl constructing...\n";
}
void Girl::Print()
{
	cout<<"Girl's name: "<<name<<endl;
	cout<<"Girl's age: "<<age<<endl;
}
void Girl::VisitBoy(Boy &boy)
{
	cout<<"Boy's name: "<<boy.name<<endl;
	cout<<"Boy's age: "<<boy.age<<endl;
}
Boy::Boy(string N,int A)
{
	name=N;
	age=A;
	cout<<"Boy constructing...\n";
}
void Boy::Print()
{
	cout<<"Boy's name: "<<name<<endl;
	cout<<"Boy's age: "<<age<<endl;
}
/*void Boy::VisitGirl(Girl & girl)
{
	cout<<"Girl's name: "<<girl.name<<endl;
	cout<<"Girl's age: "<<girl.age<<end;
}*/
int main()
{
	Girl g("xiaohong",11);
	Boy b("xiaoming",12);
	g.VisitBoy(b);
	g.Print();
	b.Print();
	return 0;
}

