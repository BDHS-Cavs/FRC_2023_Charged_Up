// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#pragma once
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/Encoder.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/WaitCommand.h>
#include <frc/BuiltInAccelerometer.h>
class Drive: public frc2::SubsystemBase {

private:

    // left
    frc::Spark m_leftFront{2};
    frc::Spark m_leftRear{3};

    // right
    frc::Spark m_rightFront{4};
    frc::Spark m_rightRear{5};

    frc::MotorControllerGroup m_controllerRight{m_leftFront, m_leftRear};
    frc::MotorControllerGroup m_controllerLeft{m_rightFront, m_rightRear};

    frc::DifferentialDrive m_differentialDrive{m_controllerLeft, m_controllerRight}; //might have to change left and right to make turning work

// Initializes an encoder on DIO pins 0 and 1
    frc::Encoder encoder{0, 1, true, frc::Encoder::EncodingType::k1X}; // inverted and 1x
    
public:
    Drive();
	
    void Periodic() override;
    void SimulationPeriodic() override;
    void Motivate(double leftSpeed, double rightSpeed);
    void AutoMotivateRotate();
    void AutoBackwards();
    void ResetEncoder();
    void Stop();
    bool CompareAngles(double x, double y, double epsilon);
    bool CalculateAverageEncoderDistance();
    void AutoGyroCrawl();
    void GyroCalibrate();
    frc::ADXRS450_Gyro m_drivegyro;
    frc::BuiltInAccelerometer m_accelerometer;

    double m_encoderdistance = encoder.GetDistance(); //does nothing because no encoders - these were made for autos.h which doesnt work
    double m_encoderrate = encoder.GetRate(); //does nothing
};