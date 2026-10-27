# Capstone

Command-line calculator for linear algebra. Matrices, vectors, and row operations live here.

## Setup

From this folder:

```
python3 -m venv .venv
source .venv/bin/activate
pip install -e ".[dev]"
pytest
```

On Ubuntu, `python3 -m venv` needs the `python3.12-venv` package the first time.

`pytest` should report one passing test. That test only checks that the package imports.
