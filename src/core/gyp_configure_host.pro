# Prevent generating a makefile that attempts to create a lib
TEMPLATE = aux

# Pick up the host toolchain
option(host_build)

GYPI_CONTENTS = "{" \
                "  'make_global_settings': [" \

GYPI_FILE = $$OUT_PWD/qmake_extras.gypi
!build_pass {
    write_file($$GYPI_FILE, GYPI_CONTENTS)
}
