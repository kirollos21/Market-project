#include <iostream>
#include <cstddef>
#include <string>
#include <cstring>
using namespace std;


struct cf
{
	string ftn;
	string ltn;
	string barcode;
	double price;
	string pn;
	int quantity;
	cf* link;
};
typedef cf* cfp;
struct product
{
	string product;
   string barco;
	double pre;
};
struct customer
{
	string firname;
	string laname;
};
class cart
{
public:
	cart();
	cart(cart& c);
	void push(product& a, customer& b, int qty);
	void pop();
	void display();
	bool empty();
	void rem(string bcde);
	double total();
private:
	cfp head;
};


int main()
{
	struct product prt[10] =
	{
		{ "milk", "10001", 9.78},
		{"toast", "10002", 8.63},
		{"fish", "10003", 38.45},
		{"apple", "10004", 13.57},
		{"water", "10005", 3.79},
		{"cheese", "10006", 16.78},
		{"oil", "10007", 15.89},
		{"onion", "10008", 14.58},
		{"orange", "10009", 12.68},
		{"potato", "100010", 14.89},

	};
	
	struct customer cu[10] =
	{
		{"ab", "cd"},
		{"ef", "gh"},
		{"ij", "kl"},
		{"mn", "op"},
		{"qr", "st"},
		{"uv","wx"},
		{"yz", "abc"},
		{"def", "hij"},
		{"klm", "nop"},
		{"qrs", "tuv"},
	};
	cart ct;
	for (int i = 0; i < 10; i++)
		ct.push(prt[i], cu[i], i);
	ct.display();
	ct.total();
	ct.pop();
	ct.pop();
	cout << endl;
	ct.display();
	ct.total();
	cout << endl;
	ct.rem("10004");
	ct.rem("10005");
	ct.display();
	ct.total();

	return 0;
}

cart::cart():head(NULL)
{
}

cart::cart(cart& c)
{
	if (c.head == NULL)
		head = NULL;
	else
	{
		cfp temp = c.head;
		cfp end;
		end = new cf;
		end->barcode = temp->barcode;
		end->ftn = temp->ftn;
		end->ltn = temp->ltn;
		end->price = temp->price;
		end->pn = temp->pn;
		end->quantity = temp->quantity;
		temp = temp->link;
		while (temp != NULL)
		{
			end->link = new cf;
			end = end->link;
			end->barcode = temp->barcode;
			end->ftn = temp->ftn;
			end->ltn = temp->ltn;
			end->price = temp->price;
			end->pn = temp->pn;
			end->quantity = temp->quantity;
			temp = temp->link;
		}
		end->link = NULL;
	}
}

void cart::push(product& a, customer& b, int qty)
{
	cfp temptr;
	temptr = new cf;
	temptr->barcode = a.barco;
	temptr->pn = a.product;
	temptr->price = a.pre;
	temptr->ftn = b.firname;
	temptr->ltn = b.laname;
	temptr->quantity = qty;
	temptr->link = head;
	head = temptr;
}

void cart::pop()
{
	if (empty())
		exit(1);
	cfp temptr;
	temptr = head;
	head = head->link;
	delete temptr;
}

void cart::display()
{
	cfp temptr;
	temptr = head;
	cout << "pn   " << "barcode " << "price  " << " ftn " << "ltn " << " qty " << endl;
	while (temptr!=NULL)
	{
		cout << temptr->pn << " " << temptr->barcode << " " << temptr->price << " "
			<< temptr->ftn << " " << temptr->ltn << " " << temptr->quantity << " ";
		cout << endl;
		temptr = temptr->link;
	}
}
void cart:: rem(string bcde)
{
	cfp temptr = head;
	cfp tp = head;
	if (temptr != NULL)
	{
		while(temptr->barcode != bcde)
			temptr = temptr->link;
		while (tp->link != temptr)
			tp = tp->link;
		tp->link = temptr->link;
		temptr->link = NULL;
		delete temptr;
	}

}

double cart::total()
{
	double money=0;
	cfp temptr = head;
	while (temptr != NULL)
	{
		money = money + ((temptr->price) * (temptr->quantity));
		temptr = temptr->link;
	}
	cout <<endl<< "total bill is " << money << endl;
	return money;
}
bool cart::empty()
{
	return (head==NULL);
}

