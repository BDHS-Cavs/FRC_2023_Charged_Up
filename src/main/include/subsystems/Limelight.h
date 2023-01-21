// created by Cavaliers Programming Team

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

using namespace std;

class Limelight: public frc2::SubsystemBase {

private:

    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

public:
    Limelight();

    void Periodic() override;
    void SimulationPeriodic() override;
    void Update();
};