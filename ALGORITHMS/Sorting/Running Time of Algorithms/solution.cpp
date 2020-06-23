'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the runningTime function below.
function runningTime(arr) {
let shift=0;
for(let i=1;i<arr.length;i++){
let temp=arr[i];

for(let j=i;j>=0;j--){
    if(temp<arr[j-1]){
        arr[j]=arr[j-1];
        shift++;// counts the no. of shifts
        console.log(shift);
    }else{
         arr[j]=temp; // remember your logic when u come next time-KD
        break;

    }
}
}
return shift;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    let result = runningTime(arr);

    ws.write(result + "\n");

    ws.end();
}
