import java.io.*;
import java.util.*;
import java.util.stream.*;

class Main {
    
    static class Node {
        public int id;
        public Node left;
        public Node right;

        public Node (int id) {
            this.id = id;
            this.left = null;
            this.right = null;
        }
        public Node(int id, Node left, Node right) {
            this.id = id;
            this.left = left;
            this.right = right;
        }
    }

    static Node constructTree(List<Integer> preorder, List<Integer> inorder) {
        if (preorder.size() == 0) {
            return null;
        }
        if (preorder.size() == 1) {  // leaf node
            return new Node(preorder.get(0));
        }
        List<Integer> leftChildInorder = new ArrayList<>();
        List<Integer> rightChildInorder = new ArrayList<>();
        List<Integer> leftChildPreorder = new ArrayList<>();
        List<Integer> rightChildPreorder = new ArrayList<>();
        Set<Integer> leftChilds = new HashSet<>();
        Set<Integer> rightChilds = new HashSet<>();

        int rootId = preorder.get(0);
        // System.out.printf("ROOTID: %d\n", rootId);
        int rootIndexAtInorder = inorder.indexOf(Integer.valueOf(rootId));
        for (int i = 0; i < rootIndexAtInorder; i++) {
            int child = inorder.get(i);
            leftChilds.add(child);
            leftChildInorder.add(child);
        }
        for (int i = rootIndexAtInorder + 1; i < inorder.size(); i++) {
            int child = inorder.get(i);
            rightChilds.add(child);
            rightChildInorder.add(child);
        }
        for (int i = 1; i < preorder.size(); i++) {
            int child = preorder.get(i);
            if (leftChilds.contains(child)) {
                leftChildPreorder.add(child);
            } else {
                rightChildPreorder.add(child);
            }
        }

        // System.out.println(leftChildPreorder);
        // System.out.println(rightChildPreorder);
        // System.out.println(leftChildInorder);
        // System.out.println(rightChildInorder);

        Node leftNode = constructTree(leftChildPreorder, leftChildInorder);
        Node rightNode = constructTree(rightChildPreorder, rightChildInorder);
        return new Node(rootId, leftNode, rightNode);
    }

    static List<Integer> result;
    static void traverseTreePostorder(Node root) {
        if (root.left != null) {
            traverseTreePostorder(root.left);
        }
        if (root.right != null) {
            traverseTreePostorder(root.right);
        }
        result.add(root.id);
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        final StringBuilder printer = new StringBuilder();
        final int T = Integer.parseInt(scanner.readLine());
        for (int t = 0; t < T; t++) {
            final int N = Integer.parseInt(scanner.readLine());
            StringTokenizer tokenizer = new StringTokenizer(scanner.readLine(), " ");
            List<Integer> preorder = new ArrayList<>();
            for (int n = 0; n < N; n++) {
                preorder.add(Integer.parseInt(tokenizer.nextToken()));
            }

            tokenizer = new StringTokenizer(scanner.readLine()," ");
            List<Integer> inorder = new ArrayList<>();
            for (int n = 0; n < N; n++) {
                inorder.add(Integer.parseInt(tokenizer.nextToken()));
            }

            Node root = constructTree(preorder, inorder);
            result = new ArrayList<>();
            traverseTreePostorder(root);
            printer.append(result.stream()
                                .map(i -> i.toString())
                                .collect(Collectors.joining(" ")))
                        .append('\n');
        }

        System.out.println(printer);
        scanner.close();
    }
}