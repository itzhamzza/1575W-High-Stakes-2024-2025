#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "autons.hpp"

bool togglable = false;
//Redirect
void intakeButton(){
    if(master.get_digital(DIGITAL_B) && togglable == false){
        togglable = true;
        pros::delay(50);
        master.rumble(".");
        
    }
    else if(master.get_digital(DIGITAL_B) && togglable == true){
        togglable = false;
        pros::delay(50);
        master.rumble(".");
    }


}
// void allianceStake(){
//     if(master.get_digital(DIGITAL_B)){
//         driveTrainLeft.move_relative(1000,50);
//         driveTrainRight.move_relative(1000,50);
//         pros::delay(300);
        
//     }
    
// }
bool sortering = false;

int toggle2 = 0;
//Intake
void intaking(){
    
        if (togglable == true){

            if(master.get_digital_new_press(DIGITAL_R2) && sortering == false){
                if (toggle2 == 0){
                    //intakes in
                    intake.move_velocity(-1200);      
                    toggle2++;
                    //pros::delay(50);
                }
                else if (toggle2 == 1){
                    intake.move_velocity(0);      
                    toggle2--;
                    //pros::delay(50);
                }
            }
            else if(master.get_digital(DIGITAL_R1)){

                //intakes out
                intake.move_velocity(600);
                
            }
        }
    
    
        if (togglable == false){
             if(master.get_digital(DIGITAL_R2) && sortering == false){

                //intakes in
                intake.move_velocity(-1200);
                
            }
            else if(master.get_digital(DIGITAL_R1)){

                //intakes out
                intake.move_velocity(600);
                
            }
            else if (sortering == false){
                intake.move_velocity(0);
                //intake.set_brake_mode(MOTOR_BRAKE_COAST);
                
    
            }
        }
    
        
        
}

void colorSort(){
    while(true){
    
        // //THIS THORWS OUT RED
       
            //  if (color_sens.get_hue() < 13 && color_sens.get_hue() > 8){
            //    // pros::delay(25);
            //         sortering = true;
            //         intake.move_velocity(1200);
            //         pros::delay(700);
            //         sortering = false;
            //  }
        
        //THIS THROWS OUT BLUE
       
               if (color_sens.get_hue() < 230 && color_sens.get_hue() > 210){
                //pros::delay(25);
                    sortering = true;
                    intake.move_velocity(1200);
                    pros::delay(700);
                    sortering = false;
            }
        
               pros::delay(10);
        

    }
}

void autoClamper(){
    while (true){
        if (limitSwitchLeft.get_new_press() || limitSwitchRight.get_new_press()){
            //pros::delay(500);
            clamper.set_value(true);
            pros::delay(1500);
        }
        pros::delay(50);
    }
}
// void autoClamperAuton(){
//     while (true){
//         if (limitSwitchLeft.get_new_press() && limitSwitchRight.get_new_press()){
//             //pros::delay(500);
//             clamper.set_value(true);
//             pros::delay(700);
            
//         }
//         pros::delay(50);
//     }
// }
void autoFlipping(){
    while (true){
        if (autoFlipper.get_new_press()){
            //pros::delay(500);
            ez::as::page_up();
            
        }
        pros::delay(50);
    }
}

int stage = 0;


void ladybrownMovement(){
    

        if(master.get_digital_new_press(DIGITAL_L1)){
            //arm up
            if (stage == 0){
                ladyBrown.set_brake_mode(MOTOR_BRAKE_HOLD);
                intake.set_brake_mode(MOTOR_BRAKE_HOLD);
            
                ladyBrown.move_absolute(-350, 200);
                togglable = false;
                stage++;
            }
            // else if (stage == 1){
            //     intake.set_brake_mode(MOTOR_BRAKE_COAST);
            //     ladyBrown.move_absolute(-1500, 200);
            //     stage++;
            // }
            else if(stage == 1){
                ladyBrown.move_absolute(-1800, 200);

            }

            
            //rotation_sens.reset();
           // while (rotation_sens.get_position() > 27000){
            
             //   ladyBrown.move_velocity(-600);
               // locker.set_value(true);
            //}
            

        }
        else if(master.get_digital_new_press(DIGITAL_L2)){
            //arm down
            ladyBrown.move_absolute(-10, 200);
            ladyBrown.set_brake_mode(MOTOR_BRAKE_COAST);
            intake.set_brake_mode(MOTOR_BRAKE_COAST);
            togglable = true;
            stage = 0;
            
            //rotation_sens.reset();
            //while (rotation_sens.get_position() <= 35700){
              //  ladyBrown.move_velocity(600);
                
            //}
            
        }
        
        pros::delay(100);
    

}

void intakeExtender(){
    if(master.get_digital_new_press(DIGITAL_X)){
        //Arm Extender
        armPiston.set_value(true);
       
    }
    else if(master.get_digital_new_press(DIGITAL_A)){
        //Arm Extender Off
        armPiston.set_value(false);
        
    }
}

void clamping(){

    if(master.get_digital(DIGITAL_Y)){
        //clamps on
        clamper.set_value(true);
        

    }
    else if(master.get_digital(DIGITAL_RIGHT)){
        //clamps off
        
        clamper.set_value(false);
        
        
    }

}
int toggle = 0;
void goalClamper(){
    if(master.get_digital(DIGITAL_LEFT) && toggle ==0){
      goalClamp.set_value(true);
      toggle++;
      pros::delay(50);
    }
    else if(master.get_digital(DIGITAL_LEFT) && toggle ==1){
        goalClamp.set_value(false);
      toggle--;
      pros::delay(50);
    }

}
void doinker(){

    if(master.get_digital(DIGITAL_UP)){
        //clamps on
      doink.set_value(true);
        

    }
    else if(master.get_digital(DIGITAL_DOWN)){
        //clamps off
        doink.set_value(false);
        
    }

}
