// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/FunctionalCommand.h>

frc2::CommandPtr autos::CenterAuto(Arm* arm, Drive* drive, Grabber* grabber) {
  return frc2::FunctionalCommand(
             // onInit - drive reset encoders
             [drive, grabber]
             { drive->ResetEncoder(); grabber->CompressorEnable();}, // returns void

             // onExecute - drive forward per the command
             [drive, grabber]
             { drive->AutoGyroCrawl(); grabber->GrabberCloseOpenAutonomous();}, // returns void

             // onEnd - stop driving
             [drive, grabber](bool interrupted)
             { drive->Stop(); grabber->GrabberStop();}, // returns void

             // isFinished - calculate average encoder distance (for the future)
             [drive, grabber]
             { return drive->CalculateAverageEncoderDistance(); return grabber->GrabberDontStop();}, // returns bool

             // requirements - this requires only the drive subsystem
             {drive, grabber})
      .ToPtr();
}

frc2::CommandPtr autos::LeftAuto(Arm* arm, Drive* drive, Grabber* grabber) {
  return frc2::FunctionalCommand(
             // onInit - drive reset encoders
             [drive, grabber]
             { drive->ResetEncoder(); grabber->CompressorEnable();}, // returns void

             // onExecute - drive forward per the command
             [drive, grabber]
             { drive->AutoGyroCrawl(); grabber->GrabberCloseOpenAutonomous();}, // returns void

             // onEnd - stop driving
             [drive, grabber](bool interrupted)
             { drive->Stop(); grabber->GrabberStop();}, // returns void

             // isFinished - calculate average encoder distance (for the future)
             [drive, grabber]
             { return drive->CalculateAverageEncoderDistance(); return grabber->GrabberDontStop();}, // returns bool

             // requirements - this requires only the drive subsystem
             {drive, grabber})
      .ToPtr();
}

frc2::CommandPtr autos::RightAuto(Arm* arm, Drive* drive, Grabber* grabber) {
  return frc2::FunctionalCommand(
             // onInit - drive reset encoders
             [drive, grabber]
             { drive->ResetEncoder(); grabber->CompressorEnable();}, // returns void

             // onExecute - drive forward per the command
             [drive, grabber]
             { drive->AutoGyroCrawl(); grabber->GrabberCloseOpenAutonomous();}, // returns void

             // onEnd - stop driving
             [drive, grabber](bool interrupted)
             { drive->Stop(); grabber->GrabberStop();}, // returns void

             // isFinished - calculate average encoder distance (for the future)
             [drive, grabber]
             { return drive->CalculateAverageEncoderDistance(); return grabber->GrabberDontStop();}, // returns bool

             // requirements - this requires only the drive subsystem
             {drive, grabber})
      .ToPtr();
}