#include <iostream>
#include <string>
using namespace std;
struct card
		{
			long long number;
			int password;
			float balance;
		};

class payement
{
	private:
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
    		}
		}
};
int main()
{
int num;
cout << "Please enter your payement method (Type '1' for delivery pay and '2' for credit card pay): ";
cin >> num;
while(num != 1 && num != 2)
{
    cout << "Invalide input" << endl;
    cout << "Please enter your payement method (Type '1' for delivery pay and '2' for credit card pay): ";
    cin >> num;
}

if(num == 1)
{
    payement pay;
    pay.DeliveryPay();
}

else
{
card c;
cout << "Please enter the data of your card" << endl;
cout << "Credit card number: ";
cin >> c.number;
cout << "Credit card password: ";
cin >> c.password;
cout << "Balance of the card: ";
cin >> c.balance;
payement pay(c);
pay.CreditPay(500);
}
}
