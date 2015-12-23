#!/usr/bin/env node

var program = require('commander');
var pkg = require('./package.json');
var toMarkdown = require('to-markdown').toMarkdown;
var fs = require('fs');
var path = require('path');

program
    .version(pkg.version)
    .option('-i, --input <html-file>', 'html file to convert');

program.parse(process.argv);

if (!program.input) {
    throw new Error("An input html file is required.");
}

console.log('processing ' + program.input + ' ...');

var markdownTxt = toMarkdown(fs.readFileSync(program.input, 'utf8'));
var ifile = path.normalize(program.input);

/* calculate output file name : filename.md */
var outfile = path.basename(ifile, '.html') + '.md';
var dirname = path.dirname(ifile);

/* if input file is prefixed with directories
 * add the directory to output file too 
 */
if (dirname !== '.') {
    outfile = dirname + outfile;
} 

/* write output file */
fs.writeFile(outfile, markdownTxt, function (err) {
    if (err) {
        throw err;
    }
    console.log('converted ' + program.input + ' to ' + outfile + '!');
});

