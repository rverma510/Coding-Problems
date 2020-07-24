int main() {
    int i, j, *p;
    i = 42; // i is an lvalue and 42 is an rvalue
    p = new int;
    *p = i; // derefernced pointer is as lvalue
    delete p;

    ((i < 42) ? i : j) = 25; // the conditional operator returns an lvalue (either i or j)

    // icorrect usage of lvalues and rvalues
    // 42 = i // left operand must be lvalue
    // j * 42 = 23 // left operand must be lvalue

    return 0;

}