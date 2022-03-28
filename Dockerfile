FROM ubuntu:latest
RUN mkdir project
RUN apt-get update && apt-get install -y python3
RUN apt-get -y install python3-pip
RUN pip install opencv-python
WORKDIR /project
COPY maket.py /project/maket.py
