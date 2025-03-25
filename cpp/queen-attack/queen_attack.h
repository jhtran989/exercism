#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <utility>
#include <stdexcept>

namespace queen_attack {

// TODO: add your solution here
class chess_board {
private:
    std::pair<int, int> white_pos;
    std::pair<int, int> black_pos;

    static bool check_not_valid_position(std::pair<int, int> pos) {
        return pos.first < 0 || pos.second < 0 || pos.first > 7 || pos.second > 7;
    }

    static bool check_same_position(std::pair<int, int> white_pos, std::pair<int, int> black_pos) {
        return white_pos == black_pos;
    }

    bool same_row() const {
        return white_pos.first == black_pos.first;
    }

    bool same_column() const {
        return white_pos.second == black_pos.second;
    }

    bool same_diagonal() const {
        int delta = black_pos.first - white_pos.first;

        // first check positive diagonal or negative diagonal (could have used abs...)
        return delta == (black_pos.second - white_pos.second) || delta == -(black_pos.second - white_pos.second);
    }

public:
    chess_board(std::pair<int, int> white_pos, std::pair<int, int> black_pos) 
    : white_pos(white_pos), black_pos(black_pos) {
        if (check_not_valid_position(white_pos) 
        || check_not_valid_position(black_pos)
        || check_same_position(white_pos, black_pos))
        {
            throw std::domain_error("");
        }        
    }

    std::pair<int, int> black() const {
        return black_pos;
    }

    std::pair<int, int> white() const {
        return white_pos;
    }

    bool can_attack() const {
        return same_row() || same_column() || same_diagonal();
    }
};

}  // namespace queen_attack

#endif  // QUEEN_ATTACK_H