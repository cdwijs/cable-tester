add_executable(blink
        blink.c
        )


target_link_libraries(blink pico_stdlib)


pico_add_extra_outputs(blink)


example_auto_set_url(blink)
