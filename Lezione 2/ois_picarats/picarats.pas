{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 10000;

{ input data }
var
    N, M, C_0, i  : longint;
    a, b, c  : longint;
    P     : array[0..MAXN-1] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N, M, C_0);
    for i:=0 to N-1 do
        read(P[i]);
    readln();
    for i:=0 to M-1 do
        readln(a, b, c);

    { insert your code here }

    writeln(42); { print result }
end.
