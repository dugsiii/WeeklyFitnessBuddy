#include <string>
#include <iostream>
#include "WeeklyFitnessBuddy.h"

WeeklyFitnessBuddy::WeeklyFitnessBuddy()
{
  userName = " ";
  userHeight = 0;
  userWeight = 0;
  userGoalWeight = 0;
  loseOrGain = ' ';
}

void WeeklyFitnessBuddy::setUserName(std::string &name)
{
  userName = name;
}

std::string WeeklyFitnessBuddy::printName()
{
  std::string inputedName;
  inputedName = userName;
  return inputedName;
}

void WeeklyFitnessBuddy::setStats(double height, double weight, double goalWeight)
{
  userHeight = height;
  userWeight = weight;
  userGoalWeight = goalWeight;
}

double WeeklyFitnessBuddy::calculateBMI()
{
  double BMI;
  double BMIheightFactor;
  BMIheightFactor = userHeight * userHeight;
  BMI = userWeight/BMIheightFactor;
  BMI *= 703;
  return BMI;
}

void WeeklyFitnessBuddy::determineGoal(int weight, int goalWeight)
{
  char goal = ' ';
  if(goalWeight < weight)
  {
    goal = 'L';
  }
  else if(goalWeight > weight)
  {
    goal = 'G';
  }
  else
  {
    goal = 'M';
  }
  loseOrGain =  goal;
}

void WeeklyFitnessBuddy::giveRecommendation()
{
  if(loseOrGain == 'L')
  {
    if(userWeight > userGoalWeight)
    {
      std::cout<<"You did not achieve your goal this week. In order to lose a healthy amount of weight, I recommend eating at an average caloric deficit of -250 to -500 cals"<<std::endl;
    }
    else if(userWeight < userGoalWeight)
    {
      std::cout<<"Congratulations, you over achived this week! You may be losing weight too fast so I recommend evaluating how you feel before you continue your eating pattern"<<std::endl;
    }
    else
    {
      std::cout<<"Congratulations, you achieved your weight loss goal for the week!"<<std::endl;
    }
  }
  else if(loseOrGain == 'G')
  {
    if(userWeight < userGoalWeight)
    {
      std::cout<<"You did not achieve your goal this week. In order to gain a healthy amount of weight, I recommend eating an average caloric surplus of +250 to +500 cals"<<std::endl;
    }
    else if(userWeight > userGoalWeight)
    {
      std::cout<<"Congratulations, you over achived this week! You may be gaining weight too fast so I recommend evaluating how much you want to gain before you continue your eating pattern"<<std::endl;
    }
    else
    {
      std::cout<<"Congratulations, you achieved your weight gain goal for the week!"<<std::endl;
    }
  }
  else if(loseOrGain == 'M')
  {
    if(userWeight == userGoalWeight)
    {
      std::cout<<"Congrulations! You maintained your weight this week!"<<std::endl;
    }
    else
    {
      std::cout<<"You did not achieve your goal this week. In oder to maintain weight your intake should not be above or below your expenditure by 100 cals"<<std::endl;
    }
  }
}
