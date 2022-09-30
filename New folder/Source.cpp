#include <iostream>
#include <cstddef>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

class payement
{
	private:
		struct card
{
	long long number; 
	int password;
	float balance;
};
		card customer_card;

	public:
		payement()
		{
    		customer_card.number = 0;
    		customer_card.password = 0;
   			customer_card.balance = 0;
		}

		payement(card c)
		{
	    	customer_card.number = c.number;
	    	customer_card.password = c.password;
	    	customer_card.balance = c.balance;
		}
	
		void DeliveryPay()
		{
    		string address;
		    cout << "Please enter the your address: ";
	    	cin.ignore(1, '\n');
	   		getline(cin, address);
		    cout << "Thank you! Your order will be delivered to: " << address << endl; 
		}

		void CreditPay(float AmountToPay)
		{
    		if(customer_card.balance < AmountToPay)
   			{
	 		    cout << "Sorry you don't have enough money in your card" << endl;
   			}

		    else
		    {
       			cout << "Successful process." << endl;
		        cout << AmountToPay << " have been paid";
		        customer_card.balance=customer_card.balance-AmountToPay;
    		}
		}
};

class Product
{
	private:
	struct Pro
{
    int id;
    string  pName;
    int pQuanitiy;
    float price;

};
    int pInd = 0;
Pro product[10];
public:
    void Add(int ID,string productName, int productQuantity, float Price ){
        product[pInd].id = ID;
        product[pInd].pName = productName;
        product[pInd].pQuanitiy = productQuantity;
        product[pInd].price   = Price;
        pInd++;
        
    };
   void Display()
        {
            for(int i=0;i<pInd;i++)
                cout << product[i].id << '\t' <<
                        product[i].pName << '\t' <<
                        product[i].pQuanitiy << '\t' <<
                        product[i].price << endl;
            cout << "-------------------------------------" << endl;
        };
    void deleteP(int pID)
    {
        int i=0;
			while (product[i].id!=pID)
			{
				i++;
			}
			for(int k=i; k<pInd;k++)
			{
				product[k]=product[k+1];
			}
			pInd--;
    };
	void deleteQ(int pID, int Quan)
    {
        int i=0;
			while (product[i].id!=pID)
			{
				i++;
			}
			if(product[i].pQuanitiy==0)
				cout<<"Out Of Stock"<<endl;
			else if(Quan>product[i].pQuanitiy)
				cout<<"There are/is only "<<product[i].pQuanitiy<<" pice/s"<<endl;
			else
				product[i].pQuanitiy=product[i].pQuanitiy-Quan;
    };
    	void AddQ(int pID, int Quan)
    {
        int i=0;
			while (product[i].id!=pID)
			{
				i++;
			}
			product[i].pQuanitiy=product[i].pQuanitiy+Quan;
    };
    void Save()
    {
        ofstream File;
        
        File.open("Product.dat");
        for(int i=0;i<pInd;i++)
            File << product[i].id <<'\t' <<
                    product[i].pName << '\t'
                <<  product[i].pQuanitiy << '\t' <<
                    product[i].price << endl;
        File.close();
    };
void    Load()
    {
        ifstream File;
        int i=0;
        File.open("Product.dat");
        
        while( ! File.eof())
        {
            File >> product[i].id;
            File >> product[i].pName;
            File >> product[i].pQuanitiy;
            File >> product[i].price;
            i++;
        }
        pInd = i-1;
        
        File.close();
    };
    
};

class category
{
	private:
		struct cate
		{
			int id;
			string name;
		};
		cate c[5];
		int cind = 0;
	public:
		void display()
		{
			for(int i=0; i<cind; i++)
				cout<<(i+1)<<") "<<c[i].name<<"("<<c[i].id<<")"<<endl;
		};
		void add(int id, string n)
		{
			c[cind].id=id;
			c[cind].name=n;
			cind++;
		};
		void remove(int i)
		{
			int s=0;
			while (c[s].id!=i)
			{
				s++;
			}
			for(int k=s; k<cind;k++)
			{
				c[k]=c[k+1];
			}
			cind--;
		};
		void save()
		{
			ofstream w;
			w.open("category.dat");
			for(int i=0; i<cind; i++)
				w<<c[i].id<<' '<<c[i].name<<endl;
		};
		void load()
		{
			ifstream r;
			int i=0;
			r.open("category.dat");
			while(!r.eof())
			{
				r>>c[i].id;
				r>>c[i].name;
				i++;
			}	
			cind=i-1;
			r.close();
		};
};

class Customer
{
private:
    struct C
    {
        int    Cid;
        string Fna;
        string Lna;
        string email;
        string usern;
        string pass;
    };
    int Cind = 0;
    C Cdb[50];
public:

