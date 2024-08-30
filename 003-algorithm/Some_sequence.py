Algorithm="""
Algorithm='''
def generate_Some_sequence(N):
    with open("answer.txt","w") as f:
        tmp_counter=0
        line=f"{-N**2} "
        prev=-N**2
        while tmp_counter<(3*N-1):
            prev+=(2*tmp_counter+1)
            line+=f"{prev} "
            tmp_counter+=1
 
        print(line)
        f.write(line+"\\n")
        f.write("\\n")
        f.write("Algorithm(In Python): \\n")
        f.write(Algorithm)
'''
def generate_Some_sequence(N):
    with open("answer.txt","w") as f:
        tmp_counter=0
        line=f"{-N**2} "
        prev=-N**2
        while tmp_counter<(3*N-1):
            prev+=(2*tmp_counter+1)
            line+=f"{prev} "
            tmp_counter+=1
 
        print(line)
        f.write(line+"\\n")
        f.write("\\n")
        f.write("Algorithm(In Python): \\n")
        f.write(Algorithm)
"""
def generate_Some_sequence(N):
    with open("answer.txt","w") as f:
        tmp_counter=0
        line=f"{-N**2} "
        prev=-N**2
        while tmp_counter<(3*N-1):
            prev+=(2*tmp_counter+1)
            line+=f"{prev} "
            tmp_counter+=1
 
        print(line)
        f.write(line+"\n")
        f.write("\n")
        f.write("Algorithm(In Python): \n")
        f.write(Algorithm)

generate_Some_sequence(6)
