#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Vector2D {
	float X;
	float Y;
};

int main()
{
    int BuildingWidth;
    int BuildingHeight;
    std::cin >> BuildingWidth >> BuildingHeight;
    std::cin.ignore();

    int RemainingTurns; // Maximum number of turns before game over.
    std::cin >> RemainingTurns;
    std::cin.ignore();

    Vector2D CharacterLocation;
    std::cin >> CharacterLocation.X >> CharacterLocation.Y;
    std::cin.ignore();

    // game loop
    while (1) {
        std::string DirectionFromCharacterToBomb; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        std::cin >> DirectionFromCharacterToBomb;
        std::cin.ignore();

        // The location of the window Batman will jump to
        Vector2D NextWindowLocation;
        std::string WindowToJumpTo = std::to_string(NextWindowLocation.X) + " " + std::to_string(NextWindowLocation.Y);
        std::cout << WindowToJumpTo << "\n";
    }
}