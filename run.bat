cmake -S source -B ./build
cmake --build build

cd %~dp0build\Debug
main.exe > ..\..\image\04-addsphere.ppm
pause