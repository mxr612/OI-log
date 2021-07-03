var
  n,max:integer;
  ti,ai,bi:array[1..1000] of integer;
procedure rr;
  var
    f1:text;
    i:integer;
  begin
    assign(f1,'work.in');
    reset(f1);
    readln(f1,n);
    for i:=1 to n do
      readln(f1,ti[i],ai[i],bi[i]);
    close(f1);
  end;
procedure main;
  var
    i,j,t,k:integer;
  begin
    for i:=1 to n-1 do
      for j:=1 to n-1 do
        if ti[j]>ti[j+1] then
          begin
            t:=ti[j];
            ti[j]:=ti[j+1];
            ti[j+1]:=t;
            t:=ai[j];
            ai[j]:=ai[j+1];
            ai[j+1]:=t;
            t:=bi[j];
            bi[j]:=bi[j+1];
            bi[j+1]:=t;
          end;
    for k:=1 to n do
      for i:=1 to n do
        if (ti[i]<=bi[i]) and (ai[i]=0) and (ti[i]<>0)
          then
            begin
              for j:=i to n do
                begin
                  ai[j]:=ai[j]-ti[i];
                  bi[j]:=bi[j]-ti[i];
                  if ai[j]<0 then ai[j]:=0;
                  if bi[j]<0 then bi[j]:=0;
                end;
              max:=max+ti[i];
              ti[i]:=0;ai[i]:=0;bi[i]:=0;
            end;
  end;
procedure ww;
  var
    f2:text;
  begin
    assign(f2,'work.out');
    rewrite(f2);
    writeln(f2,max);
    close(f2);
  end;
begin
  rr;
  main;
  ww;
end.