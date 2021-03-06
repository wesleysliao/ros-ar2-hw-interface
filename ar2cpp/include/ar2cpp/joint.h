#ifndef AR2CPP__JOINT_H
#define AR2CPP__JOINT_H

#include <sstream>

#define ACTUATOR_TYPE_NONE -1
#define ACTUATOR_TYPE_MOTOR 0
#define ACTUATOR_TYPE_SERVO 1
#define ACTUATOR_TYPE_STEPPER 2

namespace ar2cpp
{
	class Joint
	{
		private:
			uint8_t _motorId = 0;
			uint8_t _actuatorType = 0;
			uint8_t _minServoValue = 0;
			uint8_t _maxServoValue = 75;
			double _previousEffort;
			double _filterAngle(double angle);
			int _angleReads = 0;
			static const int _filterPrevious = 3;
			double _previousAngles[_filterPrevious];
		public:
			std::string name;
			Joint();
			Joint(uint8_t motorId);
			~Joint();
			double sensorResolution = 1024;
			double angleOffset = 0;
			double readRatio = 1;
			uint8_t getMotorId();
			void setMotorId(uint8_t motorId);
			void setActuatorType(uint8_t actuatorType);
			void setServoLimits(uint8_t minValue, uint8_t maxValue);
			int getActuatorType();
			double getPreviousEffort();
			void actuate(double effort, uint8_t duration);
			double readAngle();
	};
}

#endif