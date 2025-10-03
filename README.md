# _eskDron

_eskDron is a small experimental database written in **C**.  
The main goal of this project is to practice and apply **good design patterns** while building a minimal query engine.

## Features (work in progress)
- Basic **garbage collector** to prevent memory leaks
- Readline-based command input
- Supported commands:
  - `RUN` → start the query engine
  - `EXIT` → exit gracefully and free memory

## Project Goals
- Deepen knowledge of the C programming language
- Experiment with design patterns suitable for systems programming
- Evolve step by step into a small database engine

## Build
```bash
make

./eskdron
