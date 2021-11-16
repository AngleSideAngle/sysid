// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// #include <ctre/Phoenix.h>

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <frc/Encoder.h>
#include <frc/TimedRobot.h>
#include <frc/motorcontrol/MotorController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <wpi/json.h>
#include <wpi/raw_istream.h>

#include "sysid/logging/SysIdGeneralMechanismLogger.h"

class Robot : public frc::TimedRobot {
 public:
  Robot();
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void SimulationPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  std::vector<std::unique_ptr<frc::MotorController>> m_controllers;
  std::function<double()> m_position;
  std::function<double()> m_rate;
  wpi::json m_json;
  // std::unique_ptr<CANCoder> m_cancoder;
  std::unique_ptr<frc::Encoder> m_encoder;
  sysid::SysIdGeneralMechanismLogger m_logger;
};
