FROM ubuntu

RUN apt update
RUN apt install -y wget gnupg2
RUN echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy main" > /etc/apt/sources.list.d/llvm.list
RUN echo "deb-src http://apt.llvm.org/jammy/ llvm-toolchain-jammy main" >> /etc/apt/sources.list.d/llvm.list
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc
RUN apt update
RUN apt install -y socat build-essential clang-18* clang-tools-18 llvm-18* llvm clang

RUN mkdir /home/build_env

COPY src /home/build_env/src
COPY include /home/build_env/include
COPY Makefile /home/build_env/


WORKDIR /home/build_env

RUN make > makeout.txt

USER 65534:65534

EXPOSE 4000

CMD bash -c "socat tcp-listen:4000,reuseaddr,fork exec:'cat makeout.txt && bash'"