# On Linux/MAC:
- Prepare environment:
```
brew install cmake vcpkg
vcpkg install nlohmann_json
export VCPKG_ROOT=<VCPKG_INSTALL_PATH>
cmake -B build -DCMAKE_TOOLCHAIN_FILE=[vcpkg/scripts/buildsystems/vcpkg.cmake]
```
- Compile:
```
  cmake --build ./build
```
- Run:
```
  ./build/JsonApp
```
# On Windows:
- Prepare environment **(Install Visual Studio - it will install MSVC, Windows SDK and cmake)**
```
git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
cd C:\vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg.exe install nlohmann-json
cmake -B build -DCMAKE_TOOLCHAIN_FILE=[vcpkg/scripts/buildsystems/vcpkg.cmake]
```
- Compile:
```
cmake --build build --config Release
```
