FROM debian:11.9

RUN apt-get update 
RUN apt-get upgrade -y
RUN apt-get -y install git vim wget procps build-essential libssl-dev libmariadb-dev-compat mariadb-client net-tools valgrind cppcheck cmake clang-format python3-pip rsyslog libgtest-dev libgmock-dev screen libcurl4-openssl-dev
RUN pip install cpplint  
RUN mkdir -p /etc/supla-server
RUN cd /usr/src/ && \
    wget https://ftp.openbsd.org/pub/OpenBSD/LibreSSL/libressl-3.5.4.tar.gz && \
    tar zxvf libressl-3.5.4.tar.gz && \
    cd libressl-3.5.4 && \
    sed -ri 's/(\{ \global\:)/LIBRESSL \1/' configure && \
    ./configure --prefix /usr/src/libressl && \
    make all && \
    make install  

WORKDIR /CProjects/supla-core/supla-server

COPY supla.cfg /etc/supla-server/
COPY supla-test.cfg /etc/supla-server/
COPY private.key /etc/supla-server/
COPY cert.crt /etc/supla-server/
