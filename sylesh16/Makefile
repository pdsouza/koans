CFLAGS := -std=c99
TARGET := happy_birthday_sylesh

.PHONY: all clean tests

all: $(TARGET)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

tests: CFLAGS += -DDEBUG
tests: clean $(TARGET)
	@cp $(TARGET) tests/
	@cd tests && ./test.sh $(TARGET)
	@rm tests/$(TARGET)

clean:
	@if [ -f $(TARGET) ] ; then rm $(TARGET); fi
	@if [ -f $(TARGET).o ] ; then rm $(TARGET).o; fi
