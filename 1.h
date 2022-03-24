#include<string>
class BookCard{
    private:
        string id;    //借书证学生的学号
        string stuName;  //借书证学生的姓名
        int number;  //所借书的数量
    public:
        BookCard(string x="B19010250",string y="雪峰",int z=4){
            id=x;
            stuName=y;
            number=z;
            cout<<"test!! ";
        }
        //显示借书证的3个数据成员的信息
        void display(){
            cout<<id<<" "<<stuName<<" "<<number; 
        }
        //借书的数量不足10则将数量加1，数量达到10 则直接返回false
        bool borrow(){
            if (number<10){
                number++;
            }
            else{
                return false;
            }
        }
};