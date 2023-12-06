// created by Cavaliers Programming Team

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include "span"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include "span"


class Limelight: public frc2::SubsystemBase {

private:
//std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

    //double m_targetArea = table->GetNumber("ta", 0.0);
    //double m_targetHorizontalOffset = table->GetNumber("tx", 0.0);
    //double m_targetValid = table->GetNumber("tv", 0.0);
    //double m_targetVerticalOffset = table->GetNumber("ty", 0.0);
    //int m_lltid = table->GetNumber("tid",0.0);
    //double m_llbotpose = table->GetNumber("botpose",0.0);
    
public:
    Limelight();

    void Periodic() override;
    void SimulationPeriodic() override;
    void Update();
};

