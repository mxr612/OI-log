program work(input,output);
var f:array[0..1500] of longint;
    used:array[0..1500] of longint;
    wo:array[1..1000,1..3] of longint;
    i,j,k,n,max,min,minn:longint;

function check(us,x:longint):boolean;
var i,j:integer;
begin
  check:=false;
  for i:=1 to n do
   if (wo[i,2]<=x) and (x<=wo[i,3]) and (wo[i,3]-wo[i,1]>=us) and (wo[i,1]<=x-us) then exit(true);
end;

procedure check2(us,x:longint;var a,b:longint);
var i,j:integer;
begin
  for i:=1 to n do
   if (wo[i,2]<=x) and (x<=wo[i,3]) and (wo[i,3]-wo[i,1]>=us) and (wo[i,1]<=x-us) and (f[wo[i,3]-wo[i,1]]+wo[i,1]<=x) then
   begin
      a:=f[wo[i,3]-wo[i,1]]+wo[i,1];
      b:=wo[i,3];
      break;
   end;
end;

begin
  assign(input,'work.in');
  assign(output,'work.out');
  reset(input);rewrite(output);
  readln(n);max:=0;
  for i:=1 to n do begin
      readln(wo[i,1],wo[i,2],wo[i,3]);
      if wo[i,3]>max then max:=wo[i,3];
  end;
  fillchar(f,sizeof(f),0);
  fillchar(used,sizeof(used),0);
  for i:=1 to max do begin
      if i=10 then
         min:=999999999;
      min:=999999999;
      for j:=1 to n do
          if (wo[j,3]=i) and (f[wo[j,2]]+wo[j,1]<min) then begin
             min:=f[wo[j,2]]+wo[j,1];
          end;
      if check(used[i-1],i) {and (min<>999999999)} then begin
         used[i]:=i;
         if min=999999999 then check2(used[i-1],i,f[i],used[i]) else f[i]:=min;
      end else
          if f[i-1]<min then begin
             used[i]:=used[i-1];
             f[i]:=f[i-1];
          end else begin
                 f[i]:=min;
                 used[i]:=i;
              end;
  end;
  write(f[max]);
  close(input);close(output);
end.
