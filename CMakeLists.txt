cmake_minimum_required(VERSION 3.22.0)

project(Clients_DB)

set(PostgreSQL_ADDITIONAL_VERSIONS "14")
set(CMAKE_CXX_STANDARD 17)
add_executable(Clients_DB main.cpp ClientsDB.cpp ClientsDB.h)
add_subdirectory("C:\\libpqxx-7.9.0\\libpqxx-7.9.0" libpqxx-build)
target_link_libraries(Clients_DB PRIVATE pqxx)