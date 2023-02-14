// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "subsystems/Grabber.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/raw_ostream.h> // for wpi outs()


Grabber::Grabber(){
    SetName("Grabber");
    SetSubsystem("Grabber");

    AddChild("GrabberSolenoid", &m_grabberSolenoid);
}




void Grabber::Periodic() {
    // Put code here to be run every loop
}

void Grabber::SimulationPeriodic() {
}

// Put methods for controlling this subsystem here and call from commands

void Grabber::GrabberOpen(){
    //Open the Grabber
    m_grabberSolenoid.Set(frc::DoubleSolenoid::Value::kForward); //TODO: Is this the right direction?
}

void Grabber::GrabberClose(){
    //Close the Grabber
    m_grabberSolenoid.Set(frc::DoubleSolenoid::Value::kReverse); //TODO: Is this the right direction?
}

void Grabber::CompressorEnable(){
    //Enable the Compressor
    m_compressor.EnableDigital(); //check with build team
}

void Grabber::CompressorDisable(){
    //Disable the Compressor
    m_compressor.Disable();
}

void Grabber::GrabberStop(){
    // Stop the Grabber
    m_grabberSolenoid.Set(frc::DoubleSolenoid::Value::kOff); //TODO: Is this correct?
}