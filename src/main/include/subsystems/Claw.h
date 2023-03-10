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

#include <frc/motorcontrol/Spark.h>
#include <frc2/command/SubsystemBase.h>

class Claw: public frc2::SubsystemBase {

private:
    frc::Spark m_clawMotor{5}; //tuned value

public:
    Claw();

    void Periodic() override;
    void SimulationPeriodic() override;
    void ClawStop();
};