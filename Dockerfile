FROM registry.redhat.io/ubi9/ubi
RUN dnf install -y httpd /usr/bin/ps /usr/bin/lsof /usr/bin/curl /usr/sbin/ip && \
    useradd myuser && \
    chmod a+rwx /run/httpd /var/lib/httpd /var/log/httpd

COPY rootfs /
USER myuser

EXPOSE 8080
LABEL Documentation 'This is a webserver implementation'

ONBUILD ADD src /var/www/html
RUN touch /tmp/v1

CMD ["/usr/sbin/httpd", "-DFOREGROUND"]



