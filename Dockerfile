FROM python:3.12 AS build


RUN apt-get update && \
    apt-get install -y --no-install-recommends gcc && \
    apt-get install -y cmake && \
    apt-get install -y python3-dev && \
    pip install "pybind11[global]"


ADD ./src/lib /app/src/lib


WORKDIR /app/build


RUN cmake ../src/lib && \
    cmake --build .


#--------------------------------
FROM python:3.12


WORKDIR /app


COPY /src/app .
COPY --from=build /app/build/ .


CMD ["python", "./main.py"]
