'use strict';

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

// Complete the insertionSort1 function below.
function insertionSort1(n, arr) {
let temp = arr[n-1];
for(let i =(n-1);i>=0;i--){ // (i>=0) for test case 2 ..check it if any doubt later 
    if(arr[i-1]>temp){
        arr[i]=arr[i-1];
        console.log(...arr);
    }
    else{
        arr[i]=temp;
        console.log(...arr);
        break;
        
    }
    
    //(...)spread operator used to print all array elements in same line without brackets and comma
}
}

function main() {
    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    insertionSort1(n, arr);
}
