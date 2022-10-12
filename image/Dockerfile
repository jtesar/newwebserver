FROM registry.access.redhat.com/ubi9/ubi
RUN dnf install -y httpd /usr/bin/ps /usr/bin/lsof /usr/bin/curl /usr/sbin/ip make && \
    useradd myuser && \
    chmod o+rwx /run/httpd /var/lib/httpd /var/log/httpd

COPY rootfs /
EXPOSE 8080
LABEL Documentation 'This is a webserver implementation'


CMD ["/usr/sbin/httpd", "-DFOREGROUND"]

