Como compilar:

RPI:
gcc libaudio.c main.c simon.c rpi_input.c rpi_output.c rpi_setup.c -I/usr/local/include -L/usr/local/lib -lSDL -o simon -lwiringPi



ALLEGRO:

