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
    units::second_t period2 = 5_s;
    units::second_t period3 = 7_s;
    units::second_t period4 = 9_s;
    units::second_t period5 = 11_s;
    units::second_t period6 = 12_s;
    
    if(m_firstTime)
    {
        m_timer.Reset();
        m_firstTime = false;
    }

    m_timer.Start();

    frc::SmartDashboard::PutNumber("Autonomous Command Timer", double(m_timer.Get()));

    if (m_timer.Get() >= units::second_t(0_s) && m_timer.Get() < period1) //period 0
    {
        //do nothing
    }
    else if(m_timer.Get() >= period1 && m_timer.Get() < period2) //period 1 (starts at 1s) (ends at 5s) (4s)
    {
        m_grabber->CompressorEnable(); // enable the compressor
    }
    else if(m_timer.Get() >= period2 && m_timer.Get() < period3) //period 2 (starts at 5s) (ends at 7s) (2s)
    {
        m_arm->ArmUnlock();
        m_arm->ArmLock();
        m_arm->ArmUnlock(); //unlock solenoid
        frc2::WaitCommand(1_s);
        m_arm->AutoArmBackward(); //lower the arm
    }
    else if(m_timer.Get() >= period3 && m_timer.Get() < period4) //period 3 (starts at 7s) (ends at 9s) (2s)
    {
        m_grabber->GrabberClose(); //release the piece (todo rename to open)
        m_arm->ArmLock(); //lock arm
        m_arm->ArmUnlock(); //unlock arm
        m_arm->ArmLock(); //lock the arm
    }
    else if(m_timer.Get() >= period4 && m_timer.Get() < period5) //period 4 (starts at 9s) (ends at 11s) (2s)
    {
        m_drive->AutoMotivateBackward(); //COMMENT THIS OUT IF WE ARE IN THE MIDDLE
    }
    else if(m_timer.Get() >= period5 && m_timer.Get() < period6) //period 5 (starts at 11s) (ends at 12s) (1s)
    {
        m_drive->Stop();
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