# check if build dir exists if not create one
if ((Test-Path build) -ne $True)
{
    mkdir build;
}

cd build

cmake ..;
cmake --build .;
cd ../bin