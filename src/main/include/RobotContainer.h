// RobotBuilder Version: 4.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: RobotContainer.

#pragma once

// frc includes
#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>

#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include <frc2/command/button/JoystickButton.h>

// our includes
#include "commands/Autos.h"
#include "commands/ArmForwardCommand.h"
#include "commands/ArmBackwardCommand.h"
#include "commands/GrabberCloseCommand.h"
#include "commands/GrabberOpenCommand.h"
#include "commands/AutonomousCommand.h"
#include "commands/ArmExtendCommand.h"
#include "commands/ArmRetractCommand.h"
#include "commands/CompressorEnableCommand.h"
#include "commands/CompressorDisableCommand.h"
#include "commands/ArmSpeedUpCommand.h"

#include "subsystems/Arm.h"
#include "subsystems/Drive.h"
#include "subsystems/Limelight.h"
#include "subsystems/Grabber.h"

class RobotContainer {

public:

    frc2::Command* GetAutonomousCommand();
    static RobotContainer* GetInstance();

    // The robot's subsystems
    Arm       m_arm;
    Drive     m_drive;
    Limelight m_limelight;
    Grabber   m_grabber;

    // Get the control values
    frc::Joystick *getJoystick();
    frc::XboxController *getController();

private:

    RobotContainer();

    // Joysticks
    frc::Joystick m_joystick{0};
    frc::XboxController m_controller{1};

    
    // For Multiple Autos
    // The chooser for the autonomous modes
    frc::SendableChooser<frc2::Command*> m_chooser;
    
    // The autonomous modes
    frc2::CommandPtr m_leftAuto = autos::LeftAuto(&m_arm, &m_drive, &m_grabber);
    frc2::CommandPtr m_rightAuto = autos::RightAuto(&m_arm, &m_drive, &m_grabber);
    frc2::CommandPtr m_centerAuto = autos::CenterAuto(&m_arm, &m_drive, &m_grabber);

    static RobotContainer* m_robotContainer;

    void ConfigureButtonBindings();
};