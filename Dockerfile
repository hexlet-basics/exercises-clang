FROM hexletbasics/base-image:latest



RUN apt-get update && apt-get install -y libcunit1 libcunit1-doc libcunit1-dev tcc

RUN pip install --upgrade pip
ENV PIP_ROOT_USER_ACTION=ignore
RUN pip install cpplint 

RUN curl -sO https://raw.githubusercontent.com/silentbicycle/greatest/master/greatest.h --output-dir /usr/local/include
RUN curl -sO https://raw.githubusercontent.com/silentbicycle/greatest/master/contrib/greenest --output-dir /usr/local/bin
RUN chmod +x /usr/local/bin/greenest

WORKDIR /exercises-clang

COPY . .

ENV PATH=/exercises-clang/bin:$PATH
