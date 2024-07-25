docker:
	docker image prune -a --force --filter "until=24h"
	docker build -t archlinux .
	docker run --rm -v ${PWD}:/app archlinux /bin/bash -c "cd /app && ls -alh"
