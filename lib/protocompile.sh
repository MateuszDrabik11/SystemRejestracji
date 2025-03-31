protoc --grpc_out=. --plugin=protoc-gen-grpc='../server/build/_deps/grpc-build/grpc_cpp_plugin' $1
protoc --cpp_out=. $1

