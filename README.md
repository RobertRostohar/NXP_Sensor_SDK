# NXP Sensor SDK using Open-CMSIS-Pack
Proof of concept for NXP Sensor SDK using Open-CMSIS-Pack csolution - CMSIS Project Manager.

Demonstrates a scalable solution for sensor examples using multiple boards and shields.

Projects are using software layers with specified standard interfaces.


## Repository top-level structure

Directory                   | Description
----------------------------|-------------------------------------------------
[packs](./packs)            | NXP Packs: various DFPs and BSPs

Details about the packs are described in [packs/README.md](./packs/README.md).

## ISSDK Sensor examples

IoT Sensing SDK (ISSDK) examples for various sensors are available on [Open-CMSIS-Pack/Sensor-SDK-Example](https://github.com/Open-CMSIS-Pack/Sensor-SDK-Example) GitHub repository.

Projects are described with CMSIS Project Manager input files (YML format) and are using CMSIS software packs (Open-CMSIS-Pack format).

The projects consist of:
 - application with middleware
 - board software layer
 - shield software layer

### Software Prerequisites
 - Visual Studio Code with Arm Keil Studio Pack extension
 - CMSIS-Toolbox (manged though vcpkg)
 - Arm Compiler for Embedded (managed through vcpkg)
 - CMSIS packs mapped as software packs (not published via the CMSIS-Pack index):
   - [ISSDK](https://github.com/Open-CMSIS-Pack/Sensor-SDK-Example) - Sensor SDK Example
   - [EVK-MIMXRT1060_BSP](packs/EVK-MIMXRT1060_BSP/) when using NXP EVK-MIMXRT1060 board
   - [MIMXRT1062_DFP](packs/MIMXRT1062_DFP/) when using NXP EVK-MIMXRT1060 board
   - [FRDM-K22F_BSP](packs/FRDM-K22F_BSP/) when using NXP FRDM-K22F board
   - [MK22F51212_DFP](packs/MK22F51212_DFP/) when using NXP FRDM-K22F board
   - [LPCXpresso55S69_BSP](packs/LPCXpresso55S69_BSP/) when using NXP LPCXpresso55S69 board
   - [LPC55S69_DFP](packs/LPC55S69_DFP/) when using NXP LPCXpresso55S69 board
   - [LPCXpresso54114_BSP](packs/LPCXpresso54114_BSP/) when using NXP LPCXpresso54114 board
   - [LPC54114_DFP](packs/LPC54114_DFP/) when using NXP LPCXpresso54114 board
  >Packs are installed using `cpackget add <pack_path>/<pack_vendor>.<pack_name>.pdsc`

## Compatible Sensor SDK Examples and board/shield layers

### fxas21002 sensor examples
| Project           | Board           | Shield        |
|-------------------|-----------------|---------------|
| fifo              | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, agm01 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, agm01 |
| interrupt         | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, agm01 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03        |
| poll              | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, agm01 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, agm01 |
| poll_spi          | FRDM-K22F       | agmp03, agm01 |
|                   | LPCXpresso55S69 | agmp03, agm01 |


### fxls8962 sensor examples
| Project           | Board           | Shield        |
|-------------------|-----------------|---------------|
| freefall          | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03        |
|                   | LPCXpresso54114 | agmp03        |
| interrupt         | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03        |
|                   | LPCXpresso54114 | agmp03        |
| normal            | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03        |
|                   | LPCXpresso54114 | agmp03        |
| normal_spi        | FRDM-K22F       | agmp03        |
|                   | LPCXpresso54114 | agmp03        |

### fxls8974cf sensor examples
| Project           | Board           | Shield        |
|-------------------|-----------------|---------------|
| interrupt         | EVK-MIMXRT1060  | a8974         |
|                   | FRDM-K22F       | a8974         |
|                   | LPCXpresso54114 | a8974         |
|                   | LPCXpresso55S69 | a8974         |
|                   | B-U585I-IOT02A  | a8974         |
| motion_wakeup     | FRDM-K22F       | a8974         |
|                   | LPCXpresso55S69 | a8974         |
|                   | B-U585I-IOT02A  | a8974         |
| poll              | EVK-MIMXRT1060  | a8974         |
|                   | FRDM-K22F       | a8974         |
|                   | LPCXpresso54114 | a8974         |
|                   | LPCXpresso55S69 | a8974         |
|                   | B-U585I-IOT02A  | a8974         |
| spi               | FRDM-K22F       | a8974         |
|                   | LPCXpresso54114 | a8974         |
|                   | LPCXpresso55S69 | a8974         |
|                   | B-U585I-IOT02A  | a8974         |

### fxos8700 sensor examples
| Project           | Board           | Shield        |
|-------------------|-----------------|---------------|
| fifo              | EVK-MIMXRT1060  | /, agm01      |
|                   | FRDM-K22F       | /, agm01      |
|                   | LPCXpresso54114 | agm01         |
|                   | LPCXpresso55S69 | agm01         |
| interrupt         | EVK-MIMXRT1060  | /, agm01      |
|                   | FRDM-K22F       | /, agm01      |
|                   | LPCXpresso54114 | agm01         |
|                   | LPCXpresso55S69 | agm01         |
| poll              | EVK-MIMXRT1060  | /, agm01      |
|                   | FRDM-K22F       | /, agm01      |
|                   | LPCXpresso54114 | agm01         |
|                   | LPCXpresso55S69 | agm01         |
| poll_spi          | FRDM-K22F       | /, agm01      |
|                   | LPCXpresso54114 | agm01         |
|                   | LPCXpresso55S69 | agm01         |
>Board has an on-board compatible sensor: /

### mag3110 sensor examples
| Project           | Board           | Shield        |
|-------------------|-----------------|---------------|
| normal            | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03        |
|                   | LPCXpresso54114 | agmp03        |
| normal_interrupt  | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03        |
|                   | LPCXpresso54114 | agmp03        |
| oneshot           | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03        |
|                   | LPCXpresso54114 | agmp03        |

### mpl3115 sensor examples
| Project           | Board           | Shield        |
|-------------------|-----------------|---------------|
| altitude          | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, p3115 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, p3115 |
| fifo              | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, p3115 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, p3115 |
| fifo_interrupt    | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, p3115 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, p3115 |
| normal            | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, p3115 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, p3115 |
| normal_interrupt  | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, p3115 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, p3115 |
| oneshot           | EVK-MIMXRT1060  | agmp03        |
|                   | FRDM-K22F       | agmp03, p3115 |
|                   | LPCXpresso54114 | agmp03        |
|                   | LPCXpresso55S69 | agmp03, p3115 |
