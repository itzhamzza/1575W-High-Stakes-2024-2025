#include "pros/rtos.hpp"
void goalClamper();
//void allianceStake();
void colorSort();
void intaking();
void ladybrownMovement();
void clamping();
void doinker();
void intakeExtender();
void intakeButton();
void autoClamper();
void autoFlipping();
void autoClamperAuton();
inline pros::Task colorSortTask(colorSort);
inline pros::Task autoClampTask(autoClamper);
//inline pros::Task autoClampTaskAuton(autoClamperAuton);
inline pros::Task autonFlip(autoFlipping);