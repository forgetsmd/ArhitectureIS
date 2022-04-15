FROM ubuntu:latest
ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN mkdir ArhitectureIS
WORKDIR /ArhitectureIS
RUN mkdir doc
RUN mkdir src
RUN apt-get update && apt-get install -y python3
RUN apt-get -y install python3-pip
RUN pip install opencv-python
RUN apt-get install nano
RUN apt-get install ffmpeg libsm6 libxext6  -y
COPY src/maket.py /ArhitectureIS/code/maket.py
COPY doc/example.jpg /ArhitectureIS/src/example.jpg
