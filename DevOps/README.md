# SimpleLib Docker

This is a not-so-simple docker that does an in-place build of SimpleLib

## Usage
- If you have been using Linux containers, you may have to right click 
  Docker Desktop and click "Switch to Windows Containers"

- You'll also need to set some env vars:
    `set DOCKER_BUILDKIT=0`
    `set COMPOSE_DOCKER_CLI_BUILD=0`
  or equivalent lines in your docker comfig thanks to a Docker bug

- Use `docker build -t topaz-test .` to build
- Use `docker run -it topaz-test` to get a cmd then just type `main {arg}` to test  
- OR uncomment the entrypoint near the bottom and just use the run command
