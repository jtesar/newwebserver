FROM registry.access.redhat.com/ubi9/ubi
RUN dnf install -y httpd /usr/bin/ps /usr/bin/lsof /usr/bin/curl /usr/sbin/ip make g++ && \
    chmod g+rwx /usr/bin && \
    mkdir -p /var/www/html && \
    chmod g+rwx /var/www/html


COPY rootfs /

EXPOSE 8080
LABEL Documentation 'This is a webserver implementation'


CMD ["/usr/sbin/httpd", "-DFOREGROUND"]

