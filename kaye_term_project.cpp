//Kyi Lei Aye
//Term_Project:Virtual_Pet_Diliverable
//Instructor:Hilario_Balajadia
//Last_Edited_Date:12/14/2022

#include<iostream>
#include<cmath>
#include<string>
#include<ctime>

//declaring constant variables
const int MAX = 20, MIN = 0, AGEMAX = 40;

//declaring functions
void input();

int randomPoints();
void time(int a[]);

int play(int, int&);
void happinessPoints(int a[], int, int);

int feed(int, int&);
void hungerPoints(int a[], int, int);

int clean(int, int&);
void cleanlinessPoints(int a[], int, int);

int mood(int a[], int);
void talk(int a[], int);

void output(int a[], int);

int main()
{
    using namespace std;

    //calling function
    input();
    
    return 0;
}

/**
 * @brief taking input values from users and process incresion and decresion based on the user's choice
 */
void input(){
    using namespace std;
    
    char ans;
    int option, happiness, hunger, cleanliness, age;

    int stat[] = { happiness, hunger, cleanliness, age};
    int arraySize = 4;
    /*calling random number functions out of do-while loop to have
    the values of happiness, hunger, and cleanliness stats remain the same after running one time*/
    for(int i = 0; i < arraySize - 1; i++){
        stat[i] = randomPoints();
    }
    do{
        cout << "1. Play\n2. Feed\n3. Clean\n4. Talk" << endl;
        cout << "What do you want to do with your Virtual Pet? Choose one of the above options: ";
        cin >> option;
        if(option == 1){
            if(stat[0] < 0){
                happinessPoints(stat, arraySize, stat[0]);
            }
            else{
                stat[3]++;
                happinessPoints(stat, arraySize, stat[0]);
            }
        }
        else if(option == 2){
            if(stat[1] < 0){
                hungerPoints(stat, arraySize, stat[1]);
            }
            else{
                stat[3]++;
                hungerPoints(stat, arraySize, stat[1]);
            }
        }
        else if(option == 3){
            if(stat[2] < 0){
                cleanlinessPoints(stat, arraySize, stat[2]);
            }
            else{
                stat[3]++;
                cleanlinessPoints(stat, arraySize, stat[2]);
            }
        }
        else{
            talk(stat, arraySize);
        }
        cout << "Do you want to do more? Please enter Y or y for \"Yes\" (OR) N or n for \"No\": ";
        cin >> ans;
        cout << endl;
    }while(ans == 'Y' || ans == 'y');
        
}

/**
 * @brief return the random values of points for happiness, hunger, and cleanliness from 1 to 20
 * @return int 
 */
int randomPoints(){
    int random = (rand() % 19) + 1;
    return random;
}

/**
 * @brief increase the hunger and boredom level by adding the random amount of time ranging from 1 to 3
 * @param a - array that include hunger, happiness, cleanliness, and age level
 */
void time(int a[]){
    
    a[0] -= (rand() % 2) + 1;
    a[1] -= (rand() % 2) + 1;
    a[2] -= (rand() % 2) + 1;
}

/**
 * @brief play() function allows user to choose the types of games and return increased different points for happiness stat.
 * @param points - random start points for happiness 
 * @param choice - user's choices on games
 * @return int 
 */
int play(int points, int& choice){
    using namespace std;
    cout << "How would you like to play with?\n1.Tug of War\n2.Hide and Seek\n3.Chase and Retrieve\nChoose one: ";
    cin >> choice;
    if(choice == 1){
        return (points + 1);
    }
    else if(choice == 2){
        return (points + 2);
    }
    else{
        return (points + 4);
    }
}

/**
 * @brief Every time the user play, the happiness level increases based on the game type the user chose and hunger and cleanliness level decreases.
 * If the hunger stat reaches the minimum point, the pet would die.
 * The game types would not be described to choose for user if the pet's happiness level is the max level.
 * The function also output the current levels of pet's situation.
 */
