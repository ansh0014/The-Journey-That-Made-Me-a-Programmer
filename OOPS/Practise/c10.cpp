#include<iostream>
using namespace std;
class Shape{
    public:
    virtual void area(){
    cout<<"Area of shape"<<endl;
    }
    virtual ~Shape(){
        cout<<"Shape destructor called"<<endl;
    }
};
class Rectangle: public Shape{
    private:
    int length, width;
    public:
    Rectangle(int length,int width){
        this->length=length;
        this->width=width;
    }
    void area(){
        cout<<"Area of rectangle: "<<length*width<<endl;
    }
    ~Rectangle(){
        cout<<"Rectangle destructor called"<<endl;
    }
};
class Circle: public Shape{
    private:
    int radius;
    public:
    Circle(int radius){
        this->radius=radius;
    }
    void area(){
        cout<<"Area of circle: "<<3.14*radius*radius<<endl;
    }
    ~Circle(){
        cout<<"Circle destructor called"<<endl;
    }
};
int main(){
    Shape *s1=new Rectangle(5,10);
    Shape *s2=new Circle(7);
    s1->area();
    s2->area();
    delete s1;
    delete s2;
    return 0;
}