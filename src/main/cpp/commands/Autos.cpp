// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/FunctionalCommand.h>

frc2::CommandPtr autos::LeftAuto(Arm* arm, Drive* drive, Grabber* grabber, Limelight* limelight) {
  return frc2::FunctionalCommand(

    // onInit - drive reset encoders 
    [drive]
    { drive->ResetEncoder(); }, // returns void

    // onExecute - drive forward per the command
    [drive]
    { drive->AutoMotivateForward(); }, // returns void

    // onEnd - stop driving 
    [drive](bool interrupted)
    { drive->Stop(); }, // returns void

    // isFinished - calculate average encoder distance (for the future)
    [drive] 
    { return drive->CalculateAverageEncoderDistance(); }, // returns bool

    // requirements - this requires only the drive subsystem
    {drive})
 .ToPtr();
}

//frc2::commandptr autos::simpleauto(drivesubsystem* drive) {
//  return frc2::functionalcommand(
//             // reset encoders on command start
//             [drive] { drive->resetencoders(); },
//             // drive forward while the command is executing
//             [drive] { drive->arcadedrive(autoconstants::kautodrivespeed, 0); },
//             // stop driving at the end of the command
//             [drive](bool interrupted) { drive->arcadedrive(0, 0); },
//             // end the command when the robot's driven distance exceeds the
//             // desired value
//             [drive] {
//               return drive->getaverageencoderdistance() >=
//                      autoconstants::kautodrivedistanceinches;
//             },
//             // requires the drive subsystem
//             {drive})
//      .toptr();
//}
//
//frc2::CommandPtr autos::ComplexAuto(DriveSubsystem* drive,
//                                    HatchSubsystem* hatch) {
//  return frc2::cmd::Sequence(
//      // Drive forward the specified distance
//      frc2::FunctionalCommand(
//          // Reset encoders on command start
//          [drive] { drive->ResetEncoders(); },
//          // Drive forward while the command is executing
//          [drive] { drive->ArcadeDrive(kAutoDriveSpeed, 0); },
//          // Stop driving at the end of the command
//          [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
//          // End the command when the robot's driven distance exceeds the
//          // desired value
//          [drive] {
//            return drive->GetAverageEncoderDistance() >=
//                   kAutoDriveDistanceInches;
//          },
//          // Requires the drive subsystem
//          {drive})
//          .ToPtr(),
//      // Release the hatch
//      hatch->ReleaseHatchCommand(),
//      // Drive backward the specified distance
//      // Drive forward the specified distance
//      frc2::FunctionalCommand(
//          // Reset encoders on command start
//          [drive] { drive->ResetEncoders(); },
//          // Drive backward while the command is executing
//          [drive] { drive->ArcadeDrive(-kAutoDriveSpeed, 0); },
//          // Stop driving at the end of the command
//          [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
//          // End the command when the robot's driven distance exceeds the
//          // desired value
//          [drive] {
//            return drive->GetAverageEncoderDistance() <=
//                   kAutoBackupDistanceInches;
//          },
//          // Requires the drive subsystem
//          {drive})
//          .ToPtr());
//}