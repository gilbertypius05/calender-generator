#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//function prototype
void monthlyCalenderGenerator(string m_name, int n_days, int &start_day);
void yearlyCalenderGenerator(int year, int start_day);

int main(){

	int year, start_day, i=0;
	cout <<"Enter the year you'd wish to generate a calender for:\n";
	cin >> year;
	cout <<"Enter the first day of January "<<year<<" (Sun=0 to Sat=6) \n";
	cin >> start_day;
	while (start_day<0 || start_day>6)
	{
		cout <<"Invalid day of the  week!, Try again: e.g (Sun=0,Mon=1,... to Sat=6) \n";
		cin >> start_day;
		i++;
		if(i==3 && (start_day<0|| start_day>6)){
			cout << "\nYou've reached maximum attempts for today, try again after 24hours!\n"<< endl;
			return 0;
		}
	}
	cout << "\n\n";
	yearlyCalenderGenerator(year, start_day); // calling calenderGenerator()

	return 0;
}

/*prints the calendar for the month given the 
 start_day and number 0f days(n_days), and updates the start_day.*/
void monthlyCalenderGenerator(string m_name, int n_days, int &start_day){
	int i;
	//displaying the header
	if(start_day >0 && start_day <=6){
		cout << m_name << endl;
		cout << "---------------------------------------------------\n";
		cout << "Sun\tMon\tTue\tWed\tThr\tFri\tSat\n";
	}
	else if(start_day == 0){
		cout << m_name << endl;
		cout << "---------------------------------------------------\n";
		cout << "Sun\tMon\tTue\tWed\tThr\tFri\tSat";
	}

	for(i = 0; i<start_day; i++){
	cout <<"\t"; //displaying the spaces for days before the start_day
	}

	int x = 1;
	for(;x<=n_days; i++, x++) //Loop through each day
	{
		if (i % 7 == 0){
			cout << endl; // start next week if i value is divisible by 7
		}
		cout << x <<"\t"; // displaying the day
	}

	cout <<"\n\n"<< endl;
	start_day = i%7;  //update the start_day as the starting day for following month
}

void yearlyCalenderGenerator(int year, int start_day){
	bool leap_year = false;
	string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int n_days;
	string m_name;
	if (year % 4 == 0)
	{
		leap_year=true;
		cout << "LEAP YEAR!!! \n"<< endl;
	}
	cout<<"A Calender for the Year "<<year<<"\n"<<endl;
	for (int m = 0; m < 12; m++)
	{
		m_name = month[m];
		switch (m)
		{
		case 0:
			n_days = 31;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;
		case 1:
			n_days = leap_year? 29:28;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;
		case 2:
			n_days = 31;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;	
		case 3:
			n_days = 30;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;	
		case 4:
			n_days = 31;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;	
		case 5:
			n_days = 30;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;	
		case 6:
			n_days = 31;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;
		case 7:
			n_days = 31;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;
		case 8:
			n_days = 30;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;	
		case 9:
			n_days = 31;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;		
		case 10:
			n_days = 30;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;
		case 11:
			n_days = 31;
			monthlyCalenderGenerator(m_name,n_days,start_day);
			break;
		default:
			cout<<"something went wrong!"<<endl;
		}
	}
}