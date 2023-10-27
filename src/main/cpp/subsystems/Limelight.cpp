// created by Cavaliers Programming Team

#include "subsystems/Limelight.h"



Limelight::Limelight(){
    SetName("Limelight");
    SetSubsystem("Limelight");
}

void Limelight::Periodic() {
    // Put code here to be run every loop
    frc::SmartDashboard::PutNumber("Limelight Target Area", m_targetArea);
    frc::SmartDashboard::PutNumber("Limelight Horizontal Offset", m_targetHorizontalOffset);
    frc::SmartDashboard::PutNumber("Limelight Target Valid", m_targetValid);
    frc::SmartDashboard::PutNumber("Limelight Vertical Offset", m_targetVerticalOffset);
    frc::SmartDashboard::PutNumber("Limelight Target ID", m_lltid);
    frc::SmartDashboard::PutNumber("Limelight Bot Pose", m_llbotpose);
}

void Limelight::SimulationPeriodic() {
}

void Limelight::Update() {
}