class Spreadsheet {
public:
    unordered_map<string,int> sheet;

    Spreadsheet(int rows) { }

    void setCell(string cell, int value) {
        sheet[cell] = value;
    }

    void resetCell(string cell) {
        sheet[cell] = 0;
    }

    int getValue(string formula) {
    int i = 1; 
    string op1 = "";
    while (i < formula.size() && formula[i] != '+') { 
        op1 += formula[i];
        i++;
    }
    i++; 
    
    string op2 = "";
    while (i < formula.size()) {
        op2 += formula[i];
        i++;
    }

    int val1 = 0, val2 = 0;

    if (sheet.find(op1) != sheet.end()) {
        val1 = sheet[op1];
    } else {
        bool num = !op1.empty();
        for (char c : op1) {
            if (!isdigit(c)) { num = false; break; }
        }
        if (num) val1 = stoi(op1);
    }

    if (sheet.find(op2) != sheet.end()) {
        val2 = sheet[op2];
    } else {
        bool num = !op2.empty();
        for (char c : op2) {
            if (!isdigit(c)) { num = false; break; }
        }
        if (num) val2 = stoi(op2);
    }

    return val1 + val2;
}

};



/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */