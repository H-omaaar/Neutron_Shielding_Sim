# Neutron_Shielding_Sim

A Geant4 simulation toolkit project to evaluate neutron shielding properties of various stainless steel alloys.


The primary goal is to evaluate the effectiveness of different stainless steel compositions in shielding neutron radiation, which is crucial in applications like nuclear reactors and radiation protection.

Key Features:
Simulation of Neutron Interaction with Materials:

The GEANT4 simulation models the interactions between neutrons and various stainless steel alloys. It focuses on how different compositions affect neutron absorption and scattering, which are critical for effective radiation shielding.
Detailed Particle Interactions:

GEANT4’s physics engine simulates neutron interactions with the materials, tracking energy deposition and neutron scattering within the alloys. This allows for a detailed analysis of the shielding effectiveness of each material.
Geometries and Materials:

    Stainless Steel Samples: The simulated geometry includes stainless steel samples modeled as box volumes. Each sample represents a different alloy composition with specific material properties.

    Neutron Source: The neutron source is simulated using a 241Am/Be source positioned at a fixed distance from the samples. The source emits neutrons with a defined energy distribution to mimic realistic radiation exposure scenarios.

    Detector: A simulated BF3 gaseous neutron detector is placed on the opposite side of the samples to measure the number of neutrons that pass through and interact with the detector.

    World Volume: A larger world volume encloses the entire setup, ensuring that all relevant interactions are captured within the simulation.

Physics Processes:

    Neutron Scattering and Absorption: GEANT4’s physics processes simulate neutron interactions with the stainless steel samples, including elastic scattering, inelastic scattering, and neutron capture.

    Energy Deposition and Shielding Effectiveness: The simulation calculates the energy deposited in the stainless steel samples and records the number of neutrons detected by the BF3 detector. This data is critical for assessing the effectiveness of each alloy in shielding neutron radiation.

Optimization of Shielding Materials:

By adjusting the alloy composition, sample geometry, and neutron source parameters, the project seeks to optimize the shielding properties of stainless steel alloys, improving their effectiveness in real-world applications.
Data Analysis and Visualization:

The energy deposition data, neutron counts, and other relevant metrics are recorded and outputted to a ROOT file. This enables detailed post-processing, analysis, and visualization, allowing researchers to assess and compare the shielding effectiveness of different alloys.
CMake Configuration (CMakeLists.txt):

    Configures the build system to locate and use the GEANT4 libraries.
    Sets up directories, compiler flags, and creates the executable NeutronShielding.

Main Program (main.cc):

    Initializes the run manager and defines the simulation’s scope.
    Sets up the detector construction, physics list, and primary generator actions.
    Configures the visualization manager and user interface, executing vis.mac for graphical representation of the simulation.

Visualization Macro (vis.mac):

    Defines the visualization environment, including camera viewpoints, zoom level, and the visualization of particle tracks.
    Configures the display of geometries and material boundaries, aiding in visual inspection of the simulation setup.

Detector Construction (DetectorConstruction.cc/hh):

    Constructs the world volume and defines the geometry of the stainless steel samples and detector.
    Assigns material properties to each volume, such as density and elemental composition, which are critical for accurate simulation of neutron interactions.
    Incorporates visualization attributes to distinguish between different materials and geometries during simulation.

Physics List (PhysicsList.cc/hh):

    Registers the relevant physics processes, including neutron interactions, scattering, and energy deposition.
    Ensures the simulation accurately models the behavior of neutrons as they traverse through the stainless steel alloys.

Primary Generator Action (PrimaryGeneratorAction.cc/hh):

    Defines a particle gun that simulates the emission of neutrons from the 241Am/Be source, specifying parameters such as energy, direction, and spatial distribution.

Run Action (RunAction.cc/hh) & Event Action (EventAction.cc/hh):

    Implement functions to manage actions at the beginning and end of each run and event, including the collection and storage of simulation data.
    Track cumulative energy deposition and other relevant metrics across multiple simulation runs.

Stepping Action (SteppingAction.cc/hh):

    Handles actions at each simulation step, such as tracking particle movement and interactions.
    Records energy deposition at each step within the stainless steel samples, contributing to the assessment of shielding effectiveness.

Sensitive Detector (SensitiveDetector.cc/hh):

    Processes hits within the defined sensitive volumes (e.g., stainless steel samples), recording neutron interactions, energy deposition, and secondary particle generation.
    Outputs detailed data on the interactions, which can be analyzed to assess the neutron shielding properties of the materials.

This comprehensive simulation provides valuable insights into the neutron shielding capabilities of different stainless steel alloys, aiding in the development of more effective radiation protection materials.
