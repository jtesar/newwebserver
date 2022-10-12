IMAGE_NAME = mywebserver

.PHONY: build
build:
	podman build -t $(IMAGE_NAME) .

.PHONY: test
test: build
	oc delete all --all
	podman push $(IMAGE_NAME) default-route-openshift-image-registry.apps.ocp4.example.com/test/$(IMAGE_NAME)
	oc new-app $(IMAGE_NAME)~https://github.com/jtesar/mywebserver.git --context-dir=src --strategy=source --name web
	oc expose svc/web

