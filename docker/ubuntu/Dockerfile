FROM ubuntu:latest AS myubuntu-example
# Automatically answer Yes for APT questions.
ENV DEBIAN_FRONTEND noninteractive

# Update the system and install basic tools.
RUN apt-get update && apt-get install -yq git vim python3-pip sudo wget unzip
RUN pip3 install --break-system-packages setuptools numpy==2.0.0

# Clone our project and create an environment variable for it.
ENV MYAPP=/examples
RUN test -d examples && : || git clone https://github.com/pierreay/examples.git

# Move into it and do something.
WORKDIR "${MYAPP}"
RUN echo "MYAPP=${MYAPP}"
RUN ls
