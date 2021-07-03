program reward(input,output);
var
   a:array[1..1000]of integer;
   b:array[1..2000,1..2000]of boolean;
   i,j,k,x,y:integer;
   n,m:integer;
   tot:longint;
   f:boolean;
begin
   assign(input,'reward.in');
   assign(output,'reward.out');
   reset(input);
   rewrite(output);

   fillchar(b,sizeof(b),false);
   read(n);read(m);
   for i:=1 to n do a[i]:=100;
   for i:=1 to m do
     begin
      read(x);
      read(y);
      b[x,y]:=true;
     end;
   f:=true;
   for i:=1 to (n div 2) do
   for j:=1 to n do
      if (b[i,j]=true) and (b[j,i]=true) then f:=false;
   if f then
   begin
       repeat
       begin
        f:=true;
        for i:=1 to n do begin
           for j:=1 to n do begin
              if (b[i,j])and (a[j]>=a[i]) then begin a[i]:=a[j]+1;f:=false;end;
           end;
        end;
       end;
       until f;
       for i:=1 to n do tot:=tot+a[i];
       write(tot);
      end
   else  write(-1);
   close(input);
   close(output);
end.