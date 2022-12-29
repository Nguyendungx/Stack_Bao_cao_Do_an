#include "graphics.h"
#include<iostream>
#include<windows.h>
#include<string.h>
#include<sstream>
#include<conio.h>

#define MAX 100
using namespace std;


struct stack {
    int top;
    int A[MAX];
};
typedef struct stack STACK;
void Init(STACK& s) {
    s.top = -1;
}
int Empty(STACK s) {
    if (s.top == -1) {
        return 1;
    }
    return 0;
}
int IsFull(STACK s) {
    if (s.top == MAX - 1) {
        return 1;
    }
    return 0;
}

void Push(STACK& s, int x) {
    if (IsFull(s) == 0) {
        s.top++;
        s.A[s.top] = x;
    }
}
int Pop(STACK& s) {
    int x;
    if (!Empty(s)) {
        x = s.A[s.top];
        s.top--;
    }
    return x;
}
int size(STACK s) {
    STACK t = s;
    int temp = t.top+1;
    return temp;
}
int Top(STACK& s) {
    int x;
    // stack khac rong
    if (!Empty(s)) {
        //thuc hien gan phan tu cuoi bang x
        x = s.A[s.top];
        //tra ve x duoc gan bang phan tu cuoi cung cua mang
        return x;
    }
    else { //neu stack do rong thi tra ve NULL
        return NULL;
    }
}
void Input(STACK& s, int n) {
    //duyet tu 0 den n
    for (int i = 0; i < n; i++) {
        //thuc hien nhap gia tri vao bien x
        int x;
        cout<<"Nhap gia tri phan tu thu "<<i<<": ";
        cin >> x;
        //thuc hien push vao stack
        Push(s, x);
    }
}
void Output(STACK s) {
    //duyet tu phan tu top ve phan tu cuoi trong stack
    for (int i = s.top; i > -1; i--) {
        //hien thi ra ket qua
        cout<< s.A[i]<<" ";
    }
}

void dem(int n, int& t)
{
    while (n != 0)
    {
        //sau một vòng lặp thì count sẽ tăng lên 1
        t++;
        //chia lấy nguyên cho 10, cứ một lần chia thì số n sẽ có một chữ số
        n = n / 10;
    }
}
void taoNganXep(STACK s)
{
    setcolor(5);
    line(500, 200, 500, 500);
    line(600, 200, 600, 500);
    line(500, 500, 600, 500);
    STACK g = s;
    for (int j = 0; j < size(s) - 1; j++)
    {
        rectangle(510, 430 - 60 * j, 590, 480 - 60 * j);
    }
    for (int i = 0; i < size(s); i++)
    {
        Pop(g);
        if (!Empty(g))
        {
            char temp[5];
            int n = Top(g);
            int t = 0;
            dem(n, t);
            for (int i = t - 1; i >= 0; i--)
            {
                temp[i] = (n % 10) + 48;
                n = n / 10;
            }
            temp[t] = '\0';
            drawText(540, 440 + i * 60 - (size(s)-2) * 60, temp);
        }
    }
}
void kqNganXep(STACK s)
{
    system("cls");
    setcolor(5);
    line(500, 200, 500, 500);
    line(600, 200, 600, 500);
    line(500, 500, 600, 500);
    STACK g = s;
    for (int j = 0; j < size(s); j++)
    {
        rectangle(510, 430 - 60 * j, 590, 480 - 60 * j);
    }
    for (int i = 0; i < size(s); i++)
    {
        char temp[5];
        int n = Top(g);
        int t = 0;
        dem(n, t);
        for (int z = t - 1; z >= 0; z--)
        {
            temp[z] = (n % 10) + 48;
            n = n / 10;
        }
        temp[t] = '\0';
        drawText(540, 440+i*60-(size(s)-1)*60, temp);
        Pop(g);
    }
}

void add(STACK& s)
{
    system("cls");
    int x;
    cout << "Nhap gia tri muon them:" << endl;
    cin >> x;
    Push(s, x);
    //STACK g = s;
    char temp[5];
    int n = Top(s);
    int t = 0;
    dem(n, t);
    for (int i = t - 1; i >= 0; i--)
    {
        temp[i] = (n % 10) + 48;
        n = n / 10;
    }
    temp[t] = '\0';
    for (int j = 0; j < 400; j+=5)
    {
        taoNganXep(s);
        rectangle(110 + j, 100, 190 + j, 150);
        drawText(150 + j, 120, temp);
        system("cls");

    }
    for (double z = 0; z < 330-size(s)*60; z+=5)
    {
        taoNganXep(s);
        rectangle(510, 100 + z , 590, 150 + z );
        drawText(550, 110+z, temp);
        system("cls");
    }
    kqNganXep(s);

}

void pop_back(STACK& s)
{
    system("cls");
    STACK g = s;
    Pop(s);
    char temp[5];
    int n = Top(g);
    int t = 0;
    dem(n, t);
    for (int i = t - 1; i >= 0; i--)
    {
        temp[i] = (n % 10) + 48;
        n = n / 10;
    }
    temp[t] = '\0';

    for (double z = 0; z < 330 - size(s) * 60; z += 5)
    {
        kqNganXep(s);
        rectangle(510, 430 - z - size(s) * 60, 590, 480 - z - size(s) * 60);
        drawText(550, 440 - z - size(s) * 60, temp);
        system("cls");
    }
    for (int j = 400; j < 800; j += 5)
    {
        kqNganXep(s);
        rectangle(110 + j, 100, 190 + j, 150);
        drawText(150 + j, 120, temp);
        system("cls");
    }
    rectangle(110 + 800, 100, 190 + 800, 150);
    drawText(150 + 800, 120, temp);
    kqNganXep(s);
    Sleep(1000);
    kqNganXep(s);
}
void kiemTra(STACK& s)
{
    cout << "Nhap '1' de them ." << endl;
    cout << "Nhap '2' de xuat va xoa ." << endl;
    cout << "Nhap cac phim con lai de thoat ." << endl;
    int t;
    cin >> t;
    if (t == 1)
    {
        if (size(s) >= 5)
        {
            cout << "Ngan xep day.Khong the them" << endl;
            kiemTra(s);
        }
        else
        {
            add(s);
            kiemTra(s);
        }

    }

    else if (t == 2)
    {
        if (size(s) == 0)
        {
            cout << "Ngan xep Trong. Khong the xoa." << endl;
            kiemTra(s);
        }
        else
        {
            pop_back(s);
            kiemTra(s);
        }

    }  
    else
        exit;
}
int main() {
    initgraph();
    char s1[] = "Press any key to view the program.";
    setcolor(5);
    line(500, 200, 500, 500);
    line(600, 200, 600, 500);
    line(500, 500, 600, 500);
    for (int i = 0; i < 3; i++)
    {
        rectangle(510, 480 - i * 60, 590, 430 - i * 60);
    }
    rectangle(510, 280, 590, 230);
    rectangle(550, 140, 630, 190);
    setcolor(13);
    line(450, 150, 450, 450);
    line(430, 430, 450, 450);
    line(470, 430, 450, 450);
    line(650, 150, 650, 450);
    line(630, 170, 650, 150);
    line(670, 170, 650, 150);
    drawText(350, 200, "PUSH");
    drawText(650, 200, "POP");
    drawText(400, 50, s1);
    _getch();
    system("cls");
    //tao mot stack s
    STACK s;
    //khoi tao stack s
    Init(s);
    kiemTra(s);

    _getch();
}