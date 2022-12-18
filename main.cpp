#include <iostream>
#include <string>

struct Vector2D {
	int X;
	int Y;
};

class NextWindowFinder {
private:
    int BuildingWidth;
    int BuildingHeight;
    int UpBorder;
    int DownBorder;
    int LeftBorder;
    int RightBorder;

public:
    NextWindowFinder(size_t NewBuildingWidth, size_t NewBuildingHeight) {
        this->BuildingWidth = NewBuildingWidth;
        this->BuildingHeight = NewBuildingHeight;
        this->UpBorder = 0;
        this->DownBorder = BuildingHeight;
        this->LeftBorder = 0;
        this->RightBorder = BuildingWidth;
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
        for (char DirectionSymbol : DirectionFromCharacterToBomb) {
            if (DirectionSymbol == 'U') {
                Middle.Y = (UpBorder - CharacterLocation.Y) / 2;
                Middle.Y += CharacterLocation.Y - 1;
                DownBorder = CharacterLocation.Y < BuildingHeight ? CharacterLocation.Y + 1 : CharacterLocation.Y;
            }
            if (DirectionSymbol == 'D') {
                Middle.Y = (DownBorder - CharacterLocation.Y) / 2;
                Middle.Y += CharacterLocation.Y + 1;
                UpBorder = CharacterLocation.Y > 0 ? CharacterLocation.Y - 1 : CharacterLocation.Y;
            }
            if (DirectionSymbol == 'L') {
                Middle.X = (LeftBorder - CharacterLocation.X) / 2;
                Middle.X += CharacterLocation.X - 1;
                RightBorder = CharacterLocation.Y < BuildingWidth ? CharacterLocation.X + 1 : CharacterLocation.X;
            }
            if (DirectionSymbol == 'R') {
                Middle.X = (RightBorder - CharacterLocation.X) / 2;
                Middle.X += CharacterLocation.X + 1;
                LeftBorder = CharacterLocation.X > 0 ? CharacterLocation.X - 1 : CharacterLocation.X;
            }
        }

        CharacterLocation = Middle;
        return CharacterLocation;
    }
};


int main()
{
    int BuildingWidth;
    int BuildingHeight;
    std::cin >> BuildingWidth >> BuildingHeight;
    std::cin.ignore();
    NextWindowFinder WindowFinder(BuildingWidth, BuildingHeight);

    int RemainingTurns; // Maximum number of turns before game over.
    std::cin >> RemainingTurns;
    std::cin.ignore();

    Vector2D CharacterLocation;
    std::cin >> CharacterLocation.X >> CharacterLocation.Y;
    std::cin.ignore();

    // game loop
    while (1) {
        // The direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        std::string DirectionFromCharacterToBomb;
        std::cin >> DirectionFromCharacterToBomb;
        std::cin.ignore();

        // The location of the window Batman will jump to
        Vector2D NextWindowLocation = WindowFinder.GetNextWindowLocation(CharacterLocation, DirectionFromCharacterToBomb);
        std::string WindowToJumpTo = std::to_string(NextWindowLocation.X) + " " + std::to_string(NextWindowLocation.Y);
        std::cout << WindowToJumpTo << "\n";
    }

    return 0;
}
