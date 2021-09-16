#include <iostream>
#include <ctime>

void PrintSpaceship()
{
    std::cout << "\n___________________          _-_\n";
    std::cout << "\\==============_=_/ ____.---'---`---.____\n";
    std::cout << "            \\_ \\    \\----._________.----/\n";
    std::cout << "              \\ \\   /  /    `-_-'\n";
    std::cout << "          __,--`.`-'..'-_\n";
    std::cout << "         /____          ||\n";
    std::cout << "              `--.____,-'\n\n";
}

void PrintAward()
{
    std::cout << "\n _______________\n";
    std::cout << "|@@@@|     |####|\n";
    std::cout << "|@@@@|     |####|\n";
    std::cout << "|@@@@|     |####|\n";
    std::cout << "\\@@@@|     |####/\n";
    std::cout << " \\@@@|     |###/\n";
    std::cout << "  `@@|_____|##'\n";
    std::cout << "       (O)\n";
    std::cout << "    .-'''''-.\n";
    std::cout << "  .'  * * *  `.\n";
    std::cout << " :  *       *  :\n";
    std::cout << ": ~ C R I M E ~ :\n";
    std::cout << ": ~  L O R D ~  :\n";
    std::cout << " :  *       *  :\n";
    std::cout << "  `.  * * *  .'\n";
    std::cout << "    `-.....-'\n\n";    
}

void PrintIntroduction()
{
    PrintSpaceship();

    // Print welcome messages to the terminal
    std::cout << "You are a disgruntled starfleet employee. Overlooked for promotion yet again, you break into the dilithium store...\n";
    std::cout << "Dreams of a latinum fueled vacation to Risa drive you on...\n";
}

void PrintSeparator()
{
    std::cout << "\n************************************************************\n";
}

bool PlayGame(int LevelDifficulty)
{
    PrintSeparator();
    std::cout << "\nThere are multiple layers of security. Enter the correct codes to pass through security gate: " << LevelDifficulty << std::endl;

    // Declare 3 digit code
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "\n+ There are 3 numbers in the code.";
    std::cout << "\n+ The numbers add up to: " << CodeSum;
    std::cout << "\n+ The numbers multiply to give: " << CodeProduct << "\n\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        PrintSeparator();
        std::cout << "\n*** SUCCESS! You entered the correct code! ***\n";

        return true;
    }
    else
    {
        PrintSeparator();
        std::cout << "\n*** ERROR! You have entered the wrong code. Try again. ***\n";

        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create new random sequence based on the time of the day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    PrintIntroduction();

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }   
    }

    PrintSeparator();
    PrintAward();
    std::cout << "CONGRATULATIONS! The dilithium is yours!\n";
    std::cout << "Make your way to the transporter room. Harry Mudd has offered transport to Risa... for a small fee.\n";

    return 0;
}