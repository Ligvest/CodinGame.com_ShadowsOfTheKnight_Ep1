#include <iostream>
#include <string>

struct Vector2D {
    int X;
    int Y;
};

class NextWindowFinder {
private:
    int UpBorder;
    int DownBorder;
    int LeftBorder;
    int RightBorder;

public:
    NextWindowFinder(size_t BuildingWidth, size_t BuildingHeight) {
        // The range of valid coordinates is [0, BuildingSize - 1]
        this->UpBorder = 0;
        this->DownBorder = BuildingHeight - 1;


        this->LeftBorder = 0;
        this->RightBorder = BuildingWidth - 1;
    }

public:
    Vector2D GetNextWindowLocation(Vector2D& CharacterLocation, const std::string& DirectionFromCharacterToBomb) {
        /*
        PossibleValues:
            U (Up)
            UR (Up-Right)
            R (Right)
            DR (Down-Right)
            D (Down)
            DL (Down-Left)
            L (Left)
            UL (Up-Left)
        */

        Vector2D Middle;
        Middle = CharacterLocation;

        int DistanceToBorder;
        for (char DirectionSymbol : DirectionFromCharacterToBomb) {
            if (DirectionSymbol == 'U') {
                Middle.Y = (UpBorder + CharacterLocation.Y) / 2;
                DownBorder = CharacterLocation.Y;
            }
            if (DirectionSymbol == 'D') {
                Middle.Y = (DownBorder + CharacterLocation.Y) / 2;
                Middle.Y += (DownBorder + CharacterLocation.Y) % 2;
                UpBorder = CharacterLocation.Y;
            }
            if (DirectionSymbol == 'L') {
                Middle.X = (LeftBorder + CharacterLocation.X) / 2;
                RightBorder = CharacterLocation.X;
            }
            if (DirectionSymbol == 'R') {
                Middle.X = (RightBorder + CharacterLocation.X) / 2;
                Middle.X += (RightBorder + CharacterLocation.X) % 2;
                LeftBorder = CharacterLocation.X;
            }
        }

        CharacterLocation = Middle;
        return CharacterLocation;
    }
};


int main()
{
    // Get building sizes
    int BuildingWidth;
    int BuildingHeight;
    std::cin >> BuildingWidth >> BuildingHeight;
    std::cin.ignore();

    // Get amount of possible turns
    int RemainingTurns;
    std::cin >> RemainingTurns;
    std::cin.ignore();

    // Get initial character location
    Vector2D CharacterLocation;
    std::cin >> CharacterLocation.X >> CharacterLocation.Y;
    std::cin.ignore();

    // Game loop
    NextWindowFinder WindowFinder(BuildingWidth, BuildingHeight);
    while (1) {
        // Get direction from character to bomb window (U, UR, R, DR, D, DL, L or UL)
        std::string DirectionFromCharacterToBomb;
        std::cin >> DirectionFromCharacterToBomb;
        std::cin.ignore();

        // The location of the next window to jump on
        Vector2D NextWindowLocation = WindowFinder.GetNextWindowLocation(CharacterLocation, DirectionFromCharacterToBomb);
        std::string NextWindowLocationAsString= std::to_string(NextWindowLocation.X) + " " + std::to_string(NextWindowLocation.Y);
        std::cout << NextWindowLocationAsString << "\n";
    }

    return 0;
}
