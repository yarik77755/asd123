#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct phone_owner
{
	string surname, name, middle_name;
	struct adress
	{
		int postal_code;
		string country, region, area, city, street;
		int house, apartment;
	} home_adress;
	string phone_number;
};
phone_owner init_owner ()
{
	phone_owner man;
	cout<<"Введите фамилию: ";
	cin>>man.surname;
	cout<<"Введите имя: ";
	cin>>man.name;
	cout<<"Введите отчество: ";
	cin>>man.middle_name;
	cout<<"Введите почтовый индекс: ";
	cin>>man.home_adress.postal_code;
	cout<<"Введите страну проживания: ";
	cin>>man.home_adress.country;
	cout<<"Введите область: ";
	cin>>man.home_adress.region;
	cout<<"Введите район: ";
	cin>>man.home_adress.area;
	cout<<"Введите город: ";
	cin>>man.home_adress.city;
	cout<<"Введите улицу: ";
	cin>>man.home_adress.street;
	cout<<"Введите номер дома: ";
	cin>>man.home_adress.house;
	cout<<"Введите номер квартиры: ";
	cin>>man.home_adress.apartment;
	cout<<"5Введите номер телефона (без +): ";
	cin>>man.phone_number;
}
phone_owner* init_array (int demenision)
{
	phone_owner* massive=(phone_owner*)malloc(demenision*sizeof(phone_owner));
	if (massive==NULL)
	{
		return NULL;
	}
	for(int i=0;i<demenision;i++)
    {
    	cout<<"Введите информацию о "<<i+1<<" владельце телефона"<<endl;
		massive[i]=init_owner();
    }
    return massive;
}
void display_owner (phone_owner man)
{
	cout<<"\nФамилия: "<<man.surname;
	cout<<"\nИмя: "<<man.name;
	cout<<"\nОтчество: "<<man.middle_name;
	cout<<"\nПостовый индекс: "<<man.home_adress.postal_code;
	cout<<"\nСтрана: "<<man.home_adress.country;
	cout<<"\nОбласть: "<<man.home_adress.region;
	cout<<"\nРайон: "<<man.home_adress.area;
	cout<<"\nГород: "<<man.home_adress.city;
	cout<<"\nУлица: "<<man.home_adress.street;
	cout<<"\nДом: "<<man.home_adress.house;
	cout<<"\nКвартира: "<<man.home_adress.apartment;
	cout<<"\nТелефон: +"<<man.phone_number;
}
void display_array (phone_owner* massive, int demenision)
{
	for (int i=0;i<demenision;i++)
	{
		display_owner(massive[i]);
	}
}
void display_chose (phone_owner* massive, int demenision, string number)
{
	for(int i=0;i<demenision;i++)
	{
		if(number==massive[i].phone_number)
		{
			display_owner(massive[i]);
		}
	}
}
int main ()
{
	int demenision;
	string number;
	phone_owner* massive_struct;
	cout<<"Введите количество владельцев телефонов";
	cin>>demenision;
	massive_struct=init_array(demenision);
	if (massive_struct==NULL)
	{
		cout<<"\nДинамический массив не существует";
		return 0;
	}
	cout<<"\nВведите номер телефона (без +): ";
	cin>>number;
	cout<<"\nВладелец данного номера:";
	display_chose(massive_struct,demenision,number);
    
	return 0;
}