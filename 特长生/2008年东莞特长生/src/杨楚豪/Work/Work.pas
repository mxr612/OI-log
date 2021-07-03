var a:array[1..1000,0..3]of integer;
    n,x:integer;
    t1,tm:longint;
procedure run(t0,t:longint);
   var x:integer;
   begin
     if t>t1 then exit;
     if t0>tm then
       begin
         t1:=t;
         exit;
       end;
     for x:=1 to n do if (a[x,0]=0)and(t0>=a[x,2])and(t0<=(a[x,3]-a[x,1])) then
                        begin
                          a[x,0]:=1;
                          run(t0+a[x,1],t+a[x,1]);
                          a[x,0]:=0;
                        end;
   end;
begin
  assign(input,'work.in');
  reset(input);
  readln(input,n);
  t1:=0;
  for x:=1 to n do
    begin
      readln(input,a[x,1],a[x,2],a[x,3]);
      a[x,0]:=0;
      t1:=t1+a[x,3];
    end;
  close(input);
  tm:=0;
  for x:=1 to n do if (a[x,3]-a[x,1])>tm then tm:=a[x,3]-a[x,1];
  run(0,0);
  assign(output,'work.out');
  rewrite(output);
  write(t1);
  close(output);
end.