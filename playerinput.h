#ifndef _PLAYER_INPUT_H_
#define _PLAYER_INPUT_H_

#include <string>
#include <vector>

enum class Command { DiceLoad, DiceFair, Roll, Board, Status, Criteria, Achieve, Complete, Improve, Trade, Next, Save, Help, Quit };
enum class Response { Yes, No };
enum class Colour;

struct TradeInfo;

class PlayerInput {
public:
    ~PlayerInput() = default;

    Command getCommand();
    int getLoadedDice(const int min, const int max);
    int getCriterionPlacement(const int min, const int max);
    int getGoalPlacement(const int min, const int max);
    int getTile(const int min, const int max);
    TradeInfo getTrade();
    Response getResponse();
    std::string getSaveFile();
    Colour getStealChoice(const std::vector<Colour>& choices);
};

#endif
