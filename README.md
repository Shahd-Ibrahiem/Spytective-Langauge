# Spytective-Langauge
Complete compiler project for the custom Spytective language — a creative fusion of detective deduction and spy missions. Includes lexical analysis, parsing, and code generation phases implemented in C++.

Tagline: Investigate. Interrogate. Infiltrate.

Overview:
Spytective is a creative, story-driven programming language that merges the logic of detective investigations with the thrill of spy operations.
This repository contains a C++ lexical scanner (tokenizer) built for the Spytective language as part of a compiler design course project.

Key Features:

Detects all Spytective keywords, data types, identifiers, literals, and operators.

Handles comments (->>), strings, and symbols.

Reads Spytective source files (.spy or .txt) and outputs token classifications.

Structured and extendable for parser integration in future assignments.

Supported Keywords:
motive, crime_scene, report, trigger, investigate, fallback, resist, expose, truth, alibi

Supported Data Types:
fine, evidence, briberry, intent

Example Input:

motive crime_scene() {
    fine clue = 9 ->>
    investigate (clue > 7) {
        report "Prime suspect detected!" ->>
    }
    fallback {
        report "No leads found. Keep investigating." ->>
    }
}


Example Output:

Line 1: motive          => Keyword  
Line 1: crime_scene     => Keyword  
Line 2: fine            => Data Type  
Line 2: clue            => Identifier  
Line 3: investigate     => Keyword  
Line 4: report          => Keyword  
...


Files Included:

Scanner.cpp → C++ source code for the lexical analyzer

spytective_input.spy → Sample test file

Spytective.pdf → Language documentation & design description

Language Concept Summary:
Spytective turns logic into investigation — each function is a motive, every loop is resistance, and every conditional is an investigation.
