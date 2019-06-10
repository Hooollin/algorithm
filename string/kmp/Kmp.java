public class Kmp {
    private int[] prefixTable;
    private String text;
    private String pattern;
    private StringBuilder sb = new StringBuilder();

    public Kmp(String text, String pattern) {
        this.text = text;
        this.pattern = pattern;
        prefixTable = new int[pattern.length()];
        buildPrefixTable();
        shiftPrefixTable();
    }

    private void buildPrefixTable() {
        int len = 0;
        int i = 1;
        while (i < pattern.length()) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len += 1;
                prefixTable[i] = len;
                i += 1;
            } else {
                if (len == 0) {
                    prefixTable[i] = len;
                    i += 1;
                } else {
                    len = prefixTable[len - 1];
                }
            }
        }
    }

    private void shiftPrefixTable() {
        for (int i = 0; i < prefixTable.length - 1; i++) {
            prefixTable[i + 1] = prefixTable[i];
        }
        prefixTable[0] = -1;
    }

    public int firstMatch() {
        int i = 0, j = 0;
        while (i < text.length()) {
            if (j == pattern.length() - 1 && pattern.charAt(j) == text.charAt(i)) {
                System.out.println(text);
                for (int t = 0; t < i - j; t++) {
                    sb.append(" ");
                }
                System.out.println(sb.toString() + pattern);
                System.out.println(String.format("found pattern at index : %d", i - j));
                return i - j;
            }
            if (text.charAt(i) == pattern.charAt(j)) {
                i += 1;
                j += 1;
            } else {
                j = prefixTable[j];
                if (j == -1) {
                    i += 1;
                    j += 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Kmp Kmp = new Kmp("ABABABABBAABB", "AABB");
        Kmp.firstMatch();
    }
}