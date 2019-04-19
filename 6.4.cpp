/*Create an inheritance hierarchy to represent various types of packages. Use
Package as the base class of the hierarchy, then include classes TwoDayPackage and
OvernightPackage that derive from Package. Base class Package should include data
members representing the name, address, city, state and ZIP code for both the sender
and the recipient of the package, in addition to data members that store the weight (in
ounces) and cost per ounce to ship the package. Package's constructor should initialize
these data members. Ensure that the weight and cost per ounce contain positive values.
Package should provide a public member function calculateCost() that returns a
double indicating the cost associated with shipping the package. Package's
calculateCost() function should determine the cost by multiplying the weight by the
cost per ounce. Derived class TwoDayPackage should inherit the functionality of base
class Package, but also include a data member that represents a flat fee that the
shipping company charges for two-day-delivery service. TwoDayPackage's

constructor should receive a value to initialize this data member. TwoDayPackage
should redefine member function calculateCost() so that it computes the shipping cost
by adding the flat fee to the weight-based cost calculated by base class Package's
calculateCost() function. Class OvernightPackage should inherit directly from class
Package and contain an additional data member representing an additional fee per
ounce charged for overnight-delivery service. OvernightPackage should redefine
member function calculateCost() so that it adds the additional fee per ounce to the
standard cost per ounce before calculating the shipping cost. Write a test program that
creates objects of each type of Package and tests member function calculateCost().*/
#include<iostream>
using namespace std;
class Package
{
	public:
		string name, address, city, state; 
		int zip ;
		float cost , weight;
		Package()
		{
			weight=50;
			cost=5*weight;
		}
		void sender()
		{
			cout<<"ENter sender name : ";
			cin>>name;
			cout<<"Enter Address : ";
			cin>>address;
			cout<<"ENTER CITY: ";
			cin>>city;
			cout<<"ENTER STATE: ";
			cin>>state;
			cout<<"ENTER ZIP CODE: ";
			cin>>zip;
			
		}
		void receiver()
		{
			cout<<"ENter receiver name : ";
			cin>>name;
			cout<<"Enter Address : ";
			cin>>address;
			cout<<"ENTER CITY: ";
			cin>>city;
			cout<<"ENTER STATE: ";
			cin>>state;
			cout<<"ENTER ZIP CODE: ";
			cin>>zip;
			
		}
		void show()
		{
			sender();
		}
		void show1()
		{
			receiver();
		}
		
		float calculatecost()
		{
			
			return cost*weight;
			
		}
		
		
		
};
class TwoDayPackage:public Package
{
	public:
	float calculatecost()
		{
			
			cout<<"Two day cost =  "<<50<<endl;
			cout<<"TOTAL COST WILL BE : ";
			return Package::calculatecost()+50;
			
			
		}
		
};
class OvernightPackage:public Package
{
	public:
	float calculatecost()
		{
			
			cout<<"Overnight will cost you Rs. 5 per ounce "<<endl;
			float oncost=5*weight;
			cout<<"Overnight cost =  "<<oncost<<endl;
			cout<<"TOTAL COST WILL BE : ";
			return oncost+ Package::calculatecost();
			
			
		}
		
};

int main()
{
	char op;
	Package P1;
	TwoDayPackage t1;
	OvernightPackage o1;
	cout<<"SENDER INFORMATION : "<<endl<<endl;
	P1.sender();
	cout<<endl<<endl;
	cout<<"REceiver info: "<<endl<<endl;
	P1.receiver();
	cout<<endl;

	cout<<"\ngenral cost: "<<endl;
	cout<<P1.calculatecost()<<endl;
	cout<<"\n Select O for overnight and T for 2 day package : ";
	cin>>op;
	if (op=='T'|| op=='t')
	{
		t1.weight=P1.weight;
		cout<<"YOU HAVE SELECTED 2 day package: "<<endl;
		cout<<"calculating cost: "<<endl;
		cout<<t1.calculatecost();
	}
	else if (op=='O'|| op=='o')
	{
		cout<<"YOU HAVE SELECTED overnight package: "<<endl;
		cout<<"calculating cost: "<<endl;
		cout<<o1.calculatecost();
	}


	
}
