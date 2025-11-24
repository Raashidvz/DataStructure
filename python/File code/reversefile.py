with open("input.txt", "w") as f:
    f.write("Hello World\n")
    f.write("Python Programming\n")
    f.write("File Handling\n")
with open("input.txt", "r") as f:
    lines = f.readlines()
with open("reversed.txt", "w") as f:
    for line in reversed(lines):
        reversed_text = line.strip()[::-1]
        f.write(reversed_text + "\n")
