find . -type f -name "*.sh" | sed "s/\.sh//" | rev | tr "/" "," | cut -d , -f 1 | rev
