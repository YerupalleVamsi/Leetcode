class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        string row = "";
        for (int i = 1; i < cell.size(); i++)
            row = row + cell[i];
        sheet[stoi(row) - 1][col - 'A'] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        string row = "";
        for (int i = 1; i < cell.size(); i++)
            row = row + cell[i];
        sheet[stoi(row) - 1][col - 'A'] = 0;
    }
    
     int getValue(string formula) {
        int i = 1; 
        string op1 = "";
        while (i < formula.size() && formula[i] != '+') { 
            op1 = op1 + formula[i];
            i++;
        }
        i++; 
        
        string op2 = "";
        while (i < formula.size()) {
            op2 = op2 + formula[i];
            i++;
        }
        if ((op1[0] >= 'A' && op1[0] <= 'Z') && (op2[0] >= 'A' && op2[0] <= 'Z')) {
            char col1 = op1[0];
            string row1 = "";
            for (int i = 1; i < op1.size(); i++)
                row1 = row1 + op1[i];
            
            char col2 = op2[0];
            string row2 = "";
            for (int i = 1; i < op2.size(); i++)
                row2 = row2 + op2[i];
            
            int sum = sheet[stoi(row1) - 1][col1 - 'A'] + sheet[stoi(row2) - 1][col2 - 'A'];
            return sum;
        }
        else if (op1[0] >= 'A' && op1[0] <= 'Z') {
            char col1 = op1[0];
            string row1 = "";
            for (int i = 1; i < op1.size(); i++)
                row1 = row1 + op1[i];
            
            int s2 = stoi(op2);
            return sheet[stoi(row1) - 1][col1 - 'A'] + s2;
        }
        else if (op2[0] >= 'A' && op2[0] <= 'Z') {
            char col2 = op2[0];
            string row2 = "";
            for (int i = 1; i < op2.size(); i++)
                row2 = row2 + op2[i];
            
            int s1 = stoi(op1);
            return s1 + sheet[stoi(row2) - 1][col2 - 'A'];
        }
        return stoi(op1) + stoi(op2);
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */