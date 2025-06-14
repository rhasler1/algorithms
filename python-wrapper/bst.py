#TODO: read ctypes documentation
# encapsulate c_types
# expose friendly API
# what is needed to interact with this API?
# user should only need to pass in a list of integers

import ctypes

# path to shared bst library
#lib = ctypes.CDLL("../lib/MAC/libbst.so")
lib = ctypes.CDLL("../c-mods/trees/lib/libbst.so")

# Node class to match C Node struct
class TreeNode(ctypes.Structure):
    pass

# creating Node* (Node pointer) type
TreeNodePTR = ctypes.POINTER(TreeNode)


# field positioning must match C Node struct
TreeNode._fields_ = [
    ("l", TreeNodePTR),
    ("r", TreeNodePTR),
    ("payload", ctypes.c_int),
]

# setting function build_node arg types
lib.build_node.argtypes = [ctypes.c_int]
# bst build tree function arg types
lib.bst_build_tree.argtypes = [ctypes.POINTER(TreeNodePTR), ctypes.c_int]

lib.print_tree_structured.argtypes = [TreeNodePTR, ctypes.c_int]

#lib.insert_node_left.argtypes = (NodePTR, NodePTR)

# setting function build_node return type
lib.build_node.restype = TreeNodePTR

# bst build tree function return type
lib.bst_build_tree.restype = TreeNodePTR

lib.print_tree_structured.restype = None

#lib.insert_node_left.restype = ctypes.c_int


# function call
nodes = []
for i in range(5):
    node = lib.build_node(i)
    nodes.append(node)
    print("node value =", nodes[i].contents.payload)




NodeArrayType = TreeNodePTR * len(nodes)

node_array = NodeArrayType(*nodes)

lib.bst_build_tree(node_array, len(nodes))

lib.print_tree_structured(node_array[0], len(nodes))
