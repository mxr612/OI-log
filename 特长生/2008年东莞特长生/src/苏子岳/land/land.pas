const
  inf='land.in';
  ouf='land.out';
  maxn=1000;
var
  n:integer;
  a,b:array[0..maxn] of longint;
procedure init;
  begin
    assign(input,inf);
    assign(output,ouf);
    reset(input);
    rewrite(output);
    readln(n);
    fillchar(a,sizeof(a),0)
  end;
procedure work(m:longint);
  var
    i,j,k,s,g:longint;
  begin
    if m=1
      then
        begin
          a[maxn]:=2;
          exit
        end;
    work(m div 2);
    fillchar(b,sizeof(b),0);
    k:=1;
    while a[k]=0 do
      inc(k);
    g:=0;
    for i:=maxn downto 2*k-maxn-1 do
      begin
        g:=0;
        for j:=maxn downto 2*k-maxn-1 do
          begin
            s:=b[i+j-maxn]+a[i]*a[j]+g;
            b[i+j-maxn]:=s mod 10;
            g:=s div 10
          end
      end;
    a:=b;
    if m mod 2=1
      then
        begin
          j:=1;
          while a[j]=0 do
            inc(j);
          g:=0;
          for i:=maxn downto j-1 do
            begin
              s:=a[i]*2+g;
              a[i]:=s mod 10;
              g:=s div 10
            end
        end
  end;
procedure print;
  var
    i,j:longint;
  begin
    work(n*n);
    dec(a[maxn]);
    j:=1;
    while a[j]=0 do
      inc(j);
    for i:=j to maxn do
      write(a[i]);
    writeln;
    close(input);
    close(output)
  end;
begin
  init;
  print
end.
