# FopMath

FopMath is a small C++ math toolkit exposed to Python through pybind11. It installs a
native extension module named `FopMath` that you can import directly in Python.

## Install

```bash
pip install FopMath
```

Prebuilt wheels are provided for supported platforms, so no C++ compiler is needed for
normal `pip install` usage.

## Usage

```python
import FopMath

FopMath.Square_root(16)
FopMath.quadratic_formula(1, -5, 6)
FopMath.point_distance(2, 6, 1, 8)
FopMath.triangle_area(2, 3, 3)
FopMath.standart_diviation(0.61, 5000)
```

## Functions

- quadratic_formula(ax, bx, c)
- Square_root(root)
- is_prime(prime)
- factorial(factorial)
- circle_area(radius)
- circle_circumference(radius)
- triangle_area(a, b, c)
- point_distance(x1, x2, y1, y2)
- standart_diviation(p, n)

## Build from source (optional)

```bash
python -m pip install --upgrade pip build
python -m build
pip install dist/*.whl
```

Building from source requires a C++ compiler and Python development headers.
