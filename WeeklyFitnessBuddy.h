#include <string>
#ifndef _WEEKLYFITNESSBUDDY_H_
#define _WEEKLYFITNESSBUDDY_H_

class WeeklyFitnessBuddy
{
private:
  std::string userName;
  double userHeight;
  double userWeight;
  double userGoalWeight;
  char loseOrGain;
public:
  WeeklyFitnessBuddy();
  void setUserName(std::string &);
  std::string printName();
  void setStats(double, double, double);
  double calculateBMI();
  void determineGoal(int, int);
  void giveRecommendation();
};

#endif
