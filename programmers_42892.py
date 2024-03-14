import sys
sys.setrecursionlimit(10**6)

class Node:
    def __init__(self, item: list):
        self.value = item[0]
        self.key = item[2]
        self.left = None
        self.right = None

class BSTree:
    def __init__(self):
        self.root = None
    
    def insert(self, item: list):
        if self.root is None:
            self.root = Node(item)
            return

        node = self.root
        while True:
            if item[0] < node.value:
                if node.left is None:
                    node.left = Node(item)
                    break
                else:
                    node = node.left
            else:
                if node.right is None:
                    node.right = Node(item)
                    break
                else:
                    node = node.right
    
    def preorder(self, node: Node, pre: list):
        if node is None:
            return
        pre.append(node.key)
        self.preorder(node.left, pre)
        self.preorder(node.right, pre)

    def postorder(self, node: Node, post: list):
        if node is None:
            return
        self.postorder(node.left, post)
        self.postorder(node.right, post)
        post.append(node.key)
       
            
def solution(nodeinfo):
    nodeinfo = [nodeinfo[i] + [i+1] for i in range(len(nodeinfo))]
    nodeinfo.sort(key=lambda x: -x[1])

    bst = BSTree()
    for item in nodeinfo:
        bst.insert(item)
    
    pre = []
    post = []
    bst.preorder(bst.root, pre)
    bst.postorder(bst.root, post)
    return [pre, post]


if __name__ == "__main__":
    print(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]))