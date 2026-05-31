FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        catch2 \
        cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . .

RUN cmake -S . -B /tmp/build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build /tmp/build --parallel \
    && ctest --test-dir /tmp/build --output-on-failure \
    && cmake --install /tmp/build --prefix /opt/console-paint

FROM ubuntu:24.04 AS runtime

RUN useradd --create-home --shell /usr/sbin/nologin appuser

COPY --from=builder /opt/console-paint/bin/console_paint /usr/local/bin/console_paint

USER appuser
WORKDIR /home/appuser

ENTRYPOINT ["console_paint"]
CMD ["--help"]
