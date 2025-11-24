with open("marks.txt", "w") as f:
    f.write("John,85,92,78\n")
    f.write("Alice, 90,88,95\n")
    f.write("Bob,72,68,75\n")

def mark_analyzer():
    with open("marks.txt","r") as f:
        lines = f.readlines()

    results=[]
    class_total=0

    for line in lines:
        name,m1,m2,m3 = line.strip().split(",")
        m1,m2,m3 =int(m1),int(m2),int(m3)
        total = m1+m2+m3
        avg = total/3
        class_total += avg
        results.append((name,total,avg))

    topper = max(results,key=lambda x:x[1])

    with open("results.txt","w") as f:
        f.write("Student Results: \n")
        for name,total,avg in results:
            f.write(f"{name} - Total: {total}, Average:{avg:.2f}\n")

        f.write("\n")
        f.write(f"Class Average: {class_total/len(results):.2f}\n")
        f.write(f"Topper: {topper[0]} with {topper[1]} marks")
        print("Results written to results.txt\n")

mark_analyzer()

