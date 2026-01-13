#include <iostream>

using namespace std;

int largestNuber(int a, int b, int c){
    int largest = a;
    if(b > largest)
        largest = b;
    if(c > largest)
        largest = c;
    return largest;
}
int main()
{
    int a,b,c;
    cout << "Enter three numbers\n";
    cin >> a >> b >> c;
    cout << "Largest number is: " << largestNuber(a,b,c)<<endl;
    return 0;
}
