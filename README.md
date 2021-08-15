# Vacuum-Cleaner-TDD-internship
 Implementing the speed control module in vacuum cleaner device using Test Driven Development(TDD) technique.

# Details
 We have a vacuum cleaner device which consists of 3 main modules:
 * Switches Driver: It's responsible for interacting with push buttons to increase/decrease speed and on/off the device then it passed the data(pressed switch and the duration) to __Speed Controller__ module.
 * Speed Controller: This is the module we are going to implement. It's responsible for controlleng the speed of the motor according to the passed data from __Switches Driver__ module. It controlls the __motor angle__ according to the passed data and passes it to __Motor Driver__ module.
 * Motor Driver: It's responsible for controlling the speed of the motor according to motor angle parameter which is cotrolled by __Speed Control__ module.

# Requirements
 All needed requirements are found [here](https://github.com/AhmedWageh97/Vacuum-Cleaner-TDD-internship/blob/main/TDD%20Internship.pdf)
