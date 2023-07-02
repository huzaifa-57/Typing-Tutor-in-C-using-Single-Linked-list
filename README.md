# Typing-Tutor-in-C++-using-Single-Linked-list

This is a typing game implemented in C++. Here's a breakdown of what's happening in the code:
* The code includes necessary header files for input/output, string manipulation, time, and Windows-specific functions.
* Global variables are declared to store various game-related information such as score, counters, user choices, delay time, etc.
* A structure called node is defined to create a linked list for storing characters and their positions.
* Function prototypes are declared for functions used in the code.
* Several functions are defined to handle different aspects of the game:
  - `gotoxy()`: Moves the cursor to the specified position on the console.
  - `InsertNode()`: Inserts a new node with character data and position into the linked list.
  - `deleteNode()`: Deletes a node with the specified character data from the linked list.
  - `searchInLinkList()`: Searches for a character data in the linked list.
  - `randX()`: Generates a random x-coordinate for character position.
  - `capitalAlphabet()`: Generates a random capital alphabet character and inserts it into the linked list.
  - `digits()`: Generates a random digit character and inserts it into the linked list.
  - `startingScreen()`: Displays the starting screen and allows the user to choose between starting the game, getting help, or exiting.
  - `levelSelection()`: Prompts the user to select the game level (alphabet or digits) and speed level (1 or 2) and calls keyPressed function.
  - `helpScreen()`: Displays the help screen with game instructions and controls.
  - `printChar()`: Prints the characters from the linked list on the console and handles missed characters.
  - `scorescreen()`: Displays the game score, time left, missed characters, etc. on the console.
  - `keyPressed()`: Handles the main gameplay logic by listening for user key presses, updating the score, deleting characters from the linked list, and checking for game over conditions.
  - `gameLost()`: Displays the game summary when the player loses.
  - `winningScreen()`: Displays the game summary when the player wins.
* The main function initializes the random number generator, clears the console, and starts the game by calling the startingScreen function.

Overall, the code implements a simple typing game where the player needs to type the displayed characters correctly to score points. The game ends when the player reaches the maximum allowed missed characters or presses the Escape key.
