cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\text.txt Debug\text.txt
copy src\urldomains.txt Debug\urldomains.txt
cd Debug\
exam.exe
pause