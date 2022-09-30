#include <iostream>
#include <fstream>
using namespace std;

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
int main()
{
	class category C;
	int ar;
	int i;
	string n;
	cin>>ar;
	while(ar!=0)
	{
		if (ar==1)
		{
			cin>>i>>n;
			C.add(i,n);
		}
		else if (ar==2)
		{
			cin>>i;
			C.remove(i);
		}
		else if (ar==3)
		{
			C.display();
		}
		else if (ar==4)
		{
			C.save();
		}
		else if (ar==5)
		{
			C.load();
		}
		cin>>ar;
	}
}
