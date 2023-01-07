# Term_Project_Virtual_Pet_Deliverable
###### Kyi Lei Aye
###### 12/14/2022

### Overview
This is a program that allows the player to take care of a virtual pet. The player can talk, feed, play, or clean their virtual pet. The pet's three basic stats, hunger, happiness, and cleanliness, will be shown to remind the player which one they need to do.
The player is completely responsible for keeping the pet happy and healthy. They can feed and play with the pet to keep it in a good mood.  If the player fails to feed or entertain your pet, it will have a mood change for the worse (and run away or die!)

### Problem Solving Phase
1. Take user input
2. Allow the user choose what game to play with the pet and increase its happiness level according to the game type
3. Let the user choose what to feed and increase specific hunger stat according to the food
4. Let the user choose the way to clean the pet and increase the cleanliness level according to the way it is cleaned
5. Display the mood of the pet when they talk to the pet

### Implementation Phase
1. Create input() function to take the option of what the user want to do with the pet
2. Create randomPoints() function to return random number for starting points of the stats
3. Create time() function to decrease by 1 to 3 points and call it after every action of playing, feeding, cleaning, and talking
4. Create play() function to let the user choose the game type and points for the happiness level
5. Create happinessPoints() function to display the current situation and mood of the pet according to the range
6. Create feed() function to let the user choose the food and points for the hunger level
7. Create hungerPoints() function to display the current situation and mood of the pet according to the range
8. Create clean() function to let the user choose the way it can be cleaned and points for the cleanliness level
9. Create cleanliness() function to display the current situation and mood of the pet according to the range
10. Create mood() function to return the sum of the three stats
11. Create output() function to show current stats and mood of the pet 
12. Declare stat[] array in the input() function and assign the random values by calling randomPoints() functions outside of Do-While loop to keep the values change on the previous values until the program terminates.
13. Call input() function in the main() function to have the program compiled

### References
1. "**Problem Solving with C++**" by Walter Savitch, Chapter 2, 3, 4, 5, 7

 
