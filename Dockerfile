FROM hexletbasics/base-image:latest

RUN apt-get update && apt-get install libcunit1 libcunit1-doc libcunit1-dev gcc tcc python3-pip

RUN pip install cpplint

# ENV CPLUS_INCLUDE_PATH=/opt

WORKDIR /exercises-clang

COPY . .

# ENV PATH=~/.local/bin/:/exercises-cpp/bin:$PATH

ENV PATH=/exercises-clang/bin:$PATH
