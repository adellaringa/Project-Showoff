#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int MAX_SIZE = 100;
//to change int to string you would do to_string(x)

//display menu
void display(){
cout << "C - MANTAINANCE CHECK << M - UPDATE MILEAGE << R - UPDATE ROTATE TIRES << O - UPDATE OIL CHANGE" << endl;
cout << "T - UPDATE TRANSMISSION FLUID CHANGE << B - UPDATE BRAKE FLUID CHANGE << H - HALDEX FLUID CHANGE " << endl;
cout << "K - MAINTENANCE HISOTRY <<  S - SAVE CHANGES << X - EXIT" << endl;
}
//saving and updating information
/*
void save(int mileage, int last_oilchange, int oilchange, int last_haldexfluid ,
		int haldexfluid, int last_transfluid, int transfluid, int last_rotatetires,
		int rotatetires, int last_brakefluid, int brakefluid ,string date[], string mainthistory[], int iterator, ofstream outfile){
	outfile << to_string(mileage) << to_string(last_oilchange) << to_string(oilchange) << to_string(last_haldexfluid) <<
			to_string(haldexfluid) << to_string(last_transfluid) << to_string(transfluid) << to_string(last_rotatetires) <<
			to_string(rotatetires) << to_string(last_brakefluid) << to_string(brakefluid) << endl;
	for(int i = 0; i < iterator; i++){
		outfile << date[i] << endl;
		outfile << mainthistory[i] << endl;
	}


}*/
int main() {
	//declarations
	bool flag = false;
	int mileage,last_oilchange, oilchange, last_haldexfluid	,
	haldexfluid,last_transfluid,transfluid, last_rotatetires,
	rotatetires, last_brakefluid, brakefluid;
	string date[MAX_SIZE];
	string mainthistory[MAX_SIZE];
	string userin, line;

		//trying to open in-file
		cout << "trying to open text file" << endl;
		ifstream infile("/Users/dellaringo/Downloads/audiA3maint.txt");
		//mando things
		int iterator = 0;
		//checking for successful open
		if (!infile.is_open())
		{
			cout << "unsuccessful open" << endl;
		}

		//mileage
		getline(infile,line);
		mileage = stoi(line.substr(0,9));
		cout << "mileage " << mileage << endl;

		//oil change
		last_oilchange = stoi(line.substr(9,8));
		cout << "last oil change " << last_oilchange << endl;
		oilchange = stoi(line.substr(17,8));
		cout << "oil change " << oilchange << endl;

		//haldexfluid
		last_haldexfluid = stoi(line.substr(25,7));
		cout << "last haldex fluid " << last_haldexfluid << endl;
		haldexfluid = stoi(line.substr(32,9));
		cout << "haldex fluid " << haldexfluid << endl;
		//transmission fluid
		last_transfluid = stoi(line.substr(41,7));
		cout << "last transmission fluid " << last_transfluid << endl;
		transfluid = stoi(line.substr(48,8));
		cout << "transmission fluid " << transfluid << endl;
		//rotate tires
		last_rotatetires = stoi(line.substr(56,11));
		cout << "last rotate tires " << last_rotatetires << endl;
		rotatetires = stoi(line.substr(67,8));
		cout << "rotate tires " << rotatetires << endl;
		//brake fluid
		last_brakefluid =stoi(line.substr(75,8));
		cout << "last brake fluid " << last_brakefluid << endl;
		brakefluid = stoi(line.substr(83,5));
		cout << "brake fluid " << brakefluid << endl;
		//carbon cleaning

		//brake pads

		//brake rotors

		//problems/issues

		//prior mainthisotry with dates

		//other stuff i want to do
		while(!infile.eof()){

			getline(infile,line);
			date[iterator] = line;
			getline(infile, line);
			mainthistory[iterator] = line;
			iterator++;
		}
		infile.close();

	//getting into loop
	display();
	getline(cin,userin);

	//trying to open-outfile
	cout << "trying to open output file" << endl;
	ofstream outfile( "/Users/dellaringo/Downloads/audiA3.txt");
	if(!outfile.is_open()){
		cout << "unsuccessful open" << endl;
	}


	while(userin.at(0) != 'X'){

		//change rotate tires
		if(userin.at(0) =='R'){
			cout << "what is the mileage" << endl;
			string temp;
			getline(cin, temp);
			mileage = stoi(temp);
		}
		//change brake fluid
		else if(userin.at(0) =='B'){
			cout << "what is the mileage" << endl;
						string temp;
						getline(cin, temp);
						mileage = stoi(temp);
				}
		//change transmission fluid
		else if(userin.at(0) =='T'){
			cout << "what is the mileage" << endl;
						string temp;
						getline(cin, temp);
						mileage = stoi(temp);
				}
		//change oil
		else if(userin.at(0) =='O'){
			cout << "what is the mileage" << endl;
						string temp;
						getline(cin, temp);
						mileage = stoi(temp);
				}
		//change haldex
		else if(userin.at(0) =='H'){
			cout << "what is the mileage" << endl;
						string temp;
						getline(cin, temp);
						mileage = stoi(temp);
				}

		//check if maintenance is needed
		else if(userin.at(0)=='C'){
			cout << "**************************************************************************" << endl;
			cout << "\t-----------CHECKING IF MAINTENANCE IS NEEDED--------------" << endl;
			cout << "**************************************************************************" << endl;
			if(last_oilchange >= oilchange){
				cout << "YOU NEED AN OIL CHANGE" << endl;
			}
			else{
				int q = oilchange-last_oilchange;
				cout << "miles til you need oil change:\t\t\t" << q <<endl;
			}
			if(last_haldexfluid >= haldexfluid){
				cout << "YOU NEED TO CHANGE THE HALDEX FLUID" << endl;
			}
			else{
				int q = haldexfluid-last_haldexfluid;
				cout << "miles til you need to change haldex fluid: \t" << q << endl;
			}
			if(last_transfluid >= transfluid){
				cout << "YOU NEED TO CHANGE TRANSMISSION FLUID" << endl;
			}
			else{
				int q = transfluid-last_transfluid;
				cout << "miles til you need to change trans fluid:\t" << q << endl;
			}
			if(last_rotatetires >= rotatetires){
				cout << "YOU NEED TO ROTATE TIRES" << endl;
			}
			else{
				int q = rotatetires-last_rotatetires;
				cout << "miles til you need to rotate tires:\t\t" << q << endl;
			}
			if(last_brakefluid >= brakefluid){
				cout << "NEED TO CHANGE BRAKE FLUID" << endl;
			}
			else{
				int q = brakefluid-last_brakefluid;
				cout << "miles til you need change brake fluid:\t\t" << q << endl;
			}

		}

		//updating mileage
		else if (userin.at(0)=='M')
		{
			cout << 'M' << endl;
			cout << "What is the new mileage" << endl;
			string temp;
			getline(cin,temp);
			int storage = stoi(temp)-mileage;
			mileage = stoi(temp);
			cout << "**************************************************************************" << endl;
			cout << "\t-----------UPDATED INFO--------------" << endl;
			cout << "**************************************************************************" << endl;
			cout << "new mileage: \t" << mileage << endl;
			last_oilchange += storage;
			cout << "new mileSL oil change: \t" << last_oilchange << endl;
			last_haldexfluid += storage;
			cout << "new mileSL haldex change: \t" << last_haldexfluid << endl;
			last_transfluid += storage;
			cout << "new mileSL trans fluid change: \t" << last_transfluid << endl;
			last_rotatetires += storage;
			cout << "new mileSL rotation of tires: \t" << last_rotatetires << endl;
			last_brakefluid += storage;
			cout << "new mileSL brake fluid change: \t" << last_brakefluid << endl;
			cout << "**************************************************************************" << endl;
		}

		else if(userin.at(0) == 'K'){
			cout << "**************************************************************************" << endl;
			cout << "\t-----------DISPLAYING MAINT HISTRY--------------" << endl;
			cout << "**************************************************************************" << endl;
			for(int i = 0; i < iterator ;i++){
				cout << "date:\t\t\t" << date[i] << endl;
				cout << "maintenance performed:\t\t" << mainthistory[i] << endl;
			}
			cout << "Would you like to add a new maintenance? Y or N" << endl;
			getline(cin, userin);
					while(userin.at(0) != 'N'){
						cout << "enter new maintenance date :" << endl;
						getline(cin, date[iterator]);
						cout << "enter new maintenance :" << endl;
						getline(cin, mainthistory[iterator]);
						cout << "Would you like to add a new maintenance record? Y or N" << endl;
						getline(cin, userin);
						iterator++;
						flag = true;

					}
					if(flag){
				for(int i = 0; i < iterator; i++){
						outfile << date[i] << "\n";
						outfile << mainthistory[i] << "\n";
					}
		}
		}
		else if(userin.at(0) == 'S'){
			cout << "**************************************************************************" << endl;
			cout << "\t-----------SAVING CHANGES--------------" << endl;
			cout << "**************************************************************************" << endl;

			//save(mileage,last_oilchange, oilchange, last_haldexfluid, haldexfluid,last_transfluid,transfluid, last_rotatetires, rotatetires, last_brakefluid, brakefluid, date, mainthistory, iterator, outfile);
			outfile << to_string(mileage) << to_string(last_oilchange) << to_string(oilchange) << to_string(last_haldexfluid) <<
						to_string(haldexfluid) << to_string(last_transfluid) << to_string(transfluid) << to_string(last_rotatetires) <<
						to_string(rotatetires) << to_string(last_brakefluid) << to_string(brakefluid) << endl;
				for(int i = 0; i < iterator; i++){
					outfile << date[i] << endl;
					outfile << mainthistory[i] << endl;
		}
		}


		display();
		getline(cin,userin);
		outfile.close();

	}
	return 0;
	}
