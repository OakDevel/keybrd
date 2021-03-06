Change Log for keybrd library
=============================
All notable changes to the keybrd project will be documented in this file.
This project adheres to [Semantic Versioning 2.0.0](http://semver.org/).

keybrd version 0.x.x is for initial development.
keybrd version 1.0.0 will be released when the public API is stable.

0.6.7 (2016-11-21)
------------------
* Enhancements
  * change #define SAMPLE_COUNT_MACRO to const SAMPLE_COUNT
  * add tutorial_7ab_mapping_layout_to_matix.md

0.6.6 (2016-11-16)
------------------
* Enhancements
  * rename #define SAMPLE_COUNT_MACRO to const SAMPLE_COUNT
  * change #include <keybrd library file> angle bracket to double quotes

0.6.5 (2016-11-16)
------------------
* Enhancements
  * add Code_LayerHoldShift and tutorials/keybrd_3g_shift_pairings/keybrd_3g_shift_pairings.ino

0.6.4 (2016-11-16)
------------------
* Enhancements
  * add Port_MCP23018
  * add Port_MCP23S18
  * add Port_ShiftRegs
  * add PortWriteInterface
  * add add LED_PortOpenDrain
  * add examples/IOE_PCA9655E_development/
  * rename strobeOn to activeState
  * move strobe logic from Port_*::write() to Scanner_IOE::scan()

* Backward incompatible changes
  * rename print_microseconds_per_scan() to printMicrosecondsPerScan()
  * rename print_scans_per_second() to printScansPerSecond()
  * rename Scanner_ShiftRegsPISOSingleRow to Scanner_ShiftRegsRead
  * rename Scanner_ShiftRegsPISOMultiRow to Scanner_ShiftRegsReadStrobed
  * in Scanner_ShiftRegsReadStrobed, reverse slaveSelect HIGH/LOW for SPI compatible tri-state
  * in Port_MCP23S17, add slaveSelect to constructor parameter
  * in Port_*, replace write() with writeHigh() and writeLow()

0.6.3 (2016-10-06)
------------------
* Enhancements
  * add comma to Scanner_IOE constructor

0.6.1 (2016-10-02)
------------------
* Enhancements
  * Redesign I/O expander Port classes
  * Scanner_ShiftRegsReadtrobed class can now read from multiple shift register chains

* Backward incompatible changes
  * Rename Scanner_ShiftRegsPISOSingleRow to Scanner_ShiftRegsRead
  * Rename Scanner_ShiftRegsPISOMultiRow to Scanner_ShiftRegsReadStrobed

0.6.0 (2016-09-28)
------------------
* Enhancements
  * Add Port_MCP23S17
  * Add Scanner_ShiftRegsPISOSingleRow and Scanner_ShiftRegsPISOMultiRow
  * Refine and update tutorials
  * Add tutorial_3cde_sublayer_keyboard.md
  * Add tutorial_4_connecting_split_keyboards.md
  * Add tutorial_4b_split_keyboard_with_shift_registers.md
  * Add tutorial_4c_split_keyboard_with_IOE.md
  * Add tutorial_5b_LED_on_IOE.md

* Backward incompatible changes
  * Move scanner instantiation from Row_* to sketch
  * Delete Row_uC and Row_IOE, and replace them with Row
  * Combine PortWrite_PCA9655E and PortRead_PCA9655E into Port_PCA9655E
  * Delete PortIOE, and move PortIOE variables to IOE port classes
  * Rename LED_PCA9655E to LED_Port
  * Rename Scanner_Port to Scanner_IOE
  * Rename Key_LayeredKeysArray to Key_LayeredKeys
  * Rename Code_Layered* to Key_Layered*
  * Rename object_*.h files to instantiations_*.h

0.5.0 (2016-07-22)
------------------
* Enhancements
  * Update tutorials
  * Add tutorials for LEDs, active high

* Backward incompatible changes
  * Add 32x32 matrix capability to Row_uC
  * Add STROBE_ON and STROBE_OFF to scanner class, to set active state
  * Rename classes

0.4.1 (2016-06-21)
------------------
* Enhancements
  * Add config_keybrd.h for size configurations.
  * Add RowScanner_SPI-ShiftRegisters for compact split keyboards up to 32 keys per matrix.
  * Add LED_PinNumber for controlling indicator lights by pin number.

0.4.0 (2016-06-10)
------------------
* Enhancements
  * Add Row_uC
  * Add Row_IOE
  * Add RowScannerInterface
  * Add RowScanner_PinsArray
  * Add RowScanner_PinsBitwise
  * Add DebouncerInterface
  * Add Debouncer_4Samples

* Backward incompatible changes
  * Change uC from scanning port arrays to scanning Arduino pins, thereby adding support for:
    * Arduino boards, Teensy 3, and Teensy LC microcontrollers
    * up to 31x31 matrix capability
  * Change IOE from scanning port arrays to scanning single ports.
  * Move scanner and debouncer into their own classes.
  * Remove Port arrays

0.3.1 (2016-06-02)
------------------
* Enhancements
  * Add RowBase class
  * Add Row::debounce()

0.3.0 (2016-05-09)
------------------
* Enhancements
  * Add Tutorials

* Backward incompatible changes
  * Restructure the project directory to conform to Arduino library manager specifications
    * Moved keybrd_DH library extension (for DodoHand) to its own repository
    * Moved sketches to examples directory
  * Replace Key_Layered dependency on LayerManager with LayerState class

0.2.0 (2016-02-25)
------------------
* Enhancements
  * Add Port classes for microcontrollers and I/O expanders
  * Add DH_2565 sketch with DataHand layout
  * Add Sticky mouse button (SMB) for DataHand layout
  * Add Supporting documentation

0.1.0 (2015-02-10)
------------------
* Enhancements
  * The library runs on Teensy 2.0 microcontroller and MCP23018 I/O expander
  * Limited to 8x8 matrix, which is enough for compact or split keyboards
  * Add first draft of supporting documentation
  * Add example keybrd sketches for single-layer, multi-layer, and DataHand layer schemes
