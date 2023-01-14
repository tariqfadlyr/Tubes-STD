#include "tubes.h"

//Procedure pembuatan stack string
void createStack(Stack1 &S) {
    Top(S) = 0;
}

//procedure pembuatan stack integer
void createStack2(Stack2 &S) {
    Top(S) = 0;
}

/*function pengecekan jika stack string kosong yang akan
menghasilkan output boolean*/
bool isEmpty(Stack1 S) {
    return Top(S) == 0;
}

/*function pengecekan jika stack integer kosong yang akan
menghasilkan output boolean*/
bool isEmpty2(Stack2 S) {
    return Top(S) == 0;
}

/*function pengecekan jika stack string penuh yang akan
menghasilkan output boolean*/
bool isFull(Stack1 S) {
    return Top(S) == 10;
}

/*function pengecekan jika stack integer penuh yang akan
menghasilkan output boolean*/
bool isFull2(Stack2 S) {
    return Top(S) == 10;
}

//procedure memasukan infotype ke stack string dengan insert first
void push(Stack1 &S, infotype1 x) {
    if(isFull(S)) {
        cout<<"STACK FULL"<<endl;
    } else {
        Top(S) = Top(S) + 1;
        info(S)[Top(S)] = x;
    }
}

//procedure memasukan infotype ke stack integer dengan insert first
void push2(Stack2 &S, infotype2 x) {
    if(isFull2(S)) {
        cout<<"STACK FULL"<<endl;
    } else {
        Top(S) = Top(S) + 1;
        info(S)[Top(S)] = x;
    }
}

//function mengeluarkan infotype dari stack string dengan delete last
infotype1 pop(Stack1 &S) {
    infotype1 x;
    x = info(S)[Top(S)];
    Top(S) = Top(S) - 1;
    return x;
}

//function mengeluarkan infotype dari stack integer dengan delete last
infotype2 pop2(Stack2 &S) {
    infotype2 x;
    x = info(S)[Top(S)];
    Top(S) = Top(S) - 1;
    return x;
}

//procedure menampilkan isi dari stack dengan perulangan
void print(Stack1 S) {
    for(int i = 1; i < Top(S); i++) {
        cout<<info(S)[i]<<" ";
    }
    cout<<endl;
}

//function pengecekan apakah variabel operator dengan menggunakan switch
bool isOperator(char x) {
    switch(x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

//function perubahan notasi postflix ke preflix
infotype1 postfixToPrefix(Stack1 S, string x) {
    //pengukuran isi string
    int length = x.size();
    //perulangan untuk perpindahan index
    for(int i = 0; i < length; i++) {
        //memanggil isOperator untuk pengecekan isi dari X[i]
        if(isOperator(x[i])) {
            /*jika Operator maka pop 2 dari Top lalu
            operator dengan kedua hasil pop lalu di push*/
            string op1 = info(S)[Top(S)];
            pop(S);
            string op2  = info(S)[Top(S)];
            pop(S);
            //perumusan notasi prefix = operator + operand2 + operand1
            string temp = x[i] + op2 + op1;
            push(S,temp);
        } else {
            //jika operand maka akan langsung di push
            push(S, string(1,x[i]));
        }
    }
    //return hasil gabungan string (hasil prefix)
    return info(S)[Top(S)];
}

//procedure pengurutan array menggunakan stack secara ascending
void urut(infotype2 X[20], int n) {
    //pembuatan stack
    Stack2 S;
    createStack2(S);
    int i = 0, j = 0, Max;
    //looping hingga i sama dengan/melebihi n
    while(i < n) {
        //pengecekan jika isi array dengan index i != -1
        if(X[i] != -1) {
            //inisialisasi Max dengan i
            Min = i;
            //inisialisasi j = i+1 dan looping j hingga < n
            for(j = i+1; j < n; j++) {
                /*pengecekan jika array index Max lebih kecil dari
                array index j dan jika array index j != -1*/
                if(X[Max] < X[j] && X[j] != -1) {
                    /*inisialisasi nilai Max dengan j (nilai array j
                    lebih besar dari Max sehingga di tukar)*/
                    Max = j;
                }
            }
            //memasukan nilai array Max ke Stack
            push2(S,X[Max]);
            /*Merubah nilai array index Max dengan -1 (sehingga
            nilai di index tersebut tidak akan di cek lagi)*/
            X[Max] = -1;
        //pengecekan jika isi array dengan index i = -1
        } else if(X[i] == -1) {
            /*penambahan nilai i (jika nilai index i -1 maka akan
            dilewatkan di pengecekan selanjutnya)*/
            i++;
        }
    }
    //inisialisasi i = 0
    i = 0;
    //looping hingga stack kosong
    while(!isEmpty2(S)) {
        //memindahkan nilai di stack ke array dengan pop
        X[i] = pop2(S);
        //increment i untuk memasukan nilai ke index selanjutnya
        i++;
    }
}
