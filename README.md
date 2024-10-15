# Assembler for the Simple CPU emulator

This project provides a simple assembly language assembler that converts a specified assembly language syntax into binary format. The assembler reads instructions from a `.asm` file and outputs the corresponding binary data into a `.b` file.

## Features

- Supports basic arithmetic and data movement instructions:
  - `LDR` (Load Register)
  - `ADD` (Addition)
  - `SUB` (Subtraction)
  - `MUL` (Multiplication)
  - `DIV` (Division)
  - `RST` (Reset)
  - `HLT` (Halt)
  - `LDM` (Load Immediate)
  - `STM` (Store Memory)
  - `NOP` (No Operation)
  - `INC` (Increment)
  - `DEC` (Decrement)
  - `MOV` (Move)
- Processes operands in the format of registers (e.g., `reg0`, `reg1`) and memory locations (e.g., `mem0`, `mem1`).
- Outputs binary instructions to a file for use in simulated or real hardware.

## Requirements

- C compiler (e.g., `gcc`)
- Standard C library

## How to Build

1. Clone the repository:
   ```bash
   git clone https://github.com/CppHacker-dev/Simple-CPU-Assembler.git
   cd assembly-to-binary-converter
   ```

2. Compile the code:
   ```bash
   gcc -o assembler assembler.c
   ```

## Usage

1. Create an assembly source file (e.g., `asm.asm`) with your assembly instructions.
2. Run the assembler:
   ```bash
   ./assembler
   ```
3. The output binary will be written to `asm.b`.

### Example Assembly File (asm.asm)

```asm
LDR reg0, mem0
ADD reg1, reg0
SUB reg2, reg1
MUL reg3, reg2
MOV reg4, reg3
HLT
```

## Error Handling

The assembler will print an error message for any unknown instruction encountered in the assembly file. Ensure all instructions are valid as per the supported set.

## License

This project is licensed under the GNU General Public License (GPL). See the `LICENSE` file for details.

## Contributing

Feel free to submit issues or pull requests for any improvements, bug fixes, or additional features.

---

# LICENSE

GNU GENERAL PUBLIC LICENSE
Version 3, 29 June 2007

Copyright (C) CppHacker-dev
Everyone is permitted to copy and distribute verbatim copies of this license document

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
