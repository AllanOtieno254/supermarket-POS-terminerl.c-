#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class shopping
{
private:
    int pcode; //p is product
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem(); //remove
    void list();
    void receipt();
};

void shopping::menu()
{
   m: //label
    int choice;
    string email;
    string password;

    cout << "\t\t\t___________\n";
    cout << "\t\t\t                              \n";
    cout << "\t\t\t     supermarket main menu     \n";
    cout << "\t\t\t                                \n";
    cout << "\t\t\t_____________\n";
    cout << "\t\t\t                                  \n";
    cout << "\t\t\t| 1) administrator   |\n";
    cout << "\t\t\t                     |\n";
    cout << "\t\t\t| 2) buyer           |\n";
    cout << "\t\t\t                     |\n";
    cout << "\t\t\t| 3) exit            |\n";
    cout << "\t\t\t                     |\n";
    cout << "\n\t\t\t  please select!   ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t please login \n";
        cout << "\t\t\t enter email   \n";
        cin >> email;
        cout << "\t\t\t password    \n";
        cin >> password;

        if (email == "allanotieno2001@gmail.com" && password == "Whoareyou2001?")
        {
            administrator();
        }
        else
        {
            cout << "invalid email/password";
        }
        break;

    case 2:
        buyer();
        break;

    case 3:
        

    default:
        cout << "please select from the given options";
    }
    goto m;
}

void shopping::administrator()
{
   m:
    int choice;
    cout << "\n\t\t\t administrator menu";
    cout << "\n\t\t\t|_1) add the product_|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|_2) modify product ___|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|_3) delete product  __|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|_4)back to main menu__|";

    cout << "\n\n\t please enter your choice ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "invalid choice";
    }
    goto m;
}

void shopping::buyer()
{
   m:
    int choice;
    cout << "\t\t\t buyer          \n";
    cout << "\t\t\t______ \n";
    cout << "                        \n";
    cout << "\t\t\t 1) buy product    \n";
    cout << "                          \n";
    cout << "\t\t\t 2) go back          \n";
    cout << "\t\t\t enter your choice:   \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "invalid choice";
    }

    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t add new product";
    cout << "\n\n\t product code of the product ";
    cin >> pcode;
    cout << "\n\n\t name of product ";
    cin >> pname;
    cout << "\n\n\t price of  product ";
    cin >> price;
    cout << "\n\n\t doscount on the product ";
    cin >> dis;
    //opening a file
    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << "\n"; //write inside a file
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d; //initializing index of file

        while (!data.eof()) //end of file
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1) //if product is in duplicate
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << pcode << " " << pname << " " << price << " " << dis << "\n"; //writing inside a file
            data.close();
        }
    }
    cout << "\n\n\t\t record inserted !";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t modify the record";
    cout << "\n\t\t\t product code";
    cin >> pkey;

    data.open("database.txt", ios::in); //open file to check if it exists
    if (!data)
    {
        cout << "\n\n file doesnt exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode) //pkey is the code entered by admin if he wants to edit and we check if it matches with the product code
            {
                cout << " \n\t\t product new code:";
                cin >> c;
                cout << " \n\t\t name of the product:";
                cin >> n;
                cout << " \n\t\t price:";
                cin >> p;
                cout << " \n\t\t discount:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t record edited:";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");        //remove the list in the file
        rename("database1.txt", "database.txt");

        if (token == 0) //if token is not incremented
        {
            cout << "\n\n record not found sorry!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t delete product";
    cout << "\n\n\t  product code:";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "file doesnt exist";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) //eof is end of file
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t product deleted succesfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n"; //all products will be shown except the ones deleted
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n_______________\n";
    cout << "proNo\t\tName\t\tprice                      \n";
    cout << "\n\n______________ \n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n empty database";
    }
    else
    {
        data.close();

        list();
        cout << "\n______________\n";
        cout << "\n|                                     \n";
        cout << "\n|    please place the order            \n";
        cout << "\n|                                     \n";
        cout << "\n______________\n";
        do
        {
            cout << "\n\n enter product code:";
            cin >> arrc[c];
            cout << "\n\n enter product quantity:";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n duplicate product code. please try again!";
                   
                }
            }
            c++;
            cout << "\n\n do you want to buy another product? if yes then press 1(yes) else 0(no)";
            cin >> choice;
        } while (choice == '1');

        cout << "\n\n\t\t\t________RECEIPT_______\n";
        cout << "\nproduct No\t product name\t product quantity\tprice\tamount\t amount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n______________";
    cout << "\n total amount :" << total;
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}