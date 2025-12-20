# _eskDron - BDD

## Introduction

_eskDron is a lightweight, local database engine written entirely in C for performance.  
The project is based on a SQL-like query language with low-level execution control in C.

For now, the database can only be controlled using scripts. In the future, a dedicated library named **lib_eskdron** is planned to expose database features.  
This library will be developed if _eskDron is used in my future C projects.

A stable beta release is planned for **07/07/2026**.

## Features (overview)

- Custom SQL-like query language (ESK_QUERY)
- Script execution workflow for batch operations
- Fully written in C
- Designed for high performance and memory efficiency
- Modular and extensible architecture

## Getting Started

### Prerequisites

- GCC or Clang compiler  
- Make build system  
- Linux/Unix environment (Windows WSL supported)  

### Installation

```bash
# Clone the repository
git clone https://github.com/IlyasFounas/_eskDron.git
cd _eskDron

# Build the project
make

# Run the bdd engine
./eskdron

# To run a script (from inside the engine)
run

# To exit the bdd engine
exit
