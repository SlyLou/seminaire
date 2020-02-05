# **Consignes TP séminaire ROS** *(jeudi 11 février 2020)*

## Configuration requise :

- Ubuntu 16.04 LTS
- ROS Kinetic
- Catkin tools *(préférable)*
- Visual Studio Code *(préférable)*

--------------------

## I. Création du modèle URDF
Utilisez les parties dans le dossier meshes pour créer votre digital twin.

### **1)** Placez chaque composants à leur place :

- **Roues :**

    link : xyz="0 0 0" rpy="0 0 0"

    joint : xyz="+-0.2 +-0.216235 -0.06" rpy="0 0 0"

- **Support plateau :** 

    link : xyz="-0.015 -0.19 -0.1" rpy="1.5707963267949 0 1.5707963267949"

    joint : xyz="-0.3 0 0" rpy="0 0 0"

- **Plateau :**

    link : xyz="-0.33 -0.25 -0.1" rpy="1.5707963267949 0 1.5707963267949" 
    
    joint : xyz="-0.32 0 0.13" rpy="0 0 0" 



### **2)** Ajoutez au moins 1 élément de tunning.

------------------------------

## II. Faire bouger le Digital Twin

### **1)** Créer le node qui calcule l'odométrie du robot et fait bouger le Digital twin

Souscrire à sensor_encs le topic des encodeurs (attention on utilise un message custom)

S'inspirer des papier pour les équations : 
- équations de base https://research.ijcaonline.org/volume113/number3/pxc3901586.pdf 
        
- équations avec prise en compte d'un "rayon variable" https://www.researchgate.net/publication/326283867_Influence_of_mecanum_wheels_construction_on_accuracy_of_the_omnidirectional_platform_navigation_on_exanple_of_KUKA_youBot_robot


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