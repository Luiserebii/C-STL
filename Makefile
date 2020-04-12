.PHONY: lint
lint:
	./scripts/lint.sh

.PHONY: test
test: 
	cd test && make test
