FROM ubuntu:24.04

RUN apt-get update
RUN apt-get install -y build-essential cmake catch2

WORKDIR /app

COPY . .

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build
RUN ctest --test-dir build --output-on-failure

ENTRYPOINT ["./build/console_paint"]
