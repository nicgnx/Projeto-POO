cd src
clang-format -i *.cpp
pause
cd ../program
clang-format -i *.cpp
pause
cd ../tests
clang-format -i *.cpp

cd ../includes
clang-format -i *.hpp
pause

cd ..