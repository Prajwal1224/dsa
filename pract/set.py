def union(setA, setB):
    # Initialize union set
    union_set = setA.copy()
    
    # Copy elements of setB not present in setA to union_set
    for x in setB:
        if x not in setA:
            union_set.add(x)
    
    return union_set

def intersection(setA, setB):
    # Initialize intersection set
    intersection_set = set()
    
    # Copy elements present in both setA and setB to intersection_set
    for x in setA:
        if x in setB:
            intersection_set.add(x)
    
    return intersection_set

def difference(setA, setB):
    # Initialize difference set
    difference_set = set()
    
    # Copy elements of setA not present in setB to difference_set
    for x in setA:
        if x not in setB:
            difference_set.add(x)
    
    return difference_set

def subset(setA, setB):
    # Check if every element of setA is present in setB
    for x in setA:
        if x not in setB:
            return False
    
    return True

def proper_subset(setA, setB):
    # Check if every element of setA is present in setB and setB is strictly larger than setA
    if subset(setA, setB) and len(setB) > len(setA):
        return True
    
    return False

# Example usage:
A = set()
B = set()

a = int(input("Enter number of elements in set 1 : "))
print("Enter Elements : ")
for i in range(0, a):
    ele = int(input())
    A.add(ele) 

b = int(input("Enter number of elements in set 2 : "))
print("Enter Elements : ")
for i in range(0, b):
    ele = int(input())
    B.add(ele) 

print("Union:", union(A, B))
print("Intersection:", intersection(A, B))
print("Difference:", difference(A, B))
print("Subset:", subset(A, B))
print("Proper Subset:", proper_subset(A, B))