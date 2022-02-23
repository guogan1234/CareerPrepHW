#include <iostream>

#define ROW 8
#define COL 8

using namespace std;

char** chess = nullptr;

struct Position
{
    int x;
    int y;
};

void initChess(char** ces)
{
    ces = new char*[ROW];
    chess = ces;
    printf("chess address: %p\n", ces);
    for(int i = 0; i < ROW; i++){
        ces[i] = new char[COL];
    }
    printf("chess[0] is: %p\n", ces[0]);
    for(int i = 0; i < ROW; i++){
        if(i == 0){
            ces[i][0] = 'R'; ces[i][1] = 'H'; ces[i][2] = 'B'; ces[i][3] = 'K';
            ces[i][4] = 'Q'; ces[i][5] = 'B'; ces[i][6] = 'H'; ces[i][7] = 'R';
            continue;
        }
        else if (i == 1 || i == 6) {
//            for(int j = 0; j < COL; j++){
//                if(i == 1) ces[i][j] = 'P';
//                if(i == 6) ces[i][j] = 'p';
//            }
//            continue;
        }
        else if (i == 7) {
            ces[i][0] = 'r'; ces[i][1] = 'h'; ces[i][2] = 'b'; ces[i][3] = 'k';
            ces[i][4] = 'q'; ces[i][5] = 'b'; ces[i][6] = 'h'; ces[i][7] = 'r';
            continue;
        }
        for(int j = 0; j < COL; j++){
            ces[i][j] = '0';
        }
    }
}

void printChess()
{
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%c", chess[i][j]);
            printf(",");
        }
        printf("\n");
    }
}

bool isPositionValid(const Position* pos)
{
    if(pos == nullptr) return false;
    if(pos->x >= 0 && pos->x < ROW && pos->y >= 0 && pos->y < COL) return true;
    return false;
}

bool isStartVaild(char** ces, const Position* start)
{
    if(start == nullptr) return false;
    if(!isPositionValid(start)) return false;
    if(ces[start->x][start->y] != '0')  return true;
    return false;
}

bool isRookMoveValid(char** ces, const Position* start, const Position* end, bool uppercase)
{
    if(ces == nullptr || start == nullptr || end == nullptr) return false;
    // end valid
    char endPiece = ces[end->x][end->y];
    if(uppercase){
        if(endPiece == 'R' || endPiece == 'H' || endPiece == 'B' || endPiece == 'K' || endPiece == 'Q' || endPiece == 'P'){
            return false;
        }
    } else {
        if(endPiece == 'r' || endPiece == 'h' || endPiece == 'b' || endPiece == 'k' || endPiece == 'q' || endPiece == 'p'){
            return false;
        }
    }
    // check path valid when row is equal
    if(start->x == end->x){
        int sy = start->y;
        int ey = end->y;
        bool flag = true;
        if(sy < ey){
            // path valid
            for(int i = sy + 1; i < ey; i++){
                if(ces[start->x][i] != '0'){
                    flag = false;
                }
            }
        }
        else if (sy == ey) {
            return false;
        }
        else {
            for(int i = ey + 1; i < sy; i++){
                if(ces[start->x][i] != '0') flag = false;
            }
        }
        return flag;
    }
    // check path valid when column is equal
    if(start->y == end->y){
        int sx = start->x; int ex = end->x;
        bool flag = true;
        if(sx == ex) return false;
        if(sx < ex){
            for(int i = sx + 1; i < ex; i++){
                if(ces[i][start->y] != '0'){
                    flag = false;
                }
            }
        } else {
            for(int i = ex + 1; i < sx; i++){
                if(ces[i][start->y] != '0'){
                    flag = false;
                }
            }
        }
        return flag;
    }
    return false;
}

bool isHorseMoveValid(char** ces, const Position* start, const Position* end, bool uppercase)
{

}

bool isBishopMoveValid(char** ces, const Position* start, const Position* end, bool uppercase)
{

}

bool isKingMoveValid(char** ces, const Position* start, const Position* end, bool uppercase)
{

}

bool isQueenMoveValid(char** ces, const Position* start, const Position* end, bool uppercase)
{

}

bool isPawnMoveValid(char** ces, const Position* start, const Position* end, bool uppercase)
{

}

bool isValidMove(char** ces, const Position* start, const Position* end)
{
    if(start == nullptr || end == nullptr) return false;
    if(isPositionValid(start) && isPositionValid(end)){
        if(!isStartVaild(ces, start)) return false;
        char piece = ces[start->x][start->y];
        if(piece == 'R') return isRookMoveValid(ces, start, end, true);
        if(piece == 'r') return isRookMoveValid(ces, start, end, false);
        if(piece == 'H') return isHorseMoveValid(ces, start, end, true);
        if(piece == 'h') return isHorseMoveValid(ces, start, end, false);
        if(piece == 'B') return isBishopMoveValid(ces, start, end, true);
        if(piece == 'b') return isBishopMoveValid(ces, start, end, false);
        if(piece == 'K') return isKingMoveValid(ces, start, end, true);
        if(piece == 'k') return isKingMoveValid(ces, start, end, false);
        if(piece == 'Q') return isQueenMoveValid(ces, start, end, true);
        if(piece == 'q') return isQueenMoveValid(ces, start, end, false);
        if(piece == 'P') return isPawnMoveValid(ces, start, end, true);
        if(piece == 'p') return isPawnMoveValid(ces, start, end, false);
    }
    return false;
}

int main()
{
    cout << "Hello World!" << endl;
    initChess(chess);
    printChess();

    //test
    Position start = {0, 0};
    Position end = {7, 0};
    cout << isValidMove(chess, &start, &end) << std::endl;
    return 0;
}
