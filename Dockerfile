FROM hexletbasics/base-image:latest

RUN apt-get update && apt-get install -y libcunit1 libcunit1-doc libcunit1-dev tcc

WORKDIR /exercises-clang

COPY . .

ENV PATH=/exercises-clang/bin:$PATH
