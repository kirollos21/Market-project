#include<fstream>
#include<string.h>
#include<iomanip>
#include<iostream>
 
 
using namespace std;
 
class Product
{
    int pInd = 0;
struct Pro
{
    int id;
    string  pName;
    int pQuanitiy;
    float price;

};
Pro product[100];
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
    void Save()
    {
        ofstream File;
        
        File.open("Customer.dat");
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
        File.open("Customer.dat");
        
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

 
int main() {
    Product x;
}
