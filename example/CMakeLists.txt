add_executable(yourlib-example
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    )

target_link_libraries(yourlib-example PRIVATE
    yourlib::yourlib
    )
