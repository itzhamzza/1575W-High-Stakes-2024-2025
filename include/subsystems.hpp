#pragma once

#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');
inline pros::Motor ladyBrown(1, pros::v5::MotorGears::green);


// inline pros::MotorGroup driveTrainRight({4,6, 12}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
// inline pros::MotorGroup driveTrainLeft({-13,-15, -16}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);

inline pros::MotorGroup intake({7,9}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
inline pros::Distance distance_sens(19);

inline pros::Rotation rotation_sens(18);

inline pros::Optical color_sens(14);

inline pros::adi::DigitalOut clamper('B', 0);

inline pros::adi::DigitalOut goalClamp('C', 0);

inline pros::adi::DigitalOut armPiston('A', 0);

inline pros::adi::DigitalOut doink('D', 0);