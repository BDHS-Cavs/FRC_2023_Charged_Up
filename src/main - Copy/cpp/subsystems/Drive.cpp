// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "subsystems/Drive.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/raw_ostream.h> // for wpi outs()

Drive::Drive(){
    SetName("Drive");
    SetSubsystem("Drive");

    AddChild("DifferentialDrive", &m_differentialDrive);
    m_differentialDrive.SetSafetyEnabled(true);
    m_differentialDrive.SetExpiration(0.1_s);
    m_differentialDrive.SetMaxOutput(1.0);

    AddChild("m_controllerRight", &m_controllerRight);

    AddChild("m_rightFront", &m_rightFront);
    m_rightFront.SetInverted(true);

    AddChild("m_rightRear", &m_rightRear);
    m_rightRear.SetInverted(true);

    AddChild("m_controllerLeft", &m_controllerLeft);

    AddChild("m_leftFront", &m_leftFront);
    m_leftFront.SetInverted(false);

    AddChild("m_leftRear", &m_leftRear);
    m_leftRear.SetInverted(false);

    AddChild("m_drivegyro", &m_drivegyro);
}

void Drive::Periodic() {
    // Put code here to be run every loop
    //frc::SmartDashboard::PutNumber("Encoder Distance : ", m_encoderdistance);
    //frc::SmartDashboard::PutNumber("Encoder Rate : ", m_encoderrate);
    
}

void Drive::SimulationPeriodic() {
    // This method will be called once per scheduler run when in simulation
}

// Functions called by robot commands
void Drive::Motivate(double leftSpeed, double rightSpeed) {

    m_differentialDrive.ArcadeDrive(leftSpeed, rightSpeed, true);
}

void Drive::AutoMotivateRotate() {

    double autoLeftSpeed = 1;
    double autoRightSpeed = -1;
    m_differentialDrive.ArcadeDrive(autoLeftSpeed, autoRightSpeed, true);
}


void Drive::ResetEncoder() {
    // is there something to do here?
}

bool Drive::CompareAngles(double x, double y, double epsilon = 0.01)
{
    if (fabs(x - y) < epsilon)
    {
        return true;
        wpi::outs() << "returning true in compareangles!\n";
    }
    else
    {
        return false;
        wpi::outs() << "returning false in compareangles!\n";
    };
}

bool Drive::CalculateAverageEncoderDistance() {
    // do nothing here, yet
    return true;
}

void Drive::Stop(){
    // cease your actions!!
    m_differentialDrive.ArcadeDrive(0.0, 0.0, true);
}

void Drive::AutoBackwards(){
    double autoBackwardsLeftSpeed = 0.55;
    double autoBackwardsRightSpeed = 0; //rotation!!!!!
    m_differentialDrive.ArcadeDrive(autoBackwardsLeftSpeed, autoBackwardsRightSpeed, true);
}

void Drive::AutoGyroCrawl(){
    //m_differentialDrive.ArcadeDrive(0.55, 0.0, true); //drive back for a bit until gyro goes 0.1 to -0.1 (tuned value not real angles)
    //if(m_drivegyro.GetAngle() > 0.1){ //tuned value
    //m_differentialDrive.ArcadeDrive(0.2, 0.0, true);
    //}
    //else if(m_drivegyro.GetAngle() < -0.1){ //tuned value
    //m_differentialDrive.ArcadeDrive(-0.2, 0.0, true);
    //}
    //else{ //if gyro is 0.09 to -0.09 (tuned value not real angles)
    //m_differentialDrive.ArcadeDrive(0.0, 0.0, true);
    //}
}

void Drive::GyroCalibrate(){
    m_drivegyro.Calibrate();
}