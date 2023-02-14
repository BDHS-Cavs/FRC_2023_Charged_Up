// RobotBuilder Version: 3.1
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "commands/CompressorDisableCommand.h"

CompressorDisableCommand::CompressorDisableCommand(Grabber* m_grabber)
:m_grabber(m_grabber){

    // Use AddRequirements() here to declare subsystem dependencies
    // eg. AddRequirements(m_Subsystem);
    SetName("CompressorDisableCommand");
    AddRequirements(m_grabber);
}

// Called just before this Command runs the first time
void CompressorDisableCommand::Initialize() {
   m_grabber->CompressorDisable();
}

// Called repeatedly when this Command is scheduled to run
void CompressorDisableCommand::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool CompressorDisableCommand::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void CompressorDisableCommand::End(bool interrupted) {
}

bool CompressorDisableCommand::RunsWhenDisabled() const {
    return false;
}