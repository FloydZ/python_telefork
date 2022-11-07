# create the needed header files for including
cd deps/telefork
cargo build
cp target/debug/libtelefork.so ../../libtelefork.so
cbindgen --config cbindgen.toml --crate telefork --output telefork.h
cp telefork.h ../../
cd ../..

# create the cmake project
mkdir build
cd build
cmake ..
make
cd ..

