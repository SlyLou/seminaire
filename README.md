# **Consignes TP séminaire ROS** *(mardi 11 février 2020)*

## Configuration requise :

- Ubuntu 16.04 LTS
- ROS Kinetic
- Catkin tools *(préférable)*
- Visual Studio Code *(préférable)*

--------------------

## I. Création du modèle URDF
Utilisez les parties dans le dossier meshes pour créer votre digital twin.

### **1)** Placez chaque composants à leur place :
- **Empreinte au sol :**

    link (que inertial pas de visual) : xyz="0 0 0" rpy="0 0 0"
    
    joint : xyz="0 0 0.1" rpy="0 0 0" / parent link="base_footprint" / child link="base_link"
        
- **Base :**

    link : xyz="-0.15 0.025 0.0" rpy="0 0 1.57079"
    
- **Roues :**

    link : xyz="0 0 0" rpy="0 0 0"

    joint : xyz="+-0.2 +-0.216235 -0.06" rpy="0 0 0" / parent link="base_link" / child link="wheel_XX" / limit effort="9.1201845" velocity="8.79645942"

- **Support plateau :** 

    link : xyz="-0.015 -0.19 -0.1" rpy="1.5707963267949 0 1.5707963267949"

    joint : xyz="-0.3 0 0" rpy="0 0 0" / parent link="base_link" / child link="support"

- **Plateau :**

    link : xyz="-0.33 -0.25 -0.1" rpy="1.5707963267949 0 1.5707963267949" 
    
    joint : xyz="-0.32 0 0.13" rpy="0 0 0" / parent link="base_link" / child link="plate" / limit effort="147" lower="0.0" upper="0.386" velocity="0.039"



### **2)** Ajoutez au moins 1 élément de tunning.

------------------------------

## II. Création de nodes

### **1)** Créer le node de commande par manette 

- Souscrire au topic *joy* pour récupérer les données de la manette.
- Transformer ces données en commandes de vitesse pour le robot et son plateau.
- Publier respectivement sur les topics cmd_vel et cmd_vel_winch.


### **2)** Créer le node pour faire bouger le plateau du Digital twin

Souscrire à winchHeight et publier la donnée dans plate_joint_states


----------------------

## Tips :

Si vous utilisez Visual Studio Code il existe une extension Preview URDF trés pratique pour la visualisation du robot en live.

## Commandes utiles :

Compiler les programmes du package

    cd catkin_ws
    catkin build
    source devel/setup.bash

Lancer un launch

    roslaunch seminaire <nom du launch>

Lancer un node du package seminaire

    rosrun seminaire <nom du node>

Ecouter un topic

    rostopic echo <nom du topic>

*Pour d'autres infos on reste à votre disposition :)*
