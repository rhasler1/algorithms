#TODO: read ctypes documentation

import ctypes

# path to shared bst library
lib = ctypes.CDLL("../lib/MAC/libbst.so")

# Node class to match C Node struct
class Node(ctypes.Structure):
    pass

# creating Node* (Node pointer) type
NodePTR = ctypes.POINTER(Node)

# field positioning must match C Node struct
Node._fields_ = [
    ("l", NodePTR),
    ("r", NodePTR),
    ("payload", ctypes.c_int),
]

# setting function build_node arg types
lib.build_node.argtypes = [ctypes.c_int]

# setting function build_node return type
lib.build_node.restype = NodePTR

# function call
root = lib.build_node(5)

# check
assert root
print("Root value: ", root.contents.payload)
