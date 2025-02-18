#include <iostream>
using namespace std;

class BMW {
private:
	void exterior()
	{
		cout << "Exterior: 18 V - Spoke Bicolor 866 Wheels with All Season Tires " << endl;

	}
	void connectivity()
	{
		cout << "Connectivity: Remote Software Upgrade Capable" << endl;
	}
	void audioSystem()
	{
		cout << "Audio System: HiFi Sound System" << endl
			<< "SiriusXM® with 360L + 1 year Platinum Plan Subscription" << endl;
	}
	void controls()
	{
		cout << "Controls: 3-spoke leather-wrapped sport steering wheel" << endl;
	}
	void warranty()
	{
		cout << "Warranty: 12-year Unlimited Mileage Rust Perforation Limited Warranty" << endl
			<< "4-year Unlimited Mileage Roadside Assistance Program" << endl;
	}
protected:
	virtual void efficiency() = 0;
	virtual void handling() = 0;
	virtual const char* modelName() = 0;
	virtual void interiorTrim() = 0;
	virtual void comfort() = 0;
	virtual void security() = 0;
	virtual float price() = 0;
public:
	void spacification()
	{
		cout << endl;
		cout << "Model:\t\t" << modelName() << endl;
		cout << "=========================================================" << endl;
		efficiency();
		cout << "=========================================================" << endl;
		handling();
		cout << "=========================================================" << endl;
		exterior();
		cout << "=========================================================" << endl;
		interiorTrim();
		cout << "=========================================================" << endl;
		connectivity();
		cout << "=========================================================" << endl;
		audioSystem();
		cout << "=========================================================" << endl;
		controls();
		cout << "=========================================================" << endl;
		comfort();
		cout << "=========================================================" << endl;
		security();
		cout << "=========================================================" << endl;
		warranty();
		cout << "=========================================================" << endl;
		cout << "Price: $" << price() << endl;
		cout << "=========================================================" << endl;
	}
};
// -------------------------------
// SUVs
class SUVs : public BMW {
protected:
	void security()
	{
		cout << "Security: 360-degree cameras, and advanced airbag systems. Sturdy build for enhanced protection" << endl;
	}
	void interiorTrim()
	{
		cout << "Interior Trim: Premium materials like Vernasca and Merino leather with" << endl
			<< "wood and aluminum accents, emphasizing luxury and utility. ." << endl;
	}
};
// X1
class X1suv : public SUVs {
protected:
	void efficiency()
	{
		cout << "Motor: 2.0-liter BMW TwinPower Turbo inline 4-cylinder, xDrive, intelligent all-wheel drive" << endl;
	}
	void comfort()
	{
		cout << "Comfort: Engine Start/Stop button" << endl;
	}
	void handling()
	{
		cout << "Handling: Servotronic vehicle-speed-sensitive power steering" << endl;
	}
};
class X1xDrive28i : public X1suv {
protected:
	const char* modelName()
	{
		return "X1 xDrive28i";
	}
	float price()
	{
		return 41350;
	}
};
class X1M35i : public X1suv {
protected:
	const char* modelName()
	{
		return "X1 M35i";
	}
	float price()
	{
		return 41350;
	}
};
// X4
class X4suv : public SUVs {
protected:
	void comfort()
	{
		cout << "Comfort: Advanced Vehicle & Key Memory includes most recently used climate-control temperature and air-distribution settings." << endl;
	}
};
class X4xDrive30i : public X4suv {
protected:
	void efficiency()
	{
		cout << "Motor: 2.0-liter BMW TwinPower Turbo inline 4-cylinder, 16-valve 248-hp engine." << endl;
	}
	const char* modelName()
	{
		return "X4 xDrive30i";
	}
	void handling()
	{
		cout << "Handling: xDrive all-wheel-drive system. " << endl;
	}
	float price()
	{
		return 55300;
	}
};
class X4M40i : public X4suv {
protected:
	void efficiency()
	{
		cout << "Motor: 3.0-liter BMW M TwinPower Turbo inline 6-cylinder, 24-valve 382-hp engine." << endl;
	}
	const char* modelName()
	{
		return "X4 M40i";
	}
	void handling()
	{
		cout << "Handling: Variable Sport Steering" << endl;
	}
	float price()
	{
		return 66700;
	}
};
// X4M
class X4Msuv : public SUVs {
protected:
	void efficiency()
	{
		cout << "Motor: 3.0-liter BMW M TwinPower Turbo technology 473-hp inline 6-cylinder engine." << endl;
	}
	void handling()
	{
		cout << "Handling: M Sport Differential" << endl;
	}
	const char* modelName()
	{
		return "X4M";
	}
	void comfort()
	{
		cout << "Comfort: Driver's and passenger's front airbag supplemental restraint system (SRS) with advanced technology" << endl;
	}
	float price()
	{
		return 79100;
	}
};
// X5
class X5suv : public SUVs {
protected:
	void handling()
	{
		cout << "Handling: Dynamic Stability Control(DSC), including Brake Fade Compensation." << endl;
	}
	void comfort()
	{
		cout << "Comfort: Advanced Vehicle & Key Memory includes most recently used climate-control temperature and air-distribution settings." << endl;
	}
};
class X5xDrive40i : public X5suv {
protected:
	void efficiency()
	{
		cout << "Motor: 3.0 - liter BMW TwinPower Turbo inline 6 - cylinder, 24 - valve 375 - hp engine with eBoost 48V mild hybrid technology." << endl;
	}
	const char* modelName()
	{
		return "X5 xDrive40i";
	}
	float price()
	{
		return 68600;
	}
};
class X5M60i : public X5suv {
protected:
	void efficiency()
	{
		cout << "Motor: 4.4-liter BMW M TwinPower Turbo V-8, 32-valve 523-hp engine with eBoost 48V mild hybrid technology. " << endl;
	}
	const char* modelName()
	{
		return "X5 M60i";
	}
	float price()
	{
		return 90850;
	}
};
class X5xDrive50e : public X5suv {
protected:
	void efficiency()
	{
		cout << "Motor: 3.0-liter BMW TwinPower Turbo inline 6-cylinder, 24-valve engine." << endl;
	}
	const char* modelName()
	{
		return "X5 xDrive50e";
	}
	float price()
	{
		return 73800;
	}
};
// ----------------------------------
// Sedans
class Sedans : public BMW {
protected:
	void security()
	{
		cout << "Security: Standard BMW safety features like lane departure warning, blind-spot detection, and crash mitigation systems." << endl;
	}
	void interiorTrim()
	{
		cout << "Interior Trim: High-end finishes like Sensatec and genuine leather with sleek wood and aluminum trims." << endl
			<< "Attention to detail for a refined, luxurious ambiance." << endl;
	}
};
// I5
class I5Sedans : public Sedans {
protected:
	void handling()
	{
		cout << "Handling: Variable Sport Steering. " << endl;
	}
	void comfort()
	{
		cout << "Comfort: Universal garage-door opener. " << endl;
	}
};
class I5M60 : public I5Sedans {
protected:
	void efficiency()
	{
		cout << "Motor: Dual all-electric motors with a total power output of 593 hp and 586 lb ft of torque." << endl;
	}
	const char* modelName()
	{
		return "i5 M60";
	}
	float price()
	{
		return 84100;
	}
};
class I5xDrive40 : public I5Sedans {
protected:
	void efficiency()
	{
		cout << "Motor: Dual all-electric motors with a total power output of 389-hp and 435 lb-ft of torque. " << endl;
	}
	const char* modelName()
	{
		return "i5 xDrive40";
	}
	float price()
	{
		return 70100;
	}
};
// I7
class I7Sedans : public Sedans {
protected:
	void handling()
	{
		cout << "Handling: 4-wheel ventilated disc brakes with Anti-lock Braking System (ABS). " << endl;
	}
	void comfort()
	{
		cout << "Comfort: Advanced Vehicle & Key Memory includes most recently used climate-control temperature and air-distribution settings. " << endl;
	}
};
class I7xDrive60 : public I7Sedans {
protected:
	void efficiency()
	{
		cout << "Motor: Dual all-electric motors with a total power output of 536-hp and 549lb-ft of torque. " << endl;
	}
	const char* modelName()
	{
		return "i7 xDrive60";
	}
	float price()
	{
		return 124200;
	}
};
class I7M70 : public I7Sedans {
protected:
	void efficiency()
	{
		cout << "Motor: Dual all-electric motors with a total power output of 650hp and 749 lb-ft of torque motor. " << endl;
	}
	const char* modelName()
	{
		return "i7 M70";
	}
	float price()
	{
		return 168500;
	}
};
// M8
class M8Sedans : public Sedans {
protected:
	void efficiency()
	{
		cout << "Motor: 4.4-liter BMW M TwinPower Turbo V-8, 32-valve 617-hp engine. " << endl;
	}
	void handling()
	{
		cout << "Handling: M-developed electric power steering with Servotronic" << endl;
	}
	const char* modelName()
	{
		return "M8 Competition Gran Coupe";
	}
	void comfort()
	{
		cout << "Comfort: Advanced Vehicle & Key Memory includes most recently used climate-control temperature and air-distribution settings. " << endl;
	}
	float price()
	{
		return 140000;
	}
};
// -------------------------------
// Coupes
class Coupe : public BMW {
protected:
	void security()
	{
		cout << "Security: Sport-inspired interiors featuring Alcantara, carbon fiber accents," << endl
			<< "and contoured sport seats for the driver and front passenger." << endl;
	}
	void interiorTrim()
	{
		cout << "Interior Trim: Sport-inspired interiors featuring Alcantara, carbon fiber accents," << endl
			<< "and contoured sport seats for the driver and front passenger.." << endl;
	}
};
// 2
class Coupe2 : public Coupe {
protected:
	void handling()
	{
		cout << "Handling: Servotronic power-steering assist. " << endl;
	}
	void comfort()
	{
		cout << "Comfort: Storage compartment package. " << endl;
	}
};
class Coupe230ixDrive : public Coupe2 {
protected:
	void efficiency()
	{
		cout << "Motor: 2.0-liter BMW TwinPower Turbo inline 4-cylinder, xDrive all-wheel drive. " << endl;
	}
	const char* modelName()
	{
		return "230i xDrive";
	}
	float price()
	{
		return 41600;
	}
};
class CoupeM240ixDrive : public Coupe2 {
protected:
	void efficiency()
	{
		cout << "Motor: 3.0-liter BMW TwinPower Turbo inline 6-cylinder, xDrive all-wheel drive. " << endl;
	}
	const char* modelName()
	{
		return "M240i xDrive";
	}
	float price()
	{
		return 52600;
	}
};
// M2
class CoupeM2 : public Coupe {
protected:
	void efficiency()
	{
		cout << "Motor: 3.0-liter BMW M TwinPower Turbo technology 473-hp inline 6-cylinder engine. " << endl;
	}
	void handling()
	{
		cout << "Handling: M-developed electric power steering with Servotronic. " << endl;
	}
	const char* modelName()
	{
		return "M2 Coupe";
	}
	void comfort()
	{
		cout << "Comfort: Advanced Vehicle & Key Memory includes most recently used climate-control temperature and air-distribution settings. " << endl;
	}
	float price()
	{
		return 65500;
	}
};
// --------------------------
// Convertibles 
class Convertible : public BMW {
protected:
	void security()
	{
		cout << "Security: Reinforced roll bars, pop-up roll protection, and robust chassis design for rollover safety." << endl;

	}
	void interiorTrim()
	{
		cout << "Interior Trim: Luxury materials similar to coupes but with added weather-resistant finishes." << endl;
	}
};
// 8
class Convertible8 : public Convertible {
protected:
	void handling()
	{
		cout << "Handling: Dynamic Stability Control (DSC), including Brake Fade Compensation," << endl
			<< "Start - off Assistant, Brake Drying, and Brake Stand - by features. " << endl;
	}
	void comfort()
	{
		cout << "Comfort: Advanced Vehicle & Key Memory includes most recently used climate-control temperature and air-distribution settings. " << endl;
	}
};
class Convertible840ixDrive : public Convertible8 {
protected:
	void efficiency()
	{
		cout << "Motor: 3.0-liter BMW TwinPower Turbo inline 6-cylinder, xDrive; intelligent all-wheel drive. " << endl;
	}
	const char* modelName()
	{
		return "840i xDrive";
	}
	float price()
	{
		return 104400;
	}
};
class ConvertibleM850ixDrive : public Convertible8 {
protected:
	void efficiency()
	{
		cout << "Motor: 4.4-liter BMW M TwinPower Turbo V-8 engine, xDrive; intelligent all-wheel drive. " << endl;
	}
	const char* modelName()
	{
		return "M850i xDrive";
	}
	float price()
	{
		return 117000;
	}
};
// BMW Cars Function
void BmwCars()
{
	cout << "Choose a Type: " << endl
		<< "1: SUVs" << endl
		<< "2: Sedans" << endl
		<< "3: Coupes" << endl
		<< "4: Convertibles" << endl;
	cout << "Which One: ";
	int typeChoice;
	cin >> typeChoice;
	while (typeChoice > 4 || typeChoice < 1)
	{
		cout << "Invalid Choice!" << endl;
		cout << "Enter Again: ";
		cin >> typeChoice;
	}
	if (typeChoice == 1)
	{
		cout << "Choose An SUV: " << endl
			<< "X1" << endl
			<< "\t1: X1 xDrive28i SUV" << endl
			<< "\t2: X1 M35i SUV" << endl
			<< "X4" << endl
			<< "\t3: X4 xDrive30i SUV" << endl
			<< "\t4: X4 M40i SUV" << endl
			<< "X4M" << endl
			<< "\t5: X4M SUV" << endl
			<< "X5" << endl
			<< "\t6: X5 xDrive40i SUV" << endl
			<< "\t7: X5 M60i SUV" << endl
			<< "\t8: X5 xDrive50e SUV" << endl;
		cout << "---------------------" << endl;
		cout << "Which One: ";
		cin >> typeChoice;
		while (typeChoice > 8 || typeChoice < 1)
		{
			cout << "Invalid Choice!" << endl;
			cout << "Enter Again: ";
			cin >> typeChoice;
		}
	}
	else if (typeChoice == 2)
	{
		cout << "Choose A Sedans: " << endl
			<< "I5" << endl
			<< "\t9: i5 M60 Sedan" << endl
			<< "\t10: i5 xDrive40 Sedan" << endl
			<< "I7" << endl
			<< "\t11: i7 xDrive60 Sedan" << endl
			<< "\t12: i7 M70 Sedan" << endl
			<< "M8" << endl
			<< "\t13: M8 Competition Gran Coupe" << endl;
		cout << "---------------------" << endl;
		cout << "Which One: ";
		cin >> typeChoice;
		while (typeChoice > 13 || typeChoice < 9)
		{
			cout << "Invalid Choice!" << endl;
			cout << "Enter Again: ";
			cin >> typeChoice;
		}
	}
	else if (typeChoice == 3)
	{
		cout << "Choose A Coupe: " << endl
			<< "2" << endl
			<< "\t14: 230i xDrive Coupe" << endl
			<< "\t15: M240i xDrive Coupe" << endl
			<< "M2" << endl
			<< "\t16: M2 Coupe" << endl;
		cout << "---------------------" << endl;
		cout << "Which One: ";
		cin >> typeChoice;
		while (typeChoice > 16 || typeChoice < 14)
		{
			cout << "Invalid Choice!" << endl;
			cout << "Enter Again: ";
			cin >> typeChoice;
		}
	}
	else if (typeChoice == 4)
	{
		cout << "Choose A Convertible: " << endl
			<< "8" << endl
			<< "\t17: 840i xDrive Convertible" << endl
			<< "\t18: M850i xDrive Convertible" << endl;
		cout << "---------------------" << endl;
		cout << "Which One: ";
		cin >> typeChoice;
		while (typeChoice > 18 || typeChoice < 17)
		{
			cout << "Invalid Choice!" << endl;
			cout << "Enter Again: ";
			cin >> typeChoice;
		}
	}
	BMW* BmwCar = nullptr;
	switch (typeChoice)
	{
	case 1:
		BmwCar = new X1xDrive28i;
		break;
	case 2:
		BmwCar = new X1M35i;
		break;
	case 3:
		BmwCar = new X4xDrive30i;
		break;
	case 4:
		BmwCar = new X4M40i;
		break;
	case 5:
		BmwCar = new X4Msuv;
		break;
	case 6:
		BmwCar = new X5xDrive40i;
		break;
	case 7:
		BmwCar = new X5M60i;
		break;
	case 8:
		BmwCar = new X5xDrive50e;
		break;
	case 9:
		BmwCar = new I5M60;
		break;
	case 10:
		BmwCar = new I5xDrive40;
		break;
	case 11:
		BmwCar = new I7xDrive60;
		break;
	case 12:
		BmwCar = new I7M70;
		break;
	case 13:
		BmwCar = new M8Sedans;
		break;
	case 14:
		BmwCar = new Coupe230ixDrive;
		break;
	case 15:
		BmwCar = new CoupeM240ixDrive;
		break;
	case 16:
		BmwCar = new CoupeM2;
		break;
	case 17:
		BmwCar = new Convertible840ixDrive;
		break;
	case 18:
		BmwCar = new ConvertibleM850ixDrive;
		break;
	}
	if (BmwCar)
	{
		BmwCar->spacification();
		delete BmwCar;
	}
}
// -----------------------
// Main Function
void main()
{
	char again = 'y';
	while (again == 'Y' || again == 'y')
	{
		BmwCars();
		cout << "Do you want to run again(Y/n): ";
		cin >> again;
	}
}