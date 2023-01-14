#include "tubes.h"

int main()
{
    Stack1 S;
    Stack2 R;
    createStack(S);
    createStack2(R);
    string postfix;
    infotype1 prefix;
    int n = 3;
    infotype2 X[20];
    cout<<"======== 1. Postflix To Preflix ========"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"input Postfix "<<i+1<<": ";cin>>postfix;
        prefix = postfixToPrefix(S,postfix);
        cout<<"Output Preflix "<<i+1<<": "<<prefix<<endl<<endl;
    }
    cout<<"=========================================";
    cout<<endl<<endl;
    cout<<"========== 2. Sorting To Stack =========="<<endl;
    cout<<"Masukkan 10 angka: ";
    for(int i = 0;i<10;i++) {
        cin>>X[i];
    }
    cout<<endl;
    urut(X,10);
    cout<<"Hasil Sorting Ascending: ";
    for(int i = 0;i<10;i++) {
        cout<<X[i]<<" ";
    }
    cout<<endl;
    cout<<"=========================================";
}
