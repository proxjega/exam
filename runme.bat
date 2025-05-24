cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\text.txt Debug\text.txt
cd Debug\
exam.exe
pause