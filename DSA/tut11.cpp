#include<iostream>
using namespace std;
// void tailRecursion(int n){
//     if(n==0){
//         return ;
//     }
//     cout<<n<<" ";
//     tailRecursion(n-1); 
// }
void headfunc(int n){
    if(n==0){
        return;
    }
    headfunc(n-1);
    cout<< n<<" ";
}

int main(){
    int n;
    cout<<"enter a no:";
    cin>>n;
    // tailRecursion(n);
    headfunc(n);
    return 0;
}
// | Feature               | Tail Recursion                              | Loop                                                  |
// | --------------------- | ------------------------------------------- | ----------------------------------------------------- |
// | ✅ **Time Complexity** | Same as the loop (usually `O(n)`)           | Same as recursion (`O(n)`)                            |
// | 🧠 **Space Usage**    | Uses **call stack**, unless optimized       | Uses **constant space** `O(1)`                        |
// | ⚙️ **Optimization**   | May get optimized (*Tail Call Elimination*) | Always optimized by compiler                          |
// | 🔁 **Control Flow**   | Function call per iteration                 | Single iteration, no stack usage                      |
// | 🚀 **Speed**          | Slightly slower (unless optimized)          | Faster due to lower overhead                          |
// | 🔧 **Use Case**       | Preferred in **functional programming**     | Preferred in **imperative languages** like C/C++/Java |
