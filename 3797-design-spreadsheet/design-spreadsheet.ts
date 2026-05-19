class Spreadsheet {

    sheet: number[][];

    constructor(rows: number) {

        this.sheet = [];

        for (let i = 0; i < rows; i++) {
            this.sheet.push(new Array(26).fill(0));
        }
    }

    setCell(cell: string, value: number): void {

        let col: number =
            cell[0].charCodeAt(0) - 'A'.charCodeAt(0);

        let row: number =
            parseInt(cell.slice(1)) - 1;

        this.sheet[row][col] = value;
    }

    resetCell(cell: string): void {

        let col: number =
            cell[0].charCodeAt(0) - 'A'.charCodeAt(0);

        let row: number =
            parseInt(cell.slice(1)) - 1;

        this.sheet[row][col] = 0;
    }

    evaluate(value: string): number {

        if (value[0] >= '0' && value[0] <= '9') {

            return parseInt(value);

        } else {

            let col: number =
                value[0].charCodeAt(0) - 'A'.charCodeAt(0);

            let row: number =
                parseInt(value.slice(1)) - 1;

            return this.sheet[row][col];
        }
    }

    getValue(formula: string): number {

        formula = formula.slice(1);

        const [x, y] = formula.split('+');

        return this.evaluate(x) + this.evaluate(y);
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * var obj = new Spreadsheet(rows)
 * obj.setCell(cell,value)
 * obj.resetCell(cell)
 * var param_3 = obj.getValue(formula)
 */