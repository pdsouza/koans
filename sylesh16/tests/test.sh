set -e

cp "$1" happy_birthday_sylesh &>/dev/null || true

./happy_birthday_sylesh > out.txt
diff noarg.txt out.txt

./happy_birthday_sylesh "Hello World" > out.txt
diff helloworld.txt out.txt

./happy_birthday_sylesh abcdefghijklmnopqrstuvwxyz > out.txt
diff alphabet.txt out.txt

./happy_birthday_sylesh "This is a really super crazy long sentence as an edge case." > out.txt
diff long.txt out.txt

rm out.txt

echo "All tests passed."
