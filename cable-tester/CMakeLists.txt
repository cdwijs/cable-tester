add_executable(cable-tester
        cable-tester.c
        )

# pull in common dependencies
target_link_libraries(cable-tester pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(cable-tester)

# add url via pico_set_program_url
example_auto_set_url(cable-tester)
