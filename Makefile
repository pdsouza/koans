TARGET := happy_birthday_sylesh

.PHONY: all clean tests

all: tests

tests: $(TARGET)
	@cp $(TARGET) tests/
	@cd tests && ./test.sh
	@rm tests/$(TARGET)

$(TARGET): happy_birthday_sylesh.o
	$(CC) $^ -o $@

clean:
	@if [ -f $(TARGET) ] ; then rm $(TARGET); fi
	@if [ -f $(TARGET).o ] ; then rm $(TARGET).o; fi
