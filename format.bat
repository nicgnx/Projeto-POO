cd src
clang-format -i *.cpp
pause
cd ../program
clang-format -i *.cpp
pause

cd ../includes
clang-format -i *.hpp
pause

cd ..