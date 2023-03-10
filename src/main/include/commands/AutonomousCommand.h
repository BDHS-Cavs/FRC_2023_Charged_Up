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

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Timer.h>
#include <frc2/command/WaitCommand.h>

#include "subsystems/Arm.h"
#include "subsystems/Drive.h"
#include "subsystems/Limelight.h"
#include "subsystems/Grabber.h"

class AutonomousCommand: public frc2::CommandHelper<frc2::CommandBase, AutonomousCommand> {

public:

    explicit AutonomousCommand(Arm* m_arm, Drive* m_drive, Limelight* m_limelight, Grabber* m_grabber);

void Initialize() override;
void Execute() override;
bool IsFinished() override;
void End(bool interrupted) override;
bool RunsWhenDisabled() const override;


private:
    bool       m_firstTime;
    frc::Timer m_timer; 

    Arm*       m_arm;
    Drive*     m_drive;
    Limelight* m_limelight;
    Grabber*   m_grabber;
};
