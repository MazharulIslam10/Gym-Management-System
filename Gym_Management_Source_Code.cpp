#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class gym;
class trainers;
class customers;
class exerciseplan;
class equipment;
class date;
class equipment
{
public:
    int id;
    string name;

    equipment()
    {
        id = 0;
        name = '\0';
    }
    equipment(int i, string n)
    {
        id = i;
        name = n;
    }
    
    void Eprint()
    {
        cout << "=========EQUIPMENTS MENU=======" << endl;
        cout << "press 1 for equipments list" << endl;
        cout << "press 2 to add a equipments" << endl;
        cout << "press 3 to remove a equipments\n";
        cout << "press 4 to edit equipments details" << endl;
        cout << "press 5 to back to main menu " << endl;

        int a;
        while (true)
        {
            cin >> a;
            if (a == 1)
            {
                cout << "-----Equipments list------" << endl;
                ifstream myfile("equipments.txt", ios::in);
                if (myfile.is_open())
                {
                    while (!myfile.eof())
                    {
                        myfile >> id >> name;
                        cout << id << "\t" << name << "\t" << endl;
                    }
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                myfile.close();
                cout << "=========EQUIPMENTS MENU=======" << endl;
                cout << "press 1 for equipments list" << endl;
                cout << "press 2 to add a equipments" << endl;
                cout << "press 3 to remove a equipments\n";
                cout << "press 4 to edit equipments details" << endl;
                cout << "press 5 to back to main menu " << endl;
            }
            if (a == 2)
            {
                ofstream myfile("equipments.txt", ios::app);
                if (myfile.is_open())
                {
                    cout << "enter id and name of equipment to add " << endl;
                    cin >> id >> name;
                    myfile << endl
                           << id << "\t" << name;
                    cout << id << "\t" << name << "\t";
                    cout << "Equipment added successfully " << endl;
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                myfile.close();
                cout << "=========EQUIPMENTS MENU=======" << endl;
                cout << "press 1 for equipments list" << endl;
                cout << "press 2 to add a equipments" << endl;
                cout << "press 3 to remove a equipments\n";
                cout << "press 4 to edit equipments details" << endl;
                cout << "press 5 to back to main menu " << endl;
            }
            if (a == 3)
            {
                int ID_;
                cout << "enter id to remove equipment " << endl;
                cin >> ID_;
                ifstream fin("equipments.txt");

                ofstream myfile;
                myfile.open("temp.txt", ofstream::out);

                char A;
                int line = 1;
                while (fin.get(A))
                {

                    if (A == '\n')
                        line++;

                    if (line != ID_)
                        myfile << A;
                }
                myfile.close();
                fin.close();

                remove("equipments.txt");
                rename("temp.txt", "equipments.txt");

                cout << "Equipment removed successfully" << endl;
                cout << "=========EQUIPMENTS MENU=======" << endl;
                cout << "press 1 for equipments list" << endl;
                cout << "press 2 to add a equipments" << endl;
                cout << "press 3 to remove a equipments\n";
                cout << "press 4 to edit equipments details" << endl;
                cout << "press 5 to back to main menu " << endl;
            }
            if (a == 4)
            {
                int ID_;
                cout << "enter id to edit Equipment" << endl;
                cin >> ID_;
                ifstream fin("equipments.txt");

                ofstream myfile;
                myfile.open("temp.txt", ofstream::out);

                char A;
                int line = 1;
                while (fin.get(A))
                {

                    if (A == '\n')
                        line++;

                    if (line != ID_)
                        myfile << A;
                }
                myfile.close();
                fin.close();

                remove("equipments.txt");
                rename("temp.txt", "equipments.txt");

                ofstream Myfile("equipments.txt", ios::app);
                if (Myfile.is_open())
                {
                    cout << "enter new id and name " << endl;
                    cin >> id >> name;
                    Myfile << endl
                           << id << "\t" << name;
                    cout << id << "\t" << name << "\t" << endl;
                    cout << "equipment data edited successfully " << endl;
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                Myfile.close();
                cout << "=========EQUIPMENTS MENU=======" << endl;
                cout << "press 1 for equipments list" << endl;
                cout << "press 2 to add a equipments" << endl;
                cout << "press 3 to remove a equipments\n";
                cout << "press 4 to edit equipments details" << endl;
                cout << "press 5 to back to main menu " << endl;
            }
            if (a == 5)
            {
                cout << "=========  WELCOME TO OUR GYM  ===========" << endl;
                cout << "-----1 for customers------" << endl;
                cout << "-----2 for trainers --------" << endl;
                cout << "-----3 for equipment--------" << endl;
                cout << "-----4 for exercise plans-----" << endl;
                cout << "-----5 to end the program------" << endl;
                break;
            }
        }
    }
    friend istream &operator>>(istream &input, equipment &D)
    {
        cout << "Enter Equipment id(must be integer) :" << endl;
        input >> D.id;
        cout << "Enter Equipment name :" << endl;
        input >> D.name;
        //cin.ignore();
        return input;
    }
};

class exerciseplan
{
public:
    int plan_ID;
    int duration;
    trainers *trainer_id;
    equipment *equipment_id;
    int no_of_equipments;

    exerciseplan()
    {
        plan_ID = 0;
        int duration = 0;
    }
    exerciseplan(int plan)
    {
        plan_ID = plan;
        trainer_id = nullptr;

        duration = 0;
    }

    void Exprint()
    {
        cout << "plan ID: " << plan_ID << endl;
        cout << "Duration : " << duration << endl;
    }
    void Add_equipments()
    {
        int no_of_eqp;
        string name;
        cout << "Enter number of eqp you want to add " << endl;
        cin >> no_of_eqp;
        equipment_id = new equipment[no_of_eqp];
        for (int i = 0; i < no_of_eqp; i++)
        {
            cout << "Add equipment id you want to add :" << endl;
            int id;
            cin >> id;
            cout << "add equipment name you want to add " << endl;
            cin >> name;
            
            ifstream myfile("equipments.txt", ios::in);
            if (myfile.is_open())
            {
                bool check = true;
                while (!myfile.eof())
                {
                    check = true;
                    myfile >> id >> name;
                    if (id == plan_ID)
                    {
                        check = false;
                        equipment obj(id, name);
                        equipment_id[i] = obj;
                        cout << "Equipment already exists " << endl;
                        break;
                    }
                }
                if (check == true)
                    cout << "Equipment not found " << endl;
            }
            else
            {
                cout << "unable to open equipments file" << endl;
            }
        }
    }
};
class trainers
{
public:
    int id;
    string name;
    int no_of_plans;    
    exerciseplan *plan; 

    trainers()
    {
        id = 0;
        name = '\0';
        no_of_plans = 0;

        {
            plan = nullptr;
        }
    }
    trainers(int i, string n)
    {
        id = i;
        name = n;

        {
            plan = nullptr;
        }
    }
    
    void Tprint()
    {
        cout << "=======TRAINERS MENU========" << endl;
        cout << "press 1 for trainers list" << endl;
        cout << "press 2 to add a trainer" << endl;
        cout << "press 3 to remove a trainer" << endl;
        cout << "press 4 to edit trainer details" << endl;
        cout << "press 5 to add exercise plan" << endl;
        cout << "press 6 to go back to main menu " << endl;
        int a;
        while (true)
        {
            cin >> a;
            if (a == 1)
            {
                cout << "-----Trainers list-------" << endl;
                ifstream myfile("trainers.txt", ios::in);
                if (myfile.is_open())
                {
                    while (!myfile.eof())
                    {
                        myfile >> id >> name;
                        cout << id << "\t" << name << "\t" << endl;
                    }
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                myfile.close();
                cout << "=======TRAINERS MENU========" << endl;
                cout << "press 1 for trainers list" << endl;
                cout << "press 2 to add a trainer" << endl;
                cout << "press 3 to remove a trainer" << endl;
                cout << "press 4 to edit trainer details" << endl;
                cout << "press 5 to add exercise plan" << endl;
                cout << "prss 6 to go back to main menu " << endl;
            }
            if (a == 2)
            {
                ofstream myfile("trainers.txt", ios::app);
                if (myfile.is_open())
                {
                    cout << "enter id and name of trainer to add " << endl;
                    cin >> id >> name;
                    myfile << endl
                           << id << "\t" << name;
                    cout << id << "\t" << name << "\t";
                    cout << "Trainer added successfully" << endl;
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                myfile.close();
                cout << "=======TRAINERS MENU========" << endl;
                cout << "press 1 for trainers list" << endl;
                cout << "press 2 to add a trainer" << endl;
                cout << "press 3 to remove a trainer" << endl;
                cout << "press 4 to edit trainer details" << endl;
                cout << "press 5 to add exercise plan" << endl;
                cout << "prss 6 to go back to main menu " << endl;
            }
            if (a == 3)
            {
                int ID_;
                cout << "enter id to remove trainer " << endl;
                cin >> ID_;
                ifstream fin("trainers.txt");

                ofstream myfile;
                myfile.open("temp.txt", ofstream::out);

                char A;
                int line = 1;
                while (fin.get(A))
                {

                    if (A == '\n')
                        line++;

                    if (line != ID_)
                        myfile << A;
                }
                myfile.close();
                fin.close();

                remove("trainers.txt");
                rename("temp.txt", "trainers.txt");

                cout << "Trainer removed successfully" << endl;
                cout << "=======TRAINERS MENU========" << endl;
                cout << "press 1 for trainers list" << endl;
                cout << "press 2 to add a trainer" << endl;
                cout << "press 3 to remove a trainer" << endl;
                cout << "press 4 to edit trainer details" << endl;
                cout << "press 5 to add exercise plan" << endl;
                cout << "prss 6 to go back to main menu " << endl;
            }
            if (a == 4)
            {
                int ID_;
                cout << "enter id to edit Trainer" << endl;
                cin >> ID_;
                ifstream fin("trainers.txt");

                ofstream myfile;
                myfile.open("temp.txt", ofstream::out);

                char A;
                int line = 1;
                while (fin.get(A))
                {

                    if (A == '\n')
                        line++;

                    if (line != ID_)
                        myfile << A;
                }
                myfile.close();
                fin.close();

                remove("trainers.txt");
                rename("temp.txt", "trainers.txt");

                ofstream Myfile("trainers.txt", ios::app);
                if (Myfile.is_open())
                {
                    cout << "enter new id and name " << endl;
                    cin >> id >> name;
                    Myfile << endl
                           << id << "\t" << name;
                    cout << id << "\t" << name << "\t" << endl;
                    cout << "Trainer data edited successfully " << endl;
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                Myfile.close();
                cout << "=======TRAINERS MENU========" << endl;
                cout << "press 1 for trainers list" << endl;
                cout << "press 2 to add a trainer" << endl;
                cout << "press 3 to remove a trainer" << endl;
                cout << "press 4 to edit trainer details" << endl;
                cout << "press 5 to add exercise plan" << endl;
                cout << "prss 6 to go back to main menu " << endl;
            }
            if (a == 6)
            {
                cout << "=========  WELCOME TO OUR GYM  ===========" << endl;
                cout << "-----1 for customers------" << endl;
                cout << "-----2 for trainers --------" << endl;
                cout << "-----3 for equipment--------" << endl;
                cout << "-----4 for exercise plans-----" << endl;
                cout << "-----5 to end the program------" << endl;
                break;
            }
            if (a == 5)
            {
                exerciseplan obj(id);
                trainers OBJ;
                ifstream myfile("equipments.txt", ios::in);
                if (myfile.is_open())
                {
                    while (!myfile.eof())
                    {
                        myfile >> id >> name;
                        cout << id << "\t" << name << endl;
                    }
                }
                else
                {
                    cout << "unable to open file " << endl;
                }
                myfile.close();

                ofstream fin("equipments.txt", ios::app);
                if (fin.is_open())
                {
                    fin << endl
                        << id << name;
                    obj.Add_equipments();
                    OBJ.Add_plan(obj);
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                fin.close();
                cout << "=======TRAINERS MENU========" << endl;
                cout << "press 1 for trainers list" << endl;
                cout << "press 2 to add a trainer" << endl;
                cout << "press 3 to remove a trainer" << endl;
                cout << "press 4 to edit trainer details" << endl;
                cout << "press 5 to add exercise plan" << endl;
                cout << "prss 6 to go back to main menu " << endl;
            }
            
        }
    }
    void Add_plan(exerciseplan &obj)
    {
        ofstream fin("exerciseplans.txt", ios::out);
        if(fin.is_open())
        {
        cout << "Enter plan ID : ";
        cin >> id;
        fin<< id ;
        cout << "plan for 3 days " << endl;
        plan = new exerciseplan[3];
        for (int i = 0; i < 3; i++)
        {
            exerciseplan obj(id);
            obj.Add_equipments();
        }
        }
        else 
        {
            cout<<"unable to write in file "<<endl;
        }
    }
    
};
class customers
{
public:
    int id;
    string name;
    string address;
    int phone;
    string email;
    trainers *trainer;
    customers()
    {
        id = 0;
        name = '\0';
        address = '\0';
        phone = 0;
        email = '\0';
        trainer = nullptr;
    }

    customers(int i, string n, int a, int p, string e)
    {
        id = i;
        name = n;
        address = a;
        phone = p;
        email = e;
        trainer = nullptr;
    }
    
    void Cprint()
    {
        cout << "==========CUSTOMER MENU==========" << endl;
        cout << "press 1 for customers list" << endl;
        cout << "press 2 to add a customer" << endl;
        cout << "press 3 to remove a customer\n";
        cout << "press 4 to edit customer details" << endl;
        cout << "press 5 to go back to main menu " << endl;
        int a;
        while (true)
        {
            cin >> a;

            if (a == 1)
            {
                ifstream myfile("customers.txt", ios::in);
                if (myfile.is_open())
                {
                    while (!myfile.eof())
                    {
                        myfile >> id >> name >> address >> phone >> email;
                        cout << id << "\t" << name << "\t" << address << "\t" << phone << "\t" << email << "\t" << endl;
                    }
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                myfile.close();
                cout << "==========CUSTOMER MENU==========" << endl;
                cout << "press 1 for customers list" << endl;
                cout << "press 2 to add a customer" << endl;
                cout << "press 3 to remove a customer\n";
                cout << "press 4 to edit customer details" << endl;
                cout << "press 5 to go back to main menu " << endl;
            }
            if (a == 2)
            {
                ofstream myfile("customers.txt", ios::app);
                if (myfile.is_open())
                {
                    cout << "enter id, name, address , phone, email" << endl;
                    cin >> id >> name >> address >> phone >> email;
                    myfile << endl
                           << id << "\t" << name << "\t" << address << "\t" << phone << "\t" << email;
                    cout << id << "\t" << name << "\t" << address << "\t" << phone << "\t" << email << "\t" << endl;
                    cout << "customer added successfully " << endl;
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                myfile.close();
                cout << "==========CUSTOMER MENU==========" << endl;
                cout << "press 1 for customers list" << endl;
                cout << "press 2 to add a customer" << endl;
                cout << "press 3 to remove a customer\n";
                cout << "press 4 to edit customer details" << endl;
                cout << "press 5 to go back to main menu " << endl;
            }
            if (a == 3)
            {
                int ID_;
                cout << "enter id to remove customer" << endl;
                cin >> ID_;
                ifstream fin("customers.txt");

                ofstream myfile;
                myfile.open("temp.txt", ofstream::out);

                char A;
                int line = 1;
                while (fin.get(A))
                {

                    if (A == '\n')
                        line++;

                    if (line != ID_)
                        myfile << A;
                }
                myfile.close();
                fin.close();

                remove("customers.txt");
                rename("temp.txt", "customers.txt");

                cout << "Costumer removed successfully" << endl;
                cout << "==========CUSTOMER MENU==========" << endl;
                cout << "press 1 for customers list" << endl;
                cout << "press 2 to add a customer" << endl;
                cout << "press 3 to remove a customer\n";
                cout << "press 4 to edit customer details" << endl;
                cout << "press 5 to go back to main menu " << endl;
            }
            if (a == 4)
            {
                int ID_;
                cout << "enter id to edit customer" << endl;
                cin >> ID_;
                ifstream fin("customers.txt");

                ofstream myfile;
                myfile.open("temp.txt", ofstream::out);

                char A;
                int line = 1;
                while (fin.get(A))
                {

                    if (A == '\n')
                        line++;

                    if (line != ID_)
                        myfile << A;
                }
                myfile.close();
                fin.close();

                remove("customers.txt");
                rename("temp.txt", "customers.txt");

                ofstream Myfile("customers.txt", ios::app);
                if (Myfile.is_open())
                {
                    cout << "enter new id, name, address , phone, email to edit customer " << endl;
                    cin >> id >> name >> address >> phone >> email;
                    Myfile << endl
                           << id << "\t" << name << "\t" << address << "\t" << phone << "\t" << email;
                    cout << id << "\t" << name << "\t" << address << "\t" << phone << "\t" << email << "\t" << endl;
                    cout << "customer data edited successfully " << endl;
                }
                else
                {
                    cout << "unable to read file" << endl;
                }
                Myfile.close();
                cout << "==========CUSTOMER MENU==========" << endl;
                cout << "press 1 for customers list" << endl;
                cout << "press 2 to add a customer" << endl;
                cout << "press 3 to remove a customer\n";
                cout << "press 4 to edit customer details" << endl;
                cout << "press 5 to go back to main menu " << endl;
            }
            if (a == 5)
            {
                cout << "=========  WELCOME TO OUR GYM  ===========" << endl;
                cout << "-----1 for customers------" << endl;
                cout << "-----2 for trainers --------" << endl;
                cout << "-----3 for equipment--------" << endl;
                cout << "-----4 for exercise plans-----" << endl;
                cout << "-----5 to end the program------" << endl;
                break;
            }
        }
    }
    void select_trainer()
    {
        int i_d;
        cout << "enter trainer ID : " << endl;
        cin >> i_d;
        string name_;

        ifstream myfile("trainers.txt", ios::in);
        if (myfile.is_open())
        {
            while (!myfile.eof())
            {
                myfile >> id >> name;
                if (i_d == id)
                {
                    trainers obj(i_d, name_);
                    trainer = &obj;
                    cout << "trainer selected successfully" << endl;
                }
                else
                {
                    cout << "Trainer not found " << endl;
                }
            }
        }
        else
        {
            cout << "unable to read file" << endl;
        }
        myfile.close();
    }
};

class Date
{
public:
    int sub_id;
    int date;
    int customer_id;
    int plan_id;

    Date()
    {
        sub_id = 0;
        date = 0;
        customer_id = 0;
        plan_id = 0;
    }
    Date(int sub_, int d, int c, int p)
    {
        sub_id = sub_;
        date = d;
        customer_id = c;
        plan_id = p;
    }
    
};

class gym
{
public:
    customers *customer[5];
    trainers *Trainer[5];
    equipment *equipments[5];

    gym()
    {
        for (int i = 0; i < 5; i++)
        {
            customer[i] = nullptr;
            Trainer[i] = nullptr;
            equipments[i] = nullptr;
        }
    }
    ~gym()
    {
        for (int i = 0; i < 5; i++)
        {
            
            customer[i] = nullptr;
            
            Trainer[i] = nullptr;

            equipments[i] = nullptr;
        }
    }
};

int main()
{
    cout << "=========  WELCOME TO OUR GYM  ===========" << endl;
    int a;
    customers b;
    trainers t;
    equipment e;
    exerciseplan E;

    cout << "-----1 for customers------" << endl;
    cout << "-----2 for trainers --------" << endl;
    cout << "-----3 for equipment--------" << endl;
    cout << "-----4 to end the program------" << endl;
    while (true)
    {
        cin >> a;
        if (a == 1)
        {
            b.Cprint();
        }
        if (a == 2)
        {
            t.Tprint();
        }
        if (a == 3)
        {
            e.Eprint();
        }
        if (a == 4)
        {
            break ;
        }
        
    }
    
	system("pause");

    return 0;
}