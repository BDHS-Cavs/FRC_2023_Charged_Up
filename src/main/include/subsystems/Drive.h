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

#include <frc/ADXRS450_Gyro.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/Encoder.h>
#include <frc2/command/SubsystemBase.h>

class Drive: public frc2::SubsystemBase {

private:
    frc::ADXRS450_Gyro m_drive_gyro;

    // left
    frc::Spark m_leftFront{0};
    frc::Spark m_leftRear{1};
    frc::MotorControllerGroup m_controllerLeft{m_leftFront, m_leftRear};

    // right
    frc::Spark m_rightFront{2};
    frc::Spark m_rightRear{3};
    frc::MotorControllerGroup m_controllerRight{m_rightFront, m_rightRear};

    frc::DifferentialDrive m_differentialDrive{m_controllerLeft, m_controllerRight};

// Initializes an encoder on DIO pins 0 and 1
    frc::Encoder encoder{0, 1, true, frc::Encoder::EncodingType::k1X}; // inverted and 1x
    
public:
    Drive();
	
    void Periodic() override;
    void SimulationPeriodic() override;
    void Motivate(double leftSpeed, double rightSpeed);
    void AutoMotivateBackward();
    void AutoMotivateRotate();
    void Stop();
    bool CompareAngles(double x, double y, double epsilon);

    double m_encoderdistance = encoder.GetDistance();
    double m_encoderrate = encoder.GetRate();
};
