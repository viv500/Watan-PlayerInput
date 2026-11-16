#ifndef _LOADED_DICE_H_
#define _LOADED_DICE_H_
#include "dice.h"

class PlayerInput;
class TextDisplay;

class LoadedDice final : public Dice {
  PlayerInput *in;
  TextDisplay *td;

  int getRollVal() override;
  public:
    LoadedDice(PlayerInput *in, TextDisplay *td);
};
#endif
