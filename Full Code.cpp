#include<fstream>
#include<string.h>
#include<iomanip>
#include<iostream>
#include <cstddef>
#include <string>
#include <cstring>
#include <cmath>
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

		void cards()
		{
			long long number;
			int password;
			float balance;
			cout<<"Enter credit card number : ";
			cin>>number;
			cout<<"Enter password : ";
			cin>>password;
			cout<<"Enter balance : ";
			cin>>balance;
	    	customer_card.number = number;
	    	customer_card.password = password;
	    	customer_card.balance = balance;
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
		        cout << AmountToPay << " have been paid"<<endl;
		        customer_card.balance=customer_card.balance-AmountToPay;
		        cout << "Your card balance = "<<customer_card.balance<<endl;
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
	int cat;
};
    int pInd = 0;
Pro product[50];
public:
    void Add(int ID,string productName, int productQuantity, float Price, int Cat ){
        product[pInd].id = ID;
        product[pInd].pName = productName;
        product[pInd].pQuanitiy = productQuantity;
        product[pInd].price   = Price;
        product[pInd].cat   = Cat;
        pInd++;
        
    };
   void Display(int c)
        {
        	int j=0;
        	cout << "Name" << '\t' << "Quantity" << '\t' << "Price"<< '\t' << "ID" << endl<<endl;
            for(int i=0;i<pInd;i++)
            {
            	if(product[i].cat==c)
				{
                	cout << ++j<<" ) "<< product[i].pName << '\t' << product[i].pQuanitiy << '\t' << product[i].price<< '\t' 
					<< product[i].id << endl;
        		}
        	}
        };
        
   void deletePro(int pID)
    {
        int i=0;
		while (product[i].id!=pID)
		{
			i++;
		};
		for(int e=i; e<pInd; e++)
		{
			product[e]=product[e+1];
		};
		pInd--;
	}
	
    int deleteP(int pID, int Quan, string &NAM, float &I)
    {
        int i=0;
			while (product[i].id!=pID)
			{
				i++;
			}
			NAM=product[i].pName;
			I=product[i].price;
			if(product[i].pQuanitiy==0)
			{
				cout<<"Out Of Stock"<<endl;
				return 0;
			}
			else if(Quan>product[i].pQuanitiy)
			{
				cout<<"There are/is only "<<product[i].pQuanitiy<<" pice/s"<<endl;
				return 0;
			}
			else
			{
				product[i].pQuanitiy=product[i].pQuanitiy-Quan;
				Save();
				return 1;
			}
    };
    int AddP(int pID, int Quan)
    {
        int i=0;
			while (product[i].id!=pID)
			{
				i++;
			}
				product[i].pQuanitiy=product[i].pQuanitiy+Quan;
				Save();
    };
    void Save()
    {
        ofstream File;
        
        File.open("Product.dat");
        for(int i=0;i<pInd;i++)
            File << product[i].id <<'\t' <<
                    product[i].pName << '\t'
                <<  product[i].pQuanitiy << '\t' <<
                    product[i].price << '\t' <<
                    product[i].cat << endl;
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
            File >> product[i].cat;
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
		class Product p;
		int cind = 0;
	public:
		category()
		{
			p.Load();
		}
		int display()
		{
			for(int i=0; i<cind; i++)
			{
				cout<<(i+1)<<") "<<c[i].name<<endl;
			}
			return cind;
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
		void buy(int k, string &Nam, int &PID, float &Price, int &Q)
		{
			int d=0, q=0;
			p.Display(k);
			cout<<"Enter product ID : ";
			cin>>d;
			cout<<"Enter Quantity : ";
			cin>>q;
			int w= p.deleteP(d,q,Nam, Price);
			while (w==0)
			{
				cout<<endl<<"Re-enter Quantity : ";
				cin>>q;	
				w= p.deleteP(d,q,Nam,Price);
			}
			PID=d;
			Q=q;
		};
		void remp(int k)
		{
			int d=0;
			p.Display(k);
			cout<<"Enter proudct ID : ";
			cin>> d;
			p.deletePro(d);
			prosav();
		}
		void sellp(int ID,string productName, int productQuantity, float Price, int Cat )
		{
			p.Add(ID, productName, productQuantity, Price, Cat);
		}
		void prosav()
		{
			p.Save();
		}
		void retern(int pID, int Quan)
		{
			p.AddP(pID,Quan);
		}
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
    void push(string prd, int br, double pre, int qty)
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
    cout << f << " " << l << endl<<"Cart Proudcts :"<<endl;
    
    cout << "Name" << '\t' << "ID" << '\t' << "Price"<< '\t' << "Quantity" << endl<<endl;
    for (int i = 0; i <cid; i++)
    {
        cout << ca[i].pn << "\t " << ca[i].barcode << "\t " << ca[i].price << "\t "<< ca[i].quantity <<endl;
    }
	};
	void Delete()
	{
		for(int k=cid;k>0;k--)
            ca[k] = ca[k + 1];
        cid=0;
	}
    void rem(int bcde, int qty)
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
        int barcode;
        double price;
        string pn;
        int quantity;
    };
    cf ca[10];
    int cid = 0;

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
        int Cind=0;
        C Cdb[100];
        class cart bas[100];
        class category Catego;
        class payement payy;
    public:
    	Customer()
    	{
    		Catego.load();
		};
    	int k=0;
   		int s=0;
   		void SignUp()
   		{
   			int Cid;
			string Fna;
			string Lna;
			string email;
			string usern;
			string pass;
			string passCon;
			cout<<"Enter First Name : ";
			cin>> Fna;
			cout<<"Enter Last Name : ";
			cin>> Lna;
			cout<<"Enter User Name : ";
			cin>> usern;
			cout<<"Enter ID : ";
			cin>> Cid;
			cout<<"Enter Email : ";
			cin>> email;
			cout<<"Enter Password : ";
			cin>> pass;
			do
			{
			cout<<"Confirm Password : ";
			cin>> passCon;
			}while (passCon!=pass);
		Add(Cid, Fna, Lna, email, usern, pass);
		Save();
		};
		void LogIn()
		{
			string email;
			string pass;
			s=0;
			cout<<"Enter Your Email : ";
			cin>> email;
			while (Cdb[s].email!=email)
			{
				s++;
				if(s>Cind)
				{
				cout<<"Wrong Email!"<<endl;
				cout<<"Re-enter Your Email : ";
				cin>> email;
				s=0;
				}
			};
			cout<<"Enter Your Password : ";
			cin>> pass;
			while(Cdb[s].pass!=pass)
			{
				cout<<"Wrong Password!"<<endl;
				cout<<"Re-enter Your Password : ";
				cin>> pass;
			};
			cout<<"Welcome "<<Cdb[s].usern<<"!!!"<<endl;
		};
       void Remove()
       {
			for(int k=s; k<Cind;k++)
			{
				Cdb[k]=Cdb[k+1];
			}
			Cind--;
       };
       void Add(int Cid, string Fna, string Lna, string email,string usern, string pass)
        {
          Cdb[Cind].Cid = Cid;
           Cdb[Cind].Fna = Fna;
           Cdb[Cind].Lna = Lna;
          Cdb[Cind].email  = email;
          Cdb[Cind].usern  = usern;
          Cdb[Cind].pass  = pass;
           Cind++;
          
       };

   void Display()
    {
        for(int i=0;i<Cind;i++)
            cout << Cdb[i].Cid << '\t' << Cdb[i].Fna << '\t' << Cdb[i].Lna << '\t' << Cdb[i].email << '\t'<< Cdb[i].usern << '\t'<< Cdb[i].pass << endl;
        cout << "-------------------------------------" << endl;
    };
       void Save()
        {
            ofstream W;
            
            W.open("Customer.txt");
            for(int i=0;i<Cind;i++)
            {
                W << Cdb[i].Cid << '\t' << Cdb[i].Fna << '\t' << Cdb[i].Lna << '\t' << Cdb[i].email << '\t' <<Cdb[i].usern << '\t' <<Cdb[i].pass<< endl;
                
            }
           
            W.close();
        };
      void  Load()
        {
            ifstream R;
            int i=0;
            R.open("Customer.txt");
            
            while( ! R.eof())
            {
                R >> Cdb[i].Cid;
                R >> Cdb[i].Fna;
                R >> Cdb[i].Lna;
                R >> Cdb[i].email;
                R >> Cdb[i].usern;
                R >> Cdb[i].pass;
                i++;
            }
            Cind = i-1;
            
            R.close();
        };
        void ViewCart()
        {
        	bas[s].display(Cdb[s].Fna,Cdb[s].Lna);
        	cout<<endl<<"The Total Price = "<<bas[s].total()<<endl;
		}
		void Savecart()
		{
			bas[s].save(Cdb[s].Fna,Cdb[s].Lna);
		}
		void Buy()
		{
			string Nam;
			int PID, Quan;
			float PRI;
			int l =Catego.display();
			do
			{
				cin>>k;
			}while(k<1||k>l);
			Catego.buy(k,Nam, PID, PRI, Quan);
			bas[s].push(Nam, PID,PRI,Quan);
			ViewCart();
		}
		void Sell()
		{
			string Nam;
			int PID, Quan;
			double PRI;
			int l =Catego.display();
			cout<<++l<<") Add new Category."<<endl;
			do
			{
				cin>>k;
			}while(k<1||k>l);
			if(k==l)
			{
				cout<<"Enter name of the category : ";
				cin>>Nam;
				Catego.add(l,Nam);
			};
			cout<<"Enter product name : ";
			cin>>Nam;
			cout<<"Enter product price : ";
			cin>>PRI;
			cout<<"Enter product Quantity : ";
			cin>>Quan;
			cout<<"Enter product ID : ";
			cin>>PID;
			Catego.sellp(PID,Nam,Quan,PRI,k);
			Catego.save();
			Catego.prosav();
		};
		void rempro()
		{
			int l =Catego.display();
			do
			{
				cin>>k;
			}while(k<1||k>l);
			Catego.remp(k);
		};
		void Pay()
		{
			double t= bas[s].total();
			cout<<"Enter :"<<endl<<"1) Cash on delevery."<<endl<<"2) Credit Card."<<endl;
			do
			{
				cin>>k;
			}while(k<1||k>2);
			if(k==1)
				payy.DeliveryPay();
			else
			{
				payy.cards();
				payy.CreditPay(t);
			}
			bas[s].Delete();
		}
		void restre()
		{
			int PID, Quan;
			cout<<"Enter product ID : ";
			cin>>PID;
			cout<<"Enter product Quantity : ";
			cin>>Quan;
			bas[s].rem(PID,Quan);
			Catego.retern(PID,Quan);
		}
};


