#ifndef _WATAN_H_
#define _WATAN_H_
#include "board.h"
#include "state.h"
#include "student.h"
#include "subject.h"
#include "textdisplay.h"
#include <map>
#include <string>
#include <vector>

class Watan final : public Subject<WatanState> {
  TextDisplay *td = nullptr;
  PlayerInput *in = nullptr;
  int firstTurn;
  std::vector<Colour> turnOrder;
  std::map<Colour, Student *> students;
  unsigned int gameSeed;
  Board *board = nullptr;
  bool loaded;

  void loadResources(std::map<Resource, int> &rmap, std::stringstream &data);
  void loadGoals(Colour student, std::vector<Goal *> goals,
                 std::stringstream &data);
  void loadCriteria(Colour student, std::vector<Criterion *> criteria,
                    std::stringstream &data);
  std::string randomBoardString() const;
  Colour whoWon() const;

public:
  Watan(unsigned int seed = 1);
  Watan(const std::string &loadFilename, unsigned int seed = 1);
  ~Watan();
  void init(const std::vector<std::string> &initialConditions);
  bool start();
  void loseToGeese() const;
  void steal(Colour robber, Colour target) const;
  void distributeResources(int rolledNum) const;
  void giveTo(Colour student, const std::map<Resource, int> &amount) const;
  void takeFrom(Colour student, const std::map<Resource, int> &amount) const;
  std::vector<Colour> attemptPlaceGeese(Colour attacker, int tileIndex) const;
  bool attemptAchieve(Colour owner, int goalIndex) const;
  bool attemptImprove(Colour owner, int criterionIndex, bool initial) const;
  CriterionTier getCriterionTier(int criterionIndex) const;
  void save(const std::string &saveFilename, const bool rolled,
            const Colour curStudent) const;
  void save(const std::string &&saveFilename, const bool rolled,
            const Colour curStudent) const;
};
#endif
