# CustPorts: Customer Portfolio Management

## Introduction

CustPorts is a comprehensive customer portfolio management system designed in C++ for tracking and analyzing customer portfolios, including stock and bond accounts. Leveraging a data-driven approach, CustPorts enables users to create, manage, and project the future value of customer portfolios, providing insights into investment strategies and growth opportunities.

## Features

- **Customer and Account Management:** Easily add new customer profiles and their corresponding account details, including account ID, balance, growth rate, and compounding frequency.
- **Data Input and Output:** Supports reading customer and account data from `.dat` files and writing modified data back to files, facilitating persistent storage.
- **Portfolio Projection:** Calculate future values of portfolios based on current account balances, growth rates, and specified projection periods.
- **Interactive Menu:** A user-friendly interactive menu allows for seamless navigation and management of customer portfolios.
- **Comprehensive Reporting:** Generate detailed reports displaying customer information, account details, and future value projections, both on-screen and written to text files.

## Getting Started

### Prerequisites

- GNU g++ compiler
- Basic Linux command line knowledge

### Installation and Compilation

1. Clone the repository or download the source files to your local machine.
2. Navigate to the project directory containing `cust_ports.cpp`, `cust_ports.h`, and `Makefile`.
3. Compile the project using the provided Makefile:
   ```bash
   make
   ```
   This will generate an executable named `cust_ports`.

### Running CustPorts

Execute the program from the terminal:
```bash
./cust_ports
```
You can also use command-line arguments to perform specific actions directly:
- `-h` to display the help menu.
- `-i` to enter interactive mode.
- `-f [filename]` to specify an input data file.
- Additional arguments for reporting and data output can be found in the help menu (`-h`).

## Usage

Upon running, CustPorts offers an interactive menu with options to manage customer portfolios, including adding new portfolios, displaying customer information, projecting portfolio values, and generating reports.


## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

- **Christopher Reyes**

CustPorts is designed with flexibility and user-friendliness in mind, providing a powerful tool for financial analysis and customer portfolio management.