int main()
{
	class Customer C;
	C.Load();
	char an;
	cout<<"Enter : "<<endl<<"1- Sign up."<<endl<<"2- Log in."<<endl<<"3- Exit."<<endl;
	do
	{
		cin>> an;
	}while(an!='1'&&an!='2'&&an!='3');
	if(an=='1')
	{
		C.SignUp();
		main();
		C.Save();
	}
	else if(an=='2')
	{
		C.LogIn();
		while(an!='9')
		{
			an=0;
			cout<<"Enter : "<<endl<<"1- View Cart."<<endl<<"2- Buy a Product."<<endl<<"3- Return a Product."<<endl<<"4- Pay."<<endl<<"5- Sell a Product."<<endl<<"6- Remove a Product."<<endl<<"7- Log Out."<<endl<<"8- Remove Your Account."<<endl<<"9- Exit."<<endl;
			do
			{
				cin>> an;
			}while(an<'1'||an>'9');
			if(an=='1')
			{
				C.ViewCart();
			}
			else if(an=='2')
			{
				C.Buy();
			}
			else if(an=='3')
			{
				C.ViewCart();
				C.restre();
				C.ViewCart();
			}
			else if(an=='4')
			{
				C.Pay();
			}
			else if(an=='5')
			{
				C.Sell();
			}
			else if(an=='6')
			{
				C.rempro();
			}
			else if(an=='7')
			{
				C.s=0;
				main();
				return 0;
			}
			else if(an=='8')
			{
				C.Remove();
				C.s=0;
				main();
				C.Save();
				return 0;				
			}
			C.Savecart();
		}
	}
	
	
	cout<<"Good Bye!!!"<<endl;
	C.Save();
}
