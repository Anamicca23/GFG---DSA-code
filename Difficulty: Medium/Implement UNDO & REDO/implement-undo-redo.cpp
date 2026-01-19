class Solution {
private:
    string builder;
    stack<char> st;

public:
    void append(char x) {
        // append x into document
        builder.push_back(x);
    }

    void undo() {
        // undo last change
        if (builder.empty()) return;
        st.push(builder.back());
        builder.pop_back();
    }

    void redo() {
        // redo changes
        if (st.empty()) return;
        builder.push_back(st.top());
        st.pop();
    }

    string read() {
        // read the document
        return builder;
    }
};
 