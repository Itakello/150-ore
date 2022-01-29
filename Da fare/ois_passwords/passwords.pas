const
    MAXN = 10000;
    MAXW = 10;
var
    N, K, L, i : longint;
    W          : array[0..MAXN-1] of array[0..MAXW] of char;
    P          : array[0..MAXN] of char;
    fr, fw     : text;

begin
    assign(fr, 'input.txt');
    assign(fw, 'output.txt');
    reset(fr);
    rewrite(fw);
    readln(fr, N, K, L);
    for i:=0 to N-1 do
        readln(fr, W[i]);

    (* insert your code here *)
    P[0] := 'a';
    P[1] := chr(0);

    writeln(fw, P);
    close(fr);
    close(fw);
end.
