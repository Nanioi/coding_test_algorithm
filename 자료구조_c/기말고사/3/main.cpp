int isMirror(Tree *T1, Tree  *T2) {

    int result;

    if (T1 == null && T2 == null) {
        return 1;
    }
    else if (T1 == null) {
        return 0;
    }
    else if (T2 == null) {
        return 0;
    }
    else {
        result = isMirror(T1->left, T2->right);
    }
    return result;
}