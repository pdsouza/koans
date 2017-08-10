TARGET := happy_birthday_sylesh

all: $(TARGET)

$(TARGET): happy_birthday_sylesh.o
	$(CC) $^ -o $@

clean:
	@if [ -f $(TARGET) ] ; then rm $(TARGET); fi
	@if [ -f $(TARGET).o ] ; then rm $(TARGET).o; fi
