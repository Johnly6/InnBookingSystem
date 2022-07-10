#include<bits/stdc++.h>

using namespace std;

class RoomData
{
    private:
    string checkInTime;
    int numberOfAdults;
    float numberOfDays;
    
    public:
    void setCheckInTime(string checkTime)
    {
        this->checkInTime = checkTime;
    }
    void setNumberOfAdults(int adults)
    {
        this->numberOfAdults =adults;
    }
    void setNumberOfDays(int days)
    {
        this->numberOfDays =days;
    }
    string getCheckInTime()
    {
        return checkInTime;
    }
    int getNumberOfAdults()
    {
        return this->numberOfAdults;
    }
    int getNumberOfDays()
    {
        return this->numberOfDays;
    }
    
    float caclNumofDays(string check,int days)
    {
        string AM_or_PM=check.substr(5,2);
        string hrs= check.substr(0,2);
        string min=check.substr(3,2);
    
        int inthrs=stoi(hrs);
        int intmin=stoi(min);
    
        if(AM_or_PM=="AM"&&(inthrs==12||(inthrs>=1&&inthrs<=5)||(inthrs==6&&intmin<=30)))
            days+=1;
    
        if(AM_or_PM=="AM"&&(inthrs>=7&&inthrs<=11)||(inthrs==6&&intmin>=31))
            days+=0.5;
        
        return days;
    }
    
    int calcFinalPrice(int rooms,float days,int price,int tax)
    {
        //cout<<rooms <<" "<<days<<" "<<price<<" "<<tax;
        int billingAmount=rooms*days*price;
        //billingAmount=billingAmount+((tax*billingAmount)/100);
        
        return billingAmount;
    }
    
};
class Dormitary:public RoomData
{
  private:
  int price =500;
  int tax =0;
  public:
  int numberOfRooms()
  {
    return getNumberOfAdults();
  }
  int getPrice()
  {
    return this->price;
  } 
  int getTax()
  {
    return this->tax;
  }
};
class Non_AC:public RoomData
{
  private:
  int price =1000;
  int tax =0;
  public:
  int numberOfRooms()
  {
    return ((getNumberOfAdults()/2)+(getNumberOfAdults()%2));
  }
  int getPrice()
  {
    return this->price;
  } 
  int getTax()
  {
    return this->tax;
  }
};
class AC_Room:public RoomData
{
  private:
  int price =2500;
  int tax =5;
  public:
  int numberOfRooms()
  {
    return ((getNumberOfAdults()/2)+(getNumberOfAdults()%2));
  }
  int getPrice()
  {
    return this->price;
  } 
  int getTax()
  {
    return this->tax;
  }
};
class Premium:public RoomData
{
  private:
  int price =5000;
  int tax =7;
  public:
  int numberOfRooms()
  {
    float temp = getNumberOfAdults()/4.0;
    int rooms = ceil(temp);
    return rooms;
  }
  int getPrice()
  {
    return this->price;
  } 
  int getTax()
  {
    return this->tax;
  }
};
void display(auto obj,string inTime,int adultNumber,int daysStaying)
{
    obj.setCheckInTime(inTime);
        obj.setNumberOfAdults(adultNumber);
        obj.setNumberOfDays(daysStaying);
    
        float newNumberOfDays=obj.caclNumofDays(inTime,daysStaying);
        int finalPriceCalc =obj.calcFinalPrice(obj.numberOfRooms(),newNumberOfDays,obj.getPrice(),obj.getTax());
    
        cout<<finalPriceCalc;
}
int main()
{
    string inTime,roomType;
    int adultNumber,daysStaying;
    
    cout<<"Enter the room Type: ";
    cin >>roomType;
    cout<<"Enter the check in time";
    cin >>inTime;
    cout <<"Enter the number of Adults:";
    cin>>adultNumber;
    cout<<"Enter the number of days you are planing to stay:";
    cin >>daysStaying;
    
    map<string,int>keyValue {{"Dormitary",1},{"Non_AC_Room",2},{"AC_Room",3},{"Premium",4}};
    auto value = keyValue.find(roomType);
    
    switch(value->second)
    {
        case 1:
        {
            Dormitary obj;
            display(obj,inTime,adultNumber,daysStaying);
            break;
        }
        case 2:
        {
            Non_AC obj1;
            display(obj1,inTime,adultNumber,daysStaying);
            break;
        }
        case 3:
        {
            AC_Room obj2;
            display(obj2,inTime,adultNumber,daysStaying);
            break;
        }
        case 4:
        {
            Premium obj3;
            display(obj3,inTime,adultNumber,daysStaying);
            break;
        }
        default:
            cout <<"No Rooms available";
        
    }
    return 0;
}