# Publishing FopMath to PyPI

This guide shows how to build and publish prebuilt wheels so users can install with
`pip install FopMath` without a compiler.

## Prerequisites

- A PyPI account: https://pypi.org/account/register/
- Build tools:
  - `python -m pip install --upgrade pip build twine`
- (Recommended) Build a wheel per platform you want to support.

## 1) Build distributions locally

```bash
python -m build
```

This creates:
- `dist/*.whl` (wheel)
- `dist/*.tar.gz` (sdist)

## 2) Upload to TestPyPI (safe test)

```bash
twine upload --repository testpypi dist/*
```

Install from TestPyPI:

```bash
pip install -i https://test.pypi.org/simple/ FopMath
```

## 3) Upload to PyPI (public)

```bash
twine upload dist/*
```

## 4) Verify public install

```bash
pip install FopMath
python -c "import FopMath; FopMath.Square_root(16)"
```

## Notes on wheels (no compiler for users)

To ensure users do not need a compiler, upload wheels for each target platform:
- Windows: build on Windows
- macOS: build on macOS
- Linux: build on manylinux (often via CI)

If a user installs on a platform without a matching wheel, pip will fall back to
building from source, which requires a compiler.

## Optional: automate with CI

You can automate cross-platform wheel builds with GitHub Actions using `cibuildwheel`.
That is the standard way to produce Windows/macOS/Linux wheels in one release.
