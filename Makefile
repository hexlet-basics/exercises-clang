-include /opt/basics/common/common.mk

compose-setup: compose-build

compose:
	docker-compose up

compose-build:
	docker-compose build

code-lint:
	@(for i in $$(find . -type f -name main.c); do cpplint --filter=-legal/copyright $$(dirname $$i)/main.c ; done)

compose-bash:
	docker-compose run exercises bash

compose-test:
	docker-compose run exercises make test

compose-lint:
	docker-compose run exercises make code-lint

compose-description-lint:
	docker-compose run exercises make description-lint

compose-schema-validate:
	docker-compose run exercises make schema-validate

ci-check:
	docker-compose --file docker-compose.yml build
	docker-compose --file docker-compose.yml up --abort-on-container-exit
