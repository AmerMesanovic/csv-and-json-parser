#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>



using namespace std;

// clasa ulazne datoteke inputA.csv
class inputA{                               
	
	public:
		string id;
		int quantity;
		double price;
		
};

// clasa ulazne datoteke inputB.json
class inputB{
	
	public:
		string id;
		int quantity;
    	double price;
	
};

// clasa izlazne datoteke output.csv
class output{
	
	public:
		string id;
		int quantity;
		double price;
};




int main(){
	
	inputA ia;
	inputB ib;
	output out;


  ifstream ip("inputA.csv");
  if(!ip.is_open()) cout << "ERROR" << '\n';
  string some_id;

  
  ifstream ip2("inputB.json");
  if(!ip2.is_open()) cout << "ERROR" << '\n';
 

    string line;
    string id;
    string quantity;
    string price;
    string s33;
    string s3;
  
  
 ofstream izlazni("izlazni.csv");



  while(ip.good()&&ip2.good()&&izlazni.good()){

  
          while(getline(ip2, line)&&getline(ip,some_id)){
                stringstream ss(line);
                getline(ss,id,',');
                getline(ss,quantity,',');
                getline(ss,price,',');

                stringstream ss3(some_id);
                getline(ss,s3,',');
                string s1 = some_id.substr(0,8);
                string s2 = some_id.substr(9,3);
                string s3 = some_id.substr(12,4);

              string targets3 = ",";
              int founds3=-1;
                        do{
	                        founds3=s3.find(targets3, founds3+1);
	                        if(founds3!=-1){
	                      	s3=s3.substr(0,founds3)+s3.substr(founds3+targets3.length());
                                        	}
                        }while(founds3!=-1);



              string target = "{ \"id\": ";
              int found=-1;
                        do{
                           	found=id.find(target, found+1);
                        	if(found!=-1){
	                       	id=id.substr(0,found)+id.substr(found+target.length());
                       	                 }
                        }while(found!=-1);


              string target1 ="\"quantity\":";
              int found1=-1;
                        do{
                           	found1=quantity.find(target1, found1+1);
                        	if(found1!=-1){
	                       	quantity=quantity.substr(0,found1)+quantity.substr(found1+target1.length());
                          	              }
                        }while(found1!=-1);


               string target2 ="\"price\":";
               int found2=-1;
                         do{
                        	found2=price.find(target2, found2+1);
                        	if(found2!=-1){
	                       	price=price.substr(0,found2)+price.substr(found2+target2.length(),5);
	                                      }
                           }while(found2!=-1);




int quantity1 = atoi(quantity.c_str());
int s22 = atoi(s2.c_str());
double a= stod(s3);
double price1= stod(price);

ia.id = s1;
ia.quantity= s22;
ia.price=a;

ib.id = id;
ib.quantity= quantity1;
ib.price=price1;






  izlazni<<"\"inputA\""<<"; "<<ia.id<<"; "<<ia.quantity<<"; "<<ia.price<<'\n';   
  izlazni<<"\"inputB\""<<"; "<<ib.id<<"; "<<ib.quantity<<"; "<<ib.price<<'\n';


 
    
                                                            }   
}


  
  return 0;
}
