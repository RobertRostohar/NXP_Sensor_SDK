# Repository contents

This document explains in detail the repository contents, how it was derived from NXP SDKs and extended with Open-CMSIS-Pack.

## NXP SDKs

Repository contents was derived from the following generated NXP SDKs:
 - FRDM-K22F-A8974 SDK 2.12.0
   - Toolchain: MDK-ARM
   - Board+Shield: FRDM-K22F-A8974
   - Middleware: ISSDK, FreeMASTER, SDMMC
 - FRDM-K22F-AGMP03 SDK 2.11.0
   - Toolchain: MDK-ARM
   - Board+Shield: FRDM-K22F-AGMP03
   - Middleware: ISSDK, FreeMASTER, SDMMC
 - LPCXPRESSO54114-AGMP03 SDK 2.9.0
   - Toolchain: MDK-ARM
   - Board+Shield: LPCXPRESSO54114-AGMP03
   - Middleware: ISSDK, FreeMASTER

### NXP SDKs contents

Directory     | Description
--------------|-------------------------------------------------------------
`boards`      | Boards support + ISSDK sensor examples for board with shield
`CMSIS`       | CMSIS-Core, CMSIS-... - same as in ARM::CMSIS pack
`components`  | Device SDK - same as in NXP::`<device>_DFP` pack
`devices`     | Device support - same as in NXP::`<device>_DFP` pack
`docs`        | Documentation
`middleware`  | Middleware: FreeMASTER, ISSDK, ...
`tools`       | Tools (cmake)

## Restructuring SDKs

1. Updating sensor examples to use CMSIS software packs

   ISSDK sensor examples contain project files for the MDK-ARM toolchain. 
   The projects references only files within the SDK (not using any external components or packs).

   The projects are updated to use components from ARM::CMSIS and `<device>_DFP` pack:
    - Group of directly referenced files that represent a component in a pack, are replaced by that component.
    - Include path to relative directories which contain files replaced by components, are removed.
    - Component default configuration files are replaced by actual configuration files.

   >Note: no other NXP code from SDKs has been modified at this point (except the MDK-ARM project files).

2. Removing unused files

   The following directories are removed:
    - `boards/<board>` (not used)
    - `boards/<board>_<shield>/project_template` (not used)
    - `boards/<board>_<shield>/issdk_examples/sensors/hostdemo` (example not updated)
    - `CMSIS`, `components` and `devices` (referenced from packs)
    - `docs` and `tools` (not used - decreases repository size)

   The only top-level directories left are:
    - `boards/<board>_<shield>/issdk_examples/sensors`: ISSDK sensor examples
    - `middleware`: FreeMASTER, ISSDK

3. Converting MDK-ARM projects to CMSIS Project Manager format (YML files)

   MDK-ARM project files (`*.uv*`) are replaced by CMSIS Project Manager YML files:
    - `<sensor_project>.csolution.yml`:
      - `packs`: lists used CMSIS software packs (`CMSIS` and `<device>_DFP`)
      - `target-types`: `<board>_<shield>` target type
      - `build-types`: `debug` and `release` build types (including defines, compiler and linker settings)
      - `projects`: `<sensor_project>.cproject.yml` sensor project file
    - `<sensor_project>.cproject.yml`
      - `define`: additional project specific defines
      - `components`: used components from packs
      - `groups`: groups of remaining used files
   >Note: Contents of the above listed items is derived from MDK-ARM project files.

4. Introducing Board and Shield layers

   The project described in `<sensor_project>.cproject.yml` is split into:
    - application with middleware (hardware agnostic)
    - board specifics - moved to board layer into top-level directory `boards/<board>` with layer description in `<board>/clayer.yml`
      >Note: `CMSIS_board_header` defines the board specific header
    - shields specific - moved to shield layer into top-level directory `shields/<shield>` with layer description in `<shield>.clayer.yml`
      >Note: `CMSIS_shield_header` defines the shield specific header

   >Note: `issdk_hal.h` is updated to be hardware agnostic by using `CMSIS_board_header` and `CMSIS_shield_header` definitions 
   (moved to top-level directory `middleware/issdk/hal`).

   The solution described in `<sensor_project>.csolution.yml` is updated:
    - `packs`: board specific packs are moved to board layer

   The board layer is extended:
    - executes hardware initialization
    - executes applications by calling `app_main`
    - provides STDIO retargeting

   The application is updated:
    - `main` renamed to `app_main`
    - hardware initialization removed from `app_main`
    - using STDIO for PRITNF and GETCHAR

5. Solution with multiple projects

   Solution YML file `<sensor_name>.csolution.yml` is introduced for each sensor containing all projects for that sensor 
   (replaces multiple solution YML files previously defined for each project). It is also made compiler agnostic by moving 
   compiler specific options to new default YML file `<sensor_name>.cdefault.yml` containing compiler specific options.

6. Adding connections

   The `connections` node is added to the project and layer YML files. 
   The `connections` node contains meta-data that describe the compatibility of project and layers. 
   It lists functionality (drivers, pins, and other software or hardware resources) that is consumed (required) or provided.

7. Agnostic sensor defines

   Sensor examples are updated to use sensor specific defines (interface, driver, pins, ...) which are not shield or board specific 
   (could be provided by a custom target layer). Required defines are provided by the respective shield and board layer.

8. Generic GPIO API

   NXP GPIO API (not completely hardware agnostic) is replaced by generic GPIO API. Driver implementations and examples are updated accordingly.

9. Moving sensor examples 

   ISSDK sensor examples are moved from `boards/<board>_<shield>/issdk_examples/sensors` to top-level directory `examples/issdk/sensors`.

## Combining SDKs

Restructured SDKs (described in previous sections) are merged together into a single SDK featured in this repository.

### Detailed repository contents
Directory / File                                    | Description
----------------------------------------------------|----------------------------------------------------
[boards](./boards)                                  | Board layers for various evaluation boards
&emsp;`<board>`                                     | Board specific layer
&emsp;&emsp;`<board>.clayer.yml`                    | Layer description
&emsp;&emsp;`<board_id>.h`                          | Board header
&emsp;&emsp;`<board_id>.c`                          | Board module
&emsp;&emsp;`RTE`                                   | RTE directory (configuration for components)
[examples/issdk/sensors](./examples/issdk/sensors/) | ISSDK examples for various sensors
&emsp;`<sensor_name>`                               | Examples for specific sensor
&emsp;&emsp;`<sensor_name>.csolution.yml`           | Examples solution file (multi-project)
&emsp;&emsp;`<sensor_name>.cdefault.yml`            | Examples default settings (multi-project)
&emsp;&emsp;`<sensor_example>`                      | Specific sensor example
&emsp;&emsp;&emsp;`<sensor_project>.cproject.yml`   | Example project file
&emsp;&emsp;&emsp;`<sensor_project>.c`              | Example main module
&emsp;&emsp;&emsp;`freemaster_cfg.h`                | FreeMASTER configuration (only for FreeMaster Demo)
[middleware](./middleware)                          | Middleware: FreeMASTER, ISSDK, SDMMC (not used)
[shields](./shields)                                | Shield layers for various Arduino sensor shields
&emsp;`<shield>`                                    | Shield specific files
&emsp;&emsp;`<shield>.clayer.yml`                   | Layer description
&emsp;&emsp;`<shield_id>.h`                         | Shield header
