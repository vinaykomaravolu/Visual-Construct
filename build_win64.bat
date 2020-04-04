mkdir Build_Win64_Dbg
cd Build_Win64_Dbg
cmake -DCMAKE_GENERATOR_PLATFORM=x64 -DCMAKE_BUILD_TYPE=Debug ..
cd ..
mkdir Build_Win64_Rel
cd Build_Win64_Rel
cmake -DCMAKE_GENERATOR_PLATFORM=x64 -DCMAKE_BUILD_TYPE=Release ..
cd ..