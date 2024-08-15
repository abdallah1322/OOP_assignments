// Name1 : Abdallah Emad-eldin Abdallah Ibrahim       ID : 20200324
// Name2 : Nada Alaa-eldin Ali                        ID : 20200589
#include <bits/stdc++.h>
using namespace std ;
#ifndef SETCOLORFUN_H_INCLUDED
#define SETCOLORFUN_H_INCLUDED
#include <windows.h>

class ColoredBox {
private:
    char **block ;
    char form_box ;
    int length ;
    int width ;
    int color_box ;
    static int biggest_area ;

    }
public:

    void setBlockChar (char b){
        form_box = b ;
    }
    void setColor (int c){
        color_box = c ;
    }
    char getBlockChar ()const{
        return form_box ;
    }
    int getColorBox ()const{
        return color_box ;
    }
      void createTheBox (){
        block = new char *[length] ;
        for (int i = 0; i < length; ++i) {
            block[i] = new char [width] ;
        }
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                block[i][j] = getBlockChar() ;
            }
        }

    ColoredBox(){
        setColor(15) ;
        setBlockChar('#') ;
    }

    ColoredBox (int len , int wid , int col=15 , char bl='#'): length(len) , width(wid){
        cout << endl ;
        setBlockChar(bl) ;
        setColor(col) ;
        createTheBox() ;
        if (getArea() > biggest_area){
            biggest_area = getArea() ;
        }
    }

    void SetColor(int ForgC)
    {
        WORD wColor;

        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        //We use csbi for the wAttributes word.
        if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
        {
            //Mask out all but the background attribute, and add in the forgournd color
            wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
            SetConsoleTextAttribute(hStdOut, wColor);
        }
        return;
    }
    /*
Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
*/
#endif // SETCOLORFUN_H_INCLUDED

    void display (){
        SetColor(getColorBox()) ;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << block[i][j];
            }
            cout << endl ;
        }
        SetColor(15) ;
    }

    void displayTransposed (){
        swap(length,width) ;
        createTheBox() ;
        SetColor(getColorBox()) ;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << block[i][j] ;
            }
            cout << endl ;
        }
        swap(length,width) ;
        createTheBox() ;
        SetColor(15) ;
    }

    void displayWider (){
        SetColor(getColorBox()) ;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << block[i][j] << " " ;
            }
            cout << endl ;
        }
        SetColor(15) ;
    }

    void displayChess (int COLOR){
        SetColor(getColorBox()) ;
        for (int i = 0; i < length; ++i) {
            if (i%2==0) {
                for (int j = 0; j < width; ++j) {
                    if (j%2==0) {
                        SetColor(getColorBox());
                        cout << block[i][j];
                    } else {
                        SetColor(COLOR);
                        cout << block[i][j];
                    }
                }
                cout << endl;
            }
            else {
                for (int j = 0; j < width; ++j) {
                    if (j%2!=0) {
                        SetColor(getColorBox());
                        cout << block[i][j];
                    } else {
                        SetColor(COLOR);
                        cout << block[i][j];
                    }
                }
                cout << endl;
            }
        }
        SetColor(15) ;
    }

    int getArea () const{
        return length*width ;
    }

    static int getMaxArea (){
        return biggest_area ;
    }

    ~ColoredBox() {
        for (int i = 0; i < length; ++i) {
            delete [] block[i] ;
        }
        delete [] block ;
    }

};

int ColoredBox::biggest_area=0 ;

int main() {
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea()<<endl;
    delete cb1;

    cout<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}
