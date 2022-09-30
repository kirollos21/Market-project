#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Customer
{
    private:
        int Cind=0;
        struct C
        {
            int    Cid;
            string Fna;
            string Lna;
            string email;
            string usern;
            string pass;
        };
        C Cdb[100];
    public:
   
       void Remove(int id)
    {
        int s=0;
			while (Cdb[s].Cid!=id)
			{
				s++;
			}
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
            cout << Cdb[i].Cid << '\t' << Cdb[i].Fna << '\t' << Cdb[i].Lna << '\t' << Cdb[i].email << Cdb[i].usern << Cdb[i].pass << endl;
        cout << "-------------------------------------" << endl;
    };
       void Save()
        {
            ofstream W;
            
            W.open("Customer.txt");
            for(int i=0;i<Cind;i++)
            {
                W << Cdb[i].Cid << '\t' << Cdb[i].Fna << '\t' << Cdb[i].Lna << '\t' << Cdb[i].email <<Cdb[i].usern <<Cdb[i].pass<< endl;
                
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
};

int main()
{
    Customer c;
    int idnumber;
    cout<<"Enter your id if you wish to delete your account"<<endl;
    cin>>idnumber;
    c.Remove(idnumber);
   c.Save();
    c.Load();
    c.Display();

}
