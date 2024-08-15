//Name1: Abdallah Emad-eldin Abdallah Ibrahim                ID: 20200324
//Name2: Nada Alaa-eldin Ali                                 ID: 20200589
#include <iostream>
#include <fstream>
using namespace std ;


class FloatArray { // base class
protected:
    float *arr ;
    int size ;
    int index ;
public:
    FloatArray(int s){     // parameterized that take the array size
        size = s ;
        arr = new float [size] ;  // allocate the array in the memory
        index=0 ;      // variable to help know the index of array
    }
    virtual void Add (float x){
        arr[index] = x ;
        ++index ;
    }
    friend ofstream& operator<< (ofstream& os , FloatArray& obj1) ;
    friend ifstream& operator>> (ifstream& is , FloatArray& obj2) ;

    ~FloatArray(){         //destructor to deallocate the array
        delete [] arr ;
    }
};

ofstream& operator<< (ofstream& os ,const FloatArray& obj1){   // ofstream file overload
    os << obj1.index << "|\t" ;
    for (int i = 0; i < obj1.index; ++i) {
        os << (obj1.arr[i]) << "\t" ;
    }
    os << endl ;
    return os ;
}
ifstream& operator>> (ifstream& is , FloatArray& obj2){   // ifstream file overload
    for (int i = 0; i < obj2.size; ++i) {
        is >> obj2.arr[i] ;
        obj2.Add(obj2.arr[i]) ;
    }
    return is ;
}


class SortedArray : public FloatArray {  // class Sorted Array inherits form Float Array
public:
    SortedArray(int a) : FloatArray(a){
    }
    virtual void Add (float x){
        int pos=0 ;
        if (index==0){
            arr[index] = x ;
            index++ ;
        }
        else {
            for(int i = 0; i < index; i++){
                if(arr[i] < x){
                    pos++ ;
                }
                else{
                    break ;
                }
            }
            for(int i = size-1; i > pos; i--) {
                arr[i] = arr[i-1] ;
            }
            arr[pos] = x ;
            index++ ;
        }
    }
};

class FrontArray : public FloatArray {  // class Float Array inherits form Float Array
public:
    FrontArray(int s) : FloatArray(s){

    }
    void Add (float x){
        if (index == 0){
            arr[index] = x ;
            index++ ;
        }
        else {
            for(int i = index; i > 0; i--) {   // shifting the elements
                arr[i] = arr[i-1] ;
            }
            arr[0] = x ;
            index++ ;
        }
    }
};

class PositiveArray : public SortedArray { // class Positive Array inherits form Sorted Array
public:
    PositiveArray(int s) : SortedArray(s) {

    }
    virtual void Add (float x){
        if (x > 0){
            SortedArray::Add(x) ;
        }
    }
};

class NegativeArray : public SortedArray {  // class Negative Array inherits form Sorted Array
public:
    NegativeArray(int s) : SortedArray(s) {

    }
    void Add (float x) {
        if (x < 0){
            SortedArray::Add(x) ;
        }
    }
};

int main() {

    string name1 , name2 ;
    cout << "Enter the name of input file" << endl ;
    cin >> name1 ;    // input file name
    cout << "Enter the name of output file" << endl ;
    cin >> name2 ;    // output file name

    ifstream in(name1) ;    // file for input
    ofstream out(name2) ;   // file for output
    string subject ;
    int num ;
    FloatArray* obj[10] ;
    for (int i = 0; i < 10; ++i) {
        in >> subject >> num ;
        if (subject == "Sorted"){
            obj[i] = new SortedArray(num) ;
        }
        else if (subject == "Array"){
            obj[i] = new FloatArray(num) ;
        }
        else if (subject == "Front"){
            obj[i] = new FrontArray(num) ;
        }
        else if (subject == "Positive"){
            obj[i] = new PositiveArray(num) ;
        }
        else if (subject == "Negative") {
            obj[i] = new NegativeArray(num);
        }
        in >> *obj[i] ;
    }
    for (int i = 0; i < 10; ++i) {
        out << *obj[i] ;
    }
    in.close() ;
    out.close() ;
    return 0;
}
