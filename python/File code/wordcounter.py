with open("story.txt", "w") as f:
    f.write("The quick brown fox\n")
    f.write("jumps over the lazy dog.\n")
    f.write("The fox is quick.\n")

filename = "story.txt"  

with open(filename, "r") as f:
    lines = f.readlines()

total_lines = len(lines)

text = "".join(lines)

total_characters = len(text)

words = text.lower().split()

clean_words = [word.strip(".,!?;:") for word in words]

total_words = len(clean_words)

# Find most frequent word
most_word = ""
max_count = 0

for word in set(clean_words):     # using set() to check each word only once
    count = clean_words.count(word)
    if count > max_count:
        max_count = count
        most_word = word

print("File Statistics:")
print("Total lines:", total_lines)
print("Total words:", total_words)
print("Total characters:", total_characters)
print(f"Most frequent word: {most_word} ({max_count} times)")

