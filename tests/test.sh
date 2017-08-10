set -e

./happy_birthday_sylesh > out.txt
diff out.txt noarg.txt

./happy_birthday_sylesh "Hello World" > out.txt
diff out.txt helloworld.txt

rm out.txt
