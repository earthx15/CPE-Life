#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
	srand(time(0));
	string EVcommon[] = {"Tooth_decay","injec_vaccine","have_yungbra","injured_from_toys","bully","puppy_love","skipping_class","true_friend","old_camera","smoke","car","copy_theexam","activity","party","boss","cheat","Promote","retire"};
	string EVspacial[] = {"",""};
	string Evnow;
	int SizeEV; 
	int randnumber;
	int randtype;
	
	
	randtype = rand()%101;
	if (randtype >= 10 && randtype <= 100) {
		SizeEV = sizeof(EVcommon) / sizeof(EVspacial[0]);
		randnumber = rand()%SizeEV;
		Evnow = EVcommon[randnumber];
	}else if (randtype == 0 && age == 0) {
		cout << "you death" << endl;
	}else {
		SizeEV = sizeof(EVspacial) / sizeof(EVspacial[0]);
		randnumber = rand()%SizeEV;
		Evnow = EVspacial[randnumber];
	}
	
	
	if (age >= 0 && age <= 5) { // baby
		switch (Evnow) {
			case "Tooth_decay" : 
				cout << "Go to a doctor to treat your Tooth" << endl;
				Health -= random(6)+5;
				break;
			case "injec_vaccine" :
				cout << "Go to hospital to inject a vaccine" << endl;
				Health += random(6)+10;
				break;
			case "have_yungbra" :
				cout << "congratulation you have a yong brather" << endl;
				Happiness += 20;
				break;	
			case "injured_from_toys" :
				cout << "you injured from toys"
				yes : non;
				no : Health += 10;
				break;
		}
	}else (age >= 6 && age <= 14) { // primary
		case "bully" :
				cout << "you are bullied" << endl;
				talk a teacher : if (Moral >= 50) {
									if (rand(3) > 0) {
										teacher protect you : Heath += 10; 
									}else teacher ignore : Heath -= 10; look -= 10; 
								}else {
									teacher ignore : Heath -= 10; look -= 10;
								}
				argut : Heath -= 20; look -= 20;
				bully Someone : Happiness += 10; Moral -= 20;
				notthing : Heath -= 5; look -= 5;
				break;
		case "puppy_love" :	
				if(look >= 80) {
					cout << "some one confess about lovenses to you " << endl;
					yes : Happiness += 30;
					no	: not thing;
				}
		case "skipping_class" :
				cout << "your friends persuade you to skipping class" << endl;
				yes : happineess += 20; look -= 20; smart -= 30;
				no : look += 5; smart += 15;
				no and blame friends : if (random(101 <= 40) {
										your friends not satisfied; Happiness -= 15; 
									}else {
										your friends understand you; look += 5; start += 15; Happiness += 10;
									}
		case "true_friend" :
				cout << "you find true friend" << endl;
				Happiness += 10;
		case "old_camera" :
				cout << "you find dad's old camera" << endl;
				repair : Happiness += 5; 
				notthing : 
	}else (age >= 15 && age <= 18) { // scondary
		case "smoke" :
				cout << "A friend invited me to smoke" << endl;
				agree : moral -=20; Happiness+=10; look -=10; Heath -=15;
				reject : look +=10;
		case "skipping_class" :
				cout << "your friends persuade you to skipping class" << endl;
				yes : happineess += 20; look -= 20; smart -= 30;
				no : look += 5; smart += 15;
				no and blame friends : if (random(101 <= 40) {
										your friends not satisfied; Happiness -= 15; 
									}else {
										your friends understand you; look += 5; start += 15; Happiness += 10;
									} 
	}else (age >= 19 && age <= 22) { // bachelor
		case "car" :
				cout << "Parents bought a car for" << endl;
				Happiness +=15;
		case "copy_theexam" :
				cout << "A friend asked to copy the exam" << endl;
				agree : Happiness += 10; moral -= 10;
				no : 
				Tell the teacher : look -= 20;
		case "activity" :
				cout <<"Enter the activity"<<endl;
				go: look +=10;
				no: Happiness+=5;
				Cursingsenior : look -=20; Happiness +=10;
	}else (age >= 23 && age <= 40) { // primary adult
		case "party" :
				cout <<"The party" <<endl;
				go: look += 5;
				no: look -=10;
		case "boss" :
				cout <<"Being cursed by the boss"<<endl;
				sorry: Happiness -= 5; look -=5;
				retaliate : Happiness +=10 look -=15;
				Resign : "lost job";
		case "cheat" :
				cout << "A friend who works to defraud company money"<<endl;
				join: Happiness +=10; look -=20; moral -=20;
				tellboss: "friend lost job";
				
	}else (age >= 41 && age <= 60) { // second adult
		case "Promote":
				cout <<"Promote"<<endl;
		case "boss" :
				cout <<"Being cursed by the boss"<<endl;
				sorry: Happiness -= 5; look -=5;
				retaliate : Happiness +=10 look -=15;
				Resign : "lost job";
		case "retire" :
				cout <<"you retire";		
	}else // The elderly 
	{
					
	}
	

}