void happinessPoints(int a[], int size, int happyP){
    using namespace std;
    int gameChoice;
    //take out the hunger and cleanliness variables out of if statement to decrease it every time the program is iterated or run even if the happiness level is at the max point
    a[1]--;
    a[2]--;
    
    if((a[0] < MAX)){
        a[0] = play(happyP, gameChoice);
        
        if(a[0] >= 11 && a[0] <= 15){
            output(a, size);
            cout << "Your pet is okay." << endl;
        }
        else if(a[0] >= 6 && a[0] <= 10){
            output(a, size);
            cout << "Your pet is content." << endl;
        }
        else if(a[0] <= 5){
            output(a, size);
            cout << "Your pet is unhappy." << endl;
        }
        //for happiness >= 16
        else{
            output(a, size);
            cout << "Your pet is happy." << endl;
        }
        if(a[2] < 0){
            //50% chance to die
            //reduce the amount of hunger points by half
            cout << "Your pet is sick as it needs cleanliness." << endl;
            a[1] = a[1] / 2;
            if(a[1] < 0){
                cout << "Sorry! Your pet is dead..." << endl;
                exit(0);
            }
            output(a, size);
        }
    }
    else{
        output(a, size);
        cout << "Your pet is the happinest animal.";
        if(a[1] < 0){
            cout << "But your pet is dead as you forget to feed it." << endl;
        }
        if(a[2] < 0){
            //50% chance to die
            //reduce the amount of hunger points by half
            cout << "Your pet is sick as it needs cleanliness." << endl;
            a[1] = a[1] / 2;
            if(a[1] < 0){
                cout << "Sorry! Your pet is dead..." << endl;
                exit(0);
            }
            output(a, size);
        }
    }
    //decrease every three stat after playing
    time(a);
}

/**
 * @brief feed() function allows user to choose the types of food and return increased different points for hunger stat
 * @param points - points for hungry level
 * @param choice - user's choice on hungry level
 * @return int 
 */
int feed(int points, int& choice){
    using namespace std;
    cout << "What do you want to feed?\n1.Treat\n2.Chicken\n3.Turkey\nChoose One: ";
    cin >> choice;
    if(choice == 1){
        return (points + 1);
    }
    else if(choice == 2){
        return(points + 2);
    }
    else{
        return(points + 4);
    }    
}

/**
 * @brief Every time the user feed, the hunger level increases based on the food the user chose and happiness and cleanliness level decreases.
 * If the happiness stat reaches the minimum point, the pet would run away.
 * The food options will not be described to choose for user if the hunger stat reaches its max point.
 * The function also output the current levels of pet's situation.
 */
void hungerPoints(int a[], int size, int hungryP){
    using namespace std;
    int foodChoice;
    //take out the happiness and cleanliness variables out of if statement to decrease them every time the program is iterated or run even if the hunger level is at the max point
    a[0]--;
    a[2]--;
    
    if(a[1] < MAX){
        a[1] = feed(hungryP, foodChoice);
        
        if(a[1] >= 11 && a[1] <= 15){
            output(a, size);
            cout << "Your pet is not hungry." << endl;
        }
        else if(a[1] >= 6 && a[1] <= 10){
            output(a, size);
            cout << "Your pet is somewhat hungry." << endl;
        }
        else if(a[1] < 6){
            output(a, size);
            cout << "Your pet is hungry." << endl;
        }
        else{
            output(a, size);
            cout << "Your pet is full." << endl;
        }
        if(a[2] < 0){
            //50% chance to die
            //reduce the amount of hunger points by half
            cout << "Your pet is sick as it needs cleanliness." << endl;
            a[1] = a[1] / 2;
            if(a[1] < 0){
                cout << "Sorry! Your pet is dead..." << endl;
                exit(0);
            }
            output(a, size);
        } 
    }
    else{
        output(a, size);
        cout << "Your pet is not hungry at all." << endl;
        if(a[0] < 0){
            cout << "Sorry.Your pet runs away." << endl;
            exit(0);
        }
        if(a[2] < 0){
            //50% chance to die
            //reduce the amount of hunger points by half
            cout << "Your pet is sick as it needs cleanliness." << endl;
            a[1]= a[1] / 2;
            if(a[1] < 0){
                cout << "Sorry! Your pet is dead..." << endl;
                exit(0);
            }
            output(a, size);
        }
    }
    //decreasing every three stat after feeding
    time(a);
}

/**
 * @brief clean() function allows the user to choose the way how they clean the pet and return increased various points for cleanliness stat
 * @param points - random start number of cleanliness level got from randomPoints()
 * @param choice - the user choice
 * @return int 
 */
int clean(int points, int& choice){
    using namespace std;
    cout << "In what way do you want to clean your pet?:\n1.Combing fur\n2.Changing clothes\n3.Shower\nChoose One: ";
    cin >> choice;
    if(choice == 1){
        return(points + 1);
    }
    else if(choice == 2){
        return(points + 2);
    }
    else{
        return(points + 4);
    }
}  

/**
 * @brief Every time the user clean, the cleanliness level increases based on the type the user chose to clean and happiness and hunger level decreases.
 * The clean options would not be described to choose for user if the pet's happiness level is the max level.
 * The function also output the current levels of pet's situation.
 */
