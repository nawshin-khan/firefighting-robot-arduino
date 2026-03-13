# firefighting-robot-arduino
A group project for an autonomous car that detects and reacts to fire using Arduino and C++.
### 🧠 Logic Breakdown
The robot operates on a simple feedback loop:
1. **Detection:** It continuously reads three IR flame sensors (Left, Right, Forward).
2. **Movement:** - If the **Forward** sensor is triggered (`LOW`), it moves both motors.
   - If the **Left** or **Right** sensors are triggered, it turns by powering only one motor.
3. **Action:** Once the robot is close enough to the fire (Forward trigger), the `fire` boolean is set to `true`.
4. **Suppression:** The `put_off_fire()` function stops the motors, activates the water pump, and sweeps the servo motor (nozzle) from 50 to 130 degrees to cover the fire area.
