// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

#include "subsystems/Arm.h"
#include "subsystems/Drive.h"
#include "subsystems/Grabber.h"
#include "subsystems/Limelight.h"

/** Container for auto commands */
namespace autos {

/**
 * An autonomous mode that is used when the robot is in the LEFT position.
 */
frc2::CommandPtr LeftAuto(Arm* arm, Drive* drive, Grabber* grabber, Limelight* limelight);

/**
 * An autonomous mode that is used when the robot is in the RIGHT position.
 */
frc2::CommandPtr RightAuto(Arm* arm, Drive* drive, Grabber* grabber, Limelight* limelight);

/**
 * An autonomous mode that is used when the robot is in the RIGHT position.
 */
frc2::CommandPtr CenterAuto(Arm* arm, Drive* drive, Grabber* grabber, Limelight* limelight);

}  // namespace autos