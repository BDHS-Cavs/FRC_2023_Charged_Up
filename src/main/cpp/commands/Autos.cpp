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

frc2::CommandPtr autos::LeftAuto(Arm* arm, Drive* drive, Grabber* grabber) {
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

frc2::CommandPtr autos::RightAuto(Arm* arm, Drive* drive, Grabber* grabber) {
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