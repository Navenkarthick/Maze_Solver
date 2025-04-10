# 🧭 Maze Solving Robot using Arduino Nano

This project is a maze-solving robot that uses the **Algorithm** to intelligently navigate a 16x16 maze. The robot is powered by an **Arduino Nano**, driven by the **SparkFun TB6612FNG motor driver**, and equipped with **5 IR distance sensors** for wall detection.

---

## 🤖 Hardware Components

- Arduino Nano
- SparkFun TB6612FNG Motor Driver
- DC Gear Motors (2x)
- IR Distance Sensors (5x)
  - Front
  - Left
  - Right
  - Front Left
  - Front Right
- Custom 3D-Printed Chassis
- Custom PCB for motor and sensor wiring
- Castor Wheel
- Battery Pack
- Maze Arena (16x16 cells)

---

## 🛠️ Wiring and Setup

### Motor Driver (TB6612FNG) ➡ Arduino Nano

| TB6612FNG Pin | Arduino Pin |
|---------------|-------------|
| AIN1          | 2           |
| AIN2          | 3           |
| PWMA          | 5 (PWM)     |
| BIN1          | 7           |
| BIN2          | 8           |
| PWMB          | 6 (PWM)     |
| STBY          | 4           |

### IR Sensors ➡ Arduino Nano

| Sensor         | Arduino Analog Pin |
|----------------|--------------------|
| Front          | A0                 |
| Left           | A1                 |
| Right          | A2                 |
| Front Left     | A3                 |
| Front Right    | A4                 |

---

## 💻 How to Use

1. Assemble the robot chassis and mount all components.
2. Connect all components as per the wiring tables above.
3. Upload the Arduino code to the Nano.
4. Place the robot at the maze's start (usually bottom-left) facing North.
5. Power it on — the robot will begin exploring and navigating toward the goal.

---

## 🖼️ 3D Model of the Robot Chassis

- [📘 Robot 3D CAD (PDF)](https://github.com/Navenkarthick/Maze_Solver/blob/c49e77326b51e78c56ad9ce02cd186ab881e340a/CAD%20File.pdf)


## 🛠️ PCB Layout

### Top View && Bottom View

- [📘 Robot PCB (PDF)](https://github.com/Navenkarthick/Maze_Solver/blob/c49e77326b51e78c56ad9ce02cd186ab881e340a/PCB_3D.pdf)

### Schematic

- [📘 Robot Schematic (PDF)](https://github.com/Navenkarthick/Maze_Solver/blob/c49e77326b51e78c56ad9ce02cd186ab881e340a/SCHEMATIC.pdf)

## 🚀 Future Improvements

- Implement PID control for precise movement and turning
- Optimize return journey by storing shortest path
- Use ToF/LiDAR sensors for higher range precision


## **📜 License**  
This project is **open-source** under the [MIT License](LICENSE).  


## **📞 Contact**  
📧 Email: navenkarthickm@gmail.com
🚀 GitHub: [Navenkarthick](https://github.com/Navenkarthick)  