void cleanlinessPoints(int a[], int size, int cleanP){
    using namespace std;
    int cleanChoice;

    //take out the hunger and happiness variables out of if statement to decrease them every time the program is iterated or run even if the hunger level is at the max point
    a[0]--;
    a[1]--;

    if(a[2] < MAX){
        a[2] = clean(cleanP, cleanChoice);
            
            if(a[2] <= 11 && a[2] >= 15){
                output(a, size);
                cout << "Your pet is kind of clean." << endl;
            }
            else if(a[2] <= 10 && a[2] >= 6){
                output(a, size);
                cout << "Your pet is kind of smelly." << endl;
            }
            else if(a[2] >= 0 && a[2] <= 5){
                output(a, size);
                cout << "Your pet is smelly." << endl;
            }
            else if(a[2] < 0){
                //50% chance to die
                //reduce the amount of hunger points by half
                cout << "Your pet is sick as it needs cleanliness" << endl;
                a[1] = a[1] / 2;
                if(a[2] < 0){
                    cout << "Sorry! Your pet is dead..." << endl;
                    exit(0);
                }
                output(a, size);
            }
            else{
                output(a, size);
                cout << "Your pet is clean." << endl;
            }       
    }
    else{
        output(a, size);
        cout << "Your pet doesn't need cleaning." << endl;
        if(a[0] < 0){
            cout << "Sorry.Your pet runs away." << endl;
            exit(0);
        }
        if(a[1] < 0){
            cout << "Sorry.Your pet dies as you forgot to feed it." << endl;
            exit(0);
        }
    }
    //decreasing every three stat after cleaning
    time(a);
}

/**
 * @brief find the average of the three stats
 * @param a - array that include hunger, happiness, cleanliness, and age level
 * @param size - array  size
 * @return int 
 */
int mood(int a[], int size){
    int sum = 0;
    for(int i = 0; i < size -1 ; i++){
        sum += a[i];
    }
    return (sum / 3);
}

/**
 * @brief output the current levels of all three stats 
 */
void talk(int a[], int size){
    using namespace std;
    output(a, size);
    int avg = mood(a, size);
    if(avg <= 11 && avg >= 15){
        cout << "Your pet's mood is okay." << endl;
    }
    else if(avg <=6 && avg >= 10){
        cout << "Your pet's mood is frustrated." << endl;
    }
    else if(avg <= 5){
        cout << "Your pet's mood is mad." << endl;
    }
    else{
        cout << "Your pet's mood is happy." << endl;
    }
    //decreasing every three stat after talking
    time(a);
}

/**
 * @brief output the current level of all three stats and limit the stats if they are less than 0 and greater than their max values
 */
void output(int a[], int size){
    using namespace std;
    if(a[0] <= MIN){
        cout << "Happiness: " << MIN << endl;
        cout << "Hunger: " << a[1] << endl;
        cout << "Cleanliness: " << a[2] << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[0] >= MAX){
        cout << "Happiness: " << MAX << endl;
        cout << "Hunger: " << a[1] << endl;
        cout << "Cleanliness: " << a[2] << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[1] <= MIN){
        cout << "Happiness: " << a[0] << endl;
        cout << "Hunger: " << MIN << endl;
        cout << "Cleanliness: " << a[2] << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[1] >= MAX){
        cout << "Happiness: " << a[0] << endl;
        cout << "Hunger: " << MAX << endl;
        cout << "Cleanliness: " << a[2] << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[2] >= MAX){
        cout << "Happiness: " << a[0] << endl;
        cout << "Hunger: " << a[1] << endl;
        cout << "Cleanliness: " << MAX << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[0] >= MAX && a[1] <= MIN && a[2] <= MIN){
        cout << "Happiness: " << MAX << endl;
        cout << "Hunger: " << MIN << endl;
        cout << "Cleanliness: " << MIN << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[0] <= MIN && a[1] >= MAX && a[2] <= MIN){
        cout << "Happiness: " << MIN << endl;
        cout << "Hunger: " << MAX << endl;
        cout << "Cleanliness: " << MIN << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[0] <= MIN && a[1] <= MIN && a[2] >= MAX){
        cout << "Happiness: " << MIN << endl;
        cout << "Hunger: " << MIN << endl;
        cout << "Cleanliness: " << MAX << endl;
        cout << "Age: " << a[3] << endl;
    }
    else if(a[3] >= AGEMAX){
        cout << "Happiness: " << a[0] << endl;
        cout << "Hunger: " << a[1] << endl;
        cout << "Cleanliness: " << a[2] << endl;
        cout << "Age: " << AGEMAX << endl;
    }
    else{
        cout << "Happiness: " << a[0] << endl;
        cout << "Hunger: " << a[1] << endl;
        cout << "Cleanliness: " << a[2] << endl;
        cout << "Age: " << a[3] << endl;
    }
}

