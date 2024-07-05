# NXP Sensor SDK using Open-CMSIS-Pack

Proof of concept for NXP Sensor SDK using Open-CMSIS-Pack csolution - CMSIS Project Manager.

Demonstrates a scalable solution for sensor examples using multiple boards and shields.

Projects are using software layers with specified standard interfaces.

Examples have been taken from NXP  ISSDK pack (slightly modified) and extended with CMSIS Project Manager YML files.

## Repository top-level structure

Directory                   | Description
----------------------------|-------------------------------------------------
[examples](./examples)      | ISSDK examples for various sensors
[packs](./packs)            | NXP Packs: ISSDK and various DFPs and BSPs

Details about the packs are described in [packs/README.md](./packs/README.md).

## ISSDK Sensor examples

IoT Sensing SDK (ISSDK) examples for various sensors are located in directory [examples/issdk/sensors](./examples/issdk/sensors).

Projects are described with CMSIS Project Manager input files (YML format) and are using CMSIS software packs (Open-CMSIS-Pack format).

The projects consists of:
 - application with middleware
 - board software layer
 - shield software layer

### Software Prerequisites
 - Visual Studio Code with Arm Keil Studio Pack extension
 - CMSIS-Toolbox (manged though vcpkg)
 - Arm Compiler for Embedded (managed through vcpkg)
 - CMSIS packs provided in this repository mapped as software packs (not published via the CMSIS-Pack index):
   - [ISSDK](packs/ISSDK/) - IoT Sensing SDK
   - [EVK-MIMXRT1060_BSP](packs/EVK-MIMXRT1060_BSP/) when using NXP EVK-MIMXRT1060 board
   - [MIMXRT1062_DFP](packs/MIMXRT1062_DFP/) when using NXP EVK-MIMXRT1060 board
   - [FRDM-K22F_BSP](packs/FRDM-K22F_BSP/) when using NXP FRDM-K22F board
   - [MK22F51212_DFP](packs/MK22F51212_DFP/) when using NXP FRDM-K22F board
   - [LPCXpresso55S69_BSP](packs/LPCXpresso55S69_BSP/) when using NXP LPCXpresso55S69 board
   - [LPC55S69_DFP](packs/LPC55S69_DFP/) when using NXP LPCXpresso55S69 board
   - [LPCXpresso54114_BSP](packs/LPCXpresso54114_BSP/) when using NXP LPCXpresso54114 board
   - [LPC54114_DFP](packs/LPC54114_DFP/) when using NXP LPCXpresso54114 board
  >Packs are installed using `cpackget add <pack_path>/<pack_vendor>.<pack_name>.pdsc` 

### Configuring examples for specific target

Examples have already been configured for various targets with compatible board and shield layers.

Configuring a specific target:
 - Open `<sensor_name>.csolution.yml`
   - Add target under `target-types:`
     - Specify target name `type: <target_name>`
     - Specify board name `board: <board_name>` or device name `device: <device_name>`
 - Detect compatible board and shield layers by running  
   `cbuild setup <sensor_name>.csolution.yml --context-set --context <project>.<build_type>+<target_type>`
  - Open `<sensor_name>.cbuild-idx.yml` and examine detected `target-configurations` and their `Board-Layer` and `Shield-Layer` variables.
  - Copy desired `Board-Layer` and `Shield-Layer` variables to `<sensor_name>.csolution.yml` under `target-types: variables:`.

### Building the examples

1. Go to directory `examples/issdk/sensors/<sensor_name>`

2. Activate environment `vcpkg-configuration.json`

3. Activate solution and Build the selected context(s) using `Arm CMSIS Solution` extension within Visual Studio Code

   Alternatively use the `cbuild` command line tool to create the executable for specified project, build and target type

   ```
   cbuild <sensor_name>.csolution.yml --packs --update-rte --context <project>.<build_type>+<target_type>
   ```
