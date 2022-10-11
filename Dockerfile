FROM registry.redhat.io/ubi9/ubi
RUN dnf install -y httpd /usr/bin/ps /usr/bin/lsof /usr/bin/curl /usr/sbin/ip && \
    useradd myuser && \
    chmod o+rwx /run/httpd /var/lib/httpd /var/log/httpd

COPY rootfs /
USER myuser

EXPOSE 8080
LABEL Documentation 'This is a webserver implementation'

ONBUILD ADD src /var/www/html

CMD ["/usr/sbin/httpd", "-DFOREGROUND"]

