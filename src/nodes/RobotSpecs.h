#ifndef __RobotSpecs_H_
#define __RobotSpecs_H_

#define WHEEL_RADIUS 0.05

// Distances entre les roues
#define WTOW_LENGHT 0.20
#define WTO_WIDTH 0.22

// Nombre d'événements que l'on peut compter par tour de moteur
#define ENCODERS_COUNTABLE_EVENTS_MOTOR_SHAFT 28

// Nombre d'événements que l'on peut compter par tour de roue
#define ENCODERS_COUNTABLE_EVENTS_OUTPUT_SHAFT 1993.6

// Vitesse de rotation du moteur/de la roue
#define MOTOR_OUTPUT_SHAFT_MAX_RPM 84

#define MOTOR_GEAR_RATIO 71.2

// Vitesse maximum du robot
#define MAX_SPEED 0.44 // m/s


// Coefficients des roues mecanums pour les translations 
#define MECANUM_Y 1.058361968
#define MECANUM_X 0.9887535903

#endif