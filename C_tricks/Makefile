# C Tricks & Pitfalls - Modern C / Expert C Programming
EXAMPLES = $(wildcard [0-1][0-9]_*.c)
BINS     = $(EXAMPLES:.c=.out)
TOTAL    = $(shell echo $(EXAMPLES) | wc -w)
FAILS    = 3# Exactly: 04,13,15

all: $(BINS)
	@echo "\n🎉 ALL $(TOTAL) examples processed! ($(FAILS) expected to fail)"

%.out: %.c
	@echo "\n🔨 [$$(basename $< .c | cut -c1-2)] Compiling $<..."
	@if gcc -Wall -Wextra -std=c11 -O0 -o $@ $< 2>&1 | head -10; then \
		echo "   ✅ SUCCESS: $@" ; \
	else \
		echo "   ❌ FAILED:  $< (one of $(FAILS) expected)"; \
		rm -f $@; \
	fi

run:
	@working=$$(ls -1 $(BINS) 2>/dev/null | wc -l); \
	echo "\n🚀 Running $$working working examples ($(TOTAL)-$(FAILS)=$$(( $$working ))) :"; \
	for bin in $(BINS); do \
		if [ -f "$$bin" ]; then \
			echo "   📱 $$bin:"; \
			./$$bin 2>/dev/null && echo "      ✓ PASSED" || echo "      ⚠️  CRASHED"; \
		fi; \
	done

status:
	@echo "## 📊 Compile Status ($(TOTAL) total, $(FAILS) expected fails)"
	@echo "| # | File | Status |"
	@echo "|---|------|--------|"
	@for f in $(EXAMPLES); do \
		num=$$(basename $$f .c | cut -c1-2); \
		if gcc -c $$f >/dev/null 2>&1; then \
			echo "| $$num | [$$f](./$$f) | ✅ Works |"; \
		else \
			echo "| $$num | [$$f](./$$f) | ❌ Fails |"; \
		fi; \
	done

.PHONY: all run clean status rebuild
rebuild: clean all
clean:
	rm -f $(BINS) *.o
	@echo "🧹 Cleaned all binaries"
