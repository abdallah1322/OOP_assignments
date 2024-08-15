//Name1 : Abdallah Emadeldin Abdallah Ibrahim                 ID : 20200324
//Name2 : Nada Alaaeldin Ali                                  ID : 20200589
#include <bits/stdc++.h>
using namespace std ;
int c=1 ;

class Item {
private:
    int id ;
    string name ;
    int quantity ;
    double price ;
public:
    void setID (int i){
        id = i ;
    }
    void setName (string na){
        name = na ;
    }
    void setQuantity (int qu){
        quantity = qu ;
    }
    void setPrice (double pr){
        price = pr ;
    }
    int getID () const{
        return id ;
    }
    string getName () const{
        return name ;
    }
    int getQUantity () const{
        return quantity ;
    }
    double getPrice () const{
        return price ;
    }

    Item(){
        setQuantity(0) ;
        id = c ;
    }
    Item(string n , int q ,double p=0){
        name = n ;
        quantity = q ;
        price = p ;
//        c++ ;
    }
    Item (const Item &obj){
        id = obj.id ;
        name = obj.name ;
        quantity = obj.quantity ;
        price = obj.price ;
    }

    friend ostream& operator<< (ostream& os , const Item &obj1) ;
    friend istream& operator>> (istream& is ,  Item &obj2) ;

    bool operator== (const Item &right) {
        bool status ;
        if (name == right.name)
            status = true ;
        else
            status = false ;
        return status ;
    }

    bool operator<= (Item& obj){
        bool status ;
        if (quantity <= obj.quantity)
            status = true ;
        else
            status = false ;
        return status ;
    }

    Item operator+= (Item &ob) {
        quantity += ob.quantity ;
        return *this ;
    }

    Item operator-= (Item &ob) {
        quantity -=ob.quantity ;
        return *this ;
    }
    ~Item(){
    }
};

ostream& operator<< (ostream& os , const Item &obj1){
    os << endl << "ID : " << obj1.id << "\t" << "Name : " << obj1.name << "\t" <<
    "quantity : "  << obj1.quantity << "\t" << "Price : " << obj1.price ;
    return os ;
}

istream& operator>> (istream& is ,  Item &obj2){
    cout << "please enter the item name" << endl ;
    is >> obj2.name ;
    cout << "please enter the item price" << endl ;
    is >> obj2.price ;
    cout << "please enter the item quantity" << endl ;
    is >> obj2.quantity ;
    return is ;
}

class Seller {
private:
    string name ;
    string email ;
    Item *items ;
    int maxitems ;
    int count=0 ;
public:
    Seller (string n , string e , int m){
        name = n ;
        email = e ;
        maxitems = m ;
        items = new Item[maxitems] ;
    }

    friend ostream& operator<< (ostream &os , const Seller &obj) ;

    bool Add_An_Item (Item &obj){
        bool addition ;
        int a=0 ; // flag
        for (int i = 0; i < maxitems; ++i) {
            if (obj == items[i]){      // check if the item is founded or not
                items[i]+=obj ;       // if founded in items add the quantity to the item’s quantity
                a=1 ;
                addition = true ;
                cout << "the item has been added successfully" << endl ;
            }
        }
        if (a==0 && count < maxitems){
            items[count] = obj ;   // add new item to the items
            addition = true ;
            count++ ;
            c++ ;
            cout << "the item has been added successfully for fisrt time" << endl ;
        }
        else if (a==0 && count >= maxitems){
            addition = false ;
            cout << "cannot added item the capacity is full" << endl ;
        }
        return addition ;
    }

    bool Sell_An_Item (string n , int q){
        Item obj(n,q) ;
        bool found ;
        int b=0 ;  // flag
        for (int i = 0; i < maxitems; ++i) {
            if (obj == items[i]){         // first check if the item is founded
                if (obj <= items[i]){    // then check the quantity of this item
                    items[i] -= obj ;   // subtract the quantity from the item’s quantity
                    found = true;
                    b = 1;
                    cout << "your sell is done" << endl ;
                }
                else {
                    cout << "There is only " << items[i].getQUantity() << " left for this item" << endl;
                    found = false;
                    return found ;
                }
            }
        }
        if (b==0){
            cout << "sorry the item doesnot exist" << endl ;
            found = false ;
        }
        return found ;
    }

    void print_items (){
        for (int i = 0; i < count; ++i) {
            cout << items[i] << endl ;
        }
    }

    Item Find_an_item_by_ID (int i){
        return items[i-1] ;
    }

    ~Seller(){
        delete [] items ;
    }
};

ostream& operator<< (ostream &os , const Seller &obj){
    os << endl << "name : " << obj.name << endl << "email : " << obj.email << endl
    << "capacity items : " << obj.maxitems ;
    return os ;
}

int main() {
    string name, email ;
    int cap , order ;
    cout << "please enter your name: " << endl ;
    cin >> name ;
    cout << "please enter your email: " << endl ;
    cin >> email ;
    cout << "please enter your capacity: " << endl ;
    cin >> cap ;
    Seller obj (name , email , cap) ;
    while (true) {
        cout << "What do you want? : " << endl ;
        cout << "1/ print info " << endl ;
        cout << "2/ add an item " << endl ;
        cout << "3/ sell an item " << endl ;
        cout << "4/ print items " << endl ;
        cout << "5/ find an item by ID " << endl ;
        cout << "6/ exit " << endl ;
        cin >> order ;
        if (order == 1) {
            cout << obj << endl << endl ;
        }
        if (order == 2){
            Item item ;
            cin >> item ;
            obj.Add_An_Item(item) ;
            cout << endl ;
        }
        if (order == 3){
            string n ;
            int q ;
            cout << "what is the item you need?" << endl ;
            cin >> n ;
            cout << "what is the quantity you need?" << endl ;
            cin >> q ;
            obj.Sell_An_Item(n , q) ;
            cout << endl ;
        }
        if (order == 4){
           obj.print_items() ;
           cout << endl ;
        }
        if (order == 5){
            int i ;
            cout << "what is the id of the item you need?" << endl ;
            cin >> i ;
            cout << obj.Find_an_item_by_ID(i) ;
            cout << endl ;
        }
        if (order == 6){
            exit(0) ;
        }
    }
}