    string getfn(int i)
    {
        return (Cdb[i].Fna);
    };
    string getln(int i)
    {
        return (Cdb[i].Lna);
    };
    void Remove(int id)
    {
        int s = 0;
        while (Cdb[s].Cid != id)
        {
            s++;
        }
        for (int k = s; k < Cind; k++)
        {
            Cdb[k] = Cdb[k + 1];
        }
        Cind--;

    };
    void Add(int Cid, string Fna, string Lna, string email, string usern, string pass)
    {
        Cdb[Cind].Cid = Cid;
        Cdb[Cind].Fna = Fna;
        Cdb[Cind].Lna = Lna;
        Cdb[Cind].email = email;
        Cdb[Cind].usern = usern;
        Cdb[Cind].pass = pass;
        Cind++;

    };

    void Display()
    {
        for (int i = 0; i < Cind; i++)
            cout << Cdb[i].Cid << '\t' << Cdb[i].Fna << '\t' << Cdb[i].Lna << '\t' << Cdb[i].email << Cdb[i].usern << Cdb[i].pass << endl;
        cout << "-------------------------------------" << endl;
    };
    void Save()
    {
        ofstream W;

        W.open("cput.txt");
        for (int i = 0; i < Cind; i++)
        {
            W << Cdb[i].Cid << '\t' << Cdb[i].Fna << '\t' << Cdb[i].Lna << '\t' << Cdb[i].email << Cdb[i].usern << Cdb[i].pass << endl;

        }

        W.close();
    };
    void  Load()
    {
        ifstream R;
        int i = 0;
        R.open("cu2.txt");

        while (!R.eof())
        {
            R >> Cdb[i].Cid;
            R >> Cdb[i].Fna;
            R >> Cdb[i].Lna;
            R >> Cdb[i].email;
            R >> Cdb[i].usern;
            R >> Cdb[i].pass;
            i++;
        }
        Cind = i;

        R.close();
    };
};

class cart
{
public:
    void load()
	{
    int i = 0;
    ifstream in;
    in.open("take.txt");
    while (!in.eof())
    {
            in >> ca[i].pn >> ca[i].barcode >> ca[i].price >> ca[i].quantity;
            i++;
    }
    cid = i;
    
    in.close();
	};
    void push(string prd, string br, double pre, int qty)
	{
    ca[cid].pn = prd;
    ca[cid].barcode = br;
    ca[cid].price = pre;
    ca[cid].quantity = qty;
    cid++;
	};
    void display(string f, string l)
	{
    cout << "customer:\n";
    cout << f << "\t" << l << endl;
    for (int i = 0; i <cid; i++)
    {
        cout << ca[i].pn << "\t " << ca[i].barcode << "\t " << ca[i].price << "\t "
            << ca[i].quantity << "\t ";
        cout << endl;
    }
	};
    void rem(string bcde, int qty)
	{ 
    int i = 0;
    while (ca[i].barcode != bcde)
        i++;
    if (ca[i].barcode == bcde)
    {
        if (ca[i].quantity > abs(qty))
            ca[i].quantity = ca[i].quantity - qty;
        else
        {
            int k = i;
            while (k < cid)
            {
                ca[k] = ca[k + 1];
                k++;
            }
            cid--;
        }
    }
    else
        exit(1);
	};
    double total()
	{
    int i = 0;
    double money = 0;
    while (i < cid)
    {
        money = money + (ca[i].price) * (ca[i].quantity);
        i++;
    }
    return money;
	};
    void save(string fn, string ln)
	{
    int i = 0;
    ofstream out;
    out.open("put.txt");
    out << "customer:\n";
    out << fn << "\t" << ln << endl;
    while (i < cid)
    {
        out << ca[i].pn << "\t" << ca[i].barcode << "\t" << ca[i].price << "\t" << ca[i].quantity
            << endl;
        i++;
    }
    out << "total is:\t" << total() << endl;

    out.close();
	};
private:
    struct cf
    {
        string barcode;
        double price;
        string pn;
        int quantity;
    };
    cf ca[50];
    int cid = 0;

};

int main()
{

    cart c, car;
    Customer a;
    a.Load();
    a.Display();
    c.load();
    c.display(a.getfn(0), a.getln(0));
    cout << endl << "total: " << c.total() << endl;
    c.save(a.getfn(0), a.getln(0));
	c.rem("10004", 20);
    c.display(a.getfn(0), a.getln(0));
    cout << endl << "total: " << c.total() << endl;
    c.save(a.getfn(0), a.getln(0));
    c.push("tea", "100016", 14.56, 32);
    c.display(a.getfn(0), a.getln(0));
    cout << endl << "total: " << c.total() << endl;
    c.save(a.getfn(0), a.getln(0));
    c.rem("10005", 50);
    c.display(a.getfn(0), a.getln(0));
    c.save(a.getfn(0), a.getln(0));
    a.Save();
  
    return 0;
}




