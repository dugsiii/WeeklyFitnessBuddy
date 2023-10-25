FROM ubuntu:latest
LABEL title="C++ Analysis"
LABEL version=0.2
ENV CXXFLAGS=-std=c++17
ENV WORKDIR=/usr/src
WORKDIR /usr/src

# Install dependencies
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y -f \
            dos2unix \    
            build-essential \
            g++ \
            cmake \
            git-all \
            pmccabe \
            cccc

# Get source and make sure it uses unix line feed (no carriage return)
COPY . ./
RUN dos2unix *

# Load repo into image
COPY . ${WORKDIR}

# Run static analysis
CMD pmccabe *.cpp -v && \
    cccc --lang=c++ --outdir=report *.cpp
