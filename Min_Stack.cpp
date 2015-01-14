#include <iostream>

#include <deque>
using namespace std;


class MinStack {
private:
    std::deque<int> d;
    std::deque<int> mind;
public:
    void push(int x) {
        d.push_back(x);
        int min;``
        if( mind.size() <= 0)
            min = 0x7fffffff;
        else
            min = d[ mind.back()];

        if(x <= min){        
            mind.push_back(d.size()-1);
        }
        
    }

    void pop() {
        if( d.size() > 0){
            int x= top();
            d.pop_back();
            if(getMin() == x)
                mind.pop_back();
        }
    }

    int top() {
        return d.back();
    }

    int getMin() {
        return d[mind.back()];
    }

    void test(){
        push(10);
        
        
        push(14);
        push(1);
        push(23243);
        push(1);
        cout << getMin()<<endl;
        cout << top()<<endl;
        pop();
        cout << top()<<endl;
        cout << getMin()<<endl;
        pop();
        cout << top()<<endl;
        cout << getMin()<<endl;
         pop();
        cout << top()<<endl;
        cout << getMin()<<endl;
    }
  
};


int main()
{
    MinStack ms;
    ms.test();
    cout << "hello world"<<endl;
}