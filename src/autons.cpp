#include "autons.hpp"
#include "main.h"
//This is the messed up autos but complete skills run code
/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 127;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///

void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);

  chassis.pid_drive_constants_set(16, 1, 100); // 20 1 100
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);

  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

void goalRushRedCornerClear(){
  autoClampTask.suspend();
  //red = true;
  doink.set_value(true);
  armPiston.set_value(false);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(33.2_in, DRIVE_SPEED);
  //chassis.pid_wait_until(32_in);
  pros::delay(800);
  intake.move_velocity(0);
  chassis.pid_wait_quick_chain();
  goalClamp.set_value(true);
  pros::delay(200);
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  //goal in our possesion && ring in intake
  goalClamp.set_value(false);
  doink.set_value(false);
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(160_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, 70);
  chassis.pid_wait();
  clamper.set_value(true);
  //goal clamped
  chassis.drive_imu_reset();
  chassis.pid_turn_set(135_deg, TURN_SPEED);
  intake.move_velocity(-1200);
  chassis.pid_wait();
  //Ring on 1st goal
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  //goal dropped
  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(135_deg, TURN_SPEED);
 
  chassis.pid_wait();
 chassis.pid_drive_set(-26_in, 70);
  chassis.pid_wait();
  pros::delay(100);
  clamper.set_value(true);
  //2nd goal clamped
  chassis.drive_imu_reset();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(800);
  //2nd ring on 2nd goal
  
 chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(-50_deg, TURN_SPEED);
  chassis.pid_wait();
  doink.set_value(true);
  chassis.pid_drive_set(40_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(60_deg, TURN_SPEED);
  chassis.pid_wait();
  doink.set_value(false);
  chassis.drive_imu_reset();
  chassis.pid_turn_set(-75_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  autoClampTask.resume();
}
void goalRushBlueCornerClear(){
  autoClampTask.suspend();
  //reduced by 4
  doink.set_value(true);
  armPiston.set_value(false);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(34.2_in, DRIVE_SPEED); 
  chassis.pid_wait_until(32_in);
  
  intake.move_velocity(0);
  chassis.pid_wait_quick_chain();
  goalClamp.set_value(true);
  pros::delay(100);
  //pros::delay(200);
  chassis.pid_drive_set(-11_in, DRIVE_SPEED);
  chassis.pid_wait();
  //goal in our possesion && ring in intake
  goalClamp.set_value(false);
  doink.set_value(false);
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(160_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 70);
  chassis.pid_wait();
  clamper.set_value(true);
  //goal clamped
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(145_deg, TURN_SPEED);
  intake.move_velocity(-1200);
  chassis.pid_wait();
  //Ring on 1st goal
  chassis.pid_drive_set(-21_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  //goal dropped
  chassis.pid_drive_set(3_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-75_deg, TURN_SPEED);
  
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, 70);
  chassis.pid_wait();
  pros::delay(100);
  clamper.set_value(true);
  //2nd goal clamped
  chassis.pid_drive_set(35_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(800);
  //2nd ring on 2nd goal
  
 chassis.pid_drive_set(-15_in, DRIVE_SPEED);
 chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-27_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  doink.set_value(true);
  chassis.pid_drive_set(19_in, 120);
  chassis.pid_wait_quick_chain();
  //in front of 4 rings in corner
  chassis.pid_drive_set(9_in, 70);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(150_deg, TURN_SPEED);
  chassis.pid_wait();
  doink.set_value(false);
  //corner cleared
  chassis.pid_drive_set(25_in, DRIVE_SPEED);
  chassis.pid_wait();
  autoClampTask.resume();


  
}
void goalRushRed(){
  autoClampTask.suspend();
  //red = true;
  doink.set_value(true);
  armPiston.set_value(false);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(33.2_in, DRIVE_SPEED);
  //chassis.pid_wait_until(32_in);
  pros::delay(800);
  intake.move_velocity(0);
  chassis.pid_wait_quick_chain();
  goalClamp.set_value(true);
  pros::delay(200);
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  //goal in our possesion && ring in intake
  goalClamp.set_value(false);
  doink.set_value(false);
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(160_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, 70);
  chassis.pid_wait();
  clamper.set_value(true);
  //goal clamped
  chassis.drive_imu_reset();
  chassis.pid_turn_set(135_deg, TURN_SPEED);
  intake.move_velocity(-1200);
  chassis.pid_wait();
  //Ring on 1st goal
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  //goal dropped
  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(135_deg, TURN_SPEED);
 
  chassis.pid_wait();
 chassis.pid_drive_set(-26_in, 70);
  chassis.pid_wait();
  pros::delay(100);
  clamper.set_value(true);
  //2nd goal clamped
  chassis.drive_imu_reset();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(800);
  //2nd ring on 2nd goal
 
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(160_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(28_in, DRIVE_SPEED);
  chassis.pid_wait();
  //touches ladder
  autoClampTask.resume();
}

void goalRushBlueWallStake(){
  autoClampTask.suspend();
  //red = false;
  doink.set_value(true);
  armPiston.set_value(false);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(32.2_in, DRIVE_SPEED);
  //chassis.pid_wait_until(32_in);
  pros::delay(700);
  intake.move_velocity(0);
  chassis.pid_wait_quick_chain();
  goalClamp.set_value(true);
  pros::delay(200);
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait();
  //goal in our possesion && ring in intake
  goalClamp.set_value(false);
  doink.set_value(false);
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(160_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, 70);
  chassis.pid_wait();
  clamper.set_value(true);
  //goal clamped
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(145_deg, TURN_SPEED);
  intake.move_velocity(-1200);
  chassis.pid_wait();
  //Ring on 1st goal
  chassis.pid_drive_set(-25_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  //goal dropped
  chassis.pid_drive_set(7_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-75_deg, TURN_SPEED);
  
  chassis.pid_wait();
  chassis.pid_drive_set(-18_in, 70);
  chassis.pid_wait();
  pros::delay(100);
  clamper.set_value(true);
  //2nd goal clamped
  chassis.pid_drive_set(35_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(600);
  //1nd ring on 2nd goal
  chassis.pid_drive_set(-32_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-110_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  intake.move_velocity(0);
  ladyBrown.move_absolute(-455, 200);
  armPiston.set_value(true);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(25_in, DRIVE_SPEED);
  chassis.pid_wait();
  armPiston.set_value(false);
  pros::delay(100);
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  //ring in ladybrown
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(152_deg, TURN_SPEED); //159.5
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(40_in, DRIVE_SPEED);
  pros::delay(300);
  intake.move_velocity(-1200);
  pros::delay(100);
  
  armPiston.set_value(true);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset(); 
  
  chassis.pid_turn_set(-5_deg, TURN_SPEED); //159.5
  chassis.pid_wait_quick_chain();
  ladyBrown.move_absolute(-2000, 200);
  
  autoClampTask.resume();
  
}
void goalRushBlue(){
  autoClampTask.suspend();
 //reduced by 4
  doink.set_value(true);
  armPiston.set_value(false);
  intake.move_velocity(-1200);
  chassis.pid_drive_set(34.2_in, DRIVE_SPEED); 
  //chassis.pid_wait_until(32_in);
  pros::delay(1000);
  intake.move_velocity(0);
  chassis.pid_wait_quick_chain();
  goalClamp.set_value(true);
  pros::delay(200);
  chassis.pid_drive_set(-11_in, DRIVE_SPEED);
  chassis.pid_wait();
  //goal in our possesion && ring in intake
  goalClamp.set_value(false);
  doink.set_value(false);
  chassis.pid_drive_set(-3_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(160_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-10_in, 70);
  chassis.pid_wait();
  clamper.set_value(true);
  //goal clamped
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(145_deg, TURN_SPEED);
  intake.move_velocity(-1200);
  chassis.pid_wait();
  //Ring on 1st goal
  chassis.pid_drive_set(-21_in, DRIVE_SPEED);
  chassis.pid_wait();
  clamper.set_value(false);
  //goal dropped
  chassis.pid_drive_set(3_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-75_deg, TURN_SPEED);
  
  chassis.pid_wait();
  chassis.pid_drive_set(-14_in, 70);
  chassis.pid_wait();
  pros::delay(100);
  clamper.set_value(true);
  //2nd goal clamped
  chassis.pid_drive_set(35_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(800);
  //2nd ring on 2nd goal
  
  chassis.pid_drive_set(-6_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-190_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(37_in, DRIVE_SPEED);
  chassis.pid_wait();
  
  //touches ladder
  autoClampTask.resume();
}

void blueAlliance1Ring(){
  autoClampTask.suspend();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-2_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_turn_set(90_deg,TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(5_in, DRIVE_SPEED);
chassis.pid_wait();
ladyBrown.move_absolute(-1200,200);
pros::delay(500);
chassis.pid_drive_set(-5_in, DRIVE_SPEED);
chassis.pid_wait();
//Ring on alliance stake
chassis.drive_imu_reset(); 
chassis.pid_turn_set(-34_deg, TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-20_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-25_in, 50);
chassis.pid_wait_quick();
clamper.set_value(true);
armPiston.set_value(false);
ladyBrown.move_absolute(5,200);

//goal is grabbed
chassis.drive_imu_reset(); 
chassis.pid_turn_set(120_deg, TURN_SPEED);
chassis.pid_wait_quick();
intake.move_velocity(-1200);
chassis.pid_drive_set(22_in, DRIVE_SPEED);
chassis.pid_wait();
pros::delay(1000);
//1st Ring on Goal


chassis.pid_drive_set(-25_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.drive_imu_reset(); 
chassis.pid_turn_set(180_deg, TURN_SPEED);
chassis.pid_wait_quick();
chassis.pid_drive_set(15_in, 70);
chassis.pid_wait();
autoClampTask.resume();
}
void redAlliance1Ring(){
  autoClampTask.suspend();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-2_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_turn_set(-90_deg,TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(5_in, DRIVE_SPEED);
chassis.pid_wait();
ladyBrown.move_absolute(-1200,200);
pros::delay(500);
chassis.pid_drive_set(-5_in, DRIVE_SPEED);
chassis.pid_wait();
//Ring on alliance stake
chassis.drive_imu_reset(); 
chassis.pid_turn_set(34_deg, TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-20_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(-25_in, 50);
chassis.pid_wait_quick();
clamper.set_value(true);
armPiston.set_value(false);
ladyBrown.move_absolute(5,200);

//goal is grabbed
chassis.drive_imu_reset(); 
chassis.pid_turn_set(-120_deg, TURN_SPEED);
chassis.pid_wait_quick();
intake.move_velocity(-1200);
chassis.pid_drive_set(22_in, DRIVE_SPEED);
chassis.pid_wait();
pros::delay(1000);
//1st Ring on Goal


chassis.pid_drive_set(-25_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.drive_imu_reset(); 
chassis.pid_turn_set(180_deg, TURN_SPEED);
chassis.pid_wait_quick();
chassis.pid_drive_set(15_in, 70);
chassis.pid_wait();
autoClampTask.resume();
}
void blueAlliance3Ring(){
  autoClampTask.suspend();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-2_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg,TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(5_in, DRIVE_SPEED);
  chassis.pid_wait();
  ladyBrown.move_absolute(-1000,200);
  pros::delay(500);
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait();
  //Ring on alliance stake
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(34_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, 50);
  chassis.pid_wait_quick();
  clamper.set_value(true);
  armPiston.set_value(false);
  ladyBrown.move_absolute(5,200);

  //goal is grabbed
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-120_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(22_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  //1st Ring on Goal
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-120_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  pros::delay(500);
  //2nd Ring on goal
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(65_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(8_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  //3rd Ring on goal
  chassis.pid_drive_set(-6_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-120_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(25_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  autoClampTask.resume();
}
void redAlliance3Ring(){
  autoClampTask.suspend();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-2_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg,TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(5_in, DRIVE_SPEED);
  chassis.pid_wait();
  ladyBrown.move_absolute(-1000,200);
  pros::delay(500);
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait();
  //Ring on alliance stake
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-34_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-25_in, 50);
  chassis.pid_wait_quick();
  clamper.set_value(true);
  armPiston.set_value(false);
  ladyBrown.move_absolute(5,200);

  //goal is grabbed
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(120_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(22_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  //1st Ring on Goal
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(110_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(13_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  pros::delay(500);
  //2nd Ring on goal
  chassis.pid_drive_set(-10_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-56_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(10_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  //3rd Ring on goal
  chassis.pid_drive_set(-6_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(120_deg, TURN_SPEED);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(25_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  autoClampTask.resume();
}
void BlueNegHalfAWP(){
  autoClampTask.suspend();
  chassis.pid_drive_set(8_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-90_deg,TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(5_in, DRIVE_SPEED);
  chassis.pid_wait();
  ladyBrown.move_absolute(-350,200);
  pros::delay(500);
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait();
  //Ring on alliance stake
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(34_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, 50);
  chassis.pid_wait();
  clamper.set_value(true);
  armPiston.set_value(false);
  ladyBrown.move_absolute(5,200);

  //goal is grabbed
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-115_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(22_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  //1st Ring on Goal
  chassis.pid_turn_set(-100_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(15.5_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(100);
  //2nd Ring on goal
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-100_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(30_in, DRIVE_SPEED);
  chassis.pid_wait();
  autoClampTask.resume();
}
void RedSoloAWPSig(){
  
  ladyBrown.move_absolute(-2000, 200);
  pros::delay(700);
  //ring on alliance stake
  chassis.pid_turn_relative_set(20, DRIVE_SPEED, true);
  chassis.pid_wait_quick();
  ladyBrown.move_absolute(-10, 200);
  chassis.pid_drive_set(-40_in, 80, true);
  chassis.pid_wait_quick();
  pros::delay(200);
  //clamper.set_value(true);
  armPiston.set_value(false);
  //1st goal clamped
  autoClampTask.suspend();
  chassis.pid_turn_relative_set(150, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(16_in, DRIVE_SPEED, true); //20
  chassis.pid_wait_quick_chain();
  //1st ring on goal
  chassis.pid_turn_relative_set(-45, DRIVE_SPEED, true); //25
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(6_in, DRIVE_SPEED, true); //8
  chassis.pid_wait_quick_chain();
  //2nd ring on goal
  intake.move_velocity(-1200);
  chassis.pid_turn_relative_set(20, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-5_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_relative_set(-65, DRIVE_SPEED, true);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(20_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick();
   pros::delay(500);
  //3rd ring on goal
  chassis.pid_turn_relative_set(62, DRIVE_SPEED, true); //30
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-80_in, DRIVE_SPEED, true);
  intake.move_velocity(1200);
  chassis.pid_wait_quick_chain();
  clamper.set_value(false);
  chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_relative_set(-65, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  autoClampTask.resume();
  intake.move_velocity(0);
  chassis.pid_drive_set(-25_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  //2nd goal clamped
  chassis.pid_turn_relative_set(-105, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(15_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();
  pros::delay(200);
  //ring on 2nd goal
  chassis.pid_drive_set(-30_in, DRIVE_SPEED, true);
  chassis.pid_wait_quick_chain();





}
void BlueSoloAWPSig(){
  autoClampTask.suspend();
  ladyBrown.move_absolute(-2000, 200);

  autoClampTask.resume();


}

void bluePos2(){
  autoClampTask.suspend();
armPiston.set_value(false);
chassis.pid_drive_set(-28_in, 50);
chassis.pid_wait();

clamper.set_value(true);
pros::delay(500);
chassis.pid_drive_set(3_in, 80);
chassis.pid_wait();


intake.move_velocity(-1200);
//1st ring in
chassis.pid_turn_set(72_deg,TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(19_in, DRIVE_SPEED);
chassis.pid_wait();
//intake.move_velocity(-200);
pros::delay(200);
intake.move_velocity(-1200);
 //2nd ring in
pros::delay(400);
chassis.pid_drive_set(-2_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.drive_imu_reset(); 
chassis.pid_turn_set(-164_deg, TURN_SPEED);
chassis.pid_wait();
armPiston.set_value(true);

//starts going to 3rd ring
pros::delay(300);
chassis.pid_drive_set(35_in, DRIVE_SPEED);
intake.move_velocity(0);
chassis.pid_wait();
chassis.pid_drive_set(8_in, 50);
intake.move_velocity(-1200);
chassis.pid_wait();
//chassis.pid_drive_set(3_in, 30);

//chassis.pid_wait();

pros::delay(200);
armPiston.set_value(false);
pros::delay(200);
 chassis.drive_imu_reset(); 
chassis.pid_turn_set(-90_deg, TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(10_in, DRIVE_SPEED);
chassis.pid_wait();
autoClampTask.resume();
}

void redPos2(){
  autoClampTask.suspend();
armPiston.set_value(false);
chassis.pid_drive_set(-28_in, 50);
chassis.pid_wait();

clamper.set_value(true);
pros::delay(500);
chassis.pid_drive_set(3_in, 80);
chassis.pid_wait();


intake.move_velocity(-1200);
//1st ring in
chassis.pid_turn_set(-72_deg,TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(19_in, DRIVE_SPEED);
chassis.pid_wait();
//intake.move_velocity(-200);
pros::delay(200);
intake.move_velocity(-1200);
 //2nd ring in
pros::delay(400);
chassis.pid_drive_set(-2_in, DRIVE_SPEED);
chassis.pid_wait();
chassis.drive_imu_reset(); 
chassis.pid_turn_set(164_deg, TURN_SPEED);
chassis.pid_wait();
armPiston.set_value(true);

//starts going to 3rd ring
pros::delay(300);
chassis.pid_drive_set(35_in, DRIVE_SPEED);
intake.move_velocity(0);
chassis.pid_wait();
chassis.pid_drive_set(8_in, 50);
intake.move_velocity(-1200);
chassis.pid_wait();
//chassis.pid_drive_set(3_in, 30);

//chassis.pid_wait();

pros::delay(200);
armPiston.set_value(false);
pros::delay(200);
 chassis.drive_imu_reset(); 
chassis.pid_turn_set(90_deg, TURN_SPEED);
chassis.pid_wait();
chassis.pid_drive_set(10_in, DRIVE_SPEED);
chassis.pid_wait();
autoClampTask.resume();
}

void skills(){
  
  autoClampTask.suspend();
  //autoClampTaskAuton.suspend();
  
  //red = true;
  //intake.move_velocity(-1200);
  
 //REMOVE THIS WHEN COMPLETED
  //removing 3 inches 
  //tasker.suspend();
  armPiston.set_value(false);
  intake.move_velocity(-1200);
  pros::delay(500);
  //Ring on alliance stake
  chassis.pid_drive_set(10_in, DRIVE_SPEED); //13
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(0);
  chassis.pid_drive_set(-23_in, 60); //-26
  chassis.pid_wait();
  clamper.set_value(true);
  //Goal clamped
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(25_in, DRIVE_SPEED); //28
  chassis.pid_wait();
  //1st Ring on goal
  
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-40_deg, TURN_SPEED);
  chassis.pid_wait_quick(); //chaining
 
  chassis.pid_drive_set(33_in, DRIVE_SPEED); //39
  chassis.pid_wait_quick();
  
 chassis.drive_imu_reset(); 
  chassis.pid_turn_set(40_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain(); //stopped
  
  ladyBrown.move_absolute(-320, 200);
  chassis.pid_drive_set(1_in, DRIVE_SPEED); //24
  chassis.pid_wait();
  pros::delay(500);
  //ring in ladybrown
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-8_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(0);
  chassis.pid_drive_set(-25_in, DRIVE_SPEED); //-27 //-32
  chassis.pid_wait();
  ladyBrown.move_absolute(-1500, 200);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-79_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(14.5_in, 70); //21
  chassis.pid_wait();
  //2nd ring in goal
  pros::delay(100);
  ladyBrown.move_absolute(-2000, 200);
  pros::delay(50);
  //ring on wallstake
 chassis.pid_drive_set(-10_in, 65);
  chassis.pid_wait();
  ladyBrown.move_absolute(-10, 200);
  chassis.drive_imu_reset(); 
  chassis.pid_drive_set(2_in, 65);
  chassis.pid_wait();
  
  intake.move_velocity(1200);
  
  chassis.pid_turn_set(-90_deg, TURN_SPEED);
  chassis.pid_wait();
  
  intake.move_velocity(-1200);
  chassis.pid_drive_set(60_in, 60); //65
  chassis.pid_wait();
  pros::delay(250);
  //3 rings in goal
  chassis.pid_drive_set(-15_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(200);
  //6th ring on goal
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-200_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  
  chassis.pid_drive_set(-18_in, DRIVE_SPEED);
  intake.move_velocity(1200);
  //chassis.pid_wait_quick_chain();
  pros::delay(1000);
  clamper.set_value(false);
  //goal in corner

 
  chassis.pid_drive_set(5.5_in, DRIVE_SPEED); //6
  chassis.pid_wait(); 
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-111_deg, TURN_SPEED); 
  chassis.pid_wait();
  intake.move_velocity(0);
  
  chassis.pid_drive_set(-65_in, DRIVE_SPEED);
  chassis.pid_wait();
  

  

  //repeat code
  
  chassis.pid_drive_set(-20_in, 60); //-26
  chassis.pid_wait();
  clamper.set_value(true);
  //2nd Goal clamped
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(25_in, DRIVE_SPEED); //28
  chassis.pid_wait();
  //1st Ring on 2nd goal
  
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(40_deg, TURN_SPEED);
  chassis.pid_wait();
 
  chassis.pid_drive_set(29_in, DRIVE_SPEED); //39 //34
  chassis.pid_wait();
  
 chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-34_deg, TURN_SPEED);
  chassis.pid_wait();
  
  ladyBrown.move_absolute(-320, 200);
  chassis.pid_drive_set(24_in, DRIVE_SPEED); //24
  chassis.pid_wait();
  pros::delay(800);
  //ring on ladybrown
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-3_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(0);

  chassis.pid_drive_set(-27_in, DRIVE_SPEED); //-27 //-28 //18
  chassis.pid_wait();
  
  ladyBrown.move_absolute(-1500, 200);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(87_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(16.8_in, 80); //21
  chassis.pid_wait();
  //2nd ring in 2nd goal
  pros::delay(100);
 ladyBrown.move_absolute(-2000, 200);
 pros::delay(50);
  //ring on wall stake
 chassis.pid_drive_set(-10_in, 65);
  chassis.pid_wait();
  ladyBrown.move_absolute(-10, 200);
  chassis.drive_imu_reset(); 
  chassis.pid_drive_set(2_in, 65);
  chassis.pid_wait();
  intake.move_velocity(1200);
  chassis.pid_turn_set(90_deg, TURN_SPEED);
  chassis.pid_wait();
  intake.move_velocity(-1200);
  chassis.pid_drive_set(60_in, 60); //65
  chassis.pid_wait();
  pros::delay(250);
  //3 rings in 2nd goal
  chassis.pid_drive_set(-16_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(15_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  pros::delay(200);
  //6th ring on 2nd goal
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(190_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  
  chassis.pid_drive_set(-19_in, DRIVE_SPEED);
  intake.move_velocity(1200);
  pros::delay(1000);
  clamper.set_value(false);
  //2nd goal in corner
 
  
 chassis.pid_drive_set(5_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-17.7_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  
  intake.move_velocity(0);
  chassis.pid_drive_set(89_in, DRIVE_SPEED); //95
  //chassis.pid_wait_quick();
  pros::delay(2500);
  //through the middle
  intake.move_velocity(-1200);
  chassis.pid_drive_set(26.5_in, 80); //40
  chassis.pid_wait_until(24); //23.5
  intake.move_velocity(0);
  chassis.pid_wait_quick();
  //2 rings in intake
  //autoClampTaskAuton.resume();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-69_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-40_in, 70); //45
  chassis.pid_wait_quick();
  pros::delay(100);
  clamper.set_value(true);
  //3rd goal clamped
  pros::delay(100);
  chassis.pid_drive_set(15_in, DRIVE_SPEED); 
  chassis.pid_wait_quick();
 intake.move_velocity(-1200);
 //2 rings on 3rd goal
 

  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-130_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  //autoClampTaskAuton.suspend();
  chassis.pid_drive_set(-55_in, DRIVE_SPEED); 
  
  pros::delay(2500);
  intake.move_velocity(0);
  chassis.drive_imu_reset(); 
  
  chassis.pid_turn_set(30_deg, TURN_SPEED);
  clamper.set_value(false);
  pros::delay(500);
 
  //3rd goal in corner
  
  chassis.pid_drive_set(30_in, 120);
  chassis.pid_wait_quick();
  armPiston.set_value(true);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-70_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(80_in, 120);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset();
  chassis.pid_turn_set(20_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(50_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  autoClampTask.resume();

  /*
  chassis.pid_drive_set(50_in, 90); 
  chassis.pid_wait_quick_chain();
  pros::delay(100);
  //2 more rings on 3rd goal
  chassis.pid_drive_set(-20_in, DRIVE_SPEED); 
  chassis.pid_wait_quick_chain();

  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-150_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  autoClampTaskAuton.suspend();
  clamper.set_value(false);
  chassis.pid_drive_set(-40_in, DRIVE_SPEED); 
  chassis.pid_wait_quick_chain();
  // //3rd goal in corner
  intake.move_velocity(0);
  chassis.pid_drive_set(20_in, 120);
  chassis.pid_wait_quick_chain();
  armPiston.set_value(true);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-30_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(90_in, 450);
  chassis.pid_wait_quick();

  autoClampTask.resume();
  
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(30_deg, TURN_SPEED); //33
  chassis.pid_wait_quick_chain();
 
 chassis.pid_drive_set(50_in, 80);
  chassis.pid_wait_quick();
  //4 rings on 3rd goal
  chassis.pid_drive_set(-23_in, DRIVE_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(30_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(23_in, DRIVE_SPEED);
  chassis.pid_wait();
  pros::delay(100);
  //5th ring on goal
  chassis.pid_drive_set(-5_in, DRIVE_SPEED);
  chassis.pid_wait_quick();
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(160_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  clamper.set_value(false);
  chassis.pid_drive_set(-45_in, 127);
  pros::delay(1000);
  //3rd goal in corner
  intake.move_velocity(1200);
  chassis.pid_drive_set(25_in, 120);
  chassis.pid_wait_quick();
  armPiston.set_value(true);
  chassis.drive_imu_reset(); 
  chassis.pid_turn_set(-65_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(100_in, 120);
  chassis.pid_wait_quick();
  autoClampTask.resume();
  */
  
}
void redFiveRing(){
  autoClampTask.suspend();
  armPiston.set_value(false);
  chassis.pid_drive_set(-20_in, 65);
   chassis.pid_wait();
   chassis.pid_drive_set(-7_in, 50);
   chassis.pid_wait();
   clamper.set_value(true);
   pros::delay(200);
   intake.move_velocity(-1200);
   pros::delay(500);
   //Ring is in + goal is grabbed
   intake.move_velocity(-1200);
   chassis.pid_turn_set(120_deg, TURN_SPEED);
   chassis.pid_wait();
   chassis.pid_drive_set(21_in, DRIVE_SPEED);
   intake.move_velocity(-1200);
   chassis.pid_wait();
   pros::delay(500);
   //2nd ring in
   chassis.pid_drive_set(-5_in, DRIVE_SPEED);
   chassis.pid_wait();
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(-30_deg, TURN_SPEED);
   intake.move_velocity(-1200);
   chassis.pid_wait();
   chassis.pid_drive_set(13_in, DRIVE_SPEED);
   chassis.pid_wait();
   pros::delay(400);
   //3rd ring in
   chassis.pid_drive_set(-13_in, DRIVE_SPEED);
   chassis.pid_wait();
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(-60_deg, TURN_SPEED);
   chassis.pid_wait();
   intake.move_velocity(-1200);
   chassis.pid_drive_set(12_in, DRIVE_SPEED); //Used to be 12
   chassis.pid_wait();
   pros::delay(800);
   //4th ring in
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(-115_deg, TURN_SPEED);
   chassis.pid_wait();
   intake.move_velocity(-1200);
   chassis.pid_drive_set(42_in, DRIVE_SPEED);
   pros::delay(500);
   armPiston.set_value(true);
   chassis.pid_wait();
   armPiston.set_value(false);
   intake.move_velocity(-1200);
   pros::delay(700);
   chassis.pid_drive_set(-5_in, DRIVE_SPEED);
   chassis.pid_wait();
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(-100_deg, TURN_SPEED);
   chassis.pid_wait();
   chassis.pid_drive_set(10_in, DRIVE_SPEED);
   chassis.pid_wait();
   autoClampTask.resume();
  }
  void blueFiveRing(){
    autoClampTask.suspend();
  armPiston.set_value(false);
  chassis.pid_drive_set(-20_in, DRIVE_SPEED);
   chassis.pid_wait();
   chassis.pid_drive_set(-7_in, 50);
   chassis.pid_wait();
   clamper.set_value(true);
   pros::delay(200);
   intake.move_velocity(-1200);
   pros::delay(500);
   //Ring is in + goal is grabbed
   intake.move_velocity(-1200);
   chassis.pid_turn_set(-120_deg, TURN_SPEED);
   chassis.pid_wait();
   chassis.pid_drive_set(21_in, DRIVE_SPEED);
   intake.move_velocity(-1200);
   chassis.pid_wait();
   pros::delay(500);
   //2nd ring in
   chassis.pid_drive_set(-5_in, DRIVE_SPEED);
   chassis.pid_wait();
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(30_deg, TURN_SPEED);
   intake.move_velocity(-1200);
   chassis.pid_wait();
   chassis.pid_drive_set(9_in, DRIVE_SPEED);
   chassis.pid_wait();
   pros::delay(400);
   //3rd ring in
   chassis.pid_drive_set(-13_in, DRIVE_SPEED);
   chassis.pid_wait();
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(60_deg, TURN_SPEED);
   chassis.pid_wait();
   intake.move_velocity(-1200);
   chassis.pid_drive_set(12_in, DRIVE_SPEED);
   chassis.pid_wait();
   pros::delay(800);
   //4th ring in
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(115_deg, TURN_SPEED);
   chassis.pid_wait();
   intake.move_velocity(-1200);
   chassis.pid_drive_set(40_in, DRIVE_SPEED);
   pros::delay(500);
   armPiston.set_value(true);
   chassis.pid_wait();
   armPiston.set_value(false);
   intake.move_velocity(-1200);
   pros::delay(700);
   chassis.pid_drive_set(-5_in, DRIVE_SPEED);
   chassis.pid_wait();
   chassis.drive_imu_reset(); 
   chassis.pid_turn_set(100_deg, TURN_SPEED);
   chassis.pid_wait();
   chassis.pid_drive_set(10_in, DRIVE_SPEED);
   chassis.pid_wait();
   autoClampTask.resume();
  }
  void RedPosHalf(){
    chassis.pid_drive_set(-19_in, DRIVE_SPEED);
    chassis.pid_wait();
    clamper.set_value(true);
    chassis.pid_turn_set(-89_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-2_in, DRIVE_SPEED);
    chassis.pid_wait();
    intake.move_velocity(1200);
    pros::delay(1500);
    intake.move_velocity(0);
    chassis.pid_drive_set(4_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-150_deg, TURN_SPEED);
    chassis.pid_wait();
    clamper.set_value(false);
    chassis.pid_drive_set(-23_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-10_in, 50);
    chassis.pid_wait();
    pros::delay(800);
    clamper.set_value(true);
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-140_deg, TURN_SPEED);
    chassis.pid_wait();
    intake.move_velocity(1200);
    chassis.pid_drive_set(23_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-120_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(28_in, 50);
    chassis.pid_wait();
    
  }
  
  void BlueNegAWP(){
   // tasker.suspend();
    
    chassis.pid_drive_set(-15_in, DRIVE_SPEED);
    chassis.pid_wait();
    clamper.set_value(true);
    chassis.pid_turn_set(-87_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-4_in, DRIVE_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
    pros::delay(1500);
    intake.move_velocity(0);
    //Ring is in
    chassis.pid_drive_set(7_in, DRIVE_SPEED);
    chassis.pid_wait();
    clamper.set_value(false);
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-145_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-25_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-10_in, 50);
    chassis.pid_wait();
    clamper.set_value(true);
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-125_deg, TURN_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
    chassis.pid_drive_set(20_in, 70);
    chassis.pid_wait();
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-90_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(16_in, 70);
    chassis.pid_wait();
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(47_deg, TURN_SPEED);
    chassis.pid_wait();
    pros::delay(1500);
    chassis.pid_drive_set(-5_in, 70);
    chassis.pid_wait();
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-100_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, 50);
    chassis.pid_wait();
    armPiston.set_value(true);
    //tasker.resume();
    
  
  }
  void BluePos(){
    //tasker.suspend();
    
    chassis.pid_drive_set(-15_in, DRIVE_SPEED);
    chassis.pid_wait();
    clamper.set_value(true);
    chassis.pid_turn_set(87_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-4_in, DRIVE_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
    pros::delay(1500);
    intake.move_velocity(0);
    //Ring is in
    chassis.pid_drive_set(7_in, DRIVE_SPEED);
    chassis.pid_wait();
    clamper.set_value(false);
    
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(145_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-25_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-14_in, 60);
    chassis.pid_wait();
    clamper.set_value(true);
    //Goal Grabbed
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(120_deg, TURN_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
   
    chassis.pid_drive_set(20_in, 60);
    chassis.pid_wait();
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(145_deg, 50);
    chassis.pid_wait();
    pros::delay(1500);
    chassis.pid_drive_set(30_in, 60);
    chassis.pid_wait();
  
  
    //tasker.resume();
  
  }
  void BlueNeg(){
   // tasker.suspend();
    
    chassis.pid_drive_set(-22_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-5_in, 50);
    chassis.pid_wait();
    
    clamper.set_value(true);
    //Goal has been picked up
    pros::delay(400);
    intake.move_velocity(-1200);
    pros::delay(800);
    //intake.move_velocity(1200);
    pros::delay(200);
  
    intake.move_velocity(-1200);
  
    //intake.move_velocity(0);
    //Ring is in
    chassis.pid_turn_set(-98_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, DRIVE_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
    chassis.pid_drive_set(8_in, 50);
    chassis.pid_wait();
    pros::delay(1500);
    //intake.move_velocity(1200);
    pros::delay(200);
  
    intake.move_velocity(-1200);
  
    //intake.move_velocity(0);
    //2nd Ring is in
    chassis.drive_imu_reset();   
    chassis.pid_turn_set(-45_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, DRIVE_SPEED);
    chassis.pid_wait();
    //intake.move_velocity(600);
    pros::delay(500);
    intake.move_velocity(-1200);
    chassis.pid_drive_set(8_in, 50);
    chassis.pid_wait();
    chassis.pid_drive_set(-4_in, 50);
    chassis.pid_wait();
    //3rd Ring is in
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-45_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(8_in, 50);
    chassis.pid_wait();
    chassis.pid_drive_set(-4_in, 50);
    chassis.pid_wait();
    //4th Ring is in
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-65_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, 127);
    chassis.pid_wait();
    //tasker.resume();
    
  
  }
  void RedPos(){
   // tasker.suspend();
    
    chassis.pid_drive_set(-15_in, DRIVE_SPEED);
    chassis.pid_wait();
    clamper.set_value(true);
    chassis.pid_turn_set(-87_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-4_in, DRIVE_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
    pros::delay(1500);
    intake.move_velocity(0);
    //Ring is in
    chassis.pid_drive_set(7_in, DRIVE_SPEED);
    chassis.pid_wait();
    clamper.set_value(false);
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-145_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-25_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-14_in, 60);
    chassis.pid_wait();
    clamper.set_value(true);
    //Goal Grabbed
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-120_deg, TURN_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
   
    chassis.pid_drive_set(20_in, 60);
    chassis.pid_wait();
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(-145_deg, 50);
    chassis.pid_wait();
    pros::delay(1500);
    chassis.pid_drive_set(30_in, 60);
    chassis.pid_wait();
  
  
   // tasker.resume();
  }
  void RedNeg(){
  
    //tasker.suspend();
    
    chassis.pid_drive_set(-22_in, DRIVE_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(-5_in, 50);
    chassis.pid_wait();
    
    clamper.set_value(true);
    //Goal has been picked up
    pros::delay(400);
    intake.move_velocity(-1200);
    pros::delay(800);
    //intake.move_velocity(1200);
    pros::delay(200);
  
    intake.move_velocity(-1200);
  
    //intake.move_velocity(0);
    //Ring is in
    chassis.pid_turn_set(98_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, DRIVE_SPEED);
    chassis.pid_wait();
    intake.move_velocity(-1200);
    chassis.pid_drive_set(8_in, 50);
    chassis.pid_wait();
    pros::delay(1500);
    //intake.move_velocity(1200);
    pros::delay(200);
  
    intake.move_velocity(-1200);
  
    //intake.move_velocity(0);
    //2nd Ring is in
    chassis.drive_imu_reset();   
    chassis.pid_turn_set(45_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, DRIVE_SPEED);
    chassis.pid_wait();
    //intake.move_velocity(600);
    pros::delay(500);
    intake.move_velocity(-1200);
    chassis.pid_drive_set(8_in, 50);
    chassis.pid_wait();
    chassis.pid_drive_set(-4_in, 50);
    chassis.pid_wait();
    //3rd Ring is in
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(45_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(8_in, 50);
    chassis.pid_wait();
    chassis.pid_drive_set(-4_in, 50);
    chassis.pid_wait();
    //4th Ring is in
    chassis.drive_imu_reset(); 
    chassis.pid_turn_set(65_deg, TURN_SPEED);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(10_in, 127);
    chassis.pid_wait();
   // tasker.resume();
  }