// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Command.
#include "commands/AutonomousCommand.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/raw_ostream.h> // for wpi outs()

AutonomousCommand::AutonomousCommand(Arm* m_arm, Drive* m_drive, Limelight* m_limelight, Grabber* m_grabber)
:m_arm(m_arm),
m_drive(m_drive),
m_limelight(m_limelight),
m_grabber(m_grabber)
{

    // Use AddRequirements() here to declare subsystem dependencies
    // eg. AddRequirements(m_Subsystem);
    SetName("AutonomousCommand");
    AddRequirements(m_arm);
    AddRequirements(m_drive);
    AddRequirements(m_limelight);
    AddRequirements(m_grabber);

    m_firstTime = true;
    m_timer.Reset();
}

// Called just before this Command runs the first time
void AutonomousCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute() {

    units::second_t period1 = 1_s;
    units::second_t period2 = 2_s;
    units::second_t period3 = 5_s;
    units::second_t period4 = 8_s;
    
    if(m_firstTime)
    {
        m_timer.Reset();
        m_firstTime = false;
    }

    m_timer.Start();

    frc::SmartDashboard::PutNumber("Autonomous Command Timer", double(m_timer.Get()));

    if (m_timer.Get() >= units::second_t(0_s) && m_timer.Get() < period1)
    {
        //do nothing
    }
    else if(m_timer.Get() >= period1 && m_timer.Get() < period2)
    {
        m_grabber->GrabberStop(); // stop the Grabber
        m_drive->AutoMotivateForwardBackward(); // drive backwards 8 to 10 feet - about 3 seconds
    }
    else if(m_timer.Get() >= period2 && m_timer.Get() < period3)
    {
        m_arm->ArmForward(); // lower the arm
    }
    else if(m_timer.Get() >= period3 && m_timer.Get() < period4)
    {
        m_drive->AutoMotivateRotate(); // turn 180 degrees to the left
    }
    else
    {
        // do nothing
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void AutonomousCommand::End(bool interrupted) {
    m_arm->ArmPivotStop();
    m_arm->ArmExtendStop();
    m_drive->Stop();
    m_grabber->GrabberStop();

    m_firstTime = true;
}

bool AutonomousCommand::RunsWhenDisabled() const {
    return false;
}