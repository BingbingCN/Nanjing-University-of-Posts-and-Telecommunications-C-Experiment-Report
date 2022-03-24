#include<iostream>
#include<string>
using namespace std;
class Time{
    private:
        int Hour,Minute,Second;
    public:
        Time(int h=0,int m=0,int n=0);
        Time(const Time &ob);
        ~Time();
        void ChangeTime(int h,int m,int s);
        int GetHour();
        int GetMinute();
        int GetSecond();
        void PrintTime();
        void IncreaseOneSecond(); 
};
// //���캯��
Time::Time(int h,int m,int n){
    cout<<"Constructing..."<<endl;
    Hour=h;
    Minute=m;
    Second=n;
}
Time::Time(const Time &ob){
    cout<<"Copy constructing..."<<endl;
    Hour=ob.Hour;
    Minute=ob.Minute;
    Second=ob.Second;
}
//��������
Time::~Time(){
    cout<<"Destructing..."<<endl;
}
void Time::ChangeTime(int h,int m,int s){
    Hour=h;
    Minute=m;
    Second=s;
}
int Time::GetHour(){
    return Hour;
}
int Time::GetMinute(){
    return Minute;
}
int Time::GetSecond(){
    return Second;
}
void Time::PrintTime(){
    cout<<this->Hour<<":"<<this->Minute<<":"<<this->Second<<endl;
}
void Time::IncreaseOneSecond()
{
   if(Second<59)
	   Second++;
   else if(Second==59&&Minute==59&&Hour==23)
   {
	   Hour=0;
	   Minute=0;
	   Second=0;
   }
   else if(Second==59&&Minute==59&&Hour<23)
   {
	   Minute=0;
	   Second=0;
	   Hour++;
   }
   else if(Second==59&&Minute<59&&Hour<23)
   {
	   Minute++;
	   Second=0;
	   Hour++;
   }
   cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}
void f(Time *t)
{
    t->PrintTime();
    cout<<"call f\n";
}
int main(){
    Time t0,t1(1),t2(1,2),t3(1,2,3);
    t0.PrintTime();
    t1.PrintTime();
    t2.PrintTime();
    t3.PrintTime();
    t0.ChangeTime(12,12,12);
    t1.ChangeTime(12,12,13);
    t2.ChangeTime(12,12,14);
    t3.ChangeTime(12,12,15); 
    f(&t0);
    cout<<t0.Hour()<<":"<<t0.Minute<<":"<<t0.Second()<<endl;
    cout<<t1.GetHour()<<":"<<t1.GetMinute()<<":"<<t1.GetSecond()<<endl;
    cout<<t2.GetHour()<<":"<<t2.GetMinute()<<":"<<t2.GetSecond()<<endl;
    cout<<t3.GetHour()<<":"<<t3.GetMinute()<<":"<<t3.GetSecond()<<endl;
    return 0;  
}